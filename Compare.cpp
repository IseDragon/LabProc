#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Film.h"

using namespace std;

int FuncFilm(film *f);

bool Compare(film* f1, film* f2)
{
	return (FuncFilm(f1) > FuncFilm(f2));
}