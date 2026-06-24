#include <iostream>
#include <string>
#include <vector>
using namespace std;

int daysToFund(int startBalance, int dailyDeposit)
{
    const int goal = 42500;
    bool funded = false;
    int i = 0;
    int current_balance = startBalance;

    while (!funded)
    {
        i++;
        current_balance += dailyDeposit;
        cout << "Day " << i << ": deposited " << dailyDeposit << ", balance now " << current_balance << endl;
        if (current_balance >= goal)
        {
            funded = true;
        }
    }

    return i;
}

int main()
{
    int starting_value, daily_deposit, days;

    cout << "Enter the starting Vault balance: ";
        cin >> starting_value;
    cout << "Enter the daily deposit amount: ";
        cin >> daily_deposit;

    cout << "--- Vault Savings Plan ---" << endl;

    days = daysToFund(starting_value, daily_deposit);

    cout << "The Vault was funded in " << days << " days!" << endl;

    return 0;
}