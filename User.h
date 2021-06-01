#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "FileManager.h"
#include "InputChecker.h"
#include "ISCWorker.h"
#include "Aparts.h"


using namespace std;

class User
{
protected:
	char login[64];
	char password[64];
	void EncryptPassword(char* password);
public:
	User();

	User(const User& obj);

	~User();

	bool LogIn(string path);

	bool SignUp(string path, string path2);

	void CreateAdList(string path);

	void SaveAccount(string path);

	void DeleteAccount(string account_path, string list_path);

	void ChangePassword(string account_path);

	void GetAccount(string fullpath);

	void ShowAdList();

	virtual void ShowMyList() = 0;

	void AddToMyList(string adname, string path);

	virtual void ViewAd(string adname) = 0;
};

