#pragma once
#include <iostream>
#define GEOMETRY_API_EXPORTS
#ifdef GEOMETRY_API_EXPORTS
#define GEOMETRY_API __declspec(dllexport) 
#else
#define GEOMETRY_API __declspec(dllimport) 
#endif

struct GEOMETRY_API Point
{
	double x;
	double y;
	double z;	
	GEOMETRY_API friend std::ostream& operator<< (std::ostream& out, Point pnt);
};

enum GEOMETRY_API figure
{
	circle = 0,
	ellipse,
	helix
};

class GEOMETRY_API iCurve
{	
public:
	virtual Point pnt(double t) = 0;
	virtual Point vec(double t) = 0;
	virtual figure figureType() = 0;
};

class GEOMETRY_API Circle: public iCurve
{
public:
	Circle();
	Circle(double raduis);
	const double getRad();
	Point pnt(double t);
	Point vec(double t);
	figure figureType();
private:	
	double m_r;	
};

class GEOMETRY_API Ellipse : public iCurve
{
public:
	Ellipse();
	Ellipse(double a, double b);
	Point pnt(double t);
	Point vec(double t);
	figure figureType();
private:
	double m_a_r; // X
	double m_b_r; // Y
};

class GEOMETRY_API Helix : public iCurve
{
public:
	Helix();
	Helix(double raduis, double step);
	Point pnt(double t);
	Point vec(double t);
	figure figureType();
private:
	double m_r;
	double m_step;
};