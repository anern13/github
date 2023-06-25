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

void IShape::Move(Point target_)
{
    for(auto iter : m_shapes)
    {
        iter->m_center += target_; 
    }
}

void IShape::Rotate(double angle_)
{
    for(auto iter : m_shapes)
    {
        iter->m_center.Revolve(m_center, angle_);
    }
}

} // namespace ilrd
