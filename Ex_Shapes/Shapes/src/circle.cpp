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
    Init(center_, color_);
}

Circle::Circle(const Circle& o_):
m_rad(o_.m_rad)
{
    Init(o_.m_center, (COLORS)o_.m_color);
}

Circle& Circle::operator=(const Circle& rhs_)
{
    m_rad = rhs_.m_rad;
    Init(rhs_.m_center, (COLORS)rhs_.m_color);

    return *this;
}

void Circle::Draw()
{
    DrawCircle(m_color ,m_center.GetX(), m_center.GetY(), m_rad);
}
    
} // namespace ilrd


