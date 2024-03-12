#include <string>
#include "Database.h"
#include "Authentication.h"

#include<iostream>
#include"User.h"
#include "QuizAdmin.h"
using namespace std;

void Authentication ::  Register(int choice) {
	DataBase obj;
	system("CLS");
	if (choice == 1) {  
		cout << "\nEnter username :" << endl;
		cin >> arr[0];
		cout << "\nEnter password :" << endl;
		cin >> arr[1];

		arr[2] = "user";
		
		obj.addToDB(arr);
	}
	else {
		cout << "\nEnter admin username :" << endl;
		cin >> arr[0];

		cout << "\nEnter password :" << endl;
		cin >> arr[1];

		arr[2] = "admin";
		obj.addToDB(arr);
	}
}
void Authentication :: Login(int choice) {
	DataBase obj;
	system("CLS");
	if (choice == 1) { 
	beg:
		cout << "\nEnter username :" << endl;
		cin >> arr[0];
	
		cout << "\nEnter password :" << endl;
		cin >> arr[1];

		arr[2] = "user";
		
		
		if (obj.getFromDB(arr)) {
			system("CLS");
			cout << "\n~~~~~~~~~~~~~~~~ Welcome "<< arr[0]<< " ~~~~~~~~~~~~~~~~\n";
		
			User obj;
			
			obj.setUser(arr[0] ,arr[1]);

			options:
			int choice;
			cout << "\n1: Play Quiz \n2: Progress :";
			cin >> choice;

			if (choice == 1)
				obj.playQuiz();
			else if (choice == 2)
				obj.Progress();
			else {
				system("CLS");
				cout << "\n!!!! Invalid Entry !!!!";
				goto options;
			}
		}
		else {
			system("CLS");
			cout << "\n!!! Invalid Entry !!!\n";
			goto beg;
		}
	}
	else {					
		cout << "\nEnter Admin username :" << endl;
		cin >> arr[0];

		cout << "\nEnter password :" << endl;
		cin >> arr[1];

		arr[2] = "admin";
		if (obj.getFromDB(arr)) {
			cout << "\n~~~~~~~~~~~~~~~~ Welcome Admin ~~~~~~~~~~~~~~~~\n";
			QuizAdmin obj;
			obj.addQuiz();
		}
		else {
			cout << "\n Invalid Entry\n";
		}
	}
}