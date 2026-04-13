#include <iostream>
#include <string>

class BankAccount 
{
    private:
        std::string owner;
        double balance;

    public:
        void setOwner(std::string name)
        {
            owner = name;
            return;
        };
        std::string getOwner()
        {
            return owner;
        };
        void deposit(double value)
        {
            if(value <= 0)
            {
                std::cout << "Invalid value. Deposits must be positive values greater than 0." << std::endl;
                return;
            }
            balance += value;
            std::cout << "The new balance is: " << balance << std::endl;
            return;
        };
        void withdraw(double value)
        {
            if(value <= 0)
            {
                std::cout << "Invalid value. Value cannot be negative or 0." << std::endl;
                return;
            }
            else if(value > balance)
            {
                std::cout << "Invalid value. Value of withdrawal must be at most value of balance." << std::endl;
                return;
            }
            balance -= value;
            std::cout << "The new balance is: " << balance << std::endl;
            return;
        };
        double getBalance()
        {
            return balance;
        };
        void getAccountInfo()
        {
            std::cout << "Owner name: " << owner << std::endl;
            std::cout << "Balance: " << balance << std::endl;
            return;
        };

        //default constructor
        BankAccount()
        {
            balance = 0;
        }

        //constructor with parameter
        BankAccount(double value)
        {
            balance = value;
        }

        //copy-constructor
        BankAccount(const BankAccount& acc)
        {
            balance = acc.balance;
        }
};

int main()
{

    return 0;
}