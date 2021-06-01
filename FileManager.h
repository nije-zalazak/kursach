#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <vector>
#include <direct.h>
#include <fstream>



using namespace std;
using namespace std::experimental::filesystem;

class FileManager
{
private:

	static const string BUYER_PATH;
	static const string BUYER_LIST_PATH;
	static const string REALTOR_PATH;
	static const string REALTOR_LIST_PATH;
	static const string APARTMENTS_PATH;

public:

	static string GetApartPath();

	static string GetRealtorPath();

	static string GetBuyerPath();

	static string GetBuyerlistPath();

	static string GetRealtorlistPath();

	static void SignUpBuyer();

	static void SignUpRealtor();

	static void CreateApartsDir();

	static void CreateBuyersDir();

	static void CreateRealtorsDir();

	static void CreateRealtorsListDir();

	static void CreateBuyersListDir();

	void DeleteAd(string adname);



	


};