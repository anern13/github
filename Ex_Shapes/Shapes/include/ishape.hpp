/******************************************************************************/
//Author : anern13
//Project : IShapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef IShapeS_ANER_CPP
#define IShapeS_ANER_CPP

#include <vector>
#include <memory>

#include "point.hpp"

namespace ilrd
{

class IShape
{
public:
    enum COLORS
    {
        RED     = 0x010000,
        GREEN   = 0x000100,
        BLUE    = 0x000001,
        YELLOW  = 0x010100,
        MAGENTA = 0x010001,
        CYAN    = 0x000101,
        WHITE   = 0x010101,
        BLACK   = 0x000000,
        FILL    = 0x8000000
    };
    IShape()=default;
    IShape(const IShape& o_) = default;
    IShape& operator=( IShape& rhs_) = default;
    virtual ~IShape() = default;

    virtual void Draw() = 0;
    virtual void Move(Point relative_tar_);
    virtual void Rotate(double angle_);
protected:
    Point m_center;
    int m_color;
    //irenderer*  ?
private:
    std::vector<std::shared_ptr<IShape>> m_shapes;
};

}//namespace ilrd

#endif //IShapeS_ANER_CPP