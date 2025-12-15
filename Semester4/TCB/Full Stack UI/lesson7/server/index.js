import dotenv from 'dotenv'
dotenv.config() // load env immediately

import express from 'express'
import cors from 'cors'
import { connect } from './mongodb.js'
import userRouter from './routes/userRouter.js'
//ייבואים

const app = express()
app.use(express.json())
app.use(cors())

const PORT = Number(process.env.PORT) || 6000

const start = async () => {
    try {
        await connect() // wait for DB before exposing endpoints
        app.use('/user', userRouter)

        app.listen(PORT, () => {
            console.log('-----------------------------------------')
            console.log(`server is on localhost:${PORT}`)
        })
    } catch (err) {
        console.error('Failed to start:', err)
        process.exit(1)
    }
}

start()
