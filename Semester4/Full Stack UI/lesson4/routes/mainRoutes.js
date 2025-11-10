import express from "express";

const mainRouter = express.Router();

mainRouter.get("/", (req, res) => {
      res.send("Welcome to the main route");
});

mainRouter.get("/status", (req, res) => {
      res.json({ status: "OK", timestamp: new Date() });
});

const idcheck = (req, res, next) => {
      const id = req.params.id;
      if (!/^\d+$/.test(id)) {
            return res.status(400).send("Invalid ID format. ID must be a number.");
      }
      next();
};

mainRouter.get("/:id", idcheck, (req, res) => {
      res.send(`You requested the resource with ID: ${req.params.id}`);
});

export default mainRouter;