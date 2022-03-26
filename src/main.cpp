using namespace std;
#include <iostream>
#include <vector>
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

void makeQuestions(Quiz* quizObj){
	//empathy questions
	quizObj->insert_question("How likely are you to stand up for someone else?", EMPATHY);
	quizObj->insert_question("How likely are you to encourage someone you see struggling?", EMPATHY);
	quizObj->insert_question("How aware are you of other's non-verbal signals?", EMPATHY);
	quizObj->insert_question("How likely are you to report something you view as morally wrong?", EMPATHY);
	quizObj->insert_question("How often do you feel what are other people are feeling?", EMPATHY);
	quizObj->insert_question("How often do people tend to tell you their problems?", EMPATHY);
	
	//cooperation questions
	quizObj->insert_question("How likely are you to help someone?", COOPERATION);
	quizObj->insert_question("How likely are you to ask for help?", COOPERATION);
	quizObj->insert_question("Do you work well in a team setting?", COOPERATION);
	quizObj->insert_question("Do you feel approachable?", COOPERATION);
	quizObj->insert_question("How good are you at setting reachable goals?", COOPERATION);
	quizObj->insert_question("How likely are you to ask someone quiet for their opinion?", COOPERATION);
	
	//communication questions
	quizObj->insert_question("How often do you talk to others in person?", COMMUNICATION);
	quizObj->insert_question("How often do you message people online?", COMMUNICATION);
	quizObj->insert_question("How comfortable do you feel speaking in public?", COMMUNICATION);
	quizObj->insert_question("How often do you use different tones while speaking?", COMMUNICATION);
	quizObj->insert_question("Are you concise while speaking?", COMMUNICATION);
	quizObj->insert_question("How likely are you attend social events / team building activities?", COMMUNICATION);
	
	
	//listening questions
	quizObj->insert_question("Are you good at listening?", LISTENING);
	quizObj->insert_question("Do you make eye contact while talking to people?", LISTENING);
	quizObj->insert_question("Do you ask meaningful questions while listening to someone?", LISTENING);
	quizObj->insert_question("How often do you make someone else's problems about yourself?", LISTENING);
	quizObj->insert_question("Do you often judge people while listening to them?", LISTENING);
	quizObj->insert_question("How aware are you of other's non-verbal signals?", LISTENING);
	
	//nonverbal questions
	quizObj->insert_question("How often do you smile?", NONVERBAL);
	quizObj->insert_question("How often do you use your hands in conversation?", NONVERBAL);
	quizObj->insert_question("How often do you make facial expressions in conversion?", NONVERBAL);
	quizObj->insert_question("How often do you make conversation with strangers?", NONVERBAL);
	quizObj->insert_question("Do you take care of your appearance?", NONVERBAL);
}

void runTraining(vector<QuestionType> order){
	//at each index, show tasks
	for(int i=0; i<order.size(); i++){
		//determines task
		switch(order[i]){
			case EMPATHY://empathy
				Level empathyLvl;
				empathyLvl.askTasks();//rename with actual giveTasks function name
				break;
			case COOPERATION://cooperation
				Level coopLvl;
				coopLvl.askTasks();
				break;
			case COMMUNICATION://communication
				Level comLvl;
				comLvl.askTasks();
				break;
			case LISTENING://lisetening
				Level listenLvl;
				listenLvl.askTasks();
				break;
			case NONVERBAL://nonverbal
				Level nonverbalLvl;
				nonverbalLvl.askTasks();
				break;
		}
		
	}
}

int main(){
	introduction();
	
	Quiz quizObj;
	makeQuestions(quizObj);
	
	//access quizObj vector
	runTraining(quizObj.start_quiz());
	
}