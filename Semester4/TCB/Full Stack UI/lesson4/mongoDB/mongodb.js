import mongoose from "mongoose";

const connect = async() => {
      await mongoose.connect(process.env.DB_LINK);
      console.log("MongoDB connected");
}

const humanSchema = mongoose.Schema({
      id:String,
      name:String,
      birthdate:Date,
      email:String,
      phone:String
});

const studentModel = mongoose.model('student', humanSchema);
const teacherModel = mongoose.model('teacher', humanSchema);

export {
      connect,
      teacherModel,
      studentModel
}