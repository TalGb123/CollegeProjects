public abstract class Game {
    private Player p1, p2;
    private String name; 

    protected Action[] actions; 

    public Game(Player p1, Player p2, String name){
        this.name = name;
        this.p1 = p1;
        this.p2 = p2;
        InitActions();
    }

    protected abstract void InitActions();

    public void Play(int turnCount) {
        System.out.println("=== Playing " + name + " ===");
        for (int i = 0; i < turnCount; i++) {
            PlaySingleTurn();
        }
        System.out.println("\nFinal Scores:");
        System.out.println(p1.GetName() + ": " + p1.GetScore());
        System.out.println(p2.GetName() + ": " + p2.GetScore());
        System.out.println("Winner: " + GetWinner().GetName());
    }

    private void PlaySingleTurn() {
        Action a1 = p1.SelectAction(actions);
        Action a2 = p2.SelectAction(actions);
        System.out.println(p1.GetName() + " chose " + a1 + ", " + p2.GetName() + " chose " + a2);
        RewardPlayers(a1, a2);
    }

    protected abstract void RewardPlayers(Action a1, Action a2);

    public Player GetWinner() {
        if (this.p1.IsWinner(this.p2)) {
            return this.p1;
        }
        else if (this.p2.IsWinner(this.p1)) {
            return this.p2;
        }
        return null;
    }

    protected Player GetFirstPlayer() {
        return this.p1;
    }

    protected Player GetSecondPlayer() {
        return this.p2;
    }

}
