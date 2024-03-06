#include <stdlib.h>
#include <iostream>
//#include "stdafx.h"
#include "Authentication.cpp"
#include "User.cpp"
#include<iostream>
#include "mySqlConnection.h"
using namespace std;

int main()
{
	//Connection();
	User obj("Adarsh", "pass");

	Authentication auth;
	auth.Login(1); // for user
	obj.getUser();

	/*string name = "adie";
	string pass = "pass";
	addToDB(name, pass);*/
	return 0;
}