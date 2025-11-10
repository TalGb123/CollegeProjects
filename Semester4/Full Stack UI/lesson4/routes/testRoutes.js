import express from "express";

const testRouter = express.Router();

testRouter.get("/", (req, res) => {
      res.send("This is the test route");
});

testRouter.get("/ip", (req, res) => {
      res.send(req.ip);
});

export default testRouter;