import express from 'express';
import cors from 'cors';
import dotenv from 'dotenv';
import testRouter from './routes/testRoutes.js';
import mainRouter from './routes/mainRoutes.js';
import { connect, teacherModel, studentModel } from './mongoDB/mongodb.js';

const app = express();
app.use(express.json());
app.use(cors());
dotenv.config();

app.use('/test', testRouter);
app.use('/main', mainRouter);

app.listen(process.env.PORT, async () => {
      async() => {
            console.log("Connecting to MongoDB...");
            const start = Date.now();
            await connect();
            const end = Date.now();

            console.log(await studentModel.find());
            console.log(await teacherModel.find());
            console.log(`Server is running on port ${process.env.PORT}`);
            console.log(`MongoDB connection time: ${end - start} ms`);
      }
});

app.get('/', (req, res) => {
      res.send('hello world');
});
app.get('/one', (req, res) => {
      res.send('one thing');
});
