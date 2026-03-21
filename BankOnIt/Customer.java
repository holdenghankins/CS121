import java.util.Scanner;

public class Customer extends User {
    CheckingAccount checking;
    SavingsAccount savings;

    public Customer() {
        checking = new CheckingAccount();
        savings = new SavingsAccount();
    }

    public Customer(String userName, String pin) {
        setUserName(userName);
        setPin(pin);
        checking = new CheckingAccount();
        savings = new SavingsAccount();
    }

    public void main() {
        // I am unsure how we are supposed to get the cedentials for this iteration, so I am just hard coding them for now
        setUserName("Alice");
        setPin("1111");

        // Loops until user logs in to an account
        boolean loggedIn = false;
        while (!loggedIn) {
            loggedIn = login();
        }

        // Loops main menu until user quits
        Scanner scanner = new Scanner(System.in); // I don't think I am allowed to make this scanner shared so it isn't
        int input = 1; // Placeholder to initiate loop
        while (input != 0) {
            System.out.println(menu());
            switch (scanner.nextInt()) {
                case 0: // QUIT
                    scanner.close();
                    return;
                case 1: // CHECKING
                    checking.main();
                    break;
                case 2: // SAVINGS
                    savings.main();
                    break;
                case 3: // NEW PIN
                    changePin();
                    break;
                default: // INVALID INPUT
                    System.out.println("Invalid input");
            }
        }
        scanner.close();
    }

    public void start() {
        // Empty for now
    }

    /**
     * The prompt string that the user will see when interacting with menu
     */
    public String menu() {
        return "\nCustomer Menu\n\n0) Exit\n1) Manage Checking Account\n2) Manage Savings Account\n3) change PIN";
    }

    public void changePin() {
        Scanner changePinInput = new Scanner(System.in);
        System.out.print("New pin: ");
        setPin(changePinInput.nextLine());
    }

    /**
     * I could not find an exact example of how this should look so I am assuming it is both account balances + interest rate
     */
    public String getReport() {
        return "Customer: " + getUserName() + "\nChecking Balance: " + checking.getBalance() + 
        "\nSavings Balance: " + savings.getBalance() + " + " + savings.getInterestRate() + " interest";
    }
}