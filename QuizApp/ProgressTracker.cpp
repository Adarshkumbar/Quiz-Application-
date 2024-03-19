
#include"ProgressTracker.h"
#include"Database.h"
#include<iostream>
#include <string>
using namespace std;
void  ProgressTracker :: getScore(int quizId, string userName) {
	DataBase obj;
	obj.getProgress(quizId , userName);
	return;
}

void ProgressTracker::setScore(int quizId, string userName, int score) {
	DataBase obj;
	if (obj.alreadyPlayed(quizId, userName)== 1){
		obj.updateScore(quizId, userName,score);
	}
	else if(obj.alreadyPlayed(quizId, userName) == 2) {
		obj.addScore(quizId, userName, score);
	}
	else {
		cout << "\n------ You have not played this Quiz yet ------\n";
	}
	
}
void ProgressTracker::calculatePercentage(int score, int totalQuestions) {
	if (score / totalQuestions > (1 / 2)) {
		cout << "\n********************** Congratulations you Scored "<< score << " / " << totalQuestions<< " **********************"  << endl;
	}
	else {
		cout << "\n********************** You Scored " << score << "/" << totalQuestions << " [Better Luck next time] **********************" << endl;
	}
	double percentage = (score * 1.0/ totalQuestions * 1.0) *100;
	cout << "\t\t\t\tPercentage is :" << percentage <<"%"<< endl;
}