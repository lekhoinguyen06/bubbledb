import { Hono } from "hono";
import { DecompReqBodyDTO, DecompResBodyDTO } from "./decomp.dto";
import { generateText, Output } from "ai";
import { ollama } from "ai-sdk-ollama";
import { type } from "arktype";
import { decompHandler } from "./decomp.service";

export const decompRoutes = new Hono()

decompRoutes.post('/', decompHandler)