#include <stdlib.h>
#include <iostream>
//#include "stdafx.h"

#include "User.cpp"
#include<iostream>
#include "mySqlConnection.cpp"
using namespace std;

int main()
{
	Connection();
	User obj("Adarsh", "pass");
	obj.getUser();
	return 0;
}