#include <vector>
#include <map>

#include "question.h"
#include "quiz.h"

using namespace std;

int main() {
    Quiz quiz;

    quiz.insert_question("Question 1?", EMPATHY);
    quiz.insert_question("Question 2?", COOPORATION);
    quiz.insert_question("Question 3?", COMMUNICATION);
    quiz.insert_question("Question 4?", LISTENING);
    quiz.insert_question("Question 5?", NONVERBAL);

    auto order = quiz.start_quiz();

    cout << "Order:\n";
    int i = 1;
    for (auto item : order) {
        cout << i << ". " << to_string(item) << endl;
        i++;
    }
}
