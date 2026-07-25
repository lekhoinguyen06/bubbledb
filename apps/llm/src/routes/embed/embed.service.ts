import { EmbedReqBodyDTO } from "./embed.dto"
import { embed } from "ai"
import { ollama } from "ai-sdk-ollama"
import { type } from "arktype"
import { Context } from "hono"

export const embedHandler = async (c: Context) => {
  const json = await c.req.json()
  const body = EmbedReqBodyDTO(json)

  if (body instanceof type.errors) {
    return c.json({ error: body.summary }, 400)
  }

  const { embedding } = await embed({
    model: ollama.embedding('nomic-embed-text'),
    value: body.sentence,
  });

  return c.json({ embedding })
}