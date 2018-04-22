#include "Feature.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

void InFeature(feature &f, ifstream &ifst)
{
	CheckInputFile(ifst);
	ifst.getline(f.director, 256);
	CheckWrongInput(ifst);
}