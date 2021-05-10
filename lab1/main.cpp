#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale>
#include <stdio.h>
#include <Windows.h>

#include "Data.h"
#include "functions.h"
#include "lib.h"

#define path "data.txt" // path to file

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	FILE* data;
	int n = 0;
	char prot[10];

	lib* arr = (lib*)malloc(n * sizeof(lib));
	lib** parr = &arr;

	// Load/create database
	if ((data = fopen(path, "r")) == 0)
	{
		printf("Файл не открылся!\n");
		if (!(data = fopen(path, "a")) == 0)
		{
			printf("Создание нового файла!\n");
			createData(parr, &n, &data);
			fclose(data);
		}
		else
		{
			printf("Обратитесь к администратору!\n");
			return 0;
		}
	}
	else
	{
		data = fopen(path, "r");
		loadData(arr, &n, data);
		fclose(data);
	}

	// Menu
	do
	{
		int menu;

		printMenu();
		printf("Выберите пункт меню: ");
		scanf("%1d", &menu);

		gets_s(prot);//??????

		switch (menu)
		{
		case 1:
			data = freopen(path, "a", data);
			addDoctor(arr, &n, data);
			break;
		case 2:
			findDoctor(arr, n);
			break;
		case 3:
			filterDoctor(arr, n);
			break;
		case 4:
			sortData(arr, n);
			break;
		case 5:
			printAllDoctors(arr, n);
			break;
		case 6:
			data = freopen(path, "a", data);
			saveData(arr, n, data);
			fclose(data);
			free(arr);
			return 0;
		default:
			printf("Введенный вами пункт меню не существует\n");
			break;
		}
	} while (TRUE);
}