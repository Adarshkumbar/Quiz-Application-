#pragma once
#include<iostream>
#include <string>
#include"Question.h"
#include"Quiz.h"
#include "mySqlConnection.h"
using namespace std;

void Quiz :: setQuiz() {
	cout << "\nEnter quiz id ";
	cin >> this->quizId;

	cout << "\nEnter quiz title ";
	cin >> this->title;
}
void Quiz::storeQuestions(int quizId) {
	Question q[5];

	for (int i = 0; i < 5; i++) {
		q[i].createQuestion();
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
