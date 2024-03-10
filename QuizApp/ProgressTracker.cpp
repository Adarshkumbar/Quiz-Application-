
#include"ProgressTracker.h"
#include"mySqlConnection.h"
void  ProgressTracker :: getScore(int quizId, string userName) {
	cout << "\nThe name in Progress Tracker is : " << userName<< endl;
	getProgress(quizId , userName);
}