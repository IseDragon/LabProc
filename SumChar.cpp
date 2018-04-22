#include <string>
#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Film.h"
#include "Cartoon.h"
#include "Feature.h"

int SumElementsOfString(film* f, int n)
{
	string str = f->name;
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		sum = (sum + (unsigned char)str[i]) % n;
	}
	return sum;
}