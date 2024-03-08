
#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H
#include<iostream>
#include <vector>
using namespace std;
void addToDB(string arr[]);
bool getFromDB(string arr[]);
void addQuiz(pair<int , string>);
int totalQuiz(string table);
void showAllQuiz();
int totalQuestion(string table, int quizId);
vector <vector<string >> getQuiz(int quizId);
//void storeQuizInDb(Question q);
#endif // MYSQLCONNECTION_H

