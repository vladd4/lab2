#include "f_binary.h"

int main()
{
	string dateprod;
	string dateend;
	string* input_info;
	input_info = new string[MAX_STORAGE];
	string* input_info2;
	input_info2 = new string[MAX_STORAGE];
	int num = 0;
	int num2 = 0;
	char flag;

	input(dateprod, dateend, input_info, input_info2, num, num2);
	cout << "\nEnter Y/N to append info: ";
	cin >> flag;
	cin.ignore();
	if (flag == 'Y') {
		input(dateprod, dateend, input_info, input_info2, num, num2);
	}
	inputFile(input_info, num);
	outputFile(input_info2, num2);
	fdelete("input.dat", "output.dat");

	//delete[] input_info;
	//delete[] input_info2;
}

