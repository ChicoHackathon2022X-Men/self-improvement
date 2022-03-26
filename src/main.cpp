using namespace std;
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "level.h"
#include "quiz.h"

void introduction(){
	string name;
	
	cout<<"Hello!"<<endl;
	cout<<"Today we will be developing your workplace skills, including:"<<endl;
	cout<<"empathy, cooperation, verbal & written communication, listening, and nonverbal communication."<<endl;
	cout<<"When ready enter your name: ";
	cin>>name;
}

void makeQuestions(Quiz &quizObj){
	//empathy questions
	quizObj.insert_question("How likely are you to stand up for someone else?", EMPATHY);
	quizObj.insert_question("How likely are you to encourage someone you see struggling?", EMPATHY);
	quizObj.insert_question("How aware are you of other's non-verbal signals?", EMPATHY);
	quizObj.insert_question("How likely are you to report something you view as morally wrong?", EMPATHY);
	quizObj.insert_question("How often do you feel what are other people are feeling?", EMPATHY);
	quizObj.insert_question("How often do people tend to tell you their problems?", EMPATHY);
	
	//cooperation questions
	quizObj.insert_question("How likely are you to help someone?", COOPERATION);
	quizObj.insert_question("How likely are you to ask for help?", COOPERATION);
	quizObj.insert_question("Do you work well in a team setting?", COOPERATION);
	quizObj.insert_question("Do you feel approachable?", COOPERATION);
	quizObj.insert_question("How good are you at setting reachable goals?", COOPERATION);
	quizObj.insert_question("How likely are you to ask someone quiet for their opinion?", COOPERATION);
	
	//communication questions
	quizObj.insert_question("How often do you talk to others in person?", COMMUNICATION);
	quizObj.insert_question("How often do you message people online?", COMMUNICATION);
	quizObj.insert_question("How comfortable do you feel speaking in public?", COMMUNICATION);
	quizObj.insert_question("How often do you use different tones while speaking?", COMMUNICATION);
	quizObj.insert_question("Are you concise while speaking?", COMMUNICATION);
	quizObj.insert_question("How likely are you attend social events / team building activities?", COMMUNICATION);
	
	
	//listening questions
	quizObj.insert_question("Are you good at listening?", LISTENING);
	quizObj.insert_question("Do you make eye contact while talking to people?", LISTENING);
	quizObj.insert_question("Do you ask meaningful questions while listening to someone?", LISTENING);
	quizObj.insert_question("How often do you make someone else's problems about yourself?", LISTENING);
	quizObj.insert_question("Do you often judge people while listening to them?", LISTENING);
	quizObj.insert_question("How aware are you of other's non-verbal signals?", LISTENING);
	
	//nonverbal questions
	quizObj.insert_question("How often do you smile?", NONVERBAL);
	quizObj.insert_question("How often do you use your hands in conversation?", NONVERBAL);
	quizObj.insert_question("How often do you make facial expressions in conversion?", NONVERBAL);
	quizObj.insert_question("How often do you make conversation with strangers?", NONVERBAL);
	quizObj.insert_question("Do you take care of your appearance?", NONVERBAL);
}

void runTraining(vector<QuestionType> order){
    //at each index, show tasks
    
	for(auto questionType : order){
        Level questionTypeLevel(questionType);
        questionTypeLevel.getTasks();

        if(questionTypeLevel.getLevelProgress() != 5) {
            questionTypeLevel.askTasks();

            int progress = questionTypeLevel.getLevelProgress();
            if (progress == 5) {
                cout << "Congragulations you just mastered the skill of " << to_string(questionType) << "!!!" << endl;
            } else {
                cout << "You still have " << 5 - progress << " tasks left." << endl;
            }
            break;
        }
    }
}

vector<QuestionType> getOrder() {
    Quiz quiz;
    ifstream taskFile("tasks");
    string line;
    getline(taskFile, line);
    taskFile.close();

    vector<QuestionType> order;

    if (line[0] != '1') {
        introduction();

        Quiz quizObj;
        makeQuestions(quizObj);

        order = quizObj.start_quiz();

        ostringstream taskStream;
        ifstream inputTaskFile("tasks");

        taskStream << inputTaskFile.rdbuf();
        inputTaskFile.close(); 
        string taskStr = taskStream.str();

        for (int i = 0; i < 4; i ++) {
            taskStr[i*2 + 2] = 48 + order[i];
        }

        ofstream outputTaskFile("tasks", std::ios::trunc);
        outputTaskFile << taskStr << std::flush;
        outputTaskFile.close();
    } else {
        ifstream taskFile("tasks");

        getline(taskFile,line);
        getline(taskFile,line);

        for (int i = 0; i < 5; i++) {
            // cout << line[i*2]-48 << endl;
            QuestionType value = (QuestionType) (line[i*2] - 48);
            order.push_back(value);
        }

        taskFile.close();

        cout << "Welcome back!" << endl;
    }

    return order;
}

int main(){
	auto order = getOrder();

	//access quizObj vector
	runTraining(order);
}
