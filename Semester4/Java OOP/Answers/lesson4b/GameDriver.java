public class GameDriver {
    public static void main(String[] args) {
        Player p1 = new RandomPlayer("Alice");
        Player p2 = new ConsecutivePlayer("Bob");

        Game g1 = new RockPaperScissors(p1, p2);
        g1.Play(5);

        System.out.println("\n-----------------------------\n");

        Game g2 = new PrisonerDilemmas(p1, p2);
        g2.Play(5);
    }
}
