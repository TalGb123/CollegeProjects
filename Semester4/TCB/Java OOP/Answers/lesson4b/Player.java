public abstract class Player {
    private String name;
    private int score;

    public Player(String name) {
        this.name = name;
        this.score = 0;
    }

    public abstract Action SelectAction(Action[] actions);

    public boolean IsWinner(Player p) {
        return this.score > p.score;
    }

    public void UpdateScore(int points) {
        score += points;
    }

    public int GetScore() {
        return this.score;
    }

    public String GetName() {
        return this.name;
    }
}
