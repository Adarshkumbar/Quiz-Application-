#pragma once

class Authentication
{
	//int userOrQuizAdmin; // 1 -> user . 2-> QuizAdmin

public:
	std::string arr[3]; //0->name, 1->pass, 2->table(either user or admin)

	void  Register(int choice);
	void Login(int choice);
};
