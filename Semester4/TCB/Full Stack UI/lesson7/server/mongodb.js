import mongoose from "mongoose";

const userSchema = mongoose.Schema({
    _id:String,
    name:String,
    password:String,
    grades:Array,
    birthday:String
})
const userModel = mongoose.model("user",userSchema)

const connect = async()=>{
    await mongoose.connect(process.env.DB_LINK)
    console.log("Connected to DB")
}

export {connect,userModel}