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

	this->quizId = totalQuiz() + 1;
	pair.first = quizId;

	cout << "\nEnter quiz title ";
	cin >> this->title;
	pair.second = title;

	addQuiz(pair);
}
void Quiz::storeQuestions(int quizId) {
	Question q[5];

	for (int i = 0; i < 5; i++) {
		q[i].createQuestion();
		cout << "\ninserted :" << i + 1 << "th question";
		// Store quiz in DB
		//storeQuizInDb(q[i]);
	}
}
void Quiz::getQuestions() {
	Question q[5];

	for (int i = 0; i < 5; i++) {
		//q[i].getQuestion(quizId);
	}
}
