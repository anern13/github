/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef SQUARE_ANER_CPP
#define SQUARE_ANER_CPP


#include "ishape.hpp"
#include <vector>

namespace ilrd
{

class Square: public IShape
{
public:
    Square(Point center_, double side_ = 1, IShape::COLORS color_ = BLACK);
    Square(const Square& o_);
    Square& operator=(const Square& rhs_);
    ~Square() = default;

    virtual void Draw();
    virtual void Move(Point relative_tar_);
    virtual void Rotate(double angle_);

private:
    double m_side;
    std::vector<Point> m_corners;
};
    
} // namespace ilrd

#endif //SQUARE_ANER_CPP