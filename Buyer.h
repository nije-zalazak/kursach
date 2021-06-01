#pragma once
#include <iostream>
#include "User.h"

using namespace std;

class Buyer : public User {
protected:

public:
	Buyer();

	Buyer(const Buyer& obj);

	~Buyer();

	void ViewAd(string) override;

	void FilterAds();

	void ShowMyList() override;

};

