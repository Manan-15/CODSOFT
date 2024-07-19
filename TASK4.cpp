#include <iostream>
#include <vector>
using namespace std;

/*TO-DO LIST*/

struct task
{
    string description;
    bool completed;

    task(string desc)
    {
        description = desc;
        completed = false;
    }
};

class ToDoList
{
private:
    vector<task> tasks;

public:
    void addTask(string desc)
    {
        tasks.push_back(task(desc));
        cout << "task added successfully " << endl;
    }

    void viewTask()
    {
        if (tasks.empty())
        {
            cout << "To-Do List is empty " << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); i++)
        {
            cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << " " << endl;
        }
    }

    void markComplete(int taskNo)
    {
        if (!tasks.empty() && taskNo >= 1 && taskNo <= tasks.size())
        {
            tasks[taskNo - 1].completed = true;
            cout << "task has been marked as completed " << endl;
        }
        else
        {
            cout << "invalid Task No. " << endl;
        }
    }

    void removeTask(int taskNo)
    {
        if (!tasks.empty() && taskNo >= 1 && taskNo <= tasks.size())
        {
            tasks.erase(tasks.begin() + taskNo - 1);
            cout << "task has been removed " << endl;
        }
        else
        {
            cout << "invalid Task No. " << endl;
        }
    }
};

int main()
{
    ToDoList T1;
    int choice;
    string description;
    int taskNo;
    cout << "choose what operation to preform " << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Mark task as completed" << endl;

    while (true)
    {
        cout << endl
             << "enter your choice: " << endl;
        cin >> choice;

        if (choice == 1)
        {
            cout << "enter task description " << endl;
            cin >> description;
            T1.addTask(description);
        }
        else if (choice == 2)
        {
            T1.viewTask();
        }
        else if (choice == 3)
        {
            cout << "enter task no. to be removed " << endl;
            cin >> taskNo;
            T1.removeTask(taskNo);
        }
        else if (choice == 4)
        {
            cout << "enter task no. to be marked as complete " << endl;
            cin >> taskNo;
            T1.markComplete(taskNo);
        }
        else
        {
            cout << "invalid operation " << endl;
        }
    }
    return 0;
}