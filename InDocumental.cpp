#include "Documental.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

void InDocumental(documental &d, ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst >> d.year;
	CheckWrongInput(ifst);
	if (d.year <= 0 || d.year > 2018) {
		cerr << "Incorrect year of Documental film" << endl;
		exit(1);
	}
}