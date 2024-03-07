#pragma once
#include<iostream>
#include <string>
#include "mySqlConnection.h"
#include"User.cpp"
#include "QuizAdmin.cpp"

using namespace std;

/// <summary>
/// Login Or Registration will be chosen in some other class / method outside 
/// But login for user / quizAdmin || register for user / quizAdmin done here
/// </summary>
class Authentication
{
	//int userOrQuizAdmin; // 1 -> user . 2-> QuizAdmin

public:
	string arr[3]; //0->name, 1->pass, 2->table(either user or admin)
	void Register(int choice) {
		if (choice == 1) {  // user
			 // login ( get data from DB ) for  user
			cout << "\nEnter username :" << endl;
			cin >> arr[0];
			//arr[0] = "Gojo";  
			//arr[1] = "JJK";
			cout << "\nEnter password :" << endl;
			cin >> arr[1];

			arr[2] = "user";
			addToDB(arr);
		}
		else {						// Quiz Admin
			// login ( get data from DB )for  QuizAdmin
			cout << "\nEnter admin username :" << endl;
			cin >> arr[0];
	
			cout << "\nEnter password :" << endl;
			cin >> arr[1];

			arr[2] = "admin";
			addToDB(arr);
		}
	}
	void Login(int choice) {
		if (choice == 1) {  // user
			// login ( store data in DB )for  user
			 // login ( get data from DB ) for  user
			cout << "\nEnter username :" << endl;
			cin >> arr[0];
			//arr[0] = "Gojo";  
			//arr[1] = "JJK";
			cout << "\nEnter password :" << endl;
			cin >> arr[1];

			arr[2] = "user";
			if (getFromDB(arr)) {
				User obj;
				obj.playQuiz();
			}
			else {
				cout <<"\n\n\n\n Xoxox\n\n\n";
			}
		}
		else {						// Quiz Admin
			//Login ( store data in DB ) for  QuizAdmin
			cout << "\nEnter Admin username :" << endl;
			cin >> arr[0];
			//arr[0] = "Gojo";  
			//arr[1] = "JJK";
			cout << "\nEnter password :" << endl;
			cin >> arr[1];

			arr[2] = "admin";
			getFromDB(arr);
		}
	}

};

