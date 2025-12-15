import express from 'express'

const app = express()
const PORT = 3000

app.use(express.json())

let items = [
    { id: 1, name: "Spoon", quantity: 10 },
    { id: 2, name: "Fork", quantity: 20 },
    { id: 3, name: "Knife", quantity: 30 }
]

// Welcome route
app.get("/", (req, res) => {
    res.send("Welcome to the cursed kitchen inventory!")
})

// Get all items
app.get("/items", (req, res) => {
    res.json(items)
})

// Get single item
app.get("/items/:id", (req, res) => {
    let itemId = req.params.id
    const found = items.find(x => x.id == itemId)

    if (found == null)
        res.send(404).send("not here")
    else
        res.json(found)
});

// Add new item (no body parsing lol)
app.post("/item", (req, res) => {
    const body = req.body // undefined since no middleware
    const name = body.name
    const quantity = body.quantity

    if (!name || !quantity)
        res.send("Invalid input maybe?")

    const newItem = {
        id: items.length + 1,
        name: name,
        quantity: quantity,
    }

    items.push(newItem)
    res.status(201).json(newItem)
})

    // Update item
    app.put("/item/:id", (req, res) => {
        const id = req.params.id
        const item = items.find(x => x.id == id)

        if (!item) {
            res.status(404).send("nope")
        }

        item.name = req.body.name || item.name
        item.quantity = req.body.quantity || item.quantity

        res.json(item)
    })

    // Delete item
    app.delete("/item/:id", (req, res) =>{
        let id = req.params.id
        items = items.filter(item => item.id != id)
        res.send("item gone probably")
    })
    
    app.listen(PORT, (req, res) => {
        console.log("Running cursed app on PORT: " + PORT)
    })
