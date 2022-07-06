#include "curves.h"




std::ostream& operator<< (std::ostream& out, Point pnt)
{
	out << "[" << pnt.x << "," << pnt.y << "," << pnt.z << "]";
	return out;
}

Circle::Circle()
{
	m_r = 1;
}

Circle::Circle(double raduis)
{
	try
	{
		if (raduis <= 0)
			throw 1;
		else
			m_r = raduis;
	}
	catch(int i)
	{
		std::cout << "Wrong input!" << std::endl;
		std::exit(EXIT_FAILURE);
	}	
}

const double Circle::getRad()
{
	return m_r;
}

Point Circle::pnt(double t)
{
	Point result;
	result.x = m_r * std::cos(t);
	result.y = m_r * std::sin(t);
	result.z = 0;
	return result;
}

Point Circle::vec(double t)
{
	Point result;
	result.x = -(m_r * std::sin(t));
	result.y = m_r * std::cos(t);
	result.z = 0;
	return result;
}

figure Circle::figureType()
{
	return figure::circle;
}

/////////////////////////////////////////////////////

Ellipse::Ellipse()
{
	m_a_r = 2;
	m_b_r = 1;
}

Ellipse::Ellipse(double a, double b)
{
	try
	{
		if (a <= 0 || b <=0)
			throw 1;
		else
		{
			m_a_r = a;
			m_b_r = b;
		}
	}
	catch (int i)
	{
		std::cout << "Wrong input!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Point Ellipse::pnt(double t)
{
	Point result;
	result.x = m_a_r * std::cos(t);
	result.y = m_b_r * std::sin(t);
	result.z = 0;
	return result;
}

Point Ellipse::vec(double t)
{
	Point result;
	result.x = -m_a_r * std::sin(t);
	result.y =  m_b_r * std::cos(t);
	result.z = 0;
	return result;
}

figure Ellipse::figureType()
{
	return figure::ellipse;
}

/////////////////////////////////////////////////////

Helix::Helix()
{
	m_r = 1;
	m_step = 1;
}

Helix::Helix(double raduis, double step)
{
	try
	{
		if (raduis <= 0)
			throw 1;
		else
		{
			m_r = raduis;
			m_step = step;
		}
	}
	catch (int i)
	{
		std::cout << "Wrong input!" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

Point Helix::pnt(double t)
{
	Point result;
	result.x = m_r * std::cos(t);
	result.y = m_r * std::sin(t);
	result.z = m_step * t;
	return result;
}

Point Helix::vec(double t)
{
	Point result;
	result.x = -(m_r * std::sin(t));
	result.y = m_r * std::cos(t);
	result.z = m_step;
	return result;
}

figure Helix::figureType()
{
	return figure::helix;
}