#ifndef TASK_VIEW_H
#define TASK_VIEW_H

#include <iostream>
#include <vector>
#include "task_manager.h"

// Class for interacting with the user through the console
class TaskView {
public:
	// Display the list of tasks on the screen
	void displayTasks(const std::vector<Task>& tasks);

	// Get general input from the user
	std::string getInput(const std::string& prompt);

	// Get numerical input from the user
	int getIntegerInput(const std::string& prompt);
};

#endif // TASK_VIEW_H