public class PrisonerDilemmas extends Game {

    public PrisonerDilemmas(Player p1, Player p2) {
        super(p1, p2, "Prisoner's Dilemma");
    }

    @Override
    protected void InitActions() {
        actions = new Action[] {
            new Action("Confess"),
            new Action("Silent")
        };
    }

    @Override
    protected void RewardPlayers(Action a1, Action a2) {
        Player player1 = GetFirstPlayer();
        Player player2 = GetSecondPlayer();

        if (a1.toString().equals("Confess") && a2.toString().equals("Confess")) {
            player1.UpdateScore(-5);
            player2.UpdateScore(-5);
        } else if (a1.toString().equals("Confess") && a2.toString().equals("Silent")) {
            player1.UpdateScore(0);
            player2.UpdateScore(-15);
        } else if (a1.toString().equals("Silent") && a2.toString().equals("Confess")) {
            player1.UpdateScore(-15);
            player2.UpdateScore(0);
        } else {
            player1.UpdateScore(-1);
            player2.UpdateScore(-1);
        }
    }
}