
#ifndef QUESTION_H
#define QUESTION_H
#include<iostream>
#include<vector>
#include <string>
using namespace std;
class Question
{
	string question;
	string op1;
	string op2;
	string op3;
	string op4;
	string ans;
	int quizId;

public:
	
	void createQuestion(int quizId) ; //quizId is FK
//	void getQuestion(int quizId) ;
};
#endif

