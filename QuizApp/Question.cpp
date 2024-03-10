
#include "Question.h"
#include<iostream>
#include"mySqlConnection.h"
void Question::createQuestion(int quizId) {

    pair<int, vector<string>> Pair;
    Pair.second.resize(6); // Initialize vector size

    cout << "Enter Question: ";
    cin.ignore(); // Consume newline character
    getline(cin, Pair.second[0]);

    cout << "Option 1: ";
    getline(cin, Pair.second[1]);

    cout << "Option 2: ";
    getline(cin, Pair.second[2]);

    cout << "Option 3: ";
    getline(cin, Pair.second[3]);

    cout << "Option 4: ";
    getline(cin, Pair.second[4]);

    cout << "Answer: ";
    getline(cin, Pair.second[5]);

    cout << "Quiz ID: is "<< quizId<<endl;
    Pair.first = quizId;

    cout << "\nDone from Question Class\n";

    addQuesion(Pair);
}
