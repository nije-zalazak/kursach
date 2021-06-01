#include "Aparts.h"

Aparts::Aparts() {

}

Aparts::Aparts(string adname) {
	cout << "������� �������� ��������" << endl;
	
	cin >> _description;
	cout << "����� ��������: ";
	cin >> _location;
	cout << "������� �������� �/2:";
	cin >> _apartmentSize;
	cout << "����, ���: ";
	cin >> _price;
	cout << "���������� ������: ";
	cin >> _numberOfRooms;
	cout << "����: ";
	cin >> _floor;
	cout << "��� ����� ����: ";
	cin >> _year;
	cout << "��������� ����� \n1.�� \n0.���" << endl;
	cin >> _secondaryHousing;
	cout << "������� �������� \n1.�� \n0.���" << endl;
	cin >> _parking;
	cout << "������� ������� \n1.�� \n0.���" << endl;
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
	cout << "����: " << _price << endl;
	cout << "�������� ��������:\n" << _description << endl;
	cout << "�����: " << _location << endl;
	cout << "����: " << _floor << endl;
	cout << "���������� ������: " << _numberOfRooms << endl;
	cout << "������� ��������, �/2 :" << _apartmentSize << endl;
	cout << "��� ����� ����: " << _year << endl;
	cout << "������������ �����������:" << endl;
	if (_parking == true) {
		cout << "������������ ����������� �����" << endl;
	}
	if (_secondaryHousing == false) {
		cout << "�����������" << endl;
	}
	if (_repair == true) {
		cout << "���� ������" << endl;
	}

}

string Aparts::GetAdName() {
	return _adname;
}

void Aparts::EditInfo() {
	int key;
	bool atr;
	cout << _adname << endl;
	cout << "����" << _price << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) cin >> _price;

	cout << "�������� ��������:\n" << _description << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) cin >> _description;

	cout << "�����:" << _location << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) cin >> _location;

	cout << "����" << _floor << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) cin >> _floor;

	cout << "���������� ������" << _numberOfRooms << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) cin >> _numberOfRooms;

	cout << "������� ��������, �/2" << _apartmentSize << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) cin >> _apartmentSize;

	cout << "��� ����� ����:" << _year << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) cin >> _year;

	cout << "������������ �����������:" << endl;
	if (_parking == true) {
		cout << "������������ ����������� �����" << endl;
	}
	else cout << "����������� ����� �����������" << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) {
		_parking = !_parking;
	}

	if (_secondaryHousing == false) {
		cout << "�����������" << endl;
	}
	else cout << "��������� �����" << endl; 
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) {
		_secondaryHousing = !_secondaryHousing;
	}

	if (_repair == true) {
		cout << "���� ������" << endl;
	}
	else cout << "��� �������" << endl;
	cout << "��������? \n1.��\n������ ����� - ���" << endl;
	cin >> key;
	if (key == 1) {
		_repair = !_repair;
	}
	
}
std::ostream& operator<< (std::ostream& out, const Aparts& apart) {
	out << apart._adname << "\n";
	return out;
}
