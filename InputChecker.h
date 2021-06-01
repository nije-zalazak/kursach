#pragma once
#include <iostream>
#include <string>
using namespace std;

bool TryParse(string str, int& value);

bool TryParse(string str, double& value);

int ReadInt();

bool AskForEnd();

double GetDouble();
double GetDouble(double min, double max);

string ReadDate();

int GetInt(int maxNumber);
int GetInt(int minNumber, int maxNumber);

template<class T>
void Swap(T& t1, T& t2);