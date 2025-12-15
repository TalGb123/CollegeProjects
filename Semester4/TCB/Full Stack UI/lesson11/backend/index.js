import dotenv from 'dotenv'
dotenv.config() // load env immediately

import express from 'express'
import cors from 'cors'
import bcrypt from 'bcrypt'
import { connect } from './mongodb.js'
//ייבואים

const app = express()
app.use(express.json())
app.use(cors())

const PORT = Number(process.env.PORT) || 6000

const start = async () => {
      try {
            await connect() // wait for DB before exposing endpoints

            app.listen(PORT, () => {
                  console.log('-----------------------------------------')
                  console.log(`server is on localhost:${PORT}`)
            })
      } catch (err) {
            console.error('Failed to start:', err)
            process.exit(1)
      }
}

app.get('/login', async (req, res) => {
      const {email, pass} = req.query;
      const user = await userModel.findOne({ email, pass });
      const result = bcrypt.compareSync(password, user.pass);
      res.send(result);
});

app.post('/register', async (req, res) => {
      const {email, password} = req.body;
      const salt = bcrypt.genSaltSync(Number(process.env.SALT));
      const hash = bcrypt.hashSync(password, salt);
      const newUser = new userModel({email, password: hash});
      await newUser.save();
      res.send('User registered successfully');
});

start();
