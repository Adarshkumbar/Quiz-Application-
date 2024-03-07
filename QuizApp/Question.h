
#ifndef QUESTION_H
#define QUESTION_H
#include<iostream>
#include <string>
using namespace std;
class Question
{
public:
	string question;
	string op1;
	string op2;
	string op3;
	string op4;
	string ans;
	int quizId;
	
	void createQuestion() ;
//	void getQuestion(int quizId) ;
};
#endif

