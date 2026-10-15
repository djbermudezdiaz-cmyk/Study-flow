#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Una Task representa una actividad academica.
class Task {
private:
    int id;
    string course;
    string title;
    int priority;       // 1 = LOW, 2 = MEDIUM, 3 = HIGH
    bool completed;

public:
    Task(int taskId, const string& taskCourse,
         const string& taskTitle, int taskPriority)
        : id(taskId), course(taskCourse), title(taskTitle),
          priority(taskPriority), completed(false) {}

    int getId() const { return id; }
    bool isCompleted() const { return completed; }
    void markCompleted() { completed = true; }

    string getPriorityText() const {
        if (priority == 3) return "HIGH";
        if (priority == 2) return "MEDIUM";
        return "LOW";
    }

    void show() const {
        cout << "[" << id << "] " << title << '\n';
        cout << "    Course: " << course
             << " | Priority: " << getPriorityText()
             << " | Status: " << (completed ? "DONE" : "PENDING")
             << "\n";
    }
};

// TaskManager almacena y administra las actividades.
class TaskManager {
private:
    vector<Task> tasks;
    int nextId = 1;

public:
    void addTask(const string& course, const string& title, int priority) {
        tasks.emplace_back(nextId, course, title, priority);
        cout << "Assignment added with ID " << nextId << ".\n";
        ++nextId;
    }

    void showTasks(bool pendingOnly) const {
        bool found = false;
        for (const Task& task : tasks) {
            if (pendingOnly && task.isCompleted()) continue;
            task.show();
            found = true;
        }
        if (!found) {
            cout << (pendingOnly ? "No pending assignments.\n"
                                 : "No assignments registered yet.\n");
        }
    }

    bool completeTask(int id) {
        for (Task& task : tasks) {
            if (task.getId() == id && !task.isCompleted()) {
                task.markCompleted();
                return true;
            }
        }
        return false;
    }
};

// Lee numeros enteros completos y comprueba el rango.
// Devuelve -1 si se cierra la entrada (Ctrl+D).
int readNumber(const string& message, int minimum, int maximum) {
    while (true) {
        cout << message;
        string line;
        if (!getline(cin, line)) return -1;

        istringstream stream(line);
        int number;
        char extra;
        if ((stream >> number) && !(stream >> extra) &&
            number >= minimum && number <= maximum) {
            return number;
        }
        cout << "Invalid number. Try again.\n";
    }
}

// No permite materias ni titulos vacios.
string readRequiredText(const string& message) {
    while (true) {
        cout << message;
        string text;
        if (!getline(cin, text)) return "";
        if (text.find_first_not_of(" \t\r\n") != string::npos) {
            return text;
        }
        cout << "This field cannot be empty.\n";
    }
}

int main() {
    TaskManager manager;

    while (true) {
        cout << "\n===== STUDYFLOW =====\n"
             << "1. Add an assignment\n"
             << "2. View pending assignments\n"
             << "3. View all assignments\n"
             << "4. Mark assignment as completed\n"
             << "0. Exit\n";

        int option = readNumber("Choose an option: ", 0, 4);
        if (option == 0 || option == -1) {
            cout << "Goodbye!\n";
            break;
        }

        switch (option) {
            case 1: {
                string course = readRequiredText("Course name: ");
                if (!cin) break;
                string title = readRequiredText("Assignment title: ");
                if (!cin) break;
                int priority = readNumber(
                    "Priority (1=LOW, 2=MEDIUM, 3=HIGH): ", 1, 3);
                if (priority == -1) break;
                manager.addTask(course, title, priority);
                break;
            }
            case 2:
                manager.showTasks(true);
                break;
            case 3:
                manager.showTasks(false);
                break;
            case 4: {
                int id = readNumber("Assignment ID to complete: ", 1,
                                    numeric_limits<int>::max());
                if (id == -1) break;
                if (manager.completeTask(id)) {
                    cout << "Assignment completed successfully.\n";
                } else {
                    cout << "ID not found or assignment already completed.\n";
                }
                break;
            }
        }

        if (!cin) break;
    }
    return 0;
}
