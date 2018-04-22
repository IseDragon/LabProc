#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Cartoon.h"

using namespace std;

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

void InCartoon(cartoon &c, ifstream &ifst) {
	CheckInputFile(ifst);
	int k;
	ifst >> k;
	CheckWrongInput(ifst);
	switch (k) {
	case 1:
		c.t = cartoon::type::PAINTED;
		break;
	case 2:
		c.t = cartoon::type::PUPPET;
		break;
	case 3:
		c.t = cartoon::type::PLASTICINE;
		break;
	default:
		cerr << "Wrong type of Cartoon!" << endl;
		exit(1);
	}
}