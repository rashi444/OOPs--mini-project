#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string fileName = "todo.txt";

void displayTasks() {
    ifstream inFile(fileName);
    string task;

    cout << "ToDo List\n";
    cout << "----tasks----\n";

    while (getline(inFile, task)) {
        cout << task << endl;
    }

    inFile.close();
}

void addTask(const string& description) {
    ofstream outFile(fileName, ios::app);

    if (!outFile) {
        cerr << "Error opening file for writing.\n";
        return;
    }

    outFile << " * " << description << endl;

    cout << "Task added successfully.\n";

    outFile.close();
}

int main() {
    int choice;
    string taskDescription;

    while (true) {
        cout << "\nToDo List Manager\n";
        cout << "1. Display Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayTasks();
                break;
            case 2:
                cout << "Enter task description: ";
                cin.ignore(); // 
                getline(cin, taskDescription);
                addTask(taskDescription);
                break;
            case 3:
                cout << "Exiting the program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
