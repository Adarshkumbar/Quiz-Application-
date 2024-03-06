#pragma once
#include<iostream>
#include <string>
using namespace std;
class User
{
	string userName;
	string password;

public:
	User(string userName, string password) {
		this->userName = userName;
		this->password = password;
	}
	void getUser() {
		cout << " Name is : " << userName << " & Password is :" << password;
	}

	void playQuiz();
};

