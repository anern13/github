/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef RECTANGLE_ANER_CPP
#define RECTANGLE_ANER_CPP


#include "ishape.hpp"

namespace ilrd
{

class Rectangle: public IShape
{
public:
    Rectangle(double len_ = 1, double width_ = 1);
    Rectangle(const Rectangle& o_);
    Rectangle& operator=(const Rectangle& rhs_);
    ~Rectangle() = default;

    virtual void Draw();
private:
    double m_len;
    double m_width;
};
    
} // namespace ilrd

#endif //RECTANGLE_ANER_CPP