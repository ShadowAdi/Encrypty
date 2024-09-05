#include "ProcessManagement.hpp"
#include <iostream>
#include <string>
#include <cstring>
// #include <sys/wait.h>
#include "../encryptDecrypt/Cryption.hpp"

ProcessManagement::ProcessManagement() {};
bool ProcessManagement::submitToQueue(std::unique_ptr<Task> task)
{
    taskQueue.push(std::move(task));
    return true;
}

void ProcessManagement::executeTasks()
{
    while (!taskQueue.empty())
    {
        std::unique_ptr<Task> taskToExecute = std::move(taskQueue.front());
        taskQueue.pop();
        cout << "Executing Task: " << taskToExecute->toString() << std::endl;
        executeCryption(taskToExecute->toString());
    }
}