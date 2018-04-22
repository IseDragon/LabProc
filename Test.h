#include <iostream>
#include <fstream>
#include "Cartoon.h"
#include "Documental.h"
#include "Feature.h"
#include "FilesCmp.h"

using namespace std;

void InCartoon(cartoon &c, ifstream &ifst);
void OutCartoon(cartoon &c, ostream &ofst);

class CartoonTest : public ::testing::Test {
};

TEST_F(CartoonTest, CheckInput) 
{
	ifstream ifst("InCartoon.txt");
	cartoon actual;
	InCartoon(actual, ifst);
	cartoon c;
	c.t = cartoon::type::PAINTED;
	ASSERT_EQ(actual.t, c.t);
}

TEST_F(CartoonTest, CheckOutput) 
{
	ostream ofst("OutTest.txt");
	cartoon c;
	c.t = cartoon::type::PAINTED;
	OutCartoon(c, ofst);
	ofst.close();

	ifstream expected("OutCartoon.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

//##################################################################################################
//##################################################################################################

void InDocumental(documental &d, ifstream &ifst);
void OutDocumental(documental &d, ostream &ofst);

class DocumentalTest : public ::testing::Test {
};

TEST_F(DocumentalTest, CheckInput) 
{
	ifstream ifst("InDocumental.txt");
	documental actual;
	InDocumental(actual, ifst);
	documental d;
	d.year = 1;
	ASSERT_EQ(actual.year, d.year);
}

TEST_F(DocumentalTest, CheckOutput) 
{
	ostream ofst("OutTest.txt");
	documental d;
	d.year = 1;
	OutDocumental(d, ofst);
	ofst.close();

	ifstream expected("OutDocumental.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

//##########################################################################################################
//##########################################################################################################

void InFeature(feature &f, ifstream &ifst);
void OutFeature(feature &f, ostream &ofst);

class FeatureTest : public ::testing::Test {
};

TEST_F(FeatureTest, CheckInput) 
{
	ifstream ifst("InFeature.txt");
	feature actual;
	InFeature(actual, ifst);
	feature f;
	strcpy_s(f.director, "Tarantino");
	ASSERT_STREQ(actual.director, f.director);
}

TEST_F(FeatureTest, CheckOutput) 
{
	ostream ofst("OutTest.txt");
	feature f;
	strcpy_s(f.director, "Tarantino");
	OutFeature(f, ofst);
	ofst.close();

	ifstream expected("OutFeature.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

//##########################################################################################################
//##########################################################################################################

film* In(ifstream &ifst);
void Out(film *f, ostream &ofst);
bool Compare(film *f1, film *f2);
int FuncFilm(film *f);
int SumElementsOfString(film* f, int n);

class FilmTest : public ::testing::Test {
};

TEST_F(FilmTest, CheckInputCartoon) 
{
	ifstream ifst("FilmInCartoon.txt");
	film* actual = (film *)In(ifst);

	film expected;
	expected.k = film::key::CARTOON;
	strcpy_s(expected.name, "Frozen");
	strcpy_s(expected.country, "USA");
	cartoon c;
	c.t = cartoon::type::PAINTED;
	expected.c = c;

	ASSERT_TRUE(expected.k == actual->k);
	ASSERT_STREQ(actual->name, expected.name);
	ASSERT_STREQ(actual->country, expected.country);
	ASSERT_EQ(actual->c.t, expected.c.t);
}

TEST_F(FilmTest, CheckInputDocumental) 
{
	ifstream ifst("FilmInDocumental.txt");
	film* actual = (film *)In(ifst);

	film expected;
	expected.k = film::key::DOCUMENTAL;
	strcpy_s(expected.name, "Wildlife");
	strcpy_s(expected.country, "USA");
	documental d;
	d.year = 1;
	expected.d = d;

	ASSERT_TRUE(expected.k == actual->k);
	ASSERT_STREQ(actual->name, expected.name);
	ASSERT_STREQ(actual->country, expected.country);
	ASSERT_EQ(actual->d.year, expected.d.year);
}

TEST_F(FilmTest, CheckInputFeature) {
	ifstream ifst("FilmInFeature.txt");
	film* actual = (film *)In(ifst);

	film expected;
	expected.k = film::key::FEATURE;
	strcpy_s(expected.name, "Kill Bill");
	strcpy_s(expected.country, "USA");
	feature f;
	strcpy_s(f.director, "Tarantino");
	expected.f = f;

	ASSERT_TRUE(expected.k == actual->k);
	ASSERT_STREQ(actual->name, expected.name);
	ASSERT_STREQ(actual->country, expected.country);
	ASSERT_STREQ(actual->f.director, expected.f.director);
}

TEST_F(FilmTest, CheckOutputCartoon) 
{
	ostream ofst("OutTest.txt");

	film *f = new film;
	f->k = film::key::CARTOON;
	strcpy_s(f->name, "Frozen");
	strcpy_s(f->country, "USA");
	cartoon c;
	c.t = cartoon::type::PAINTED;
	f->c = c;
	Out(f, ofst);

	ifstream expected("FilmOutCartoon.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(FilmTest, CheckOutputDocumental) 
{
	ostream ofst("OutTest.txt");

	film *f = new film;
	f->k = film::key::DOCUMENTAL;
	strcpy_s(f->name, "Wildlife");
	strcpy_s(f->country, "USA");
	documental d;
	d.year = 1;
	f->d = d;
	Out(f, ofst);

	ifstream expected("FilmOutDocumental.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(FilmTest, CheckOutputFeature) 
{
	ostream ofst("OutTest.txt");

	film *f = new film;
	f->k = film::key::FEATURE;
	strcpy_s(f->name, "Kill Bill");
	strcpy_s(f->country, "USA");
	feature fe;
	strcpy_s(fe.director, "Tarantino");
	f->f = fe;
	Out(f, ofst);

	ifstream expected("FilmOutFeature.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}


TEST_F(FilmTest, CheckFunc) 
{
	film *f = new film;
	strcpy_s(f->name, "Kill Bill");
	ASSERT_EQ(FuncFilm(f), 2);
}

TEST_F(FilmTest, CheckZeroFunc) 
{
	film *f = new film;
	strcpy_s(f->name, "KLB");
	ASSERT_EQ(FuncFilm(f), 0);
}

TEST_F(FilmTest, CheckCompare) 
{
	film *f1 = new film;
	film *f2 = new film;
	strcpy_s(f1->name, "Kill Bill");
	strcpy_s(f2->name, "Bill");

	ASSERT_TRUE(Compare(f1,f2));
}

TEST_F(FilmTest, CheckSumElem) 
{
	film *f = new film;
	strcpy_s(f->name, "Kill Bill");
	ASSERT_EQ(SumElementsOfString(f,10), 5);
}

TEST_F(FilmTest, CheckZeroSumElem) 
{
	film *f = new film;
	strcpy_s(f->name, "");
	ASSERT_EQ(SumElementsOfString(f, 10), 0);
}

//#############################################################################################
//#############################################################################################

void Init(container &c);
void Clear(container &c);
void In(container &c, ifstream & ifst);
void Out(container c, ostream &ofst);
void Sort(container &c);
void OutOnlyCartoon(container c, ostream &ofst);
void OutOnlyDocumental(container c, ostream &ofst);
void OutOnlyFeature(container c, ostream &ofst);

class ContainerTest : public ::testing::Test {
};

TEST_F(ContainerTest, CheckInitContainer) 
{

	container c;
	Init(c);
	
	c.kol = 0;
	c.n = 10;
	for (int i = 0; i < c.n; i++)
	{
		c.mas[i] = NULL;
	}
	ASSERT_EQ(c.kol, 0);
	ASSERT_EQ(c.n, 10);
	for (int i = 0; i < c.n; i++)
	{
		ASSERT_TRUE(c.mas[i] == NULL);
	}
}

TEST_F(ContainerTest, CheckClearEmptyContainer) 
{

	container c;
	Init(c);

	Clear(c);

	ASSERT_EQ(c.kol, 0);
	for (int i = 0; i < c.n; i++)
	{
		ASSERT_TRUE(c.mas[i] == NULL);
	}
}

TEST_F(ContainerTest, CheckClearContainer)
{
	container c;
	Init(c);

	film *f = new film;
	strcpy_s(f->name, "Kill Bill");

	int sum = 0;
	sum = SumElementsOfString(f, c.n);
	c.mas[sum] = new node;
	c.mas[sum]->next = NULL;
	c.mas[sum]->f = f;
	Clear(c);

	ASSERT_EQ(c.kol, 0);
	for (int i = 0; i < c.n; i++)
	{
		ASSERT_TRUE(c.mas[i] == NULL);
	}
}

TEST_F(ContainerTest, CheckOutCartoon) 
{
	ostream ofst("OutTest.txt");

	container c;
	Init(c);
	c.kol = 3;

	film *f1 = new film;
	f1->k = film::key::CARTOON;
	strcpy_s(f1->name, "Frozen");
	strcpy_s(f1->country, "USA");
	cartoon ca;
	ca.t = cartoon::type::PAINTED;
	f1->c = ca;

	film *f2 = new film;
	f2->k = film::key::DOCUMENTAL;
	strcpy_s(f2->name, "Wildlife");
	strcpy_s(f2->country, "USA");
	documental d;
	d.year = 1;
	f2->d = d;
	
	film *f3 = new film;
	f3->k = film::key::FEATURE;
	strcpy_s(f3->name, "Kill Bill");
	strcpy_s(f3->country, "USA");
	feature fe;
	strcpy_s(fe.director, "Tarantino");
	f3->f = fe;
	
	int sum = 0;
	sum = SumElementsOfString(f1, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f1;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f1;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f2, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f2;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f2;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f3, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f3;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f3;
		c.mas[sum] = vn;
	}

	OutOnlyCartoon(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutCartoon.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutDocumental) 
{
	ostream ofst("OutTest.txt");

	container c;
	Init(c);
	c.kol = 3;

	film *f1 = new film;
	f1->k = film::key::CARTOON;
	strcpy_s(f1->name, "Frozen");
	strcpy_s(f1->country, "USA");
	cartoon ca;
	ca.t = cartoon::type::PAINTED;
	f1->c = ca;

	film *f2 = new film;
	f2->k = film::key::DOCUMENTAL;
	strcpy_s(f2->name, "Wildlife");
	strcpy_s(f2->country, "USA");
	documental d;
	d.year = 1;
	f2->d = d;

	film *f3 = new film;
	f3->k = film::key::FEATURE;
	strcpy_s(f3->name, "Kill Bill");
	strcpy_s(f3->country, "USA");
	feature fe;
	strcpy_s(fe.director, "Tarantino");
	f3->f = fe;

	int sum = 0;
	sum = SumElementsOfString(f1, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f1;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f1;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f2, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f2;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f2;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f3, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f3;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f3;
		c.mas[sum] = vn;
	}

	OutOnlyDocumental(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutDocumental.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutFeature) 
{
	ostream ofst("OutTest.txt");

	container c;
	Init(c);
	c.kol = 3;

	film *f1 = new film;
	f1->k = film::key::CARTOON;
	strcpy_s(f1->name, "Frozen");
	strcpy_s(f1->country, "USA");
	cartoon ca;
	ca.t = cartoon::type::PAINTED;
	f1->c = ca;

	film *f2 = new film;
	f2->k = film::key::DOCUMENTAL;
	strcpy_s(f2->name, "Wildlife");
	strcpy_s(f2->country, "USA");
	documental d;
	d.year = 1;
	f2->d = d;

	film *f3 = new film;
	f3->k = film::key::FEATURE;
	strcpy_s(f3->name, "Kill Bill");
	strcpy_s(f3->country, "USA");
	feature fe;
	strcpy_s(fe.director, "Tarantino");
	f3->f = fe;

	int sum = 0;
	sum = SumElementsOfString(f1, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f1;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f1;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f2, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f2;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f2;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f3, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f3;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f3;
		c.mas[sum] = vn;
	}

	OutOnlyFeature(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOutFeature.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSort) 
{
	ostream ofst("OutTest.txt");

	container c;
	Init(c);
	c.kol = 3;

	film *f1 = new film;
	f1->k = film::key::CARTOON;
	strcpy_s(f1->name, "Frozen");
	strcpy_s(f1->country, "USA");
	cartoon ca;
	ca.t = cartoon::type::PAINTED;
	f1->c = ca;

	film *f2 = new film;
	f2->k = film::key::DOCUMENTAL;
	strcpy_s(f2->name, "Wildlife");
	strcpy_s(f2->country, "USA");
	documental d;
	d.year = 1;
	f2->d = d;

	film *f3 = new film;
	f3->k = film::key::FEATURE;
	strcpy_s(f3->name, "Kill Bill");
	strcpy_s(f3->country, "USA");
	feature fe;
	strcpy_s(fe.director, "Tarantino");
	f3->f = fe;

	int sum = 0;
	sum = SumElementsOfString(f1, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f1;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f1;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f2, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f2;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f2;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f3, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f3;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f3;
		c.mas[sum] = vn;
	}

	Sort(c);
	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerSort.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOut) 
{
	ostream ofst("OutTest.txt");

	container c;
	Init(c);
	c.kol = 3;

	film *f1 = new film;
	f1->k = film::key::CARTOON;
	strcpy_s(f1->name, "Frozen");
	strcpy_s(f1->country, "USA");
	cartoon ca;
	ca.t = cartoon::type::PAINTED;
	f1->c = ca;

	film *f2 = new film;
	f2->k = film::key::DOCUMENTAL;
	strcpy_s(f2->name, "Wildlife");
	strcpy_s(f2->country, "USA");
	documental d;
	d.year = 1;
	f2->d = d;

	film *f3 = new film;
	f3->k = film::key::FEATURE;
	strcpy_s(f3->name, "Kill Bill");
	strcpy_s(f3->country, "USA");
	feature fe;
	strcpy_s(fe.director, "Tarantino");
	f3->f = fe;

	int sum = 0;
	sum = SumElementsOfString(f1, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f1;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f1;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f2, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f2;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f2;
		c.mas[sum] = vn;
	}

	sum = SumElementsOfString(f3, c.n);
	if (c.mas[sum] == NULL)
	{
		c.mas[sum] = new node;
		c.mas[sum]->next = NULL;
		c.mas[sum]->f = f3;
	}
	else
	{
		node* vn = new node;
		vn->next = c.mas[sum];
		vn->f = f3;
		c.mas[sum] = vn;
	}

	Out(c, ofst);
	ofst.close();

	ifstream actual("OutTest.txt");
	ifstream expected("ContainerOut.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}