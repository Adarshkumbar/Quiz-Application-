#pragma once
#include<iostream>
#include <string>
using namespace std;
class ProgressTracker
{
	int score;
	int quizId; // Foreign key
	string userName; // Foreign key

public:
	void getScore(int quizId, string userName);

	void setScore(int quizId, string userName, int score);

	void calculatePercentage(int score, int totalQuestions);
};


	
