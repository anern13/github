/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 20 / 06 / 22 
//Version : 1.0
/******************************************************************************/


#include "glut_utils.h"

#include "point.hpp"

void DrawFunction();
static int TimerFunction();

ilrd::Point g_center;

int main(int argc, char const *argv[])
{
    DrawInit(argc, (char**)argv, 1920, 1080, DrawFunction);
    DrawSetTimerFunc(TimerFunction, 100);

    DrawMainLoop();

    return 0;
}

void DrawFunction()
{
    
    DrawCircle(COLOR_GREEN, g_center.GetX(), g_center.GetY(), 15);
}

static int TimerFunction()
{
    ilrd::Point temp(1,1);

    g_center += temp;

    return 1;  /* draw */
}