
#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H
#include<iostream>
#include <vector>

using namespace std;

void addToDB(string arr[]);    // registration
bool getFromDB(string arr[]); // login
void addQuiz(pair<int , string>);
int totalQuiz(string table);
void showAllQuiz();
int totalQuestion(string table, int quizId);
vector <vector<string >> getQuizDB(int quizId);
void getProgress(int quizId, string userName);
void addQuesion(pair<int, vector<string>> pair);
void addScore(int quizId, string userName, int score);
int alreadyPlayed(int quizId, string userName);
void updateScore(int quizId, string userName, int score);

#endif // MYSQLCONNECTION_H

