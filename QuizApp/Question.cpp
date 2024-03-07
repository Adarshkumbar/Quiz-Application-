
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
		void createQuestion() {  // Store all aspects in Db
			cout << "\nEnter Question :";
			cin >> this->question;
			
			cout << "\n Option1 : ";
			cin >> this->op1;

			cout << "\n Option2 : ";
			cin >> this->op2;

			cout << "\n Option3 : ";
			cin >> this->op3;

			cout << "\n Option4 : ";
			cin >> this->op4;
			
			cout << "\n Answer : ";
			cin >> this->ans;

			cout << "\n QuizID : ";
			cin >> this->quizId;
		}
		void getQuestion(int quizId ) {
			// get questions based on quizID
		}
};

