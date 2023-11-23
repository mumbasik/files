// files.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;
#define MAX 190
void delstr(FILE* src, FILE* res) {
	char str[MAX];
	char x[MAX] = " ";
	while (fgets(str, MAX, src) != 0) {
		if (strlen(x) != '\0') {
			fputs(x, res);
			
		}
		strcpy(x, str);
	}
	
	
}
void deletstr(FILE* del, FILE *res) {
	char str[MAX];
	int x = 0;
	int count = 0;
	while (fgets(str, MAX, del) != 0) {
		if (x % 2 != 0) {
			count++;
			fputs( str , res);

		}
		x++;
		
	}
	cout << "Count of substrings: " << count << endl;
}

	
	
int main()
{
	
	const char* delsame = "Source.txt";
	const char* res = "Tex.txt";
	const char* del = "Source1.txt";
	const char* res2 = "Result2.txt";
	FILE* filesame, * fileX;
	FILE* filedel, * fileR;

	if (fopen_s(&filesame , delsame, "r") != NULL) {
		cout << "Can't open: ";
	}
	else if (fopen_s(&fileX, res, "w") != NULL) {
		cout << "Can't open: ";
	}
	else {
		deletstr(filesame, fileX);
		fclose(filesame);
		fclose(fileX);
	}
	if (fopen_s(&filedel, del, "r") != 0) {
		cout << "Can't open: ";
	}
	else if (fopen_s(&fileR, res2, "w") != 0) {
		cout << "Can't open: ";
	}
	else {
		delstr(filedel, fileR);
		fclose(filedel);
		fclose(fileR);

		
	}
}


