#include <string>
#include "mySqlConnection.h"
#include "Authentication.h"

using namespace std;

void Authentication ::  Register(int choice) {
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
void Authentication :: Login(int choice) {
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
			cout << "\nWelcome user \n";
			//obj.playQuiz();
		}
		else {
			cout << "\n\n\n\n Xoxox\n\n\n";
		}
	}
	else {						// Quiz Admin
		//Login ( store data in DB ) for  QuizAdmin
		cout << "\nEnter Admin username :" << endl;
		cin >> arr[0];

		cout << "\nEnter password :" << endl;
		cin >> arr[1];

		arr[2] = "admin";
		if (getFromDB(arr)) {
			cout << "\nWelcome admin \n";
			QuizAdmin obj;
			obj.addQuiz();
		}
		else {
			cout << "\n\n\n\n Xoxox\n\n\n";
		}
	}
}