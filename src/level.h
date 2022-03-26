#ifndef LEVEL_H
#define LEVEL_H

#include <iostream>
#include <string>
#include <vector>

#define NUM_TASKS 5

//extern Task_struct task;
//static Task_struct task;

class Level

{
  private:
    struct task {
      bool completed;
      std::string objective;
    };
    //std::vector<task> tasks(5);
    std::string trait;
    int priority;
    bool started;

  public:
    // Constructors
    Level() {}
    Level(std::string trait)
      : trait(trait) {}
    Level(std::string trait, int priority)
      : trait(trait), priority(priority) {}
    Level(std::string trait, int priority, bool started)
      : trait(trait), priority(priority), started(started) {}

    // Setters
    void getTasks(); // read tasks from file
    void saveTasks(); // save tasks to file
    void setStarted(); // determine if user started or not
    void askTasks(); // to be invoked in main
    // Getters
    int getLevelProgress(); // returns number of tasks completed
    std::string getTrait(); // returns trait
    int getPriority(); // returns level priority

  private:
    std::vector<task> tasks;
};

#endif
