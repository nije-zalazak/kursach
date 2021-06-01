#include "Buyer.h"


Buyer::Buyer()
{
	password[0] = '\0';
	login[0] = '\0';
}

Buyer::Buyer(const Buyer& obj) : User(obj)
{
	
}

Buyer::~Buyer()
{

}


void Buyer::ViewAd(string adName) {
	Aparts ad;
	ad.GetAdInfo(adName);
	ad.ShowAdInfo(adName);
		cout << "///////////////////////////////////" << endl;
		cout << "1. Добавить объявление в избранные" << endl;
		cout << "2. Вернутся к списку жилья" << endl;
		cout << "3. В главное меню" << endl;
		cout << "Ваш выбор:";
		switch (GetInt(1, 3)) {
		case 1: {
			AddToMyList(adName, FileManager::GetBuyerlistPath());
			return;
		}
		case 2: {
			ShowAdList();
		}
		default: { break;

		}

		}
}

		void Buyer::FilterAds() {
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
			switch (GetInt(1, 3)) {
			case 1: {
				for (int i = 0; i < apartments.size() - 1; i++) {
					if (apartments[i].get_repair() == true) {
						cout << apartments[i] << endl;
					}
				}
				system("pause");
				break;
			}
			case 2: {
				for (int i = 0; i < apartments.size() - 1; i++) {
					if (apartments[i].get_secondaryHousing() == false) {
						cout << apartments[i] << endl;
					}
				}
				system("pause");
				break;
			}
			case 3: {
				for (int i = 0; i < apartments.size() - 1; i++) {
					if (apartments[i].get_parking() == true) {
						cout << i << " " << apartments[i] << endl;
					}
				}
				system("pause");
				break;
			}
			default: break;
			}
		}

void Buyer::ShowMyList(){
	string str;
	int num = 1;
	vector <Aparts> my_aparts;
	ifstream infile(FileManager::GetBuyerlistPath() + login);
	infile.seekg(0, ios::beg);
	if (!infile.is_open()) {
		cout << "Could not open file!" << endl;
		system("pause");
		return;
	}

	while (getline(infile, str)) {
		Aparts apartment;
		infile >> str;
		cout << num << " " << str << endl;
		apartment.GetAdInfo(str);
		my_aparts.push_back(apartment);
		num += 1;
	}
	infile.close();
	if (my_aparts.size() == 0) {
		cout << "Список объявлений пуст" << endl;
		system("pause");
		return;
	}
	while (true) {
		cout << "Введите номер объявления для его просмотра, либо 0 для выхода в меню:";
		cin >> num;
		if (num == 0) {
			return;
		}
		else if (num < my_aparts.size() || num > 0) {
			ViewAd(my_aparts[num - 1].GetAdName());
		}
		else cout << "Неверный ввод, повторите попытку..." << endl;
	}
}

//void Buyer::CreateAdList() {
//	fstream fs;
//	fs.open(FileManager::GetBuyerlistPath() + ConvertMasCharToString(login), ios::out | ios::trunc | ios::binary);
//	fs.close();
//}



//
//bool Buyer::CheckAdList(string adname)
//{
//	fstream fs;
//	string temp;
//	char check[200];
//	char _adname[200];
//	ConvertStringToMasChar(adname, _adname);
//
//	fs.open(FileManager::GetBuyerlistPath() + login, ios::in | ios::binary);
//	while (!fs.eof()) {
//		fs.read((char*)&check, sizeof(char) * 200);
//		if (check == _adname) {
//			fs.close();
//			return true;
//		}
//	}
//	fs.close();
//	return false;
//}


