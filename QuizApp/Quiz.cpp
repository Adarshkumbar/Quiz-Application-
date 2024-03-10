#pragma once
#include<iostream>
#include <string>
#include"Question.h"
#include"Quiz.h"
#include "mySqlConnection.h"
using namespace std;

void Quiz :: setQuiz() {
	pair < int, string> pair;
	// getting quiz id from quizManagement table
	string table = "quizManagement";
	this->quizId = totalQuiz(table) + 1;
	pair.first = quizId;

	cout << "\nEnter quiz title ";
	cin >> this->title;
	pair.second = title;

	addQuiz(pair);
}
void Quiz::storeQuestions(int quizId) {
	Question q;
	q.createQuestion(quizId);	
}
void Quiz::getQuestions() {
	
}
