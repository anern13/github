/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 22 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#include "circle.hpp"

#include "glut_utils.h"


namespace ilrd
{

Circle::Circle(Point center_, double rad_, IShape::COLORS color_):
m_rad(rad_)
{
    m_center = center_;
    m_color = color_;
}

Circle::Circle(const Circle& o_):
m_rad(o_.m_rad)
{
    m_center = o_.m_center;
    m_color = o_.m_color;
}

Circle& Circle::operator=(const Circle& rhs_)
{
    m_rad = rhs_.m_rad;
    m_center = rhs_.m_center;
    m_color = rhs_.m_color;
}

void Circle::Draw()
{
    DrawCircle(m_color ,m_center.GetX(), m_center.GetY(), m_rad);
}
    
} // namespace ilrd


