#include <stdlib.h>
#include <iostream>
#include <string>

#include"mySqlConnection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
using namespace std;

const string server = "localhost:3306";
const string username = "root";
const string password = "Adarsh@123";


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
            cout << "User with username '" << arr[0] << "' and password does not exist in the " << arr[2] << " table." << endl;
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
    return false;
}
//
//void addToDB(string& name, string& pass) {
//
//	//sql::Driver* driver;
//	//sql::Connection* con;
//	//sql::Statement* stmt;
//	//sql::PreparedStatement* pstmt;
//	try {
//		sql::Driver* driver = get_driver_instance();
//		sql::Connection* con = driver->connect(server, username, password);
//		con->setSchema("dummy");
//
//		sql::PreparedStatement* pstmt = con->prepareStatement("INSERT INTO admin(name, password) VALUES(?, ?)");
//		pstmt->setString(1, name);
//		pstmt->setString(2, pass);
//		pstmt->execute();
//		cout << "user inserted." << endl;
//		delete pstmt;
//		delete con;
//	}
//	catch (sql::SQLException& e) {
//		cout << "Error inserting data: " << e.what() << endl;
//		system("pause");
//		exit(1);
//	}
//}
static void getFromDB() {

}

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