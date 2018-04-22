#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(film *f, ofstream &ofst);

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
					c.mas[i] = c.mas[i]->next;
				}
			}
		}
}