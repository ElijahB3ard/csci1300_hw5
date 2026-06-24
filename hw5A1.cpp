#include <iostream>
#include <string>
#include <vector>
using namespace std;

int totalGold(int donations[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += donations[i];
    }

    return total;
}

int main()
{
    const int fund = 42500;
    int donation_number, total;

    cout << "Enter the number of gold donations: ";
        cin >> donation_number;

    int donations[100];

    for (int i = 0; i < donation_number; i++)
    {
        cout << "Enter gold donation " << i + 1 << ": ";
            cin >> donations[i];
    }

    cout << "--- Vault Funding ---" << endl;

    total = totalGold(donations, donation_number);

    cout << "Total gold donated: " << total << endl;
    cout << "Vault goal: " << fund << endl;

    if (total >= fund)
    {
        cout << "The Vault is fully funded! Surplus: " << (total - fund) << " gold" << endl;
    }
    else
    {
        cout << "The Vault still needs " << (fund - total) << " more gold." << endl;
    }
    
    return 0;
}

