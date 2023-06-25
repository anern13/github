/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef LINE_ANER_CPP
#define LINE_ANER_CPP


#include "ishape.hpp"

namespace ilrd
{

class Line: public IShape
{
public:
    Line(double len_ = 1);
    Line(const Line& o_);
    Line& operator=(const Line& rhs_);
    ~Line() = default;

    virtual void Draw();
private:
    double m_len;
};
    
} // namespace ilrd

#endif //LINE_ANER_CPP