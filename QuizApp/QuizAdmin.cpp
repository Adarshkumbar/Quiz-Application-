#pragma once
#include<iostream>
#include <string>
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
		cout << " Name is : " << userName << " & Password is :" << password;
	}

	void addQuiz();
	void removeQuiz();
};

