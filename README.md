#C++ To-Do List Manager

A simple console-based To-Do List Manager written in C++ that allows users to manage daily tasks.

This project demonstrates the use of:
       ->Structures
       -> Arrays
       ->File Handling
       ->Functions

🚀 Features

✔ Add new tasks
✔ View all tasks
✔ Mark tasks as completed
✔ Delete tasks
✔ Save tasks to a file
✔ Load tasks automatically when the program starts
✔ Store task description, due date, and time interval

📂 Project Structure
todo-list-manager/
│
├── main.cpp        # Main source code
├── tasks.txt       # File where tasks are stored
└── README.md       # Project documentation


Each task is stored using a C++ structure:

struct Task {
    int id;
    string description;
    string dueDate;
    string timeinterval;
    bool isCompleted;
};

🛠️ Functions Used

     Function  |	 Description
displayMenu()  |	Displays the main menu
addTask()      |	  Adds a new task
viewTasks()    |	Displays all tasks
markTaskCompleted()  |	Marks a task as completed
deleteTask()   |  	Deletes a task
saveToFile()   |   Saves tasks to tasks.txt
loadFromFile() |	Loads tasks from tasks.txt

💾 File Storage

Tasks are saved in tasks.txt using file handling:


⚙️ How to Compile and Run
1️. Compile
Using g++

g++ main.cpp -o todo
2️. Run
./todo

 Objectives:
 Learning fundamentals of programming.
C++ Structures
Arrays
File handling (ifstream, ofstream)
Modular programming using functions



👨‍💻 Author
Developed by Eyosias

If you like this project, feel free to ⭐ star the repository.
