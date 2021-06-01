#include "MenuManager.h"

namespace ShowMenu {
	void ShowMainMenu() {

		cout << "1. Войти как покупатель" << endl;
		cout << "2. Войти как риэлтор" << endl;
	/*	cout << "3. Войти как Администратор" << endl;*/
		cout << "3. Выход из программы" << endl;
	}

	/*void ShowAdminMenu() {
		cout << "1. Добавить покупателя" << endl;
		cout << "2. Добавить риэлтора" << endl;
		cout << "3. Выход из программы" << endl;
	}*/

	void ShowRealtorMenu() {
		cout << "1. Добавить объявление о продаже" << endl;
		cout << "2. Просмотреть мои объявления" << endl;
		cout << "3. Просмотреть все объявления" << endl;
		cout << "4. Удалить этот аккаунт" << endl;
		cout << "5. Выход из программы" << endl;
	}

	void ShowBuyerMenu() {
		cout << "1. Просмотреть все объявления" << endl;
		cout << "2. Поиск квартиры по фильтрам" << endl;
		cout << "3. Просмотр списка избранного жилья" << endl;
		cout << "4. Удалить этот аккаунт" << endl;
		cout << "5. Выход из программы" << endl;
	}

	void ShowFilterMenu() {
		cout << "Фильтровать квартиры по:" << endl;
		cout << "1. Наличию ремонта" << endl;
		cout << "2. Только новое жилье" << endl;
		cout << "3. Наличию парковки" << endl;
		
	}
}

namespace Working {
	/*bool LoginAsAdmin() {
		string login;
		while (true) {
			cout << "Введите логин" << endl;
			cin >> login;
			if (login == "ADMIN") {
				break;
			}
			else {
				cout << "Введен неверный логин, повторить попытку? \n1. Да \n2. Нет" << endl;
				if (GetInt(1, 2) == 2) {
					return false;
				}
			}
		}
		string password;
		while (true) {
			cout << "Введите пароль:";
			cin >> password;
			if (password == "098098") {
				cout << "Вход произведен...\n\n" << endl;
				break;
			}
			else {
				cout << " Пароль введен неверно, повторить? \n1. Да\n2. Нет" << endl;
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
				cout << "1.Войти\n2.Зарегистрироваться" << endl;
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
				cout << "1.Войти\n2.Зарегистрироваться" << endl;
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