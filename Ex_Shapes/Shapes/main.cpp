/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#include "glut_utils.h"

#include "circle.hpp"
#include "square.hpp"

void DrawFunction();
static int TimerFunction();

using namespace ilrd;

Circle c(Point(1,1),30,IShape::RED);
Square s(Point(1920, 1080),30, IShape::CYAN);

int main(int argc, char const *argv[])
{

    DrawInit(argc, (char**)argv, 1920, 1080, DrawFunction);
    DrawSetTimerFunc(TimerFunction, 20);

    DrawMainLoop();

    return 0;
}

void DrawFunction()
{
    c.Draw();
    s.Draw();
}

static int TimerFunction()
{
    c.Move(Point(1,1));
    s.Move(Point(-1,-1));

    s.Rotate(0.2);

    return 1;  /* draw */
}