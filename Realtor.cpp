#include "Realtor.h"

Realtor::Realtor() {
	password[0] = '\0';
	login[0] = '\0';
}

Realtor::Realtor(const Realtor& obj) : User(obj) {
}

Realtor::~Realtor() {
}

void Realtor::MakeAd() {
		//у риэлтора есть метод добавить обь€вление.там вводитс€
		//вс€ нужна€ инфа, создаетс€ обьект класса ќбь€вление,
		//в него передаетс€ вс€ та инфа, и он сохран€етс€ в файл.
		//и плюс еще в промежуточный файл с именем риэлтора записать название обь€вки.
	char AdName[200];
	bool saveName = false;
	while (saveName == false) {
		cout << "¬ведите название объ€влени€():" << endl;
		cin.ignore(100, '\n');
		cin.getline(AdName,200);
		cout << "—охранить название? \n1.ƒа \n2.Ќет" << endl;
		if (GetInt(1, 2) == 1) {
			saveName = true;
		}
	}
	Aparts ad = Aparts::Aparts(ConvertMasCharToString(AdName));
	AddToMyList(ConvertMasCharToString(AdName), FileManager::GetRealtorlistPath());
	cout << "ќбъ€вление добавлено в список ваших объ€влений" << endl;
	ad.SaveAd(ConvertMasCharToString(AdName));


}



void Realtor::ViewAd(string adName) {
	Aparts ad;
	ad.GetAdInfo(adName);
	ad.ShowAdInfo(adName);
	while (true) {
		cout << "///////////////////////////////////" << endl;
		if (CheckAdList(adName)) {
			cout << "1. ¬ернутс€ к списку жиль€" << endl;
			cout << "2. –едактировать объ€вление" << endl;
			cout << "3. ”далить объ€вление" << endl;
			cout << "¬аш выбор:";
			switch (GetInt(1, 3)) {
			case 1: {
				break; }
			case 2: {
				ad.EditInfo();
				ad.SaveAd(adName);
				break;
			}
			case 3: {
				DeleteAd(adName);
				break;
			}
			default: break;
			}
		}
		else {
			system("pause");
			break;
		}
		
		
	}


}


string Realtor::GetLogin() {
	return ConvertMasCharToString(login);
}


void Realtor::ShowMyList() {
	string str;
	int num = 1;
	vector <Aparts> my_aparts;
	ifstream infile(FileManager::GetRealtorlistPath() + login);
	infile.seekg(0, ios::beg);
	if (!infile.is_open()) {
		cout << "Could not open file!" << endl;
		return;
	}

	while (getline(infile, str)) {
		Aparts apartment;
		cout << num << " " << str << endl;
		apartment.GetAdInfo(str);
		my_aparts.push_back(apartment);
		num += 1;
	}
	infile.close();
	if (my_aparts.size() == 0) {
		cout << "—писок объ€влений пуст" << endl;
		system("pause");
		return;
	}
	while (true) {
		cout << "¬ведите номер объ€влени€ дл€ его просмотра, либо 0 дл€ выхода в меню:";
		cin >> num;
		if (num == 0) {
			return;
		}
		else if (num < my_aparts.size() || num > 0) {
			ViewAd(my_aparts[num - 1].GetAdName());
		}
		else cout << "Ќеверный ввод, повторите попытку..." << endl;
	}	
}

void Realtor::DeleteAd(string adname) {
	fstream fs;
	string temp;
	vector<string> adlist;
	if (exists(FileManager::GetApartPath() + adname)) {
		remove(FileManager::GetApartPath() + adname);
	}
	fs.open(FileManager::GetRealtorlistPath() + login, ios::in | ios::binary);
	while (fs.eof()) {
		fs >> temp;
		adlist.push_back(temp);
	}
	fs.close();
	remove(FileManager::GetRealtorlistPath() + login);
	fs.open(FileManager::GetRealtorlistPath() + login, ios::out | ios::trunc | ios::binary);
	for(int i = 0; adlist.size()-1 > i; i++) {
		if (adname !=adlist[i]) {
			fs << adlist[i];
		}
	}
	fs.close();
}


bool Realtor::CheckAdList(string adname) {
	string check;
	ifstream infile(FileManager::GetRealtorlistPath() + login);
	while (getline(infile, check)) {
		infile >> check;
		if (check == adname) {
			infile.close();
			return true;
		}
	}
	infile.close();
	return false;
}
//void Realtor::ShowMyList(){
//	system("cls");
//	vector<Aparts> apartments;
//	vector<Aparts> my_aparts;
//	int adNum;
//	string choice;
//	for (const auto& entry : directory_iterator(FileManager::GetApartPath()))
//	{
//		Aparts apartment;
//		apartment.GetAdInfo(entry.path().stem().string());
//		apartments.push_back(apartment);
//	}
//	if (apartments.size() <= 0) {
//		cout << "ќбъ€влени€ отсутствуют!" << endl;
//		return;
//	}
//	else {
//		for (int i = 0; i < apartments.size(); i++) {
//			if (CheckAdList(apartments[i].GetAdName())) {
//				my_aparts.push_back(apartments[i]);
//			}
//		}
//		cout << "—писок моих объ€влений:" << endl;
//		for (int i = 0; i < my_aparts.size(); i++) {
//			cout << "\t" << i + 1;
//			cout << my_aparts[i];
//		}
//	}
//	cout << "¬ведите номер объ€влени€ дл€ его просмотра:";
//	cin >> adNum;
//	choice = my_aparts[adNum].GetAdName();
//	ViewAd(choice);
//}
//bool Realtor::CheckAdList(string adName) {
//	fstream fs;
//	string temp;
//	char check[200];
//	char _adname[200];
//	ConvertStringToMasChar(adName, _adname);
//
//	fs.open(FileManager::GetRealtorlistPath() + login, ios::out ,ios::binary);
//	while (!fs.eof()) {
//		fs.read((char*)&check, sizeof(char) * 200);
//		if (check == _adname) {
//			fs.close();
//			return true;
//		}
//	}
//	fs.close();
//	return false;
//	
//	
//}
