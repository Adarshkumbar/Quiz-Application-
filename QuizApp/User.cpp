#pragma once
#include<iostream>
#include <string>
using namespace std;
class User
{
	string userName;
	string password;

public:
	void getUser() {
		cout << " Name is : " << userName << " & Password is :" << password;
	}

	void playQuiz() {
		cout << " hi";
	}
};

