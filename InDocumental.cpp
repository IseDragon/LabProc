#include "Documental.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void InDocumental(documental &d, ifstream &ifst)
{
	ifst >> d.year;
}