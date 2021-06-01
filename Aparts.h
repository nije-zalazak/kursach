#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "FileManager.h"
#include "ISCworker.h"

class Aparts {
private:
	bool _parking;
	bool _secondaryHousing;
	bool _repair;
	int _floor;
	int _price;
	int _year;
	int _numberOfRooms;
	int _apartmentSize;
	//char _adname[200];
	//char _location[200];
	//char _description[200];
	string _adname;
	string _location;
	string _description;
public:
	
	Aparts();
	Aparts(string adname);
	~Aparts();

	bool get_parking() { return _parking; }
	bool get_secondaryHousing() { return _secondaryHousing; }
	bool get_repair() { return _repair; }
	/*int get_price() { return _price; }
	int get_numberOfRooms() { return _numberOfRooms; }
	int get_apartmentSize() { return _apartmentSize; }
	*/
	void SaveAd(string adname);
	void GetAdInfo(string adName);
	void ShowAdInfo(string adName);
	void EditInfo();

	string GetAdName();
	

	friend std::ostream& operator<< (std::ostream& out, const Aparts& aparts);
};