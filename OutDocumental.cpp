#include "Documental.h"
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

void OutDocumental(documental &d, ofstream &ofst) {
	ofst << "It is Documental film." << endl;
	ofst << "It was filmed in = " << d.year << endl;
}