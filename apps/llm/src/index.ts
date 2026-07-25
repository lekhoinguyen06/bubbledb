import { generateText, Output, tool } from 'ai'
import { ollama } from 'ai-sdk-ollama'
import { Hono } from 'hono'
import { decompRoutes } from './routes/decomp'
import { embedRoutes } from './routes/embed'

const app = new Hono()

app.route('/decomp', decompRoutes)
app.route('embed', embedRoutes)

console.log(app.routes)

export default app
