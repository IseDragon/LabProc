#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Cartoon.h"

using namespace std;

void InCartoon(cartoon &c, ifstream &ifst) {
	int k;
	ifst >> k;
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
	}
}