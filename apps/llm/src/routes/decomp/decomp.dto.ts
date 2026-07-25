import { type } from "arktype"

export const DecompReqBodyDTO = type({
  input: "string",
  temp: "number = 0.8",
  maxOutputTokens: "number = 256",
})

export const DecompResBodyDTO = type({
  source: "string",
  relation: "string",
  target: "string",
})