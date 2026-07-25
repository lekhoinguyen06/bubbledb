import { generateText, Output, tool } from 'ai'
import { ollama } from 'ai-sdk-ollama'
import { type } from 'arktype'
import { Hono } from 'hono'

const app = new Hono()

const DecompReqBody = type({
  sentence: "string",
  temp: "number = 0.8",
  maxOutputTokens: "number = 256",
})

const DecompResBody = type({
  subject: "string",
  relation: "string",
  object: "string",
})

app.post('/decomp', async (c) => {
  const json = await c.req.json()
  const body = DecompReqBody(json)

  if (body instanceof type.errors) {
    return c.json({ error: body.summary }, 400)
  }

  const { usage, output } = await generateText({
    model: ollama('gemma3:1b'),
    prompt: `Decompose the following sentence into subject, relation, and object: ${body.sentence}`,
    temperature: body.temp,
    maxOutputTokens: body.maxOutputTokens,
    output: Output.object({
      schema: DecompResBody,
    })
  })

  return c.json({ output, usage })
})

export default app
