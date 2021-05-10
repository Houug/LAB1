#pragma once
#include <stdio.h>
#include "lib.h"

int checkInput(int n, int mode);
void printHeader();
void printMenu();
void addDoctor(lib*& m, int* n, FILE* data);
void printDoctor(lib* m, int n);
void printAllDoctors(lib* m, int n);
lib findDoctor(lib* m, int n);
void filterDoctor(lib* m, int n);
void sortData(lib* m, int n);