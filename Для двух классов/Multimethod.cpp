#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

void Out(film *f, ofstream &ofst);

void MultiMethod(container c, ofstream &ofst)
{
	int k = 0;
	for (int i = 0; i<c.n; i++)
	{
		if (c.mas[i] != NULL)
		{
			node* Node1 = c.mas[i];
			while (Node1)
			{
				for (int j = i; j<c.n; j++)
				{
					node* Node2;
					if (j == i)
						Node2 = Node1->next;
					else
						Node2 = c.mas[j];
					if (c.mas[j] != NULL)
					{
						while (Node2)
						{
							switch (Node1->f->k)
							{
							case film::key::CARTOON:
							{
								switch (Node2->f->k)
								{
									case film::key::CARTOON:
									{
										k++;
										ofst << "\nCartoon and Cartoon.\n" << endl;
										Out(Node1->f, ofst);
										ofst << endl;
										Out(Node2->f, ofst);
										break;
									}
									case film::key::FEATURE:
									{
										k++;
										ofst << "\nCartoon and Feature.\n" << endl;
										Out(Node1->f, ofst);
										ofst << endl;
										Out(Node2->f, ofst);
										break;
									}
								}
								break;
							}
							case film::key::FEATURE:
							{
								switch (Node2->f->k)
								{
									case film::key::CARTOON:
									{
										k++;
										ofst << "\nFeature and Cartoon.\n" << endl;
										Out(Node1->f, ofst);
										ofst << endl;
										Out(Node2->f, ofst);
										break;
									}
									case film::key::FEATURE:
									{
										k++;
										ofst << "\nFeature and Feature.\n" << endl;
										Out(Node1->f, ofst);
										ofst << endl;
										Out(Node2->f, ofst);
										break;
									}
								}
								break;
							}
							}
							Node2 = Node2->next;
						}
					}
				}
				Node1 = Node1->next;
			}
		}
	}
}