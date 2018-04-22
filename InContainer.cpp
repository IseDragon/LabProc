#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

film* In(ifstream &ifst);
int SumElementsOfString(film* f, int n);

void CheckInputFile(ifstream &ifst);
void CheckWrongInput(ifstream &ifst);

void In(container &c, ifstream & ifst)
{
	CheckInputFile(ifst);
	ifst >> c.kol;
	CheckWrongInput(ifst);
	if (c.kol < 0) {
		cerr << "Wrong number of films" << endl;
		exit(1);
	}
	for (int i = 0; i<c.kol; i++)
	{
		film* f;
		f = In(ifst);
		int sum = 0;
		sum = SumElementsOfString(f, c.n);
		if (c.mas[sum] == NULL)
		{
			c.mas[sum] = new node;
			c.mas[sum]->next = NULL;
			c.mas[sum]->f = f;
		}
		else
		{
			node* vn = new node;
			vn->next = c.mas[sum];
			vn->f = f;
			c.mas[sum] = vn;
		}
	}
}