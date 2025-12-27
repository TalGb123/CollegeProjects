import express from 'express'
import { userModel } from '../mongodb.js'
const userRouter = express.Router()
// middlewares

//

userRouter.get('/all', async (req, res) => {
    try {
        console.log('HTTP GET /user/all')
        const data = await userModel.find({})
        return res.json(data)
    } catch (err) {
        console.error('GET /user/all error:', err)
        return res.status(500).json({ error: 'Server error' })
    }
})

userRouter.get('/:id', async (req,res)=>{
    const {id} = req.params
    const user = await userModel.findOne({_id:id})
    res.send(user)
})
userRouter.get('/personal/:id',async(req,res)=>{
    const {id} = req.params
    const user = await userModel.findOne({_id:id},'name password')
    res.send(user)
})
userRouter.post('/',async(req,res)=>{
    const { birthday } = req.body
    const result = await userModel.insertOne(req.body)
    res.send(result)
})
userRouter.post('/class',async(req,res)=>{
    const result = await userModel.insertMany(req.body)
    res.send(result)
})
userRouter.patch('/all',async(req,res)=>{
    const result = await userModel.updateMany({},req.body)
    res.send(result)
})

userRouter.patch('/:id',async(req,res)=>{
    const {id} = req.params

    const result = await userModel.updateOne({_id:id},req.body)
    res.send(result)
})

userRouter.delete('/all',async(req,res)=>{
    const result = await userModel.deleteMany({})
    res.send(result)
})
userRouter.delete('/:id',async(req,res)=>{
    const {id} = req.params
    const result = await userModel.deleteOne({_id:id})
    res.send(result)
})


export default userRouter