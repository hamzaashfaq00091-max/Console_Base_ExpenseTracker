#include <iostream>
#include <vector>
#include <cctype>

using namespace std;

class Expense
{

private:
    int id;
    string title;
    string category;
    double amount;
    string date;

public:
    Expense() : id(0), title(""), category(""), amount(0.0), date("") {};
    Expense(int i, string t, string c, double a, string d)
        : id(i), title(t), category(c), amount(a), date(d) {}
    void input()
    {
        cout << "Enter ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, title);

        cout << "Enter Category: ";
        getline(cin, category);

        cout << "Enter Amount: ";
        cin >> amount;

        cin.ignore();

        cout << "Enter Date: ";
        getline(cin, date);
    };

    void display()
    {

        cout << "\n----- Expense Details -----\n";
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Category: " << category << endl;
        cout << "Amount: " << amount << endl;
        cout << "Date: " << date << endl;
    };
    int getId() { return id; }
    string getTitle() { return title; }
    string getCategory() { return category; }
    double getAmount() { return amount; }
    string getDate() { return date; }
};

vector<Expense> expenses;

void addExpense()
{

    Expense expense;
    cout << "Add new Expense\n";
    expense.input();
    expenses.push_back(expense);
    cout << "Expenses Added Successfully";
};

void viewExpenses()
{

    if (expenses.empty())
    {
        cout << "Expenses Empty, Add the Expenses";
        return;
    };

    cout << "All Expenses";
    for (int i = 0; i < expenses.size(); i++)
    {
        expenses[i].display();
    }
};

void displayMenu()
{

    cout << "==============================\n";
    cout << "      EXPENSE TRACKER\n";
    cout << "==============================\n";

    cout << "1. Add Expense\n";
    cout << "2. View Expenses\n";
    cout << "3. Search Expense\n";
    cout << "4. Delete Expense\n";
    cout << "5. Update Expense\n";
    cout << "6. Total Expense\n";
    cout << "7. Category Report\n";
    cout << "8. Sort Expenses\n";
    cout << "9. Save Data\n";
    cout << "10. Load Data\n";
    cout << "0. Exit\n\n";
};

// Search Expenses

void SearchExpense()
{

    if (expenses.empty())
    {
        cout << "Expenses Empty,plz add the Expenses";
        return;
    }

    cout << "\n--- Search Expense ---\n";
    cout << "Search by:\n";
    cout << "1. ID\n";
    cout << "2. Title\n";
    cout << "3. Category\n";
    cout << "Enter your choice: ";

    int searchChoice;
    cin >> searchChoice;
    cin.ignore(); // Clear the newline

    bool found = false;

    switch (searchChoice)
    {
case 1:
    {
        // Search by ID
        int id;
        cout << "Enter Expense ID: ";
        cin >> id;

        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].getId() == id)
            {
                cout << "\n--- Expense Found ---";
                expenses[i].display();
                found = true;
                break;
            }
        }
        break;
    }
    
    case 2:
    {
        // Search by Title
        string title;
        cout << "Enter Title (or part of it): ";
        getline(cin, title);

        cout << "\n--- Search Results ---\n";
        for (int i = 0; i < expenses.size(); i++)
        {
            // Check if title contains the search term (case-insensitive)
            string expenseTitle = expenses[i].getTitle();
            // Simple case-insensitive comparison
            string searchLower = title;
            string titleLower = expenseTitle;
            for (int j = 0; j < searchLower.length(); j++)
            {
                searchLower[j] = tolower(searchLower[j]);
            }
            for (int j = 0; j < titleLower.length(); j++)
            {
                titleLower[j] = tolower(titleLower[j]);
            }

            if (titleLower.find(searchLower) != string::npos)
            {
                expenses[i].display();
                cout << "------------------------\n";
                found = true;
            }
        }
        break;
    }

    case 3:
    {
        // Search by Category
        string category;
        cout << "Enter Category: ";
        getline(cin, category);

        cout << "\n--- Search Results ---\n";
        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].getCategory() == category)
            {
                expenses[i].display();
                cout << "------------------------\n";
                found = true;
            }
        }
        break;
    }

    default:
        cout << "Invalid choice!\n";
        return;
    }

        if (!found)
        {
            cout << "\nNo matching expenses found!\n";
        }
    }


int main()
{

    int choice;

    do
    {

        displayMenu();
        cout << "Enter Your Choice : ";

        cin >> choice;

        switch (choice)
        {

        case 1:
            addExpense();
            break;

        case 2:
            viewExpenses();
            break;

        case 3:
            SearchExpense();
            break;

        case 4:
            cout << "Delete Expense Selected\n";
            break;

        case 5:
            cout << "Update Expense Selected\n";
            break;

        case 6:
            cout << "Total Expense Selected\n";
            break;

        case 7:
            cout << "Category Report Selected\n";
            break;

        case 8:
            cout << "Sort Expense Selected\n";
            break;

        case 9:
            cout << "Save Data Selected\n";
            break;

        case 10:
            cout << "Load Data Selected\n";
            break;

        case 0:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}