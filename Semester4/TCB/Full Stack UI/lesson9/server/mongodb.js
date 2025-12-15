import mongoose from 'mongoose';

const connectToMongoDB = async () => {
  try {
    await mongoose.connect(process.env.MONGO_URL)
    console.log('Connected to MongoDB');
    } catch (error) {
    console.error('Error connecting to MongoDB:', error);
  } 
};

const movieSchema = new mongoose.Schema({});
const commentsSchema = new mongoose.Schema({});
const movieModel = mongoose.model('Movie', movieSchema, 'movies');
const commentsModel = mongoose.model('Comment', commentsSchema, 'comments');

export default connectToMongoDB
export { movieModel, commentsModel };