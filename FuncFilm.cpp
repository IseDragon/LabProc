#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Film.h"

using namespace std;

int FuncFilm(film *f) {
	char glasnie[] = "aeiouAEIOU�����������������ި�";
	int kol = 0;
	for (int i = 0; i < strlen(f->name); ++i) {
		if (strchr(glasnie, f->name[i])) {
			++kol;
		}
	}
	return kol;
}