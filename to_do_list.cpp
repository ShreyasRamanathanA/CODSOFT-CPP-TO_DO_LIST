#include <iostream>
#include <string>
#include <map>
#include <limits> 
using namespace std;

struct Task {
    bool completed;
    string description;
};

map<string, Task> tasks;

void add_task(string task_name, string task_description) {
    tasks[task_name] = {false, task_description};
    cout << "Task '" << task_name << "' added with description: " << task_description << endl;
}

void complete_task(string task_name) {
    if (tasks.find(task_name) != tasks.end()) {
        tasks[task_name].completed = true;
        cout << "Task '" << task_name << "' completed." << endl;
    } else {
        cout << "Task '" << task_name << "' not found." << endl;
    }
}

void delete_task(string task_name) {
    if (tasks.find(task_name) != tasks.end()) {
        tasks.erase(task_name);
        cout << "Task '" << task_name << "' deleted." << endl;
    } else {
        cout << "Task '" << task_name << "' not found." << endl;
    }
}

void list_tasks() {
    cout << "\nTo-Do List:" << endl;
    for (auto const& task : tasks) {
        string status = task.second.completed ? "Completed" : "Not Completed";
        cout << "-- " << task.first << " (" << status << ")" << endl;
        cout << "  Description: " << task.second.description << endl;
    }
}

int main() {
    while (true) {
        cout << "\nTo-Do List Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Complete Task" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. List Tasks" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "\nEnter your choice (1/2/3/4/5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining characters in the input buffer
            cout << "\nInvalid input. Please enter a valid choice!" << endl;
            continue;
        }

        if (choice < 1 || choice > 5) {
            cout << "\nPlease enter a valid choice!" << endl;
            continue;
        }

        string task_name, task_description;

        switch (choice) {
            case 1:
                cout << "\nEnter task name: ";
                cin >> task_name;
                cout << "Enter task description: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, task_description);
                add_task(task_name, task_description);
                break;
            case 2:
                cout << "\nEnter task name: ";
                cin >> task_name;
                complete_task(task_name);
                break;
            case 3:
                cout << "\nEnter task name: ";
                cin >> task_name;
                delete_task(task_name);
                break;
            case 4:
                list_tasks();
                break;
            case 5:
                cout << "\nExiting To-Do List Application...\n" << endl;
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n" << endl;
                break;
        }
    }

    return 0;
}
