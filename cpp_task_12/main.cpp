#include "task_manager.h"
#include "task_view.h"
#include "task_controller.h"
#include <iostream>

int main() {
	// Create instances of TaskManager, TaskView, and TaskController
    TaskManager model;     // This is the class that manages tasks
    TaskView view;         // This is the class that handles user interaction
    TaskController controller(model, view); // Connects model and view
	bool exit = false;

    // User interaction loop
    while (!exit) {
        std::cout << "\n1. Add Task"
                  << "\n2. Show Tasks"
				  << "\n3. Show Filtered Tasks"
				  << "\n4. Sort Tasks"
                  << "\n5. Edit Task"
                  << "\n6. Delete Task"
                  << "\n7. Mark Task as Done"
                  << "\n8. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

        switch (choice) {
            case 1:
                controller.addTask(); // Add a new task
                break;
            case 2:
                controller.showTasks(); // Show all tasks
                break;
			case 3:
				controller.showFilteredTasks(); // Show filtered tasks
				break;
			case 4:
				controller.sortTasks(); // Sort tasks
				break;
            case 5:
                controller.editTask(); // Edit an existing task
                break;
            case 6:
                controller.deleteTask(); // Delete a task
                break;
            case 7:
                controller.markTaskAsDone(); // Mark task as done
                break;
            case 8:
                std::cout << "Exiting the program." << std::endl;
                exit = true; // Exit the program
				break;
            default:
                std::cout << "Invalid choice! Please select a valid option." << std::endl;
                break;
        }
    }

    return 0; // Exit the program
}
