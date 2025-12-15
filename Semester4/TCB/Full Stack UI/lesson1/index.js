import express from 'express';
import cors from 'cors';

const app = express();
const port = 3000;

app.use(cors());
app.use(express.json());

app.listen(port, () => {
  console.log(`Server listening on http://localhost:${port}`);
});


app.get('/', (req, res) => {
    res.send('Hello World!');
});

// 1. מסלול שמחזיר את המספר בחזקת 3
app.get('/power3/:num', (req, res) => {
    const { num } = req.params;
    res.send(num**3);
    // כתוב כאן את הקוד שיחזיר את num בחזקת 3
})

// 2. מסלול שמחזיר את השורש הריבועי של מספר
app.get('/sqrt/:num', (req, res) => {
    const { num } = req.params;
    res.send(Math.sqrt(num));
    // כתוב כאן את הקוד שמחשב שורש ריבועי
})

// 3. מסלול שמקבל שני מספרים ומחזיר את הממוצע שלהם
app.get('/average/', (req, res) => {
    const { x, y } = req.body;
    res.send((x + y) / 2);
    // כתוב כאן את הקוד שמחזיר ממוצע
})

// 4. מסלול שמחזיר אם מספר הוא זוגי או לא
app.get('/isEven/:num', (req, res) => {
    const { num } = req.params;
    res.send(num % 2 === 0 ? "even" : "odd");
    // החזר תשובה טקסטואלית כמו "even" או "odd"
})

// 5. מסלול שמחשב פקטוריאל (factorial) של מספר
app.get('/factorial/:n', (req, res) => {
      const { n } = req.params;
      let factorial = 1;
      for (let i = 2; i <= n; i++) {
            factorial *= i;
      }
      res.send(factorial);
    // חשב את n! והחזר את התוצאה
})

// 6. מסלול שמחזיר את סכום כל המספרים מ-1 עד n
app.get('/sumTo/:n', (req, res) => {
      const { n } = req.params;
      let sum = 0;
      for (let i = 1; i <= n; i++) {
            sum += i;
      }
      res.send(sum);
    // חשב סכום כל המספרים עד n
})

// 7. מסלול שמחזיר את הערך המקסימלי מבין שני מספרים
app.post('/max', (req, res) => {
    const { a, b } = req.body;
      res.send(Math.max(a, b));
    // החזר את המספר הגדול מבין שניהם
})

// 8. מסלול שמחשב שטח מלבן לפי אורך ורוחב
app.post('/rectangleArea', (req, res) => {
    const { width, height } = req.body;
    res.send(width * height);
    // החזר את שטח המלבן
})

// 9. מסלול שמחזיר את הסכום של רשימת מספרים שנשלחת בגוף הבקשה
app.post('/sumArray', (req, res) => {
    const { numbers } = req.body;
    res.send(numbers.reduce((acc, curr) => acc + curr, 0));
    // החזר את סכום המספרים במערך
})

// 10. מסלול שמחזיר את חזקת 2 לכל איבר במערך מספרים
app.post('/squareArray', (req, res) => {
    const { numbers } = req.body;
    res.send(numbers.map(num => num ** 2));
    // החזר מערך חדש שכל איבר בו הוא בחזקת 2
})