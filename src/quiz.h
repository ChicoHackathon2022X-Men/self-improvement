#ifndef QUIZ_H
#define QUIZ_H

#include <vector>
#include "question.h"

class Quiz {
    private:
        std::vector<Question> questions;
    
    public:
        Quiz();
        void scramble();
        void insert_question(std::string question, QuestionType category);
        std::vector<QuestionType> start_quiz();
};

#endif