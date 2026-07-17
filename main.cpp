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
    // Setter methods for update
    void setId(int newId) { id = newId; }
    void setTitle(string newTitle) { title = newTitle; }
    void setCategory(string newCategory) { category = newCategory; }
    void setAmount(double newAmount) { amount = newAmount; }
    void setDate(string newDate) { date = newDate; }
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

void deleteExpense()
{

    if (expenses.empty())
    {
        cout << "\nNo expenses to delete! Please add expenses first.\n";
        return;
    }

    cout << "Delete Expense";

    for (int i = 0; i < expenses.size(); i++)
    {
        cout << "ID" << expenses[i].getId()
             << "Title" << expenses[i].getTitle()
             << "Amount $" << expenses[i].getAmount() << endl;
    }

    int id;
    cout << "Enter ID to Delete";
    cin >> id;

    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getId() == id)
        {
            // Show the expense to be deleted
            cout << "\n--- Expense to Delete ---";
            expenses[i].display();

            // Confirm deletion
            char confirm;
            cout << "\nAre you sure you want to delete this expense? (y/n): ";
            cin >> confirm;

            if (confirm == 'y' || confirm == 'Y')
            {
                expenses.erase(expenses.begin() + i);
                cout << "\n✓ Expense with ID " << id << " deleted successfully!\n";
                cout << "Remaining expenses: " << expenses.size() << endl;
            }
            else
            {
                cout << "\nDeletion cancelled.\n";
            }
            return;
        }
    }
    cout << "\nExpense with ID " << id << " not found!\n";
}

void updateExpense()
{
    if (expenses.empty())
    {
        cout << "\nNo expenses to update! Please add expenses first.\n";
        return;
    }

    cout << "\n--- Update Expense ---\n";

    // Show all expenses with their IDs for reference
    cout << "\nCurrent Expenses:\n";
    for (int i = 0; i < expenses.size(); i++)
    {
        cout << "ID: " << expenses[i].getId()
             << " | Title: " << expenses[i].getTitle()
             << " | Amount: $" << expenses[i].getAmount() << endl;
    }

    int id;
    cout << "\nEnter Expense ID to update: ";
    cin >> id;

    for (int i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getId() == id)
        {
            // Show current expense
            cout << "\n--- Current Expense Details ---";
            expenses[i].display();

            cout << "\n--- Update Options ---\n";
            cout << "1. Update All Fields\n";
            cout << "2. Update Title Only\n";
            cout << "3. Update Category Only\n";
            cout << "4. Update Amount Only\n";
            cout << "5. Update Date Only\n";
            cout << "6. Cancel Update\n";
            cout << "Enter your choice: ";

            int updateChoice;
            cin >> updateChoice;
            cin.ignore();

            switch (updateChoice)
            {
            case 1:
            {
                // Update all fields
                cout << "\n--- Enter New Details ---\n";
                int newId;
                string newTitle, newCategory, newDate;
                double newAmount;

                cout << "Enter New ID: ";
                cin >> newId;
                cin.ignore();
                cout << "Enter New Title: ";
                getline(cin, newTitle);
                cout << "Enter New Category: ";
                getline(cin, newCategory);
                cout << "Enter New Amount: ";
                cin >> newAmount;
                cin.ignore();
                cout << "Enter New Date: ";
                getline(cin, newDate);

                expenses[i].setId(newId);
                expenses[i].setTitle(newTitle);
                expenses[i].setCategory(newCategory);
                expenses[i].setAmount(newAmount);
                expenses[i].setDate(newDate);

                cout << "\n✓ Expense updated successfully!\n";
                break;
            }
            case 2:
            {
                // Update title only
                string newTitle;
                cout << "Enter New Title: ";
                getline(cin, newTitle);
                expenses[i].setTitle(newTitle);
                cout << "\n✓ Title updated successfully!\n";
                break;
            }
            case 3:
            {
                // Update category only
                string newCategory;
                cout << "Enter New Category: ";
                getline(cin, newCategory);
                expenses[i].setCategory(newCategory);
                cout << "\n✓ Category updated successfully!\n";
                break;
            }
            case 4:
            {
                // Update amount only
                double newAmount;
                cout << "Enter New Amount: ";
                cin >> newAmount;
                expenses[i].setAmount(newAmount);
                cout << "\n✓ Amount updated successfully!\n";
                break;
            }
            case 5:
            {
                // Update date only
                string newDate;
                cout << "Enter New Date: ";
                getline(cin, newDate);
                expenses[i].setDate(newDate);
                cout << "\n✓ Date updated successfully!\n";
                break;
            }
            case 6:
            {
                cout << "\nUpdate cancelled.\n";
                break;
            }
            default:
                cout << "Invalid choice!\n";
            }

            // Show updated expense
            cout << "\n--- Updated Expense Details ---";
            expenses[i].display();
            return;
        }
    }
    cout << "\nExpense with ID " << id << " not found!\n";
}
void totalExpense()
{
    if (expenses.empty())
    {
        cout << "\nNo expenses to calculate! Please add expenses first.\n";
        return;
    }

    cout << "\n--- Total Expenses ---\n";
    cout << "========================\n";

    double total = 0;
    int count = expenses.size();

    // Display each expense with its amount
    cout << "\nExpense Breakdown:\n";
    for (int i = 0; i < expenses.size(); i++)
    {
        cout << "ID: " << expenses[i].getId()
             << " | " << expenses[i].getTitle()
             << " | $" << fixed << setprecision(2) << expenses[i].getAmount() << endl;
        total += expenses[i].getAmount();
    }

    cout << "\n========================\n";
    cout << "Number of Expenses: " << count << endl;
    cout << "Total Amount: $" << fixed << setprecision(2) << total << endl;

    // Calculate average
    double average = total / count;
    cout << "Average Expense: $" << fixed << setprecision(2) << average << endl;

    // Find highest and lowest
    double highest = expenses[0].getAmount();
    double lowest = expenses[0].getAmount();
    string highestTitle = expenses[0].getTitle();
    string lowestTitle = expenses[0].getTitle();

    for (int i = 1; i < expenses.size(); i++)
    {
        if (expenses[i].getAmount() > highest)
        {
            highest = expenses[i].getAmount();
            highestTitle = expenses[i].getTitle();
        }
        if (expenses[i].getAmount() < lowest)
        {
            lowest = expenses[i].getAmount();
            lowestTitle = expenses[i].getTitle();
        }
    }

    cout << "\nHighest Expense: $" << fixed << setprecision(2) << highest
         << " (" << highestTitle << ")" << endl;
    cout << "Lowest Expense: $" << fixed << setprecision(2) << lowest
         << " (" << lowestTitle << ")" << endl;
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