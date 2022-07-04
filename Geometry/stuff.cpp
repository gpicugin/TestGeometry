#include "pch.h"
#include "stuff.h"
#define M_PI  3.14159265358979323846


Point Point::operator+(Point pnt)
{
	Point result;
	result.x = x + pnt.x;
	result.y = y + pnt.y;
	result.z = z + pnt.z;
	return result;
}

Point Point::operator-(Point pnt)
{
	Point result;
	result.x = x - pnt.x;
	result.y = y - pnt.y;
	result.z = z - pnt.z;
	return result;
}

std::ostream& operator<< (std::ostream& out, Point pnt)
{
	out << "[" << pnt.x << "," << pnt.y << "," << pnt.z << "]";
	return out;
}

Curcle::Curcle()
{
	m_centr.x = 0;
	m_centr.y = 0;
	m_centr.z = 0;
	m_r = 1;
}

Curcle::Curcle(double radii)
{
	m_centr.x = 0;
	m_centr.y = 0;
	m_centr.z = 0;
	if(radii > 0)
		m_r = radii;
	else
		m_r = -radii;	
}

Curcle::Curcle(const Curcle& curcle)
{
	m_centr.x = curcle.m_centr.x;
	m_centr.y = curcle.m_centr.y;
	m_centr.z = curcle.m_centr.z;
	m_r = curcle.m_r;
}
const double Curcle::getRad()
{
	return m_r;
}

Point Curcle::pnt(double t)
{
	Point result;
	result.x = m_r * cos(t);
	result.y = m_r * sin(t);
	result.z = 0;
	return result;
}

Point Curcle::vec(double t)
{
	Point result;
	result.x = -(m_r * sin(t));
	result.y = m_r * cos(t);
	result.z = 0;
	return result;
}

figure Curcle::isFigure()
{
	return figure::curcle;
}

/////////////////////////////////////////////////////

Ellips::Ellips()
{
	m_centr.x = 0;
	m_centr.y = 0;
	m_centr.z = 0;
	m_a_r = 2;
	m_b_r = 1;
}

Ellips::Ellips(double a, double b)
{

	m_centr.x = 0;
	m_centr.y = 0;
	m_centr.z = 0;
	if (a > 0)
		m_a_r = a;
	else
		m_a_r = -a;
	if (b > 0)
		m_b_r = b;
	else
		m_b_r = -b;	
}

Point Ellips::pnt(double t)
{
	Point result;
	result.x = m_a_r * cos(t);
	result.y = m_b_r * sin(t);
	result.z = 0;
	return result;
}

Point Ellips::vec(double t)
{
	Point result;
	result.x = -m_a_r * sin(t);
	result.y =  m_b_r * cos(t);
	result.z = 0;
	return result;
}

figure Ellips::isFigure()
{
	return figure::ellips;
}

/////////////////////////////////////////////////////

Helix::Helix()
{
	m_centr.x = 0;
	m_centr.y = 0;
	m_centr.z = 0;
	m_r = 1;
	m_step = 1;
}

Helix::Helix(double radii, double step)
{

	m_centr.x = 0;
	m_centr.y = 0;
	m_centr.z = 0;
	if (radii > 0)
		m_r = radii;
	else
		m_r = -radii;
	if (step < 0)
		m_step = step;
	else
		m_step = -step;
}

Point Helix::pnt(double t)
{
	Point result;
	result.x = m_r * cos(t);
	result.y = m_r * sin(t);
	result.z = m_step * t;
	return result;
}

Point Helix::vec(double t)
{
	Point result;
	result.x = -(m_r * sin(t));
	result.y = m_r * cos(t);
	result.z = m_step;
	return result;
}

figure Helix::isFigure()
{
	return figure::helix;
}