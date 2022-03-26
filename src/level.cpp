#include "level.h"

void Level::setTasks() {
  for (int i = 0; i < NUM_TASKS; i++) {
    task t;
    tasks.push_back(t);
  }

  if (trait == "empathy") {
    tasks[0].objective = "Ask someone how they feel.";
    tasks[1].objective = "Notice someone feeling anxious.";
    tasks[2].objective = "Notice someone feeling annoyed.";
    tasks[3].objective = "Encourage someone struggling.";
    tasks[4].objective = "Stand up for someone.";
  }
  if (trait == "cooperation") {
  }
  if (trait == "communication") {
  }
  if (trait == "listening") {
  }
  if (trait == "nonverbal") {
  }
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


