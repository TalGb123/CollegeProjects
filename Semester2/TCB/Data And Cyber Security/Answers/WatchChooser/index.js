import express from 'express';
import cors from 'cors';
import 'dotenv/config.js';
import { scrapeBrands } from './question-scrap.js';

const app = express();
app.use(cors());
app.use(express.json());
const port = process.env.PORT || 5000;

app.get('/', (req, res) => {
  res.send('Hello World!');
}
);

app.get('/questionscrap', async (req, res) => {
  try {
    const scrap = await scrapeBrands();
    res.json(scrap);
  } catch (err) {
    console.error('Scraping endpoint error:', err); 
    res.status(500).json({ error: 'Failed to scrape Chrono24' });
  } 
});

app.get('/filterscrapping', async (req, res) => {
  try {
    const scrap = await scrapeBrands();
    res.json(scrap);
  } catch (err) {
    console.error('Scraping endpoint error:', err); 
    res.status(500).json({ error: 'Failed to scrape Chrono24' });
  } 
}
);

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
});
