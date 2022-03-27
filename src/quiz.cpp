#include <map>
#include <vector>
#include <algorithm>
#include <random>


#include "question.h"
#include "quiz.h"

using namespace std;

Quiz::Quiz() {}

void Quiz::insert_question(string question, QuestionType category) {
    this->questions.push_back(Question(question, category));
}

void Quiz::scramble() {
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(questions), std::end(questions), rng);
}

vector<QuestionType> Quiz::start_quiz() {
    map<QuestionType, double> averages;
    map<QuestionType, double> counts;


    for (auto question : questions) {
        auto type = question.get_type();

        counts[type]++;
        averages[type] += question.prompt();
    }

    averages[EMPATHY] /= counts[EMPATHY];
    averages[COOPERATION] /= counts[COOPERATION];
    averages[COMMUNICATION] /= counts[COMMUNICATION];
    averages[LISTENING] /= counts[LISTENING];
    averages[NONVERBAL] /= counts[NONVERBAL];

    cout << endl;

    multimap<double, QuestionType> new_map;

    for (auto category : averages) {
        new_map.insert({ category.second, category.first });
    }

    vector<QuestionType> question_order;

    for (auto it = new_map.rbegin(); it != new_map.rend(); it++) {
        question_order.push_back(it->second);
    }

    return question_order;
}