import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class Bank {
    private Admin admin;
    // Could be optimized with an RB tree, but specifications ask for ArrayList and I do not want to make one by hand
    private ArrayList<Customer> customers;

    public Bank(){
        admin = new Admin("admin", "0000");
        customers = new ArrayList<>();
        loadCustomers();
    }

    public void main() {
        start();
    }

    public void loadSampleCustomers() {
        customers.add(new Customer("Jeff", "1234"));
        customers.add(new Customer("Geoff", "4321"));
        customers.add(new Customer("Jeph", "0000"));
        customers.add(new Customer("Pjeffe", "3343"));
        customers.add(new Customer("Robert", "1644"));
        customers.sort(Comparator.comparing(Customer::getUserName));
    }

    public void loadCustomers() {
        loadSampleCustomers();
    }

    public void saveCustomers() {
        customers.sort(Comparator.comparing(Customer::getUserName));
    }

    public void fullCustomerReport() {
        for (Customer customer : customers) {
            System.out.println(customer.getReport());
        }
    }

    /**
     * Asks user for a username and pin and adds it to the ArrayList
     * Sorts ArrayList to ensure that location can still be done in O(log(n)) time
     * Sorting is done using timsort. Assuming array sorted before addition, it runs in O(n)
     */
    public void addUser() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Name: ");
        String name = scanner.nextLine();
        System.out.print("Pin: ");
        String pin = scanner.nextLine();

        customers.add(new Customer(name, pin));
        saveCustomers();
    }

    public void applyIntrest() {
        for (Customer customer : customers) {
            System.out.println(customer.updateSavings());
        }
    }

    public void loginAsCustomer() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("User Name: ");
        String username = scanner.nextLine();
        System.out.print("Pin: ");
        String pin = scanner.nextLine();

        int index = findCustomer(username);
        if (index == -1) {
            System.out.println("No user found");
            return;
        }
        Customer customer = customers.get(index);
        if (!pin.equals(customer.getPin())) {
            System.out.println("Incorrect password");
            return;
        }

        System.out.println("\nLogged In\n");
        customer.start();
    }

    /**
     * Helper method that allows for the location of a username in customers
     * Halves the list with each search, allowing for O(logn) searching
     * Returns index over customer to prevent attempting to read a null customer
     * @return index of customer in customers (-1 if not found)
     */
    public int findCustomer(String username) {
        Customer customer = new Customer();
        int max = customers.size() - 1;
        int min = 0;
        int index = max / 2;
        int previous = -1; // arbitrary number to prevent index == previous on first run
        boolean iEqualsP = false;

        while (index >= min && index <= max) {
            System.out.println(index);
            if (index == previous) {
                index++;
                iEqualsP = true;
            }

            customer = customers.get(index);
            int comparison = (customer.getUserName().compareTo(username));
            if (comparison < 0) {
                min = index + 1;
                previous = index;
                index = (index + max) / 2;
            } else if (comparison > 0) {
                max = index - 1;
                previous = index;
                index = (index + min) / 2;
            } else {
                return index;
            }

            if (iEqualsP) {
                break;
            }
        }

        return -1;
    }

    public void menu() {
        Scanner scanner = new Scanner(System.in);
        int input = -1; // Arbitrary to start loop
        while (input != 0) {
            System.out.print("\nBank menu\n0) Exit system\n1) Login as admin\n2) Login as customer\n\nAction: ");
            input = scanner.nextInt();
            switch (input) {
                case 0: // QUIT
                    break;
                case 1: // CUSTOMER
                    System.out.println("\nAdmin login");
                    startAdmin();
                    break;
                case 2: // ADMIN
                    System.out.println("\nCustomer login");
                    loginAsCustomer();
                    break;
                default: // INVALID INPUT
                    System.out.println("\nInvalid input");
                    input = -1;
            }
            System.out.print("0) Exit system\n1) Login as admin\n2) Login as customer\n\nAction: ");
            input = scanner.nextInt();
        }
        System.out.println("\nExiting");
    }

    public void start() {
        menu();
    }

    public void startAdmin() {
        Scanner scanner = new Scanner(System.in);
        System.out.print("User Name: ");
        String adminName = scanner.nextLine();
        System.out.print("Pin: ");
        String pin = scanner.nextLine();

        if (adminName.equals(admin.getUserName()) && pin.equals(admin.getPin())) {
            System.out.println("\nLogged in to admin");
        }
        else {
            System.out.println("\nIncorrect name or password");
            return;
        }

        int input = -1;
        while (input != 0) {
            System.out.print(admin.menu());
            input = scanner.nextInt();
            switch (input) {
                case 0:
                    System.out.println("\nLogged out");
                    break;
                case 1:
                    System.out.println("\nFull customer report");
                    fullCustomerReport();
                    break;
                case 2:
                    System.out.println("\nAdd user");
                    addUser();
                    break;
                case 3:
                    System.out.println("\nApply interest");
                    applyIntrest();
                    break;
                default:
                    System.out.println("\nInvalid input");
            }
        }
    }
}