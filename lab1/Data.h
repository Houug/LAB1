#pragma once
#include <stdio.h>
#include "lib.h"
#include "functions.h"

void loadData(lib*& m, int* n, FILE* data);
void createData(lib**& m, int* n, FILE** data);
void saveData(lib* m, int n, FILE* data);