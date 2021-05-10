#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale>
#include <stdio.h>
#include <Windows.h>

int checkInput(int n, int mode)
{
	if (mode == 0)
	{
		switch (n)
		{
		case 1:
			return 1;
		case 2:
			return 1;
		case 3:
			return 1;
		default:
			return 0;
		}
	}
	if (mode == 1)
	{
		switch (n)
		{
		case 0:
			return 1;
		case 1:
			return 1;
		case 2:
			return 1;
		default:
			return 0;
		}
	}

}
void printHeader()
{
	printf("\n========================================================================\n");
	printf("%40s %15s %15s\n", "�.�.� �����", "C������������", "������������");
	printf("========================================================================\n");
}
void printMenu()
{
	printf("\n\n***************����**************\n");
	printf("1 - �������� ����� � ����\n2 - ����� ����� �� �.�.�\n3 - ����� ������ �� ������������� � ������������\n4 - ���������� ���� �� ��������\n5 - ����� ���� � �������\n6 - ����� �� ���������");
	printf("\n*********************************\n");
}
void addDoctor(lib*& m, int* n, FILE* data)
{
	*n += 1;
	m = (lib*)realloc(m, *n * sizeof(lib));

	char bufName[20], bufSurname[20], bufFather[20], buf[60];

	printf("���� �������: ");
	scanf("%[a-z,A-Z,�-�,�-�,0-9]s", bufSurname);
	gets_s(buf);//?????

	printf("���� ���: ");
	scanf("%[a-z,A-Z,�-�,�-�,0-9]s", bufName);
	gets_s(buf);//?????

	printf("���� ��������: ");
	scanf("%[a-z,A-Z,�-�,�-�,0-9]s", bufFather);
	gets_s(buf);//?????

	strcpy(buf, bufSurname);
	strcat(buf, " ");
	strcat(buf, bufName);
	strcat(buf, " ");
	strcat(buf, bufFather);

	int i = *n - 1;
	m[i].fio = (char*)malloc((strlen(buf) + 1) * sizeof(char));
	strcpy(m[i].fio, buf);

	do
	{
		printf("������� �������������: ");
		scanf("%1d", &m[i].specialty);

		gets_s(buf);//?????

	} while (checkInput(m[i].specialty, 0) == 0);

	do
	{
		printf("������� ������������: ");
		scanf("%d", &m[i].qualification);

		gets_s(buf);//?????

	} while (checkInput(m[i].qualification, 1) == 0);

	fprintf(data, "%s %d %d\n", m[i].fio, m[i].specialty, m[i].qualification);
}
void printDoctor(lib* m, int n)
{
	char specialty[11], qualification[7];

	//printf("%d %d", m[n].specialty, m[n].qualification);

	switch (m[n].specialty)
	{
	case 1:
		strcpy(specialty, "��������");
		break;
	case 2:
		strcpy(specialty, "���������");
		break;
	case 3:
		strcpy(specialty, "����������");
		break;
	default:
		strcpy(specialty, "NAN");
		break;
	}
	switch (m[n].qualification)
	{
	case 0:
		strcpy(qualification, "������");
		break;
	case 1:
		strcpy(qualification, "������");
		break;
	case 2:
		strcpy(qualification, "������");
		break;
	default:
		strcpy(qualification, "NAN");
		break;
	}
	printf("%40s %15s %15s\n", m[n].fio, specialty, qualification);
}
void printAllDoctors(lib* m, int n)
{
	printHeader();
	for (int i = 0; i < n; i++)
	{
		printDoctor(m, i);
	}
}
lib findDoctor(lib* m, int n)
{
	char buf[60];
	int count = 0;
	lib foundDoctor[1];
	printf("������� �.�.� �����: ");
	gets_s(buf);

	for (int i = 0; i < n; i++)
	{
		if (strncmp(buf, m[i].fio, strlen(buf)) == 0)
		{
			count++;
			foundDoctor[0] = m[i];
			break;
		}
	}
	if (count == 0) printf("����� �� ����� ���������\n");
	else
	{
		printHeader();
		printDoctor(foundDoctor, 0);
		//printf("%s\n", foundDoctor[0].fio);
		return foundDoctor[0];
	}
}
void filterDoctor(lib* m, int n)
{
	char def[10];
	int spec = 0, qual = 0;
	int count = 0;
	do
	{
		printf("������� �������������: ");
		scanf("%1d", &spec);
		gets_s(def); //?????
	} while (checkInput(spec, 0) == 0);

	do
	{
		printf("������� ������������: ");
		scanf("%1d", &qual);
		gets_s(def); //?????
	} while (checkInput(spec, 0) == 0);

	printHeader();
	for (int i = 0; i < n; i++)
	{
		if ((spec == m[i].specialty) && (qual == m[i].qualification))
		{
			printDoctor(m, i);
			count++;
		}
	}
	if (count == 0) printf("����� �� ����� ���������\n");
}
void sortData(lib* m, int n)
{
	int min;
	lib temp;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(m[min].fio, m[j].fio) > 0)
			{
				min = j;
			}
		}

		temp = m[i];
		m[i] = m[min];
		m[min] = temp;
	}
}