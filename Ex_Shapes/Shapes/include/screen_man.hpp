/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 26 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef __ANER_SCREEN_MAMAGER_HPP__
#define __ANER_SCREEN_MAMAGER_HPP__

#include <vector>
#include <memory>//shared_ptr

#include "ishape.hpp"
#include "factory.hpp"

class Action;

class ScreenMan
{
public: 
    enum Shapes
    {

    };

    explicit ScreenMan();
    ScreenMan(const ScreenMan& o_) = delete;
    ScreenMan& operator=(const ScreenMan& rhs_) = delete;
    ~ScreenMan();

    void ConfigShape();
    void AddShape();
    void AddAction(std::shared_ptr<Action> act_);

private:
    std::vector<std::shared_ptr<ilrd::IShape>> m_shapes;
    std::vector<std::shared_ptr<Action>> m_acts;

    Singleton<Factory<Shapes, ilrd::IShape, /*insert args*/>> m_shape_factory;
};

class Action
{
    Action() = default;
    Action(const Action& o_) = delete;
    Action& operator=(const Action& rhs_) = delete;
    virtual ~Action() = default;

    virtual void Act() = 0;
};


#endif //__ANER_SCREEN_MAMAGER_HPP__