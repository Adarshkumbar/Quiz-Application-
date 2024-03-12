
#include"Database.h"

void DataBase:: addToDB(string arr[]) {
    try {
        string query = "INSERT INTO " + arr[2] + "(name, password) VALUES(?, ?)";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, arr[0]);
        pstmt->setString(2, arr[1]);
        pstmt->execute();

        delete pstmt;
        cout << "\n~~~~~ Registered Successfully ~~~~~\n";
    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}
bool DataBase:: getFromDB(string arr[]) {
    try {
       /* sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/


        string query = "SELECT COUNT(*) FROM " + arr[2] + " WHERE name = ? AND password = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, arr[0]);
        pstmt->setString(2, arr[1]);


        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int userCount = result->getInt(1);

        if (userCount > 0) {
            // cout << "User with username '" << arr[0] << "' and password exists in the " << arr[2] << " table." << endl;
        }
        else {
            cout << "Username '" << arr[0] << "' and password does not exist in the " << arr[2] << " table." << endl;
            return false;
        }

        delete result;
        delete pstmt;
        
        return true;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking user data: " << e.what() << endl;
        system("pause");
    }
}
void DataBase::addQuiz(pair<int, string> pair) {
    try {
        /*sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/



        string query = "INSERT INTO  QuizManagement (quizId, title , description) VALUES(?, ? , ?)";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setInt(1, pair.first);
        pstmt->setString(2, pair.second);
        pstmt->setString(3, pair.second);
        pstmt->execute();

        cout << "Data inserted into " << "Quiz Management" << " table." << endl;

        delete pstmt;
      //  delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

int  DataBase::totalQuiz(string table) {
    try {
      /*  sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/


        string query = "SELECT COUNT(*) FROM " + table;
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int quizCount = result->getInt(1);

        delete pstmt;
        //delete con;

        return  quizCount;
    }
    catch (sql::SQLException& e) {
        cout << "Error fetching data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}
void  DataBase:: showAllQuiz() {
    vector <pair <int, string>> quiz;
    try {

      /*  sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/


        string query = "SELECT * FROM QuizManagement";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);


        sql::ResultSet* result = pstmt->executeQuery();

        // printing all quiz available
        while (result->next()) {
            cout << "\n ID : " << result->getInt("quizID");
            cout << "\t Type :" << result->getString("title") << endl;
        }

        delete result;
        delete pstmt;
       // delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking data: " << e.what() << endl;
        system("pause");
    }
}

vector<vector<string>> DataBase::getQuizDB(int quizId) {
    vector<vector<string>> quizData;

    try {
      /*  sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/

        string query = "SELECT questionText, optionA, optionB, optionC, optionD, answer FROM Question WHERE quizId = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setInt(1, quizId);


        sql::ResultSet* result = pstmt->executeQuery();


        while (auto x = result->next()) {

            vector<string> quizRow;
            quizRow.push_back(result->getString("questionText"));
            quizRow.push_back(result->getString("optionA"));
            quizRow.push_back(result->getString("optionB"));
            quizRow.push_back(result->getString("optionC"));
            quizRow.push_back(result->getString("optionD"));
            quizRow.push_back(result->getString("answer"));
            quizData.push_back(quizRow);
        }

        delete result;
        delete pstmt;
        //delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error retrieving quiz data: " << e.what() << endl;
        system("pause");
        exit(1);
    }

    return quizData;
}
int DataBase::totalQuestion(string table, int quizId) {
    try {
      /*  sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/


        string query = "SELECT COUNT(*) FROM Question Where quizId = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setInt(1, quizId);


        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int quizCount = result->getInt(1);

        delete pstmt;
       // delete con;

        return  quizCount;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}
void  DataBase::getProgress(int quizId, string userName) {
    try {
     /*   sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/


        string query = "SELECT * FROM ProgressTracker where quizId = ? and userName = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setInt(1, quizId);
        pstmt->setString(2, userName);

        sql::ResultSet* result = pstmt->executeQuery();
        //while (result->next()) {
        result->next();


        string table = " table";
        // << " Score for " << result->getInt("quizID");
        system("CLS");
        cout << "\n[ User Name : " << result->getString("userName") <<" ]"<<endl;
        cout << "****** Score  " << result->getString("score") << " Out of " << totalQuestion(table, quizId)<<" ******";

        delete pstmt;
       // delete con;

    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

void DataBase::addQuesion(pair<int, vector<string>> pair) {
    try {
        /*sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/



        string query = "INSERT INTO  Question (questionText, optionA, optionB, optionC, optionD, answer, quizId) VALUES(?, ? , ? ,? ,? , ? , ?)";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        pstmt->setString(1, pair.second[0]);
        pstmt->setString(2, pair.second[1]);
        pstmt->setString(3, pair.second[2]);
        pstmt->setString(4, pair.second[3]);
        pstmt->setString(5, pair.second[4]);
        pstmt->setString(6, pair.second[5]);
        pstmt->setInt(7, pair.first);
        pstmt->execute();

        delete pstmt;
       // delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

void DataBase:: addScore(int quizId, string userName, int score) {
    try {
      /*  sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/

        string query = "INSERT INTO progresstracker (quizId, userName , score) VALUES(?, ? , ? )";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        pstmt->setInt(1, quizId);
        pstmt->setString(2, userName);
        pstmt->setInt(3, score);
        pstmt->execute();



        delete pstmt;
        //delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

int  DataBase::alreadyPlayed(int quizId, string userName) {
    try {
      /*  sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/

        string query = "SELECT COUNT(*) FROM progressTracker where quizID = ? AND userName = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        pstmt->setInt(1, quizId);
        pstmt->setString(2, userName);
        pstmt->execute();

        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int count = result->getInt(1);

        delete pstmt;
       // delete con;

        if (count >= 1)
            return true;
        else
            return false;


    }
    catch (sql::SQLException& e) {
        cout << "Error : " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

void  DataBase::updateScore(int quizId, string userName, int score) {
    try {
    /*    sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");*/

        string query = "UPDATE progresstracker set score = ? WHERE quizId = ? AND  userName = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        pstmt->setInt(1, score);
        pstmt->setInt(2, quizId);
        pstmt->setString(3, userName);
        pstmt->execute();
        delete pstmt;
      //  delete con;

    }
    catch (sql::SQLException& e) {
        cout << "Error updating data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}