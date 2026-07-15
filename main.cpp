#include <iostream>
#include <vector>

using namespace std;


class Expense{


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

    void display(){

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


    void addExpense(){

        Expense expense;
        cout<<"Add new Expense\n";
        expense.input();
        expenses.push_back(expense);
        cout<<"Expenses Added Successfully";
    };

    void viewExpenses(){

        if(expenses.empty()){
            cout<<"Expenses Empty, Add the Expenses";
             return;
        };
       

        cout<<"All Expenses";
        for(int i=0;i<expenses.size();i++){
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

  // Getter methods for accessing private data


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
           addExpense();
            break;

        case 2:
            viewExpenses();
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