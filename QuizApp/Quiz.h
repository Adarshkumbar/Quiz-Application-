#pragma once
#include<iostream>
#include <string>
#include"Question.h"

#include "Database.h"
using namespace std;
class Quiz
{
	int quizId;
	string title;

public:
	void setQuiz();
	void storeQuestions(int quizId);
	vector<vector<string>>  getQuiz(int quizId);
	
};

