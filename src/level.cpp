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

	tasks[5].objective = "Learn someone’s name";
	tasks[6].objective = "Ask someone for their input";
	tasks[7].objective = "Tell someone that they did a good job";
	tasks[8].objective = "Ask someone to spend time with you";
	tasks[9].objective = "Solve a problem with another person";
  }
  if (trait == "communication") {

	tasks[10].objective = "Tell a joke that makes someone smile";
	tasks[11].objective = "Talk for 30 seconds without using filler words";
	tasks[12].objective = "Send an email to teacher/boss/etc";
	tasks[13].objective = "Read an information text";
	tasks[14].objective = "Speak to a group of 5+";
  }
  if (trait == "listening") {

	tasks[15].objective = "Let someone speak for 20 second without interrupting";
	tasks[16].objective = "Maintain eye contact for 5 seconds";
	tasks[17].objective = "Ask a question";
	tasks[18].objective = "Nod while someone’s talking";
	tasks[19].objective = "Understand what someone is explaining";
  }
  if (trait == "nonverbal") {

	tasks[20].objective = "Shake someone’s hand firmly";
	tasks[21].objective = "Have a conversation with uncrossed arms";
	tasks[22].objective = "Use your hands while explaining something";
	tasks[23].objective = "Smile at a stranger";
	tasks[24].objective = "Have a conversation standing ~3 feet away from someone";
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


