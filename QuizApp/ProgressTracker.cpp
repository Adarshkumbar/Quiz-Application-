
#include"ProgressTracker.h"
#include"mySqlConnection.h"
void  ProgressTracker :: getScore(int quizId, string userName) {
	getProgress(quizId , userName);
}

void ProgressTracker::setScore(int quizId, string userName, int score) {
	if (alreadyPlayed(quizId, userName)== 1){
		updateScore(quizId, userName,score);
	}
	else if(alreadyPlayed(quizId, userName) == 2) {
		addScore(quizId, userName, score);
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