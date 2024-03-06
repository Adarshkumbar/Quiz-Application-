
#include<iostream>
#include <string>
using namespace std;
class Question
{
	string question;
	string op1;
	string op2;
	string op3;
	string op4;
	char ans;
	int quizId;

public:
	Question(string question , string op1 , string op2, string op3, string op4, char ans, int quizId ) {
		this->question = question;
		this->op1 = op1;
		this->op2 = op2;
		this->op3 = op3;
		this->op4 = op4;
		this->ans = ans;
		this->quizId = quizId;
	}


};

