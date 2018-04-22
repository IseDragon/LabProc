#include <stdio.h> 
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include "Container.h"

using namespace std;

bool Compare(film* f1, film* f2);

void Sort(container &c, int d)
{
	for (int k = 0; k<c.n; k++)
	{
		int koli = 0;
		node* prev = NULL;
		node* Node = c.mas[k];
		while (Node)
		{
			Node = Node->next;
			koli++;
		}
		for (int i = 0; i < koli - 1; i++)
		{
			node* prev = NULL;
			Node = c.mas[k];
			for (int j = i + 1; j < koli; j++)
			{
				switch (d)
				{
				case 0:
					if (Compare(Node->f, Node->next->f))
					{
						node* next = Node->next;
						Node->next = Node->next->next;
						next->next = Node;
						if (Node == c.mas[k])
						{
							c.mas[k] = next;
							prev = next;
						}
						else
						{
							prev->next = next;
							prev = next;
						}
					}
					else
					{
						prev = Node;
						Node = Node->next;
					}
					break;
				case 1:
					if (!Compare(Node->f, Node->next->f))
					{
						node* next = Node->next;
						Node->next = Node->next->next;
						next->next = Node;
						if (Node == c.mas[k])
						{
							c.mas[k] = next;
							prev = next;
						}
						else
						{
							prev->next = next;
							prev = next;
						}
					}
					else
					{
						prev = Node;
						Node = Node->next;
					}
					break;
				default:
					cerr << "Inknown d in sort function!" << endl;
					exit(1);
				}
			}
		}
	}
}