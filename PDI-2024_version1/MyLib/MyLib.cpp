#include <iostream>
#include <Windows.h>
#include <string>
#pragma warning(disable: 4996)
extern "C" {
	int __stdcall getmin(int f, int s) {
		return f < s ? f : s;
	}

	int __stdcall getmax(int f, int s) {
		return f > s ? f : s;
	}

	int __stdcall printss(int type, char* str) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "Rus");
		if (type == 1) { // INT
			unsigned int value = *reinterpret_cast<unsigned int*>(str);
			std::cout << value;
		}
		else if (type == 2) { // DOUBLE
			double value = *reinterpret_cast<double*>(str);
			std::cout << value;
		}
		else if (type == 3) { // BOOL
			bool value = *reinterpret_cast<bool*>(str);
			std::cout << (value ? "true" : "false");
		}
		else if (type == 4) { // STRING
			std::cout << str;
		}
		return 0;
	}

	int __stdcall printssln(int type, char* str) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "Rus");
		if (type == 1) { // INT
			unsigned int value = *reinterpret_cast<unsigned int*>(str);
			std::cout << value << std::endl;
		}
		else if (type == 2) { // DOUBLE
			double value = *reinterpret_cast<double*>(str);
			std::cout << value << std::endl;
		}
		else if (type == 3) { // BOOL
			bool value = *reinterpret_cast<bool*>(str);
			std::cout << (value ? "true" : "false") << std::endl;
		}
		else if (type == 4) { 
			std::cout << str << std::endl;
		}
		return 0;
	}

	int __stdcall readss(int type, char* value) {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		if (type == 1) { // INT
			unsigned int val;
			std::cin >> val;
			if ((val >= 0) && (val <= 4294967295))
			{
				*(unsigned int*)value = val;
				return 0;
			}
			return -1;
		}
		else if (type == 2) { // DOUBLE
			double val;
			std::cin >> val;
			if ((val >= DBL_MIN) && (val <= DBL_MAX))
			{
				*(double*)value = val;
				return 0;
			}
			return -1;
		}
		else if (type == 3) { // BOOL
			char bu[128];
			std::cin.getline(bu, 128);
			if (strlen(bu) == 0) {
				std::cin.getline(bu, 128);
			}
			if (!std::strcmp(bu, "true"))
			{
				*value = 1;
				return 0;
			}
			if (!std::strcmp(bu, "false"))
			{
				*value = 0;
				return 0;
			}
			return -1;
		}
		else if (type == 4) { // STRING
			std::cin.getline(value, 128);
			if (strlen(value) == 0) {
				std::cin.getline(value, 128);
			}
			return 0;
		}
		return -1;
	}

	int __stdcall compare(char* f, char* s) {
		return (int)strcmp(f, s) + 1;
	}

	int __stdcall len(char* f) {
		return strlen(f);
	}

	int __stdcall waitPause() {
		system("pause");
		return 0;
	}

	int __stdcall compnum(int type1, char* f, int type2, char* s, char op) {
		if (type1 == 1) {
			unsigned int val1 = *reinterpret_cast<unsigned int*>(f);
			if (type2 == 1) {
				unsigned int val2 = *reinterpret_cast<unsigned int*>(s);
				if (op == '>') {
					return (int)(val1 > val2);
				}
				if (op == '<') {
					return (int)(val1 < val2);;
				}
				if (op == 'e') {
					return (int)(val1 >= val2);;
				}
				if (op == 'o') {
					return (int)(val1 <= val2);;
				}
				if (op == 'n') {
					return (int)(val1 != val2);;
				}
				if (op == 'c') {
					return (int)(val1 == val2);;
				}
			}
			else if (type2 == 2) {
				double val2 = *reinterpret_cast<double*>(s);
				if (op == '>') {
					return (int)(val1 > val2);
				}
				if (op == '<') {
					return (int)(val1 < val2);;
				}
				if (op == 'e') {
					return (int)(val1 >= val2);;
				}
				if (op == 'o') {
					return (int)(val1 <= val2);;
				}
				if (op == 'n') {
					return (int)(val1 != val2);;
				}
				if (op == 'c') {
					return (int)(val1 == val2);;
				}
			}
			else {
				return -1;
			}
		}



		if (type1 == 2) {
			double val1 = *reinterpret_cast<double*>(f);
			if (type2 == 2) {
				double val2 = *reinterpret_cast<double*>(s);
				if (op == '>') {
					return (int)(val1 > val2);
				}
				if (op == '<') {
					return (int)(val1 < val2);;
				}
				if (op == 'e') {
					return (int)(val1 >= val2);;
				}
				if (op == 'o') {
					return (int)(val1 <= val2);;
				}
				if (op == 'n') {
					return (int)(val1 != val2);;
				}
				if (op == 'c') {
					return (int)(val1 == val2);;
				}
			}
			else if (type2 == 1) {
				unsigned int val2 = *reinterpret_cast<unsigned int*>(s);
				if (op == '>') {
					return (int)(val1 > val2);
				}
				if (op == '<') {
					return (int)(val1 < val2);;
				}
				if (op == 'e') {
					return (int)(val1 >= val2);;
				}
				if (op == 'o') {
					return (int)(val1 <= val2);;
				}
				if (op == 'n') {
					return (int)(val1 != val2);;
				}
				if (op == 'c') {
					return (int)(val1 == val2);;
				}
			}
			else {
				return -1;
			}
		}




		if (type1 == 3) {
			bool val1 = *reinterpret_cast<bool*>(f);
			if (type2 == 3) {
				bool val2 = *reinterpret_cast<bool*>(s);
				if (op == '>') {
					return (int)(val1 > val2);
				}
				if (op == '<') {
					return (int)(val1 < val2);;
				}
				if (op == 'e') {
					return (int)(val1 >= val2);;
				}
				if (op == 'o') {
					return (int)(val1 <= val2);;
				}
				if (op == 'n') {
					return (int)(val1 != val2);;
				}
				if (op == 'c') {
					return (int)(val1 == val2);;
				}
			}
			else {
				return -1;
			}
		}
		return -1;
	}

}
