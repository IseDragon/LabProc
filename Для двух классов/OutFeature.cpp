#include "Feature.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void OutFeature(feature &f, ofstream &ofst) {
	ofst << "It is feature film." << endl;
	ofst << "Its director is = " << f.director << endl;
}