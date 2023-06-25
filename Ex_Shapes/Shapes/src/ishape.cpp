/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 25 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#include <vector>
#include <algorithm>

#include "ishape.hpp"

namespace ilrd
{
void IShape::Init(Point center_, IShape::COLORS color_ )
{
    m_center = center_;
    m_color = color_;
}

void IShape::Move(Point target_)
{
    m_center += target_; 
}

void IShape::Rotate(double angle_)
{
    
    m_center.Revolve(m_center, angle_);
}

} // namespace ilrd
