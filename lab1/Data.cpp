#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include "lib.h"
#include <stdio.h>
#include <string.h>
#include <xloctime>
#include <stdlib.h>
#include <iostream>

void loadData(lib*& m, int* n, FILE* data)
{
	int i = 0;
	printf("‘айл успешно открыт!\n");
	while (!feof(data))
	{
		char buf[60], bufName[20], bufSurname[20], bufFather[20];

		m = (lib*)realloc(m, (*n + 1) * sizeof(lib));

		fscanf(data, "%s %s %s %d %d", bufName, bufSurname, bufFather, &m[*n].specialty, &m[*n].qualification);

		strcpy(buf, bufName);
		strcat(buf, " ");
		strcat(buf, bufSurname);
		strcat(buf, " ");
		strcat(buf, bufFather);

		m[i].fio = (char*)malloc((strlen(buf) + 1) * sizeof(char));
		strcpy(m[i].fio, buf);

		*n += 1;
		i++;
	}
	*n -= 1;
}
void createData(lib**& m, int* n, FILE** data)
{
	char prot[10];
	printf("¬ведите кол-во позиций в базе: ");
	scanf("%2d", n);
	gets_s(prot);//?????

	for (int i = 0; i < *n;)
	{
		addDoctor(*m, &i, *data);
	}
}
void saveData(lib* m, int n, FILE* data)
{
	for (int i = 0; i < n; i++)
	{
		fprintf(data, "%s %d %d\n", m[i].fio, m[i].specialty, m[i].qualification);
	}
}