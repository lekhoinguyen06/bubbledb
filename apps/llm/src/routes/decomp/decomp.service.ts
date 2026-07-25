import { DecompReqBodyDTO, DecompResBodyDTO } from "./decomp.dto"
import { generateText, Output } from "ai"
import { ollama } from "ai-sdk-ollama"
import { type } from "arktype"
import { Context } from "hono"

export const decompHandler = async (c: Context) => {
  const json = await c.req.json()
  const body = DecompReqBodyDTO(json)

  if (body instanceof type.errors) {
    return c.json({ error: body.summary }, 400)
  }

  const { usage, output } = await generateText({
    model: ollama('gemma3:1b'),
    prompt: `Decompose the following sentence into subject, relation, and object: ${body.sentence}`,
    temperature: body.temp,
    maxOutputTokens: body.maxOutputTokens,
    output: Output.object({
      schema: DecompResBodyDTO,
    })
  })

  return c.json({ output, usage })
}