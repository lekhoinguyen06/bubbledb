import { Hono } from "hono";
import { DecompReqBodyDTO, DecompResBodyDTO } from "./decomp.dto";
import { generateText, Output } from "ai";

import { decompHandler } from "./decomp.service";

export const decompRoutes = new Hono()

decompRoutes.post('/', decompHandler)