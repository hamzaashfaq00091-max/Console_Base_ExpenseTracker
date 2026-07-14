#include <iostream>

using namespace std;

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
}

int main()
{

    int choice;

    do
    {

         displayMenu();
        cout << "Enter Your Choice : ";

       

        cin>>choice;

        switch (choice)
        {

        case 1:
            cout << "Add Expense Selected\n";
            break;

        case 2:
            cout << "View Expenses Selected\n";
            break;

        case 3:
            cout << "Search Expense Selected\n";
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