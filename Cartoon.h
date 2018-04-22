#ifndef __cartoon__
#define __cartoon__
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>

using namespace std;

struct cartoon 
{
	enum type { PAINTED, PUPPET, PLASTICINE };
	type t;
};
#endif