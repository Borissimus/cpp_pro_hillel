#include "task_controller.h"
#include <iostream>

void TaskController::addTask() {
    std::string title = view.getInput("Enter task title: ");
    std::string description = view.getInput("Enter task description: ");
    int priority = view.getIntegerInput("Enter task priority (1-5): ");
	// Easily could be modified
    auto deadline = std::chrono::system_clock::now();
    // Add a new task to the model
    model.addTask(Task(title, description, priority, deadline));
    std::cout << "Task added successfully!" << std::endl;
}

void TaskController::showTasks() {
    auto tasks = model.getTasks();
    view.displayTasks(tasks);
}

void TaskController::showFilteredTasks() {
    int choice = view.getIntegerInput("Enter filtering criteria (1 - by priority, 2 - by status): ");
    
    switch (choice) {
        case 1: {
            int priority = view.getIntegerInput("Enter priority to filter by: ");
            auto filteredTasks = model.filterTasks([priority](const Task& task) {
                return task.getPriority() == priority;
            });
            view.displayTasks(filteredTasks);
            break;
        }
        case 2: {
            int statusInput = view.getIntegerInput("Enter status to filter by (0 - not done, 1 - done): ");
            bool isDone = (statusInput == 1); // Convert input to bool

            auto filteredTasks2 = model.filterTasks([isDone](const Task& task) {
                return task.isDone() == isDone;
            });
            view.displayTasks(filteredTasks2);
            break;
        }
        default:
            std::cout << "Invalid choice." << std::endl;
            break;
    }
}

void TaskController::sortTasks() {
	int choice = view.getIntegerInput("Enter sorting criteria (1 - by priority, 2 - by deadline): ");
	switch (choice) {
		case 1:
			model.sortTasks([](const Task& t1, const Task& t2) {
				return t1.getPriority() < t2.getPriority();
			});
			std::cout << "Tasks sorted by priority." << std::endl;
			break;
		case 2:
			model.sortTasks([](const Task& t1, const Task& t2) {
				return t1.getDeadline() < t2.getDeadline();
			});
			std::cout << "Tasks sorted by deadline." << std::endl;
			break;
		default:
			std::cout << "Invalid choice." << std::endl;
			break;
	}
}

void TaskController::editTask() {
    int taskIndex = view.getIntegerInput("Enter the index of the task to edit (0-based index): ");
    
    auto& tasks = model.getTasks();
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        std::string newTitle = view.getInput("Enter new task title: ");
        std::string newDescription = view.getInput("Enter new task description: ");
        int newPriority = view.getIntegerInput("Enter new task priority (1-5): ");
        
        // Update the task
        Task& task = tasks[taskIndex];
        task.setTitle(newTitle);
        task.setDescription(newDescription);
        task.setPriority(newPriority);
        
        std::cout << "Task updated successfully!" << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void TaskController::deleteTask() {
    int taskIndex = view.getIntegerInput("Enter the index of the task to delete (0-based index): ");
    
    auto tasks = model.getTasks(); // get reference to task vector
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex); // Remove the task from the vector
        std::cout << "Task deleted successfully!" << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}

void TaskController::markTaskAsDone() {
    int taskIndex = view.getIntegerInput("Enter the index of the task to mark as done (0-based index): ");
    
    auto tasks = model.getTasks();
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        Task& task = tasks[taskIndex];
        task.markAsDone(); // Assuming this method is defined in Task
        std::cout << "Task marked as done." << std::endl;
    } else {
        std::cout << "Invalid task index." << std::endl;
    }
}
