import { Hono } from "hono";
import { embedHandler } from "./embed.service";

export const embedRoutes = new Hono()

embedRoutes.post('/', embedHandler)