#include <stdlib.h>
#include <iostream>
//#include "stdafx.h"
#include "Authentication.cpp"
#include "User.cpp"
#include<iostream>
#include "mySqlConnection.h"
using namespace std;

int main()   // 1 - user ...2 - admin
{
	//Connection();
	User obj;
	obj.playQuiz();
	Authentication auth;
	//auth.Register(1) ; // for user
	auth.Login(1);
	//string name = "adie";
	//string pass = "pass";
	//string table = "user";
	//addToDB(name, pass);
	/*string name = "adie";
	string pass = "pass";
	addToDB(name, pass);*/
	return 0;
}