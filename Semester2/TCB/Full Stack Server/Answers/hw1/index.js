import express from 'express';
import cors from 'cors';
import 'dotenv/config.js';

const app = express();
app.use(cors());
app.use(express.json());
const port = process.env.PORT || 5000;
const orders = {};
let lastID = 1;

app.use((req, res, next) => {
	const auth = req.headers['authorization'];
	if (!auth || auth !== 'Bearer token123') {
		return res.status(401).json({ error: 'Unauthorized: Invalid or missing token' });
	}
	next();
});

app.post('/order', (req, res) => {
	const { customerName, tableNumber, items } = req.body;
	if (!customerName || !tableNumber || !items) {
		return res.status(400).json({ 
		error: 'Missing required fields: customerName, tableNumber, items' 
		});
	}
	const order = {
		id: lastID,
		name: customerName,
		tableNum: tableNumber,
		itemList: items,
		date: (new Date().toISOString()).split('T')[0],
		time: new Date().toLocaleTimeString()
	};
	orders[lastID] = order;
	lastID++;
	res.status(201).json({ 
    		message: 'Order created successfully',
    		orderId: order.id,
		customerName: order.name,
		tableNumber: order.tableNum,
		itemList: order.itemList,
		date: order.date,
		time: order.time
  	});
});

app.get('/order/:id', (req, res) => {
	const orderId = parseInt(req.params.id);
	const order = orders[orderId];
	if (!order) {
		return res.status(404).json({ error: 'Order not found' });
	}
	res.json(order);
});

app.get('/search/:item', (req, res) => {
	const item = req.params.item;
	const result = Object.values(orders).filter(
		order => order.itemList.includes(item));
	if (result.length === 0) {
		res.status(404).json({
		message: 'No orders found for this item'
		});
		return;
	}
	else {
		res.json({
		item: item,
		orders: result
	});
	}  
});

app.listen(port, () => {
  	console.log(`Server running on http://localhost:${port}`);
});
