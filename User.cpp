#include "User.h"

void User::EncryptPassword(char* password)
{
	auto hash_ = hash<string>{}(password);
	string result;
	result = to_string(hash_);
	ConvertStringToMasChar(result, password);
}

User::User()
{
	password[0] = '\0';
	login[0] = '\0';
}

User::User(const User& obj)
{
	CopyFromCharToChar(obj.login, login);
	CopyFromCharToChar(obj.password, password);
}

User::~User()
{

}

void User::SaveAccount(string path) {
	fstream fs;
	fs.open(path + ConvertMasCharToString(login), ios::out | ios::trunc | ios::binary);
	fs.write((char*)&password, sizeof(char) * 64);
	fs.close();
}

void User::DeleteAccount(string account_path, string list_path){
	if (exists(account_path + login)) {
		remove(account_path + login);
	}
	if (exists(list_path + login)) {
		remove(list_path + login);
	}
	cout << "Аккаунт успешно удалён!" << endl;
	system("pause");
	system("cls");
}

void User::GetAccount(string path) {
	fstream fs;
	fs.open(path + login, ios::in | ios::binary);
	fs.read((char*)&password, sizeof(char) * 64);

	fs.close();
}

bool User::SignUp(string path,string path2) {
	char checkPassword[64];
	int choice;
	while (true)
	{
		cout << "Введите ваш логин: ";
		cin.clear();
		cin.ignore(64, '\n');
		cin.getline(login, 64);
		/*if (exists(path + login)) {
			cout << "Такой пользователь уже существует! \n";
			system("pause");
			continue;
		}*/
		while (true)
		{
			cout << "Введите пароль для нового пользователя: ";
			cin.getline(checkPassword, 64);
			system("cls");
			cout << "Введите пароль ещё раз: ";
			cin.getline(password, 64);
			if (ConvertMasCharToString(password) == ConvertMasCharToString(checkPassword))
			{

				EncryptPassword(password);
				break;
			}
			else
			{
				cout << "Пароли не совпадают. Попробуйте ещё раз." << endl;
			}
		}
		cout << "Изменить данные пользователя? \n1. - да, \n2. - нет." << endl;
		choice = GetInt(1, 2);
		if (choice == 2)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	cout << "Сохранить пользователя? \n1. - да \n2. - нет" << endl;
	choice = GetInt(1, 2);
	if (choice == 1)
	{
		SaveAccount(path);
		CreateAdList(path2);
	}
	cout << "Новый пользователь успешно добавлен\n";

	return true;
}

void User::CreateAdList(string path){
	fstream fs;
	fs.open(path + ConvertMasCharToString(login), ios::out | ios::trunc | ios::binary);
	/*fs << "\n";*/
	fs.close();
}



bool User::LogIn(string startPath)
{
	fstream fs;
	char truePassword[64], tempPassword[64];
	while (true)
	{
		cout << "Введите имя пользователя: ";
		cin.clear();
		cin.ignore(64, '\n');
		cin.getline(login, 64);
		fs.open(ConnectStringAndChar(startPath, login), ios::in);
		if (fs.is_open() == false)
		{
			cout << "Неверное имя пользователя, желаете повторите попытку? 1 - да, 2 - нет.\n";
			if (GetInt(1, 2) == 2)
			{
				return false;
			}
			else
			{
				continue;
			}
		}
		else  break;
	}
	fs.read((char*)&truePassword, sizeof(char) * 64);
	while (true)
	{
		cout << "Введите пароль: ";
		cin.getline(tempPassword, 64);
		EncryptPassword(tempPassword);
		if (ConvertMasCharToString(truePassword) != ConvertMasCharToString(tempPassword))
		{
			cout << "Неверный пароль, желаете повторите попытку? \n1. - да \n2. - нет.\n";
			if (GetInt(1, 2) == 2)
			{
				return false;
			}
			else
			{
				cin.clear();
				cin.ignore(64, '\n');
				continue;
			}
		}
		else
		{
			cout << "Вход произведен!" << endl;
			break;
		}
	}
	fs.close();

	return true;
}


void User::AddToMyList(string adname, string path) {
	ofstream fs;
	fs.open(path + ConvertMasCharToString(login), ios::app);
	fs << adname << "\n";
	fs.close();
}

void User::ShowAdList() {
	system("cls");
	vector<Aparts> apartments;
	int adNum;
	string choice;
	for (const auto& entry : directory_iterator(FileManager::GetApartPath()))
	{
		Aparts apartment;
		apartment.GetAdInfo(entry.path().stem().string());
		apartments.push_back(apartment);
	}
	if (apartments.size() <= 0) {
		cout << "Объявления отсутствуют!" << endl;
		return;
	}
	else {
		cout << "Список объявлений:" << endl;
		for (int i = 0; i < apartments.size(); i++) {
			cout << "\t" << i + 1 <<". ";
			cout << apartments[i];
		}
	}
	while (true) {
		cout << "Введите номер объявления для его просмотра, либо 0 для выхода в меню:";
		cin >> adNum;
		if (adNum == 0) {
			return;
		}else if (adNum < apartments.size() || adNum > 0) {
			choice = apartments[adNum - 1].GetAdName();
			ViewAd(choice);
		}
		else cout << "Неверный ввод, повторите попытку..." << endl;
	}
	
}
