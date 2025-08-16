const express = require('express');
const { exec } = require('child_process');
const app = express();
const port = 5000;
app.use(express.json());

app.get('/', (req, res) => {
  res.send('Menu of commands:' + 
    `<ul>
    <li><a href="/scan">scan the network</a></li>
    <li><a href="/setUserFile">set user_file</a></li>
    <li><a href="/setPassFile">set pass_file</a></li>
    <li><a href="/setRHost">set rhost(s)</a></li>
    <li><a href="/verbose">set verbose - Boolean</a></li>
    <li><a href="/run">run</a></li>
    </ul>`);
});

app.get('/scan', (req, res) => {
  exec('nmap -sn'), (error, stdout, stderr) => {
    if (error) {
      console.error(`exec error: ${error}`);
      res.status(500).send(`Error: ${error.message}`);
      return;
    }
    if (stderr) {
      console.error(`stderr: ${stderr}`);
      res.status(500).send(`Error: ${stderr}`);
      return;
    }
    console.log(`stdout: ${stdout}`);
    res.send(`Scan result: ${stdout}`);
    console.log(`Scan result: ${stdout}`);
  }});


app.listen(port, () => {
  console.log(`Server is running at http://localhost:${port}`);
});
