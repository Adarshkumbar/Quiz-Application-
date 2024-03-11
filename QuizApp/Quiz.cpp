#pragma once
#include<iostream>
#include <string>
#include"Question.h"
#include"Quiz.h"
#include "mySqlConnection.h"
using namespace std;

void Quiz :: setQuiz() {
	DataBase db;
	pair < int, string> pair;
	// getting quiz id from quizManagement table
	string table = "quizManagement";
	this->quizId = db.totalQuiz(table) + 1;
	pair.first = quizId;

	cout << "\nEnter quiz title ";
	cin >> this->title;
	pair.second = title;

	db.addQuiz(pair);
}
void Quiz::storeQuestions(int quizId) {
	Question q;
	q.createQuestion(quizId);	
}
vector<vector<string>>  Quiz::getQuiz(int quizId) {

	// getting quiz and questions for it
	DataBase db;

	vector<vector<string>> quiz = db.getQuizDB(quizId);

	return quiz;
}
