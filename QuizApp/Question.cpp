
#include "Question.h"
#include<iostream>
void Question::createQuestion() {
    cout << "\nEnter Question: ";
    cin >> this->question;

    cout << "\nOption 1: ";
    cin >> this->op1;

    cout << "\nOption 2: ";
    cin >> this->op2;

    cout << "\nOption 3: ";
    cin >> this->op3;

    cout << "\nOption 4: ";
    cin >> this->op4;

    cout << "\nAnswer: ";
    cin >> this->ans;

    cout << "\nQuiz ID: ";
    cin >> this->quizId;
}
