#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(film *f, ostream &ofst);
int FuncFilm(film *f);

void CheckOutputFile(ostream &ofst);

void Out(container c, ostream &ofst)
{
	CheckOutputFile(ofst);
	ofst << "Container contains " << c.kol << " elements." << endl;
	for (int i = 0; i<c.n; i++)
		{
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