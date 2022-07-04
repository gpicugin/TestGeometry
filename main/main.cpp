#include "../Geometry/stuff.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <memory>
#include <algorithm>
#include <omp.h>
#define M_PI  3.14159265358979323846

typedef std::shared_ptr<iCurve> iCurve_ptr;
typedef std::shared_ptr<Curcle> Curcle_ptr;

double dRand(double dMin, double dMax)
{
	double d = (double)rand() / RAND_MAX;
	return dMin + d * (dMax - dMin);
}


void printData(std::vector<iCurve_ptr>& vec, std::string fileName)
{
	std::ofstream fstr;
	fstr.open(fileName);
	double t = M_PI / 4;
	for (int i = 0; i < vec.size(); i++)
	{
		Point pnt, der;
		pnt = vec[i]->pnt(t);
		der = vec[i]->vec(t);
		fstr << "Value of curve in PI/4 is " << pnt << " | Value of derivative function is " << der << std::endl;
	}
	fstr.close();
}


void fillVec(std::vector<iCurve_ptr>& vec, int n)
{
	for (int i = 0; i < n; i++)
	{
		iCurve_ptr ptr;
		vec.push_back(ptr);
	}
	for (int i = 0; i < n; i++)
	{
		//iCurve* ptr;
		int dice = rand() % 3;
		switch (dice)
		{
		case 0:
		{
			double rad = dRand(0, 10);
			std::shared_ptr<Curcle> s_ptr = std::make_shared<Curcle>(rad);
			vec[i] = s_ptr;
		}
		break;
		case 1:
		{
			double rad1 = dRand(0, 10);
			double rad2 = dRand(0, 10);
			if (rad1 == rad2)
			{
				std::shared_ptr<Curcle> s_ptr = std::make_shared<Curcle>(rad1);
				vec[i] = s_ptr;
			}
			else
			{
				std::shared_ptr<Ellips> s_ptr = std::make_shared<Ellips>(rad1, rad2);
				vec[i] = s_ptr;
			}
		}
		break;
		case 2:
		{
			double rad = dRand(0, 10);
			double step = dRand(0, 2);
			std::shared_ptr<Helix> s_ptr = std::make_shared<Helix>(rad, step);
			vec[i] = s_ptr;
		}
		break;
		default:
			break;
		}		
	}
}

void copyCurcles(std::vector<iCurve_ptr>& vec1, std::vector<Curcle_ptr>& vec2)
{
	for (int i = 0; i < vec1.size(); i++)
	{
		if (vec1[i]->isFigure() == figure::curcle)
		{
			Curcle_ptr ptr = std::make_shared<Curcle>(*(dynamic_cast<Curcle*>(vec1[i].get())));
			vec2.push_back(ptr);
		}
	}
}

bool comp(Curcle_ptr c1, Curcle_ptr c2)
{
	return (c1->getRad() < c2->getRad());
}

double sumRad(std::vector<Curcle_ptr>& vec2)
{
	double result = 0;
	#pragma omp parallel
	{
		double local_sum = 0;
		#pragma omp for
		for (int i = 0; i < vec2.size(); i++)
			local_sum += vec2[i]->getRad();
		#pragma omp atomic
		result += local_sum;
	}
	return result;
}

void main()
{	
	srand(time(NULL));
	std::vector<iCurve_ptr> vec1;
	std::vector<Curcle_ptr> vec2;
	
	fillVec(vec1, 100);
	printData(vec1, "Data.txt");
	copyCurcles(vec1, vec2);
	vec1.clear();
	std::sort(vec2.begin(), vec2.end(), comp);
	double sum = sumRad(vec2);
	std::cout << vec2.size() << " " << sum << std::endl;	
}