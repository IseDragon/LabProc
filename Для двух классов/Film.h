#ifndef __film__
#define __film__
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Feature.h"
#include "Cartoon.h"

using namespace std;

struct film {
	enum key { FEATURE, CARTOON };
	key k; // ключ
		   // используемые альтернативы
	char name[256];
	union
	{
		feature f;
		cartoon c;
	};
};
#endif