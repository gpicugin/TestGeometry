#pragma once
#include <math.h>
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
	Point operator+ (Point pnt);
	Point operator- (Point pnt);
	GEOMETRY_API friend std::ostream& operator<< (std::ostream& out, Point pnt);
};

enum GEOMETRY_API figure
{
	curcle = 0,
	ellips,
	helix
};

class GEOMETRY_API iCurve
{	
public:
	virtual Point pnt(double t) = 0;
	virtual Point vec(double t) = 0;
	virtual figure isFigure() = 0;
};

class GEOMETRY_API Curcle: public iCurve
{
public:
	Curcle();
	Curcle(double radii);
	Curcle(const Curcle& curcle);
	//~Curcle();
	const double getRad();
	Point pnt(double t);
	Point vec(double t);
	figure isFigure();
private:
	Point m_centr;
	double m_r;	
};

class GEOMETRY_API Ellips : public iCurve
{
public:
	Ellips();
	Ellips(double a, double b);
	//~Ellips();
	Point pnt(double t);
	Point vec(double t);
	figure isFigure();
private:
	Point m_centr;
	double m_a_r; // X
	double m_b_r; // Y
};

class GEOMETRY_API Helix : public iCurve
{
public:
	Helix();
	Helix(double radii, double step);
	//~Helix();
	Point pnt(double t);
	Point vec(double t);
	figure isFigure();
private:
	Point m_centr;
	double m_r;
	double m_step;
};