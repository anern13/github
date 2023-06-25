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
    Square(double side_ = 1);
    Square(const Square& o_);
    Square& operator=(const Square& rhs_);
    ~Square() = default;
    virtual void Draw();
};
    
} // namespace ilrd

#endif //SQUARE_ANER_CPP