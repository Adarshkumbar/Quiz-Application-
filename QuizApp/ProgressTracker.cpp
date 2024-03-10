
#include"ProgressTracker.h"
#include"mySqlConnection.h"
void  ProgressTracker :: getScore(int quizId, string userName) {
	cout << "\nThe name in Progress Tracker is : " << userName<< endl;
	getProgress(quizId , userName);

}

void ProgressTracker::setScore(int quizId, string userName, int score) {
	if (alreadyPlayed(quizId, userName)){
		updateScore(quizId, userName,score);
	}
	else {
		addScore(quizId, userName, score);
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