public class RockPaperScissors extends Game{
    public RockPaperScissors(Player p1, Player p2) {
        super(p1, p2, "Rock Paper Scissors");
        InitActions();
    }

    protected void InitActions(){
        this.actions = new Action[3];
        this.actions[0] = new Action("rock");
        this.actions[1] = new Action("paper");
        this.actions[2] = new Action("scissors");
    }

    @Override
    protected void RewardPlayers(Action a1, Action a2){
        if (a1.Equals(a2)) {
            int a1i = -1, a2i = -1;
            for (int i = 0; i < this.actions.length; i++){
                if (a1.equals(this.actions[i])) {
                    a1i = i;
                }
                if (a2.equals(this.actions[i])) {
                    a2i = i;
                }
            }
            if ((a1i + 1) % 3 == a2i) {
                this.GetFirstPlayer().UpdateScore(1);
                this.GetSecondPlayer().UpdateScore(-1);
            } 
            else {
                this.GetSecondPlayer().UpdateScore(1);
                this.GetFirstPlayer().UpdateScore(-1);
            }
        }
    }
}
