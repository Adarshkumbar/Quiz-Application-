#include <stdlib.h>
#include <iostream>
#include <string>
#include "Quiz.h"
#include"mySqlConnection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

const string server = "localhost:3306";
const string username = "root";
const string password = "Adarsh@123";

class DBcon {
    DBcon() {

    }
};

void addToDB(string arr[]) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");

        //string table = "user";
        // Adjust the SQL query based on the table parameter
        string query = "INSERT INTO " +arr[2] + "(name, password) VALUES(?, ?)";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, arr[0]);
        pstmt->setString(2, arr[1]);
        pstmt->execute();

        cout << "Data inserted into " << "user" << " table." << endl;

        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}
bool getFromDB(string arr[]) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");

        // Construct the SQL query to check if the user exists based on both username and password
        string query = "SELECT COUNT(*) FROM " + arr[2] + " WHERE name = ? AND password = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, arr[0]);
        pstmt->setString(2, arr[1]);

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int userCount = result->getInt(1);

        if (userCount > 0) {
            cout << "User with username '" << arr[0] << "' and password exists in the " << arr[2] << " table." << endl;
 
        }
        else {
            cout << "Username '" << arr[0] << "' and password does not exist in the " << arr[2] << " table." << endl;
            return false;
        }

        delete result;
        delete pstmt;
        delete con;
        return true;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking user data: " << e.what() << endl;
        system("pause");
    }
}
void addQuiz(pair<int, string> pair) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");



        string query = "INSERT INTO  QuizManagement (quizId, title , description) VALUES(?, ? , ?)";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setInt(1, pair.first);
        pstmt->setString(2, pair.second);
        pstmt->setString(3, pair.second);
        pstmt->execute();

        cout << "Data inserted into " << "Quiz Management" << " table." << endl;

        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

int totalQuiz() {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");


        string query = "SELECT COUNT(*) FROM  quizManagement";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int quizCount = result->getInt(1);

        delete pstmt;
        delete con;
        
        return  quizCount;
    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}
void showAllQuiz() {
    vector <pair <int, string>> quiz;
    try {
      
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("dummy");

        // Construct the SQL query to check if the user exists based on both username and password
        string query = "SELECT * FROM QuizManagement";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();

        // printing all quiz available
        while (result->next()) {
            cout<<"\n ID : " <<result->getInt("quizID");
            cout<<"\t Type :" <<result->getString("title") << endl;
        }

        delete result;
        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking data: " << e.what() << endl;
        system("pause");
    }
}
//}
//void storeQuizInDb(Question obj) {
//    try {
//        sql::Driver* driver = get_driver_instance();
//        sql::Connection* con = driver->connect(server, username, password);
//        con->setSchema("dummy");
//
//        //string table = "user";
//        // Adjust the SQL query based on the table parameter
//        string query = "INSERT INTO Question(question , op1  , op2, op3, op4 , ans , quizID) VALUES(?, ? ,? , ? , ? , ? , ?)";
//        sql::PreparedStatement* pstmt = con->prepareStatement(query);
//        pstmt->setString(1, obj.question);
//        pstmt->setString(2, obj.op1);
//        pstmt->setString(3, obj.op2);
//        pstmt->setString(4, obj.op3);
//        pstmt->setString(5, obj.op4);
//        pstmt->setString(6, obj.ans);
//        pstmt->setInt(7, obj.quizId);
//        pstmt->execute();
//
//        cout << "Data inserted into " << "user" << " table." << endl;
//
//        delete pstmt;
//        delete con;
//    }
//    catch (sql::SQLException& e) {
//        cout << "Error inserting data: " << e.what() << endl;
//        system("pause");
//        exit(1);
//    }
//}
//  

//
//static void Connection()
//{
//
//	sql::Driver* driver;
//	sql::Connection* con;
//	sql::Statement* stmt;
//	sql::PreparedStatement* pstmt;
//
//
//	try
//	{
//		driver = get_driver_instance();
//		con = driver->connect(server, username, password);
//	}
//	catch (sql::SQLException e)
//	{
//		cout << "Could not connect to server. Error message: " << e.what() << endl;
//		system("pause");
//		exit(1);
//	}
//
//	// create database "quickstartdb" ahead of time
//	con->setSchema("dummy");
//
//	/*stmt = con->createStatement();
//	stmt->execute("DROP TABLE IF EXISTS inventory");
//	cout << "Finished dropping table (if existed)" << endl;
//	stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);");
//	cout << "Finished creating table" << endl;
//	delete stmt;
//
//	pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)");
//	pstmt->setString(1, "banana");
//	pstmt->setInt(2, 150);
//	pstmt->execute();
//	cout << "One row inserted." << endl;
//
//	pstmt->setString(1, "orange");
//	pstmt->setInt(2, 154);
//	pstmt->execute();
//	cout << "One row inserted." << endl;
//
//	pstmt->setString(1, "apple");
//	pstmt->setInt(2, 100);
//	pstmt->execute();
//	cout << "One row inserted." << endl;
//
//	pstmt->setString(1, "mango");
//	pstmt->setInt(2, 120);
//	pstmt->execute();
//	cout << "One row inserted." << endl;
//
//	pstmt->setString(1, "kiwi");
//	pstmt->setInt(2, 100);
//	pstmt->execute();
//	cout << "One row inserted." << endl;
//
//	delete pstmt;
//	delete con;*/
//	//system("pause");
//	
//}