#pragma once
#include<iostream>
#include <string>
using namespace std;
class User
{
	string userName;
	string password;
	int score;

public:
	void getUser();

	void setUser(string , string);

	void playQuiz();

	void Progress();
};
