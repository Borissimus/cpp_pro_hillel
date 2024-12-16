#ifndef TASK_CONTROLLER_H
#define TASK_CONTROLLER_H

#include "task_manager.h"
#include "task_view.h"

// Class to manage interaction between the Model and View
class TaskController {
public:
    TaskController(TaskManager& model, TaskView& view) 
        : model(model), view(view) {}

    void addTask();
    void showTasks();
	void showFilteredTasks();
	void sortTasks();
    void editTask();
    void deleteTask();
    void markTaskAsDone();

private:
    TaskManager& model; // Reference to the TaskManager
    TaskView& view;     // Reference to the TaskView
};

#endif // TASK_CONTROLLER_H