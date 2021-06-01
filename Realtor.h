#pragma once
//#include "FileManager.h"
//#include "Aparts.h"
#include "User.h"
#include <iostream>
#include <string>


class Realtor : public User{
protected:

public:
	Realtor();

	Realtor(const Realtor& obj);

	~Realtor();

	void MakeAd();

	void ShowMyList() override;

	void DeleteAd(string);

	string GetLogin();

	void ViewAd(string) override;

	bool CheckAdList(string adname);



};