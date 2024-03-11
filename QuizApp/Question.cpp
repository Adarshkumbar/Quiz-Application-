
#include "Question.h"
#include<iostream>
#include"mySqlConnection.h"
void Question::createQuestion(int quizId) {

    pair<int, vector<string>> Pair;
    Pair.second.resize(6); // Initialize vector size

    cout << "Enter Question: ";
    cin.ignore(); // Consume newline character
    //getline(cin, Pair.second[0]);
    getline(cin, this->question);
    Pair.second[0] = question;

    cout << "Option 1: ";
    //getline(cin, Pair.second[1]);
    getline(cin, this->op1);
    Pair.second[1] = this->op1;

    cout << "Option 2: ";
   // getline(cin, Pair.second[2]);
    getline(cin, this->op2);
    Pair.second[2] = this->op2;

    cout << "Option 3: ";
   // getline(cin, Pair.second[3]);
    getline(cin, this->op3);
    Pair.second[3] = this->op3;

    cout << "Option 4: ";
    //getline(cin, Pair.second[4]);
    getline(cin, this->op4);
    Pair.second[4] = this->op4;

    cout << "Answer: ";
    //getline(cin, Pair.second[5]);
    getline(cin, this->ans);
    Pair.second[5] = this->ans;

    cout << "Quiz ID: is "<< quizId<<endl;
    //Pair.first = quizId;
    Pair.first = this ->quizId =  quizId;

    //cout << "\nDone from Question Class\n";

    addQuesion(Pair);
}
