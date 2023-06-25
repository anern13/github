/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/


#include "glut_utils.h"

#include "circle.hpp"

void DrawFunction();
static int TimerFunction();

using namespace ilrd;

Circle c(Point(1,1),15,IShape::BLUE);

int main(int argc, char const *argv[])
{

    DrawInit(argc, (char**)argv, 1920, 1080, DrawFunction);
    DrawSetTimerFunc(TimerFunction, 100);

    DrawMainLoop();

    return 0;
}

void DrawFunction()
{
    c.Draw();
}

static int TimerFunction()
{
    c.Move(Point(1,1));

    return 1;  /* draw */
}