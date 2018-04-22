﻿#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(film *f, ofstream &ofst);
int FuncFilm(film *f);

void Out(container c, ofstream &ofst)
{
	ofst << "Container contains " << c.kol << " elements." << endl;
	for (int i = 0; i<c.n; i++)
		{
			//cout << "\n" << i << "\n";
			if (c.mas[i] != NULL)
			{
				node* vn = c.mas[i];
				while (c.mas[i])
				{
					Out(c.mas[i]->f, ofst);
					ofst << "Number of vowels = " << FuncFilm(c.mas[i]->f) << endl;
					c.mas[i] = c.mas[i]->next;
				}
			}
		}
}