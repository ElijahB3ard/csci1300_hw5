#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Problem 1 functions
int totalSales(vector<int> sales)
{
    // Define variables
    int total = 0;

    // Sum sales from each day
    for (int i = 0; i < static_cast<int>(sales.size()); i++)
    {
        total += sales[i];
    }

    // Return statement
    return total;
}

// Problem 2 functions
int bestDayIndex(vector<int> sales)
{
    // Define variables
    int index = 0;
    int max = sales[0];

    // Find index of max
    for (int i = 1; i < static_cast<int>(sales.size()); i++)
    {
        if (sales[i] > max)
        {
            max = sales[i];
            index = i;
        }
    }

    // Return statement
    return index;
}

// Problem 3 functions
int grandTotal(int totals[], int size)
{
    // Define variable
    int total = 0;

    // Calculate total
    for (int i = 0; i < size; i++)
    {
        total += totals[i];
    }

    // Return statement
    return total;
}

// Problem 4 functions
string toUpperCase(string text)
{
    // Define variable
    int converstion_factor = 'a' - 'A';

    // Loop through each character
    for (int i = 0; i < static_cast<int>(text.length()); i++)
    {
    // Convert to uppercase
        if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] -= converstion_factor;
        }
    }

    // Return statement
    return text;
}

// Problem 5 functions
void printMenu()
{
    cout << "1. Spend on advertising (-100 gold)" << endl;
    cout << "2. Restock shelves (-50 gold)" << endl;
    cout << "3. Collect membership fees (+75 gold)" << endl;
    cout << "4. Check budget" << endl;
    cout << "5. Close terminal" << endl;
}

// Problem 6 functions
vector<int> aboveThreshold(vector<int> sales, int threshold)
{
    // Define variables
    vector<int> high_performers;

    // Populate high performers vector
    for (int i = 0; i < static_cast<int>(sales.size()); i++)
    {
        if (sales[i] > 100)
        {
            high_performers.push_back(sales[i]);
        }
    }

    // Return statement
    return high_performers;
}

// Problem 7 functions
int sumVector(vector<int> v)
{
    //     int total = 0
    //     for (int i = 0; i <= v.size(); i++) {
    //         total += v[i];
    //     }
    //     return total

    // Define variables
    int total = 0; // Fixed: added ';'

    // Calculate sum
    for (int i = 0; i < static_cast<int>(v.size()); i++) // Fixed: changed bounds 'i <= v' -> 'i < v', must add static_cast<int>() for -Wall and -Werror
    {
        total += v[i];
    }

    // Return statement
    return total; // Fixed: added ';'
}

