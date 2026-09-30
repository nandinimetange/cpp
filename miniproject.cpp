#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int number, string name, double amount)
        : accountNumber(number), holderName(name), balance(amount) {}

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully." << endl;
        }
    }

    virtual void withdraw(double amount) = 0;
    virtual double calculateInterest() const = 0;

    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    virtual ~Account() = default;
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int number, string name, double amount)
        : Account(number, name, amount), interestRate(4.0) {}

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "\n=== Savings Account ===" << endl;
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

class CurrentAccount : public Account {
private:
    double interestRate;

public:
    CurrentAccount(int number, string name, double amount)
        : Account(number, name, amount), interestRate(2.0) {}

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "\n=== Current Account ===" << endl;
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double interestRate;

public:
    FixedDepositAccount(int number, string name, double amount)
        : Account(number, name, amount), interestRate(7.0) {}

    void withdraw(double amount) override {
        cout << "Withdrawal from Fixed Deposit is restricted." << endl;
    }

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "\n=== Fixed Deposit Account ===" << endl;
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

int main() {
    SavingsAccount savings(1001, "Rahul", 50000);
    CurrentAccount current(1002, "Priya", 75000);
    FixedDepositAccount fd(1003, "Amit", 100000);

    savings.deposit(5000);
    savings.withdraw(10000);

    current.deposit(10000);
    current.withdraw(15000);

    savings.display();
    current.display();
    fd.display();

    return 0;
}