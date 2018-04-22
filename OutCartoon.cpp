#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Cartoon.h"

using namespace std;

void CheckOutputFile(ostream &ofst);

void OutCartoon(cartoon &c, ostream &ofst) 
{
	CheckOutputFile(ofst);
	ofst << "It is cartoon." << endl;
	ofst << "It is ";
	switch (c.t) 
	{
		case cartoon::type::PAINTED:
			ofst << "painted." << endl;
			break;
		case cartoon::type::PUPPET:
			ofst << "puppet." << endl;
			break;
		case cartoon::type::PLASTICINE:
			ofst << "plasticine." << endl;
			break;
		default:
			cerr << "Unknown type of Cartoon" << endl;
			exit(1);
	}
}