// Homework main function
int main()
{
// Problem 1
    // Define variables
    vector<int> sales_log;
    int sales = 0;
    int days = 0;
    int total_sales;

    // Loop through days
    while (sales != -1)
    {
    // Input
        cout << "Enter a daily sales figure (-1 to stop): ";
            cin >> sales;

    // Add to sales log
        if (sales != -1)
        {
            sales_log.push_back(sales);
            days++;
        }
    }

    // Header
    cout << "--- Daily Sales Log ---" << endl;

    // Get total sales
    total_sales = totalSales(sales_log);

    // Output
    cout << "Days logged: " << days << endl;
    cout << "Total sales: " << total_sales << endl;
// Problem 2
    // Define variables
    vector<int> sales2;
    int sale2, size2, index2;

    // Get number of days
    cout << "Enter the number of days: ";
        cin >> size2;

    // Add to sales vector
    for (int i = 0; i < size2; i++)
    {
    // Input
        cout << "Enter sales for day " << (i + 1) << ": ";
            cin >> sale2;

    // Populate sales vector
        sales2.push_back(sale2);
    }

    // Header
    cout << "--- Best Sales Day ---" << endl;

    // Get best day index
    index2 = bestDayIndex(sales2);

    // Output
    cout << "Best day: " << (index2 + 1) << endl;
    cout << "Sales: " << sales2[index2] << " gold" << endl;
// Problem 3
    // Define variables
    int daily_figures[100], regions, sale3, region_total, grand_total;
    int days3 = 3;

    // Input
    cout << "Enter the number of regions: ";
        cin >> regions;

    // Header
    cout << "--- Regional Sales ---" << endl;

    // Get sales for each region 
    for (int i = 0; i < regions; i++)
    {
    // Reset variables
        region_total = 0;

        for (int j = 1; j <= days3; j++)
        {
    // Input
            cout << "Enter sales for region " << (i + 1) << " day " << j << ": ";
                cin >> sale3;

    // Add sales 
            region_total += sale3;
        }
    
    // Populate sales log
        daily_figures[i] = region_total;

    // Output
        cout << "Region " << (i + 1) << " total: " << region_total << endl;
    }

    // Calculate grand total
    grand_total = grandTotal(daily_figures, regions);

    // Output
    cout << "Grand total: " << grand_total << endl;
// Problem 4
    // cin reset
    cin.ignore(1000, '\n');

    // Define variables
    string original_announcement, new_announcement;
    int length;

    // Input/ Initiallize
    cout << "Enter the store announcement: ";
        getline(cin, original_announcement);
    length = original_announcement.length();

    // Header 
    cout << "--- Store Announcement ---" << endl;

    // Convert original announcement
    new_announcement = toUpperCase(original_announcement);

    // Output
    cout << "Original: " << original_announcement << endl;
    cout << "Announcement: " << new_announcement << endl;
    cout << "Length: " << length << endl;
// Problem 5
    // Define variables
    int budget, choice;

    // Input
    cout << "Enter the starting daily budget: ";
        cin >> budget;

    // Header
    cout << "--- Joja Terminal ---" << endl;

    // Terminal loop
    do
    {
    // Display options
        printMenu();

    // Input
        cout << "Choose an option: ";
            cin >> choice;
    
    // Actions
        switch (choice)
        {
            case 1: // Advertising
                if (budget >= 100)
                {
                    budget -= 100;
                    cout << "Spent 100 gold on advertising. Budget: " << budget << endl;
                }
                else
                {
                    cout << "Not enough budget for advertising." << endl;
                }
                break;
            case 2: // Restocking
                if (budget >= 50)
                {
                    budget -= 50;
                    cout << "Spent 50 gold restocking. Budget: " << budget << endl;
                }
                else
                {
                    cout << "Not enough budget to restock." << endl;
                }
                break;
            case 3: // Membership fees
                budget += 75;
                cout << "Collected 75 gold in membership fees. Budget: " << budget << endl;
                break;
            case 4: // Current budget
                cout << "Current budget: " << budget << " gold" << endl;
                break;
            case 5: // Close terminal
                cout << "Closing the Joja terminal." << endl;
                break;
            default: // Invalid input
                cout << "Invalid option." << endl;
        }
    } 
    while (choice != 5);

    // Output
    cout << "Final budget: " << budget << " gold" << endl;
// Problem 6
    // Define variables
    vector<int> sales6, high_performers;
    int threshold = 100;
    int number_products, product_sales;

    // Input
    cout << "Enter the number of products: ";
        cin >> number_products;

    // Populate sales vector
    for (int i = 1; i <= number_products; i++)
    {
    // Input 
        cout << "Enter sales for product " << i << ": ";
            cin >> product_sales;

    // Populate 
        sales6.push_back(product_sales);
    }

    // Get high performance vector
    high_performers = aboveThreshold(sales6, threshold);

    // Header
    cout << "--- High Performers ---" << endl;

    // Output
    for (int i = 0; i < static_cast<int>(high_performers.size()); i++)
    {
        cout << high_performers[i] << " gold" << endl;
    }
    cout << "Products above 100 gold: " << high_performers.size() << endl;
// Problem 7
    // vector<int> nums;
    // nums.push_back(10);
    // nums.push_back(20)
    // nums.push_back(30);
    // cout << "Sum: " << sumVector(nums) << endl;

    // Define variables
    vector<int> nums;

    // Populate nums
    nums.push_back(10);
    nums.push_back(20); // Fixed: added ';'
    nums.push_back(30);

    // Header
    cout << "--- Debug Report ---" << endl;

    // Output
    cout << "Sum: " << sumVector(nums) << endl;
}