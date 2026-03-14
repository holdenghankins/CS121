import java.util.Random;
import java.util.Scanner;

/**
 * Blackbelt: logs high scores and handles user misinfomration giving the computer an impossible guessing range
 * I know that's weak, but it's 10:52
 */
public class JavaGuesser {
    private static final Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        Random random = new Random();
        int numberToGuess;
        int version;
        int computerHighScore = 100;
        int playerHighScore = 100;

        // Menu loop
        boolean exit = false;
        while (!exit) {
            numberToGuess = (random.nextInt(100)) + 1;
            version = askForVersion();
            int rounds;
            if (version == 1) { // Player Guess
                System.out.println("\nUser guess");
                rounds = playerGuess(numberToGuess, 1);
                System.out.println("Very good");

                // Determine if high score
                if (rounds < playerHighScore) {
                    System.out.println("New player high score!");
                    playerHighScore = rounds;
                }
            }
            else if (version == 2) { // Computer Guess
                System.out.println("\nComputer guess");
                rounds = computerGuess(0, 100, 1);

                // Determine if high score
                if (rounds < computerHighScore) {
                    System.out.println("New computer high score!");
                    computerHighScore = rounds;
                }
            }
            else { // Exit
                exit = true;
                scanner.close();
                System.out.println("\nexiting...");
                return;
            }
            System.out.println(); // formatting
        }
    }

    public static int askForVersion() {
        System.out.print("Which version:\n(0) exit\n(1) User Guess\n(2) Computer Guess ");
        int version = scanner.nextInt();
        if (version != 0 && version != 1 && version != 2 ) {
        System.out.println("Invalid Input");
        return askForVersion(); 
        }
        else {
            return version;
        }
    }

    /**
     * Allows player to guess which number they think it is
     * @return Current turn in recersive call
     */
    public static int playerGuess(int numberToGuess, int round) {
        int playerGuess;
        System.out.print(round + ") Please enter a number 1 through 100: ");
        playerGuess = scanner.nextInt();
        // Feedback
        if (playerGuess == numberToGuess) {
            return round;
        }
        else if (playerGuess < 1 || playerGuess > 100) {
            System.out.println("Not in range");
        }
        else if (playerGuess > numberToGuess) {
            System.out.println("Too high");
        }
        else {
            System.out.println("Too low");
        }
        return playerGuess(numberToGuess, round + 1);
    }

    /**
     * Allows player to guess which number it thinks it is
     * Guesses in middle of range each time (O(log(n)) time)
     * @return Current turn in recersive call
     */
    public static int computerGuess(int low, int high,int round) {
        // Detects if user has been lying and computer has impossible guessing perametors
        if (low > high) {
            System.out.println("Hey! Don't lie to him! He's trying his best :(");
            return 100; // Prevents new high score
        }
        // Finds middle of possible range to find value optimally
        int guess = (low + high) / 2;
        System.out.println(round + ") I guess " + guess);
        
        // Assumes user feedback is correct
        char input = getHighLowCorrect();

        // Eliminates half of range if needs to guess again
        if (input == 'l') {
            return computerGuess(guess + 1, high, round + 1);
        }
        if (input == 'h') {
            return computerGuess(low, guess - 1, round + 1);
        } else { // Correct
            return round;
        }
    }

    /**
     * Asks player to tell the AI if it is too high, too low, or correct
     * @return h, l, or c, always lowercase
     */
    public static char getHighLowCorrect() {
        System.out.println("Too (H)igh, too (L)ow, or (C)orrect?");
        char input = scanner.next().charAt(0);
        input = Character.toLowerCase(input);
        if (input != 'h' && input != 'l' && input != 'c') {
            System.out.println("Invalid Input");
            input = getHighLowCorrect();
        }

        return input;
    }
}