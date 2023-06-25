/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef SQUARE_ANER_CPP
#define SQUARE_ANER_CPP


#include "ishape.hpp"

namespace ilrd
{

class Square: public IShape
{
public:
    Square(Point center_, double side_ = 1, IShape::COLORS color_ = IShape::BLACK);
    Square(const Square& o_);
    Square& operator=(const Square& rhs_);
    ~Square() = default;
    virtual void Draw();
private:
    double m_side;
};
    
} // namespace ilrd

#endif //SQUARE_ANER_CPP