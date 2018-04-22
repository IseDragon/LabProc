#include <iostream>
#include "Film.h"
#include "Cartoon.h"
#include "Feature.h"

using namespace std;

void OutFeature(feature &f, ostream &ofst);
void OutCartoon(cartoon &c, ostream &ofst);
void OutDocumental(documental &d, ostream &ofst);

void CheckOutputFile(ostream &ofst);

void Out(film *f, ostream &ofst) 
{
	CheckOutputFile(ofst);
	ofst << f->name << endl;
	ofst << "It was filmed in " << f->country << endl;
	switch (f->k) 
	{
		case film::key::FEATURE:
			OutFeature(f->f, ofst);
			break;
		case film::key::CARTOON:
			OutCartoon(f->c, ofst);
			break;
		case film::key::DOCUMENTAL:
			OutDocumental(f->d, ofst);
			break;
		default:
			ofst << "Incorrect type of film!" << endl;
			exit(1);
	}
}