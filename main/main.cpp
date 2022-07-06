#include <omp.h>
#include <vector>
#include <random>
#include <memory>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "../Geometry/curves.h"
#define _USE_MATH_DEFINES
#include <math.h>

typedef std::shared_ptr<iCurve> iCurve_ptr;

void printData(const std::vector<iCurve_ptr>& curves, std::string fileName)
{
	std::ofstream fstr;
	fstr.open(fileName);
	double t = M_PI / 4;
	for (iCurve_ptr curve: curves)
	{
		Point pnt, der;
		pnt = curve->pnt(t);
		der = curve->vec(t);
		fstr << "Value of curve in PI/4 is " << pnt << std::endl;
		fstr << "Value of derivative function is " << der << std::endl;
		if(curve != curves.back())
		fstr << "///////////////////////////////////////////////////" << std::endl;
	}
	fstr.close();
}


void fillVec(std::vector<iCurve_ptr>& curves, int n)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distribution_10(0.0, 10.0);
	std::uniform_real_distribution<> distribution_2(0.0, 2.0);
	curves.resize(n);
	for (int i = 0; i < n; i++)
	{
		int dice = rand() % 3;
		switch (dice)
		{
		case 0:
		{
			double rad = distribution_10(gen);
			std::shared_ptr<Circle> s_ptr = std::make_shared<Circle>(rad);
			curves[i] = s_ptr;
		}
		break;
		case 1:
		{
			double rad1 = distribution_10(gen);
			double rad2 = distribution_10(gen);
			if (rad1 == rad2)
			{
				std::shared_ptr<Circle> s_ptr = std::make_shared<Circle>(rad1);
				curves[i] = s_ptr;
			}
			else
			{
				std::shared_ptr<Ellipse> s_ptr = std::make_shared<Ellipse>(rad1, rad2);
				curves[i] = s_ptr;
			}
		}
		break;
		case 2:
		{
			double rad = distribution_10(gen);
			double step = distribution_2(gen);
			std::shared_ptr<Helix> s_ptr = std::make_shared<Helix>(rad, step);
			curves[i] = s_ptr;
		}
		break;
		default:
			break;
		}		
	}
}

void copyCircles(std::vector<iCurve_ptr>& curves, std::vector<Circle*>& circles)
{
	for (int i = 0; i < curves.size(); i++)
	{
		if (curves[i]->figureType() == figure::circle)
		{
			Circle* ptr = dynamic_cast<Circle*>(curves[i].get());
			circles.push_back(ptr);
		}
	}
}

bool comp(Circle* c1, Circle* c2)
{
	return (c1->getRad() < c2->getRad());
}

double sumRad(std::vector<Circle*>& circles)
{
	double result = 0;
	#pragma omp parallel
	{
		double local_sum = 0;
		#pragma omp for
		for (int i = 0; i < circles.size(); i++)
			local_sum += circles[i]->getRad();
		#pragma omp atomic
		result += local_sum;
	}
	return result;
}

void main()
{	
	srand(time(NULL));
	std::vector<iCurve_ptr> curves;
	std::vector<Circle*> circles;
	
	fillVec(curves, 100);
	printData(curves, "Data.txt");
	copyCircles(curves, circles);	
	std::sort(circles.begin(), circles.end(), comp);
	double sum = sumRad(circles);
	std::cout << circles.size() << " " << sum << std::endl;
}