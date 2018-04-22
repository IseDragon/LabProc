#ifndef __film__
#define __film__
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Feature.h"
#include "Cartoon.h"
#include "Documental.h"

using namespace std;

struct film 
{
	enum key { FEATURE, CARTOON, DOCUMENTAL };
	key k; // ключ
		   // используемые альтернативы
	char name[256];
	char country[256];
	union
	{
		feature f;
		cartoon c;
		documental d;
	};
};
#endif