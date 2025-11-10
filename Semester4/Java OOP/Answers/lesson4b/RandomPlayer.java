public class RandomPlayer extends Player {

    public RandomPlayer(String name) {
        super(name);
    }

    @Override
    public Action SelectAction(Action[] actions) {
        return actions[(int)(Math.random() * actions.length)];
    }
}
