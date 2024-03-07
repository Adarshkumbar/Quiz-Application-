#pragma once
#include<iostream>
#include <string>
#include"Quiz.cpp"
using namespace std;
class QuizAdmin
{
	string userName;
	string password;

public:
	QuizAdmin(string userName, string password) {
		this->userName = userName;
		this->password = password;
	}
	void getAdmin() {
		//cout << " Name is : " << userName << " & Password is :" << password;
	}

	void addQuiz() {
		Quiz quiz;
		quiz.setQuiz();
	}
	void removeQuiz();
};

