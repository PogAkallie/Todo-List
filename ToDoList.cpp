
#include <iostream>
#include <string>
#include <list>
using namespace std;

class ToDoItem {
private:
    int id ;
    string descr;
    bool completed;

    static int nextId;

public:
    ToDoItem(): id(0), descr(""), completed(false) {}
    ~ToDoItem() = default;

    bool create(string newDescription) {
        id = nextId++; 
        descr = newDescription;
        return true;
    }

    int getId() {
        return id;
    }

    string getDescription() {
        return descr;
    }

    bool isCompleted(){
        return completed;
    }

    void setCompleted(bool value)
    {
        completed = value;
    }
};

int ToDoItem::nextId = 1;

int main()
{
    char inputOption;
    int inputId;
    string inputDescription;
    string version = "v0.2.0";
    list<ToDoItem> toDoItems;
    list<ToDoItem>::iterator it;

    toDoItems.clear();

    while (1) {
        system("cls");
        cout << "To Do List makes - " << version << std::endl;
        cout << endl << endl;

        for (it = toDoItems.begin(); it != toDoItems.end(); it++) {

             
            string completed = it->isCompleted() ? "done" : "not done";

            cout << it->getId() << " | " << it->getDescription() << " | "
                << completed << endl;
        }
        if (toDoItems.empty()) {
            cout << "Add your first Todo!" << endl;
        }

        cout << endl << endl; 

        cout << "[a]dd a new Todo" << endl;
        cout << "[c]omplete a Todo" << endl;
        cout << "[q]uit" << endl;

        cout << "choice: ";

        cin >> inputOption; 
        if (inputOption == 'q') {
            cout << "Bye bye~!" << endl;
            break;
        }
        else if (inputOption == 'a') {
            cout << "Add a new description: ";
            cin.clear();
            cin.ignore();
            std::getline(cin, inputDescription);

            ToDoItem newIteam;
            newIteam.create(inputDescription);
            toDoItems.push_back(newIteam);
        }
        else if (inputOption == 'c') {
            cout << "Enter id to mark completed: " << endl;
            cin >> inputId;

            for (it = toDoItems.begin(); it != toDoItems.end(); it++) {
                if (inputId == it->getId()) {
                    it->setCompleted(true);
                    break;
                }
            }
        }

      
    }
    return 0;
}
