
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int count;

public:
    SavingsAccount(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
        count = 0;
    }

    void addTransaction(double amount)
    {
        if (count == 10)
        {
            for (int i = 0; i < 9; i++)
            {
                transactions[i] = transactions[i + 1];
            }
            count--;
        }

        transactions[count] = amount;
        count++;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            addTransaction(amount);
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            addTransaction(-amount);
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }

    void miniStatement();
};

void SavingsAccount::miniStatement()
{
    cout << "\nAccount Number: " << accountNumber << endl;
    cout << "Current Balance: " << balance << endl;

    cout << "\nLast Transactions:\n";

    for (int i = 0; i < count; i++)
    {
        if (transactions[i] > 0)
            cout << "Deposit: " << transactions[i] << endl;
        else
            cout << "Withdrawal: " << -transactions[i] << endl;
    }
}

int main()
{
    SavingsAccount account(101, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(2000);
    account.withdraw(300);

    account.miniStatement();

    return 0;
}
