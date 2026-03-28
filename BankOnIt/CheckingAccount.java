import java.util.Scanner;

public class CheckingAccount implements HasMenu {
    private double balance;

    public CheckingAccount() {
        balance = 1000;
    }

    public CheckingAccount(double balance) {
        this.balance = balance;
    }

    public void main() {
        Scanner scanner = new Scanner(System.in);
        int input = 1; // Placeholder value
        while (input != 0) {
            System.out.println(menu());
            input = scanner.nextInt();
            switch(input) {
                case 0: // EXIT
                    scanner.close();
                    return;
                case 1: // BALANCE
                    checkBalance();
                    break;
                case 2: // ADD
                    makeDeposit();
                    break;
                case 3: // SUBTRACT
                    makeWithdrawal();
                    break;
                case 4: // INVALID
                    System.out.println("Invalid input");
            }
        } // end while
        scanner.close();
    } // end main

    /**
     * Prompt for interacting with a checking account
     */
    public String menu() {
        return "\nAccount menu\n\n0) quit\n1) check balance\n2) make a deposit\n3) make a withdrawal";
    }

    public void start() {
        // Empty for now
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getBalance() {
        return balance;
    }

    public String getBalanceString() {
        return "$" + Double.toString(balance);
    }

    public void checkBalance() {
        System.out.println("Balance " + balance);
    }

    /**
     * Helper method that checks the validity of a double
     * @return is double ? double : -1
     */
    private double getDouble() {
        Scanner readDouble = new Scanner(System.in);
        try {
            double d = readDouble.nextDouble();
            readDouble.close();
            return d;
        } catch(Exception e) {
            readDouble.close();
            return -1; // Documentation says "return 0", but user could well use '0' to cancel a misinput, so -1 seems more fitting
        }
    }

    public void makeDeposit() {
        System.out.println("Making a deposit...\nHow much would you like to deposit");
        double deposit = getDouble();
        if (deposit < 0) { // Catches -1 error and attempts to add a negative
            System.out.println("Invalid input");
        }
        else {
            balance += deposit;
            System.out.println("New balance: " + balance);
        }
    }

    public void makeWithdrawal() {
        System.out.println("Making a withdrawal...\nHow much would you like to withdraw");
        double withdrawal = getDouble();
        if (withdrawal < 0) { // Catches -1 error and attempts to subtract a negative
            System.out.println("Invalid input");
        }
        else {
            balance -= withdrawal;
            System.out.println("New balance: " + balance);
        }
    }
}
