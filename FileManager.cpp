#include "FileManager.h"
#include "Aparts.h"
#include "Buyer.h"
#include "Realtor.h"


const string FileManager::BUYER_PATH = "buyers/";
const string FileManager::REALTOR_PATH = "realtors/";
const string FileManager::APARTMENTS_PATH = "apartments/";
const string FileManager::BUYER_LIST_PATH = "buyerlist/";
const string FileManager::REALTOR_LIST_PATH = "realtorlist/";


string FileManager::GetApartPath() {
	return APARTMENTS_PATH;
}

string FileManager::GetRealtorPath() {
	return REALTOR_PATH;
}

string FileManager::GetBuyerPath() {
	return BUYER_PATH;
}

string FileManager::GetBuyerlistPath() {
	return BUYER_LIST_PATH;
}

string FileManager::GetRealtorlistPath() {
	return REALTOR_LIST_PATH;
}

void FileManager::SignUpBuyer() {
	system("cls");
	Buyer buyer;
	buyer.SignUp(FileManager::GetBuyerPath(), FileManager::GetBuyerlistPath());
}

void FileManager::SignUpRealtor() {
	system("cls");
	Realtor realtor;
	realtor.SignUp(FileManager::GetRealtorPath(), FileManager::GetRealtorlistPath());
}

void FileManager::CreateApartsDir()
{
	if (exists("apartments") == false)
	{
		create_directory("apartments");
	}
}

void FileManager::CreateBuyersDir()
{
	if (exists("buyers") == false)
	{
		create_directory("buyers");
	}
}

void FileManager::CreateRealtorsDir()
{
	if (exists("realtors") == false)
	{
		create_directory("realtors");
	}
}

void FileManager::CreateRealtorsListDir()
{
	if (exists("realtorlist") == false)
	{
		create_directory("realtorlist");
	}
}

void FileManager::CreateBuyersListDir()
{
	if (exists("buyerlist") == false)
	{
		create_directory("buyerlist");
	}
}

void FileManager::DeleteAd(string adname) {
	while (true) {
		system("cls");
		cout << "Вы действительно уверены что хотите удалить " << adname << " ? \n1. - да \n2. - нет\n";
		int choice = GetInt(1, 2);
		if (choice == 2)
		{
			break;
		}
		else if (choice == 1)
		{
			if (exists(FileManager::GetApartPath() + adname)) {
				remove(FileManager::GetApartPath() + adname);
				cout << "Объявление удалено успешно!" << endl;
				return;
			}
			else {
				cout << "Такого объявления не существует в базе!\n";
			}
		}
	}
}