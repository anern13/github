/******************************************************************************/
//Author : anern13
//Project : IShapes
//Date : 20 / 06 / 25 
//Version : 1.0
/******************************************************************************/

#include "square.hpp" 

#include "glut_utils.h"

namespace ilrd
{

Square::Square(Point center_, double side_, IShape::COLORS color_):
m_side(side_)
{
   Init(center_, color_);

   m_corners.push_back(m_center + Point(m_side/2, m_side/2));
   m_corners.push_back(m_center + Point(m_side/2, -m_side/2));
   m_corners.push_back(m_center + Point(-m_side/2, -m_side/2));
   m_corners.push_back(m_center + Point(-m_side/2, m_side/2));

}

Square::Square(const Square& o_):
m_side(o_.m_side)
{
    Init(o_.m_center, (COLORS)o_.m_color);
}

Square& Square::operator=(const Square& rhs_)
{
    m_side = rhs_.m_side;
    Init(rhs_.m_center, (COLORS)rhs_.m_color);

    return *this;
}

void Square::Draw()
{
    Point& p1 = m_corners[0]; 
    Point& p2 = m_corners[1]; 
    Point& p3 = m_corners[2]; 
    Point& p4 = m_corners[3]; 
 
    DrawPolygon(m_color, 4, (int)p1.GetX(), (int)p1.GetY(), (int)p2.GetX(),
    (int)p2.GetY(), (int)p3.GetX(), (int)p3.GetY(), (int)p4.GetX(), (int)p4.GetY());
}

void Square::Move(Point relative_tar_)
{
    m_center += relative_tar_;

    for(auto &iter : m_corners)
    {
        iter += relative_tar_;
    }
}

void Square::Rotate(double angle_)
{
    for(auto &iter : m_corners)
    {
        iter.Revolve(m_center, angle_);
    }
}
    
} // namespace ilrd

