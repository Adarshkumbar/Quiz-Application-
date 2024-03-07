#pragma once
#include<iostream>
#include <string>
#include"Question.cpp"
using namespace std;
class Quiz
{
	int quizId;
	string title;

public:
	void setQuiz() {
		cout << "\nEnter quiz id ";
		
		cin>>this->quizId;

		cout << "\nEnter quiz title ";
		cin >> this->title;
	}
	void storeQuestions(int quizId) {
		Question q[5];

		for (int i = 0; i < 5; i++) {
			q[i].createQuestion();
		}
	}
	void getQuestions() {
		Question q[5];

		for (int i = 0; i < 5; i++) {
			q[i].getQuestion(quizId);

		}
	}
	// creating 5 Objects of Question class to Store 5 questions for each Quiz	 
	
};

