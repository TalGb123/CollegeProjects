// Import express
const express = require('express');
const cors = require('cors')
// Create an express app
const app = express();
app.use(express.json())
app.use(cors())

// Define a list of users
const users = [
  { id: 1, name: 'John Doe', email: 'john@example.com' },
  { id: 2, name: 'Jane Smith', email: 'jane@example.com' },
  { id: 3, name: 'Alice Johnson', email: 'alice@example.com' }
];

// Set up a GET route to return the users in JSON format
app.get('/users', (req, res) => {
  res.json(users);
});
app.get('/user/:id',(req,res)=>{
  const {id} = req.params
  const user = users.filter((item)=>item.id == id)
  res.send(user)
})

// Define the port the server will listen on
const port = 3000;
app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
