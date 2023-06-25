/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef CIECLE_ANER_CPP
#define CIECLE_ANER_CPP


#include "ishape.hpp"

namespace ilrd
{

class Circle: public IShape
{
public:
    Circle( Point center_ , double rad_ = 1, IShape::COLORS color_ = BLACK);
    Circle(const Circle& o_);
    Circle& operator=(const Circle& rhs_);
    ~Circle() = default;

    virtual void Draw();
private:
    double m_rad;
};
    
} // namespace ilrd

#endif //CIECLE_ANER_CPP