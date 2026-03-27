public class SavingsAccount extends CheckingAccount {
    double interestRate; 

    public SavingsAccount() {
        super();
        interestRate = 0.04; // generic interest rate as placeholder
    }

    /**
     * I think this should just run CheckingAccount().main??
     * I might be dumb but I think it is just inhereted for now
     */
    public void main() {
        super.main();
    }
    
    /**
     * Adds the amount earned in a year to the user's balance
     */
    public void calcInterestRate() {
        setBalance(getBalance() + (getBalance() * interestRate));
    }

    public void setInterestRate(double interestRate) {
        this.interestRate = interestRate;
    }

    public double getInterestRate() {
        return interestRate;
    }
}
