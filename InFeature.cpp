#include "Feature.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void InFeature(feature &f, ifstream &ifst)
{
	ifst.getline(f.director, 256);
}