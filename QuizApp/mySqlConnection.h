
#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H
#include<iostream>
using namespace std;
void addToDB(string arr[]);
bool getFromDB(string arr[]);
void addQuiz(pair<int , string>);
int totalQuiz();
//void storeQuizInDb(Question q);
#endif // MYSQLCONNECTION_H

