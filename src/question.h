#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>

enum QuestionType {
    EMPATHY = 1,
    COOPERATION = 2,
    COMMUNICATION = 3,
    LISTENING = 4,
    NONVERBAL = 5
};

class Question {
    private:
        std::string question;
        QuestionType qtype;
    //     double value; // value 1 to 5 representing user choice
    
    public:
        Question(std::string question, QuestionType qtype);

        // prompts user for question, returns result
        double prompt();
        QuestionType get_type();        
};

std::string to_string(QuestionType type);

#endif