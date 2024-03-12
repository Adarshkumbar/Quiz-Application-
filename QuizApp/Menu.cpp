#include"Menu.h"

void Menu() {
	cout << "\n******\tWelcome to Quiz Application\t******\n";

	do {
		int choice;
		cout << "\n1.User\n2.QuizAdmin\n3.Exit: ";
		cin >> choice;
		switch (choice)
		{
		case 1: {
			system("CLS");
			cout << "\nFor User \n";
			int loginOrRegister;
		x1: cout << "\n Do you want to Register (1) or Login(2) :";
			cin >> loginOrRegister;

			Authentication auth;
			if (loginOrRegister == 1) {
				auth.Register(1);
			}
			else if (loginOrRegister == 2) {
				auth.Login(1);
			}
			else {
				cout << "\ninvalid entry \n";
				goto x1;				
			}
			break;
		}
		case 2: {
			// play or track progress
			system("CLS");
			cout << "\nFor QuizAdmin \n";
			int loginOrRegister;
		x2: cout << "\n Do you want to Register (1) or Login(2) :";
			cin >> loginOrRegister;

			Authentication auth;
			if (loginOrRegister == 1) {
				auth.Register(2);
			}
			else if (loginOrRegister == 2) {
				auth.Login(2);
			}
			else {
				"\ninvalid entry \n";
				goto x2;
			}
			break;
		}
		case 3: {
			system("CLS");
			cout << "\n******\tExiting...\t******";
			exit(0);
		}
		default:
			system("CLS");
			cout << " Invalid Entry ....\n Try Again";
			break;
		}
	} while (1);
}