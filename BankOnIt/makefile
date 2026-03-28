bank: HasMenu.class Bank.class CustomerList.class Admin.class Customer.class User.class CheckingAccount.class SavingsAccount.class

Bank.class: Bank.java CustomerList.class Admin.class Customer.class User.class CheckingAccount.class SavingsAccount.class
	javac -g Bank.java

CustomerList.class: CustomerList.java Customer.class User.class CheckingAccount.class SavingsAccount.class
	javac -g CustomerList.java

Admin.class: Admin.java User.class
	javac -g Admin.java

Customer.class: Customer.java User.class CheckingAccount.class SavingsAccount.class
	javac -g Customer.java

User.class: User.java HasMenu.class
	javac -g User.java

CheckingAccount.class: CheckingAccount.java HasMenu.class
	javac -g CheckingAccount.java

SavingsAccount.class: SavingsAccount.java CheckingAccount.class
	javac -g SavingsAccount.java

HasMenu.class: HasMenu.java
	javac -g HasMenu.java

testAdmin: Admin.class
	java Admin

testCustomer: Customer.class
	java Customer

testChecking: CheckingAccount.class
	java CheckingAccount

testSavings: SavingsAccount.class
	java SavingsAccount

clean:
	rm *.class

run: bank
	java Bank