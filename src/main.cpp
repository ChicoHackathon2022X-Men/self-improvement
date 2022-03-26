#include <vector>
#include <map>

#include "question.h"
#include "quiz.h"
#include "level.h"

using namespace std;

int main() {
    Level empathy;

    empathy.getTasks();
    empathy.askTasks();
    empathy.saveTasks();
}
