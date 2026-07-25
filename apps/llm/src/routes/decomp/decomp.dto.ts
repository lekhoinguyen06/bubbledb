import { type } from "arktype"

export const DecompReqBodyDTO = type({
  sentence: "string",
  temp: "number = 0.8",
  maxOutputTokens: "number = 256",
})

export const DecompResBodyDTO = type({
  subject: "string",
  relation: "string",
  object: "string",
})