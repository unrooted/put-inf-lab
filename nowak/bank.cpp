#include <iostream>
#include <vector>
#include <string>

class Account {
public:
    Account(const std::string& name, double balance) {
        this->name = name;
        this->balance = balance;
    }
    std::string getName() const {
        return name;
    }
    double getBalance() const {
        return balance;
    }
    void deposit(double amount) {
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds." << std::endl;
        }
    }
private:
    std::string name;
    double balance;
};

int main() {
    double amount;
    Account account("Juan Paulos", 500.00);

    std::cout << "Account Name: " << account.getName() << std::endl;
    std::cout << "Account Balance: $" << account.getBalance() << std::endl;

    std::cout << "Enter amount to deposit: $";
    std::cin >> amount;
    account.deposit(amount);
    std::cout << "New Balance: $" << account.getBalance() << std::endl;

    std::cout << "Enter amount to withdraw: $";
    std::cin >> amount;
    account.withdraw(amount);
    std::cout << "New Balance: $" << account.getBalance() << std::endl;

    return 0;
}

