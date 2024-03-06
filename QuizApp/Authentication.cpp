#pragma once
#include<iostream>
#include <string>
using namespace std;

/// <summary>
/// Login Or Registration will be chosen in some other class / method outside 
/// But login for user / quizAdmin || register for user / quizAdmin done here
/// </summary>
class Authentication
{
	//int userOrQuizAdmin; // 1 -> user . 2-> QuizAdmin

public:
	void Login(int choice) {
		if (choice == 1) {  // user
			 // login ( get data from DB ) for  user
		}
		else {						// Quiz Admin
			// login ( get data from DB )for  QuizAdmin
		}
	}
	void Register(int choice) {
		if (choice == 1) {  // user
			// register ( store data in DB )for  user
		}
		else {						// Quiz Admin
			// register ( store data in DB ) for  QuizAdmin
		}
	}

};

