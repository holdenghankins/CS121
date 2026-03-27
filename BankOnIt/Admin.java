public class Admin extends User {
    public Admin(String userName, String pin) {
        super.setUserName(userName);
        super.setPin(pin);
    }

    public void start() {
        
    }

    public String menu() {
        return "\nAdmin menu\n0) Exit this menu\n1) Full customer report\n2) Add user\n3) Apply interest to savings accounts\n\nAction: ";
    }

    public String getReport(){
        return "";
    }
}