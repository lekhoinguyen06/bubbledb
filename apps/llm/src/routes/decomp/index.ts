import { Hono } from "hono";
import { decompHandler } from "./decomp.service";

export const decompRoutes = new Hono()

decompRoutes.post('/', decompHandler)