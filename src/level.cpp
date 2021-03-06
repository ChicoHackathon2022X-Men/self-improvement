#include <iostream>
#include <fstream>
#include <sstream>

#include "level.h"
#include "question.h"

using namespace std;

int get_offset(QuestionType trait) {
  int offset = 0;

  // get file offset
  if (trait == EMPATHY)
    offset = 2;
  if (trait == COOPERATION)
    offset = 7;
  if (trait == COMMUNICATION)
    offset = 12;
  if (trait == LISTENING)
    offset = 17;
  if (trait == NONVERBAL)
    offset = 22;
  
  return offset;
}

Level::~Level() {
  saveTasks();
}

void Level::getTasks() {
  ifstream inputTaskFile("tasks");

  string taskStr;
  struct task task;
  
  int offset = get_offset(trait);

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
  // get file offset
  int offset = get_offset(trait);

  ostringstream taskStream;
  ifstream inputTaskFile("tasks");

  taskStream << inputTaskFile.rdbuf();
  inputTaskFile.close(); 

  string taskStr = taskStream.str();
  taskStr[0] = '1';

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

  return prog;
}

QuestionType Level::getTrait() {
  return trait;
}

int Level::getPriority() {
  return priority;
}

void Level::askTasks() {
  string answer;

  std::cout << "Have you completed the following tasks? Type Y for yes or N for no." << std::endl;
  for (int i = 0; i < tasks.size(); i++) {
    if (!tasks[i].completed) {
      while (answer != "Y" && answer != "N") {
        std::cout << " - " << tasks[i].objective << " : ";
        std::cin >> answer;
        tasks[i].completed = (answer == "Y") ? 1 : 0;
      }
      answer = 'J';
    }
  }
}

// void Level::displayTasks() {
//   std::cout << "Here are the tasks you need to work on next.\n";

//   for (auto task : tasks) {
//     std::cout << " - " << task.objective << "\n";
//   }
// }