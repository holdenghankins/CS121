import java.util.Scanner;

public abstract class User implements HasMenu {
    private String userName;
    private String pin;

    public User() {        
    }

    /**
     * Asks for user to provide a username and "pin" (String, unchecked for length or composition)
     * Informed the user as to the successfulness of their attempt
     */
    public boolean login() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("User name: ");
        String userNameInput = scanner.nextLine();
        System.out.print("Pin: ");
        String pinInput = scanner.nextLine();

        if (login(userNameInput, pinInput)) {
            System.out.println("\nLogin successful\n");
            return true;
        } else {
            System.out.println("\nLogin unsuccessful\n");
            return false;
        }
    }

    /**
     * Tries to login given credentials
     * @param userName String
     * @param pin String
     * @return if login worked
     */
    public boolean login(String userName, String pin) {
        return this.userName.equals(userName) && this.pin.equals(pin);
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getUserName() {
        return userName;
    }

    public void setPin(String pin) {
        this.pin = pin;
    }

    public String getPin() {
        return pin;
    }

    public abstract String getReport();
}