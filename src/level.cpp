#include <iostream>
#include <fstream>
#include <sstream>

#include "level.h"

using namespace std;

void Level::getTasks() {
  ifstream inputTaskFile("tasks");

  string taskStr;
  struct task task;
  
  int offset = 0;

  // get file offset
  if (trait == "empathy")
    offset = 0;
  if (trait == "cooperation")
    offset = 5;
  if (trait == "communication")
    offset = 10;
  if (trait == "listening")
    offset = 15;
  if (trait == "nonverbal")
    offset = 20;

  // skip lines based on the current task
  for (int i = 0; i < offset; i++)
    getline(inputTaskFile, taskStr);
  
  for (int i = 0; i < 5; i++) {
    getline(inputTaskFile, taskStr);

    task.completed = taskStr[0] == '0' ? 0 : 1;
    taskStr.erase(0, 1);

    task.objective = string(taskStr);
    tasks.push_back(task);
  }

  inputTaskFile.close();
}

void Level::saveTasks() {
  int offset = 0;
  
  // get file offset
  if (trait == "empathy")
    offset = 0;
  if (trait == "cooperation")
    offset = 5;
  if (trait == "communication")
    offset = 10;
  if (trait == "listening")
    offset = 15;
  if (trait == "nonverbal")
    offset = 20;

  ostringstream taskStream;
  ifstream inputTaskFile("tasks");

  taskStream << inputTaskFile.rdbuf();
  inputTaskFile.close(); 

  string taskStr = taskStream.str();

  int i = 0;
  int count = 0;
  while (count < offset) {
    if (taskStr[i] == '\n') {
      count++;
    }
    i++;
  }

  for (auto task : tasks) {
    if (taskStr[i] == '\n') {
      i++;
    }

    // save objective status: ascii offset
    taskStr[i] = task.completed + 48;

    // go to next newline
    while (taskStr[i] != '\n') {
      i++;
    }
  }

  std::cout << taskStr << endl;

  ofstream outputTaskFile("tasks", std::ios::trunc);
  outputTaskFile << taskStr << std::flush;
  outputTaskFile.close();
}

void Level::setStarted() {
  char answer;
  std::cout << "Are you a returning user? Y for yes or N for no" << std::endl;
  std::cin >> answer;
  started = (answer == 'Y') ? 1 : 0;
}

int Level::getLevelProgress() {
  int prog = 0;

  for (int i = 0; i < tasks.size(); i++) {
    if (tasks[i].completed == 1) {
      prog++;
    }
  }

  return prog/tasks.size();
}

std::string Level::getTrait() {
  return trait;
}

int Level::getPriority() {
  return priority;
}

void Level::askTasks() {
  if (started == 0) {
    std::cout << "Tasks to be completed to improve " << trait << std::endl;
    for (int i = 0; i < tasks.size(); i++) {
      std::cout << tasks[i].objective << std::endl;
    }
  }
  else {
    char answer;

    std::cout << "Have you completed the following tasks? Type Y for yes or N for no." << std::endl;
    for (int i = 0; i < tasks.size(); i++) {
      std::cout << tasks[i].objective << std::endl;
      std::cin >> answer;
      tasks[i].completed = (answer == 'Y') ? 1 : 0;
    }
  }
}


