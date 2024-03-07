#pragma once
#include<iostream>
#include <string>

using namespace std;
class QuizAdmin
{
	string userName;
	string password;

public:
	QuizAdmin();
	~QuizAdmin();
	void getAdmin();
	void addQuiz();
	void removeQuiz();
};