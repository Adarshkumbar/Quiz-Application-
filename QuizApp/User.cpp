
#include "User.h"
#include "mySqlConnection.h"
#include "ProgressTracker.h"
#include "Quiz.h"
void User::getUser() {
	cout << " user";
}

void User::playQuiz()
{
	int count = 0 , quizId;
	string table = "question";
	
	
	// Print quiz data
	Quiz q;
	showAllQuiz();
	cout << "\nChoose ID of Quiz you want to Play : ";
	cin >> quizId;
	vector<vector<string>>  quiz = q.getQuiz(quizId);

	int questionCount = totalQuestion(table, quizId);

	cout <<"\n\t--------[This Quiz Has " << questionCount << " Questions]--------\n";
	int i = 0;
	for (const auto& row : quiz) {
		i++;
		char ans;
		cout << "\nQuestion:" <<"[" <<i <<"] " << row[0] << endl;
		cout << "\nOptions A: " << row[1] << "\nOptions B: " << row[2] << "\nOptions C: " << row[3] << "\nOptions D: " << row[4] << endl;
		//cout << "Correct Answer: " << row[5] << endl;
		cout << "\nEnter Option (A | B | C | D) :";
		cin >> ans;

		if (ans == row[5].at(0) || ans== row[5].at(0) + 32)
			count++;
		else {
			cout << "\nIncorrect"<<endl;
		}
		cout << "--------------------------" << endl;
	}
	
	ProgressTracker progress;
	progress.setScore(quizId, this->userName, count);
	progress.calculatePercentage(count, questionCount);

	cout << "\n ********************** Thank you for playing **********************\n";
}

void User::setUser(string userName, string password) {
	this->userName = userName;
	this->password = password;
}

void User:: Progress() {
	int quizId;
	ProgressTracker progress;


	showAllQuiz();
	cout << "\n Choose ID of Quiz you want to check score of : ";
	cin >> quizId;
	cout << "\nthis is user : " << this->userName <<endl;
	progress.getScore(quizId , userName);
}
