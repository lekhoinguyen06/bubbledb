import { DecompReqBodyDTO, DecompResBodyDTO } from "./decomp.dto"
import { generateText, Output } from "ai"
import { ollama } from "ai-sdk-ollama"
import { type } from "arktype"
import { Context } from "hono"
import { prompts } from "./decomp.prompt"

export const decompHandler = async (c: Context) => {
  const json = await c.req.json()
  const body = DecompReqBodyDTO(json)

  if (body instanceof type.errors) {
    return c.json({ error: body.summary }, 400)
  }

  const { usage, output } = await generateText({
    model: ollama('gemma3:1b'),
    prompt: JSON.stringify({...prompts, input: body.input}),
    temperature: body.temp,
    maxOutputTokens: body.maxOutputTokens,
    output: Output.array({
      element: DecompResBodyDTO,
    })
  })

  return c.json({ output, usage })
}