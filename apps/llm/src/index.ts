import { generateText } from 'ai'
import { ollama } from 'ai-sdk-ollama'
import { type } from 'arktype'
import { Hono } from 'hono'

const app = new Hono()

const DecompReqBody = type({
  prompt: "string",
  temp: "number = 0.8",
  maxOutputTokens: "number = 256",
})

app.post('/chat', async (c) => {
  const json = await c.req.json()
  const body = DecompReqBody(json)

  if (body instanceof type.errors) {
    return c.json({ error: body.summary }, 400)
  }

  const { text, usage } = await generateText({
    model: ollama('gemma3:1b'),
    prompt: body.prompt,
    temperature: body.temp,
    maxOutputTokens: body.maxOutputTokens,
  })

  return c.json({ text, usage })
})

export default app
