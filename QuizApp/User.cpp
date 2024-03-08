
#include "User.h"
#include "mySqlConnection.h"
void User::getUser() {
	cout << " user";
}

void User::playQuiz()
{
	int quizId , count = 0; 
	showAllQuiz();
	cout << "\n Choose ID of Quiz you want to Play : ";
	cin >> quizId;
	
	vector<string> eachQuestion;
	vector <vector<string >> entireQUiz ;

	// getting quiz and questions for it
	vector<vector<string>> quiz = getQuiz(quizId);
	string table = "question";
	int questionCount = totalQuestion(table, quizId);
	// Print quiz data

	cout << "\nThis Quiz Has " << questionCount << " Questions\n";
	for (const auto& row : quiz) {
		string ans;
		cout << "\nQuestion: " << row[0] << endl;
		cout << "\nOptions A: " << row[1] << "\nOptions B: " << row[2] << "\nOptions C: " << row[3] << "\nOptions D: " << row[4] << endl;
		//cout << "Correct Answer: " << row[5] << endl;
		cout << "\nEnter Option (A/B/C/D)";
		cin >> ans;

		if (ans == row[5])
			count++;
		cout << "--------------------------" << endl;
	}
	cout << "\n Congratulations you Scored " << count << "/" << questionCount<<endl;

	cout << "\n Thank you for playing \n";
}
