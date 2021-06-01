#include "Aparts.h"

Aparts::Aparts() {

}

Aparts::Aparts(string adname) {
	cout << "Введите описание квартиры" << endl;
	
	cin >> _description;
	cout << "Адрес квартиры: ";
	cin >> _location;
	cout << "Площадь квартиры м/2:";
	cin >> _apartmentSize;
	cout << "Цена, руб: ";
	cin >> _price;
	cout << "Количество комнат: ";
	cin >> _numberOfRooms;
	cout << "Этаж: ";
	cin >> _floor;
	cout << "Год сдачи дома: ";
	cin >> _year;
	cout << "Вторичное жилье \n1.Да \n0.Нет" << endl;
	cin >> _secondaryHousing;
	cout << "Наличие парковки \n1.Да \n0.Нет" << endl;
	cin >> _parking;
	cout << "Наличие ремонта \n1.Да \n0.Нет" << endl;
	cin >> _repair;
	_adname = adname;

}
Aparts::~Aparts() {

}


void Aparts::SaveAd(string adname) {
	fstream fs;
	fs.open(FileManager::GetApartPath() + adname, ios::out | ios::trunc | ios::binary);
	fs << _repair << "\n";
	fs << _secondaryHousing << "\n";
	fs << _parking << "\n";
	fs << _price << "\n";
	fs << _year << "\n";
	fs << _numberOfRooms << "\n";
	fs << _floor << "\n";
	fs << _apartmentSize << "\n";
	fs << _location << "\n";
	fs << _description << "\n";
	fs.close();

}
void Aparts::GetAdInfo(string adName) {
	fstream fs;
	fs.open(FileManager::GetApartPath() + adName, ios::in | ios::binary);
	fs >> _repair;
	fs >> _secondaryHousing;
	fs >> _parking ;
	fs >> _price;
	fs >> _year;
	fs >> _numberOfRooms;
	fs >> _floor;
	fs >> _apartmentSize;
	fs >> _location;
	fs >> _description;
	_adname = adName;
	fs.close();

}

void Aparts::ShowAdInfo(string adName){
	
	cout << _adname << endl;
	cout << "Цена: " << _price << endl;
	cout << "Описание квартиры:\n" << _description << endl;
	cout << "Адрес: " << _location << endl;
	cout << "Этаж: " << _floor << endl;
	cout << "Количество комнат: " << _numberOfRooms << endl;
	cout << "Площадь квартиры, м/2 :" << _apartmentSize << endl;
	cout << "Год сдачи дома: " << _year << endl;
	cout << "Отличительне особенности:" << endl;
	if (_parking == true) {
		cout << "Присутствует парковочное место" << endl;
	}
	if (_secondaryHousing == false) {
		cout << "Новостройка" << endl;
	}
	if (_repair == true) {
		cout << "Есть ремонт" << endl;
	}

}

string Aparts::GetAdName() {
	return _adname;
}

void Aparts::EditInfo() {
	int key;
	bool atr;
	cout << _adname << endl;
	cout << "Цена" << _price << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) cin >> _price;

	cout << "Описание квартиры:\n" << _description << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) cin >> _description;

	cout << "Адрес:" << _location << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) cin >> _location;

	cout << "Этаж" << _floor << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) cin >> _floor;

	cout << "Количество комнат" << _numberOfRooms << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) cin >> _numberOfRooms;

	cout << "Площадь квартиры, м/2" << _apartmentSize << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) cin >> _apartmentSize;

	cout << "Год сдачи дома:" << _year << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) cin >> _year;

	cout << "Отличительне особенности:" << endl;
	if (_parking == true) {
		cout << "Присутствует парковочное место" << endl;
	}
	else cout << "Парковочное место отсутствует" << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) {
		_parking = !_parking;
	}

	if (_secondaryHousing == false) {
		cout << "Новостройка" << endl;
	}
	else cout << "Вторичное жилье" << endl; 
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) {
		_secondaryHousing = !_secondaryHousing;
	}

	if (_repair == true) {
		cout << "Есть ремонт" << endl;
	}
	else cout << "Без ремонта" << endl;
	cout << "Изменить? \n1.Да\nДругая цифра - Нет" << endl;
	cin >> key;
	if (key == 1) {
		_repair = !_repair;
	}
	
}
std::ostream& operator<< (std::ostream& out, const Aparts& apart) {
	out << apart._adname << "\n";
	return out;
}
