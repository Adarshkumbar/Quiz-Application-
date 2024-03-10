#pragma once
#include"Quiz.h"
#include"QuizAdmin.h"

QuizAdmin::QuizAdmin()
{
}

QuizAdmin::~QuizAdmin()
{
}

void QuizAdmin :: getAdmin() {
	//cout << " Name is : " << userName << " & Password is :" << password;
}

void QuizAdmin:: addQuiz() {
	Quiz quiz;

	int choice;
	x:
	cout << " \n Create New Quiz ? (1)\n Add a Question in Existing Quiz (2) ";
	cin >> choice;

	if( choice == 1)
		quiz.setQuiz();
	else if (choice == 2) {
		showAllQuiz();
		cout << " \nEnter quizId you want to select :";
		int quizId; 
		cin >> quizId;
		quiz.storeQuestions(quizId);
	}
	else {
		cout << "\nInvalid Entry";
		goto x;
	}
}
void QuizAdmin:: removeQuiz() {

}

