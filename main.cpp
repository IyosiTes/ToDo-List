#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Task {
    int id;
    string description;
    string dueDate;
	string timeinterval;
	bool isCompleted;
};

void displayMenu();
void addTask(Task tasks[], int &taskCount);
void viewTasks(Task tasks[], int taskCount);
void markTaskCompleted(Task tasks[], int taskCount);
void deleteTask(Task tasks[], int &taskCount);
void saveToFile(Task tasks[], int taskCount);
void loadFromFile(Task tasks[], int &taskCount);
int searchTask(Task tasks[], int taskCount, string searchDesc);


const int MAX_TASKS = 100;

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;
    
    loadFromFile(tasks, taskCount);
    
    
    do {
        displayMenu();
        cout << "Enter your choice: ";
      cin >> choice; 
     cin.ignore();  
        
        switch(choice) {
            case 1:
                addTask(tasks, taskCount);
                break;
            case 2:
                viewTasks(tasks, taskCount);
                break;
            case 3:
                markTaskCompleted(tasks, taskCount);
                break;
            case 4:
                deleteTask(tasks, taskCount);
                break;
            case 5:
                saveToFile(tasks, taskCount);
                break;
            
            case 6:
                cout << "Exiting program...\n";
                
                saveToFile(tasks, taskCount);
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
        cout << "\nPress Enter to continue...";
        cin.get();
        
    } while(choice != 6);
    
    return 0;
}

void displayMenu() {
    
    cout << "--------------------------------\n";
    cout << "        TO-DO LIST MANAGER       \n";
    cout << "=================================\n";
    cout << "1. Add New Task\n";
    cout << "2. View All Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Delete Task\n";
    cout << "5. Save Tasks to File\n";
    cout << "6. Exit\n";
    cout << "=================================\n";
}

void addTask(Task tasks[], int &taskCount) {
    if(taskCount >= MAX_TASKS) {
        cout << "Task list is full! Cannot add more tasks.\n";
        return;
    }
    
    Task newTask;
    newTask.id = taskCount + 1;
    
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    
    cout << "Enter due date (DD/MM/YYYY):";
    getline(cin, newTask.dueDate);
    cout << "Enter time interval to task :";
     getline(cin, newTask.timeinterval);
   
    newTask.isCompleted = false;
    
    tasks[taskCount] = newTask;
    taskCount++;
    
    cout << "Task added successfully! Task ID: " << newTask.id << "\n";
}

void viewTasks(Task tasks[], int taskCount) {
    if(taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }
    
    cout << "\n=====================================================\n";
    cout << "                           TASKS                     \n";
    cout << "=======================================================\n";
    cout << "ID\tStatus\tDue Date\ttime interval\tDescription\n";
    cout << "-------------------------------------------------------\n";
    
    for(int i = 0; i < taskCount; i++) {
        cout << tasks[i].id << "\t";
        cout << (tasks[i].isCompleted ? "[yes]" : "[no]") << "\t";
        cout << tasks[i].dueDate << "\t";
        cout << tasks[i].timeinterval << "\t";
         cout << tasks[i].description << "\n";
        
    }
    cout << "======================================================\n";
    cout << "Total tasks: " << taskCount << "\n";
}

void markTaskCompleted(Task tasks[], int taskCount) {

if(taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }
    
    viewTasks(tasks, taskCount);
    int taskId;
    
    cout << "Enter Task ID to mark as completed: ";
    cin >> taskId;
    
    if(taskId < 1 || taskId > taskCount) {
        cout << "Invalid Task ID!\n";
        return;
    }
    
    tasks[taskId - 1].isCompleted = true;
    cout << "Task ID " << taskId << " marked as completed!\n";
}

void deleteTask(Task tasks[], int &taskCount) {
    if(taskCount == 0) {
        cout << "No tasks available.\n";
        return;
    }
    
    viewTasks(tasks, taskCount);
    int taskId;
    
    cout << "Enter Task ID to delete: ";
    cin >> taskId;
    
    if(taskId < 1 || taskId > taskCount) {
        cout << "Invalid Task ID!\n";
        return;
    }
    
    
    for(int i = taskId - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
        tasks[i].id = i + 1; 
    }
    
    taskCount--;
    cout << "Task deleted successfully!\n";
}

void saveToFile(Task tasks[], int taskCount) {
    ofstream outFile("tasks.txt");
    
    if(!outFile) {
        cout << "Error opening file for writing!\n";
        return;
    }
    
    for(int i = 0; i < taskCount; i++) {
        outFile << tasks[i].id << endl;
        outFile << tasks[i].description << endl;
        outFile << tasks[i].isCompleted << endl;
        outFile << tasks[i].dueDate << endl;
          outFile << tasks[i].timeinterval << endl;
    }
    
    outFile.close();
    cout << "Tasks saved to file successfully!\n";
}

void loadFromFile(Task tasks[], int &taskCount) {
    ifstream inFile("tasks.txt");
    
    if(!inFile) {
        cout << "No saved tasks found. Starting fresh...\n";
        return;
    }
    
    taskCount = 0;
    while(taskCount < MAX_TASKS && inFile >> tasks[taskCount].id) {
        inFile.ignore(); 
        getline(inFile, tasks[taskCount].description);
        inFile >> tasks[taskCount].isCompleted;
        inFile.ignore();
        getline(inFile, tasks[taskCount].dueDate);
        getline(inFile, tasks[taskCount].timeinterval);
        taskCount++;
    }
    
    inFile.close();
    cout << taskCount << " tasks loaded from file.\n";
}

