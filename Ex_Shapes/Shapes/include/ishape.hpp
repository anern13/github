/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef SHAPES_ANER_CPP
#define SHAPES_ANER_CPP

#include <vector>

#include "point.hpp"

namespace ilrd
{

class IShape
{
public:
    IShape() = default;
    IShape(const IShape& o_) = default;
    IShape& operator=( IShape& rhs_) = default;
    ~IShape() = default;

    virtual void Draw() = 0;
    virtual void Move();
    virtual void Rotate();

private:
    Point m_center;
    std::vector<IShape> m_shapes;
    

};

}//namespace ilrd

#endif //SHAPES_ANER_CPP