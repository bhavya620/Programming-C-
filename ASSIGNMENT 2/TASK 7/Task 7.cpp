
#include <iostream>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;
    double transactions[10];
    int start;
    int count;

public:
    SavingsAccount(int acc, double bal)
    {
        accountNumber = acc;
        balance = bal;
        start = 0;
        count = 0;
    }

    void addTransaction(double amount)
    {
        int index = (start + count) % 10;

        if (count == 10)
        {
            index = start;
            start = (start + 1) % 10;
        }
        else
        {
            count++;
        }

        transactions[index] = amount;
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
    }

    void miniStatement()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;

        cout << "\nLast 10 Transactions:\n";

        for (int i = 0; i < count; i++)
        {
            int index = (start + i) % 10;

            cout << transactions[index] << endl;
        }
    }
};

int main()
{
    SavingsAccount account(101, 5000);

    for (int i = 1; i <= 12; i++)
    {
        account.deposit(100);
    }

    account.miniStatement();

    return 0;
}
