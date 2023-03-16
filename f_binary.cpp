#include "f_binary.h"

string appendInfo(string* array, int number, string date_s, string date_e, string name, int price) {
	array[number] = name;
	array[number].append(" (");
	array[number].append(date_s);
	array[number].append(" - ");
	array[number].append(date_e);
	array[number].append(") ");
	array[number].append(to_string(price));
	array[number].append(" UAN ");
	return array[number];
}

void dateToInt(int& day, int& month, int& year, string date) {
	day = stoi(date.substr(0, 2));
	month = stoi(date.substr(3, 5));
	year = stoi(date.substr(6, 10));
}

void input(string date_p, string date_e, string* &array1, string* &array2, int& num1, int& num2) {
	items products;
	cout << "Enter info to add: ";
	char flag = ' ';
	while (flag != 'N') {
		cout << "Enter name: ";
		getline(cin, products.name);
		cout << "Enter data of production (dd.mm.yyyy): ";
		getline(cin, date_p);
		cout << "Enter data of end (dd.mm.yyyy): ";
		getline(cin, date_e);
		cout << "Enter price: ";
		cin >> products.price;
		cin.ignore();

		dateToInt(products.day, products.month, products.year, date_p);
		dateToInt(products.day_e, products.month_e, products.year_e, date_e);
		
		appendInfo(array1, num1, date_p, date_e, products.name, products.price);

		int termin = (products.day_e + (products.month_e * 30) + (products.year_e) * 365) - (products.day + (products.month * 30) + (products.year) * 365);

		cout << "Termin prudatnosti - " << termin << endl;

		if (termin <= 14) {
			products.price -= (5 * products.price) / 100;
		}
		else if (termin > 365) {
			products.price += (3 * products.price) / 100;
		}

		termin = 0;
		//products.price = (int)products.price;
		if (products.month < 3 && products.year <= 2023) {
			appendInfo(array2, num2, date_p, date_e, products.name, products.price);
			num2++;
		}
		products = {};

		cout << "Enter Y/N to continue: ";
		cin >> flag;
		cin.ignore();
		num1++;
	}
}

void inputFile (string *array1, int num) {
	ofstream fout("input.dat", ios::binary | ios::app);
	int num3 = 0;
	if (!fout.is_open()) {
		cout << "Error! File isn`t opened!" << endl;
	}
	else {
		cout << "\nAdding data to the input file..." << endl;
		for (int i = 0; i < num; i++) {
			fout.write((char*)&array1[i], sizeof(array1[i]));
		}
	}
	fout.close();

	string data[MAX_STORAGE];
	ifstream fin("input.dat", ios::binary);
	if (!fin.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		cout << "Requesting data from the input file..." << endl;
		for (int i = 0; i < num; i++) {
			fin.read((char*)&data[i], sizeof(string));
			cout << data[i] << endl;
		}
	}
	fin.close();
}

void outputFile (string *array2, int num) {
	ofstream fout2("output.dat", ios::binary);
	if (!fout2.is_open()) {
		cout << "Error! File isn`t opened!" << endl;
	}
	else {
		cout << "\nAdding data to the output file..." << endl;
		if (num == 0) cout << "No data to add." << endl;
		else {
			for (int i = 0; i < num; i++) {
				fout2.write((char*)&array2[i], sizeof(array2[i]));
			}
		}
	}
	fout2.close();

	string data2[MAX_STORAGE];
	
	ifstream fin2("output.dat", ios::binary);
	if (!fin2.is_open()) {
		cout << "Error!" << endl;
	}
	else {
		if (num == 0) cout << "No data to read!" << endl;
		else {
			cout << "Requesting data from the output file..." << endl;
			for (int i = 0; i < num; i++) {
				fin2.read((char*)&data2[i], sizeof(array2[i]));
				cout << data2[i] << endl;
			}
		}
	}
	fin2.close();
}

void fdelete(const char* inf, const char* outf) {
	char mode;
	cout << "\nEnter Y to delete files: ";
	cin >> mode;
	cin.ignore();
	if (mode == 'Y') {
		remove(inf);
		remove(outf);
		cout << "Files were deleted successfully! " << endl;
	}
}