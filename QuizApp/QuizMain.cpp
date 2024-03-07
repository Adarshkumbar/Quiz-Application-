#include <stdlib.h>
#include <iostream>
//#include "stdafx.h"
#include "Authentication.h"
#include "User.h"
#include<iostream>
#include "mySqlConnection.h"
using namespace std;

int main()   // 1 - user ...2 - admin
{
	//Connection();
	User obj;
	obj.playQuiz();
	Authentication auth;
	
	auth.Login(1);
	
	return 0;
}