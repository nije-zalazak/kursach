#include "MenuManager.h"

namespace ShowMenu {
	void ShowMainMenu() {

		cout << "1. ����� ��� ����������" << endl;
		cout << "2. ����� ��� �������" << endl;
	/*	cout << "3. ����� ��� �������������" << endl;*/
		cout << "3. ����� �� ���������" << endl;
	}

	/*void ShowAdminMenu() {
		cout << "1. �������� ����������" << endl;
		cout << "2. �������� ��������" << endl;
		cout << "3. ����� �� ���������" << endl;
	}*/

	void ShowRealtorMenu() {
		cout << "1. �������� ���������� � �������" << endl;
		cout << "2. ����������� ��� ����������" << endl;
		cout << "3. ����������� ��� ����������" << endl;
		cout << "4. ������� ���� �������" << endl;
		cout << "5. ����� �� ���������" << endl;
	}

	void ShowBuyerMenu() {
		cout << "1. ����������� ��� ����������" << endl;
		cout << "2. ����� �������� �� ��������" << endl;
		cout << "3. �������� ������ ���������� �����" << endl;
		cout << "4. ������� ���� �������" << endl;
		cout << "5. ����� �� ���������" << endl;
	}

	void ShowFilterMenu() {
		cout << "����������� �������� ��:" << endl;
		cout << "1. ������� �������" << endl;
		cout << "2. ������ ����� �����" << endl;
		cout << "3. ������� ��������" << endl;
		
	}
}

namespace Working {
	/*bool LoginAsAdmin() {
		string login;
		while (true) {
			cout << "������� �����" << endl;
			cin >> login;
			if (login == "ADMIN") {
				break;
			}
			else {
				cout << "������ �������� �����, ��������� �������? \n1. �� \n2. ���" << endl;
				if (GetInt(1, 2) == 2) {
					return false;
				}
			}
		}
		string password;
		while (true) {
			cout << "������� ������:";
			cin >> password;
			if (password == "098098") {
				cout << "���� ����������...\n\n" << endl;
				break;
			}
			else {
				cout << " ������ ������ �������, ���������? \n1. ��\n2. ���" << endl;
				if (GetInt(1, 2) == 2) return false;
				else continue;
			}
		}
		system("pause");
		return true;
	}

	void AdminMode() {
		while (true) {
			system("cls");
			ShowMenu::ShowAdminMenu();
			switch (GetInt(5)) {
			case 1: {
				FileManager::SignUpBuyer();
				break;
			}
			case 2: {
				FileManager::SignUpRealtor();
				break;
			}
			case 3: {
				return;
				
			}
			
			default: {
				break;
			}
				   system("cls");
			}

		}
	}*/

	void Auth() {
		bool exit_key = false;
		while (exit_key == false) {
			ShowMenu::ShowMainMenu();
			switch (GetInt(4)) {
			case 1: {
				int key;
				cout << "1.�����\n2.������������������" << endl;
				cin >> key;
				if (key == 1) {
					shared_ptr<Buyer> buyer = make_shared<Buyer>();
					if (buyer->LogIn(FileManager::GetBuyerPath())) {
						buyer->GetAccount(FileManager::GetBuyerPath());
						BuyerMode(*buyer);
					}
				}
				else if (key == 2) {

					shared_ptr<Buyer> buyer = make_shared<Buyer>();
					if (buyer->SignUp(FileManager::GetBuyerPath(),FileManager::GetBuyerlistPath())) {
						buyer->SaveAccount(FileManager::GetBuyerPath());
						BuyerMode(*buyer);
					}
				}
				break;
			}
			case 2: {
				int key;
				cout << "1.�����\n2.������������������" << endl;
				cin >> key;
				if (key == 1) {
					shared_ptr<Realtor> realtor = make_shared<Realtor>();
					if (realtor->LogIn(FileManager::GetRealtorPath())) {
						realtor->GetAccount(FileManager::GetRealtorPath());
						RealtorMode(*realtor);
					}
				}
				else if (key == 2) {
					shared_ptr<Realtor> realtor = make_shared<Realtor>();
					if (realtor->SignUp(FileManager::GetRealtorPath(), FileManager::GetRealtorlistPath())) {
						realtor->SaveAccount(FileManager::GetRealtorPath());
						RealtorMode(*realtor);
					}
				}
				break;
			}
			case 3: {
				exit_key = true;
				break;
			}
			default: {
				break;
			}
				   system("cls");
			}
		}
	}

	void BuyerMode(Buyer& buyer) {
		while (true) {
			system("cls");
			ShowMenu::ShowBuyerMenu();
			switch (GetInt(4)) {
			case 1: {
				buyer.ShowAdList();
				break;
			}
			case 2: {
				ShowMenu::ShowFilterMenu();
				buyer.FilterAds();
				break;
			}
			case 3: {
				buyer.ShowMyList();
				break;
			}
			case 4: {
				buyer.DeleteAccount(FileManager::GetBuyerPath(), FileManager::GetBuyerlistPath());
			}
			case 5: {
				return;
			}
			default: {break; }
			}
		}
	}

	void RealtorMode(Realtor& realtor) {
		while (true) {
			system("cls");
			ShowMenu::ShowRealtorMenu();
			switch (GetInt(5)) {
			case 1: {

				realtor.MakeAd();
				break;
			case 2: {
				realtor.ShowMyList();
				break;
			}
			case 3: {
				realtor.ShowAdList();
				break;
			}
			case 4: {
				realtor.DeleteAccount(FileManager::GetRealtorPath(), FileManager::GetRealtorlistPath());
			}
			case 5: {
				return;
			}
			default: break;
			}
			}
		}
	}
}