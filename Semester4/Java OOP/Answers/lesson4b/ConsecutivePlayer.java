public class ConsecutivePlayer extends Player {
    private int lastIdx;

    public ConsecutivePlayer(String name) {
        super(name);
        this.lastIdx = -1;
    }

    @Override
    public Action SelectAction(Action[] actions) {
        if (actions == null || actions.length == 0) return null;
        lastIdx = (lastIdx + 1) % actions.length;
        return actions[lastIdx];
    }

}
