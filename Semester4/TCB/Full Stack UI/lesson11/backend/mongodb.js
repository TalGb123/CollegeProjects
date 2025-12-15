import mongoose from 'mongoose';

const connect = async () => {
  try {
    await mongoose.connect(process.env.DB_LINK)
    console.log('Connected to MongoDB');
    } catch (error) {
    console.error('Error connecting to MongoDB:', error);
  } 
};

const userSchema = mongoose.Schema({
  email:String,
  pass:String,
});

const userModel = mongoose.model('user', userSchema);

export { userModel, connect };