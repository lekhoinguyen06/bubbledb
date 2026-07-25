import { generateText, Output, tool } from 'ai'
import { ollama } from 'ai-sdk-ollama'
import { Hono } from 'hono'
import { decompRoutes } from './routes/decomp'

const app = new Hono()

app.route('/decomp', decompRoutes)

console.log(app.routes)

export default app
