#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <memory>
#include <conio.h>
#include "Buyer.h"
#include "Realtor.h"
#include "FileManager.h"
using namespace std;
namespace ShowMenu
{
	void ShowMainMenu();

	void ShowAdminMenu();

	void ShowBuyerMenu();

	void ShowRealtorMenu();

	void ShowFilterMenu();

}

namespace Working
{
	void Auth();

	void RealtorMode(Realtor& realtor);

	void BuyerMode(Buyer& buyer);

	bool LoginAsAdmin();

	void AdminMode();
}

