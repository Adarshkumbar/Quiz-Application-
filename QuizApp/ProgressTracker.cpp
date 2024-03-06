
#include<iostream>
#include <string>
using namespace std;
class ProgressTracker
{

	int score; 
	int quizId; // Foreign key
	string userName; // Foreign key

public:
	ProgressTracker(int score, int quizId , string userName ) {
		this->score = score;
		this->quizId = quizId;
		this->userName = userName;
	}
};

