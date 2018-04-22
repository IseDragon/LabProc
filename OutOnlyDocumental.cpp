#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(film *f, ostream &ofst);

void CheckOutputFile(ostream &ofst);

void OutOnlyDocumental(container c, ostream &ofst)
{
	CheckOutputFile(ofst);
	ofst << "Container contains " << c.kol << " elements." << endl;
	for (int i = 0; i<c.n; i++)
	{
		//cout << "\n" << i << "\n";
		if (c.mas[i] != NULL)
		{
			node* vn = c.mas[i];
			while (c.mas[i])
			{
				if (c.mas[i]->f->k == film::key::DOCUMENTAL)
					Out(c.mas[i]->f, ofst);
				c.mas[i] = c.mas[i]->next;
			}
		}
	}
}