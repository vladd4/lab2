#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#define MAX_STORAGE 100

using namespace std;

string appendInfo(string* array, int number, string date_s, string date_e, string name, int price);
void dateToInt(int& day, int& month, int& year, string date);
void input(string date_p, string date_e, string* &array1, string* &array2, int &num1, int &num2);
void inputFile(string* array1, int num);
void outputFile(string *array2, int num);
void fdelete(const char* inf, const char* outf);

struct items {
	string name;
	int day = 0;
	int month = 0;
	int year = 0;

	int day_e = 0;
	int month_e = 0;
	int year_e = 0;

	int price = 0;
};
