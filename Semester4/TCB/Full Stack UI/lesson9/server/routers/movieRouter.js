import express from "express";
import mongoose from "mongoose";
const router = express.Router();

import { movieModel as Movie } from "../mongodb.js";
import { commentsModel as Comment } from "../mongodb.js";

// 2. get /movies/all/names – רק שמות הסרטים
router.get("/movies/all/names", async (req, res) => {
    const data = await Movie.find({}, { title: 1, _id: 1 }).limit(100);
    res.send(data);
});

// 3. get /movie/:id – חיפוש לפי ObjectId
router.get("/movie/:id", async (req, res) => {
    const { id } = req.params;
    try {
        const movie = await Movie.findById(new mongoose.Types.ObjectId(id));
        const comments = await Comment.find({ movie_id: new mongoose.Types.ObjectId(id) });
        console.log(comments,movie)
        res.send({
            movie:movie,
            comments:comments
        });
    } catch (err) {
        console.log(err)
        res.status(400).send({ error: "Invalid ObjectId" });
    }
});



export default router;
