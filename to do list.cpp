#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

// Function prototypes
void addTask(vector<Task> &tasks);
void viewTasks(const vector<Task> &tasks);
void markCompleted(vector<Task> &tasks);
void removeTask(vector<Task> &tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n====== To-Do List Manager ======\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore newline after number input

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the To-Do List Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new task
void addTask(vector<Task> &tasks) {
    string desc;
    cout << "Enter the task description: ";
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added successfully.\n";
}

// Function to view all tasks
void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "No tasks found.\n";
        return;
    }

    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].completed ? "✔" : " ") << "] "
             << tasks[i].description << "\n";
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);

    if (tasks.empty()) return;

    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed.\n";
    }
    cin.ignore(); // clear newline
}

// Function to remove a task
void removeTask(vector<Task> &tasks) {
    int index;
    viewTasks(tasks);

    if (tasks.empty()) return;

    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully.\n";
    }
    cin.ignore(); // clear newline
}
