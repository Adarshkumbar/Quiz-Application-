#pragma once
#include<iostream>
#include <string>
#include"Question.h"
#include "mySqlConnection.h"
using namespace std;
class Quiz
{
	int quizId;
	string title;

public:
	void setQuiz();
	void storeQuestions(int quizId);
	vector<vector<string>>  getQuiz(int quizId);
	// creating 5 Objects of Question class to Store 5 questions for each Quiz	 
};

