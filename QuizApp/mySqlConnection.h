
#ifndef MYSQLCONNECTION_H
#define MYSQLCONNECTION_H

#include"mySqlConnection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

#include<iostream>
#include <vector>

using namespace std;


class DataBase {
private :
	const string server = "localhost:3306";
	const string username = "root";
	const string password = "Adarsh@123";
	sql::Driver* driver = get_driver_instance();
	sql::Connection* con = driver->connect(server, username, password);

public:
	DataBase() {
		con->setSchema("dummy");
	}
	~DataBase() {
		delete con;
	}

	void addToDB(string arr[]);  // registration

	bool getFromDB(string arr[]); // login

	void addQuiz(pair<int, string>);

	int totalQuiz(string table);

	void showAllQuiz();

	int totalQuestion(string table, int quizId);

	vector <vector<string >> getQuizDB(int quizId);

	void getProgress(int quizId, string userName);

	void addQuesion(pair<int, vector<string>> pair);

	void addScore(int quizId, string userName, int score);

	int alreadyPlayed(int quizId, string userName);

	void updateScore(int quizId, string userName, int score);


};

#endif // MYSQLCONNECTION_H

