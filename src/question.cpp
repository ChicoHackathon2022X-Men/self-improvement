#include <iostream>

#include "question.h"

using namespace std;

string to_string(QuestionType type) {
  switch (type) {
  case EMPATHY:
    return "empathy";
  case COOPERATION:
    return "cooperation";
  case COMMUNICATION:
    return "communication";
  case LISTENING:
    return "listening";
  case NONVERBAL:
    return "nonverbal";
  };
}

Question::Question(string question, QuestionType qtype) {
  this->question = question;
  this->qtype = qtype;
}

double Question::prompt() {
  cout << "\n\033[1m" << question << "\033[0m [" << to_string(qtype) << "]\n";

  int value = 1;
  do {
    if (cin.fail() || value > 5 || value < 1) {
      cout << "\nInput must be an integer between 1 and 5. Try again.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "[1,2,3,4,5]: ";
    cin >> value;
  } while (cin.fail() || value > 5 || value < 1);

  return (double)value;
}

QuestionType Question::get_type() { return qtype; }
