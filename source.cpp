#include <iostream>
#include <Windows.h>
#include "MenuManager.h"
#include "FileManager.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    FileManager::CreateApartsDir();
    FileManager::CreateBuyersDir();
    FileManager::CreateRealtorsDir();
    FileManager::CreateRealtorsListDir();
    FileManager::CreateBuyersListDir();
    Working::Auth();
    return 0;

}

