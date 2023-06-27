/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 26 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef __ANER_SCREEN_MAMAGER_HPP__
#define __ANER_SCREEN_MAMAGER_HPP__

#include <vector>
#include <memory>       //std::shared_ptr
#include <functional>   //std::function

#include "ishape.hpp"
#include "factory.hpp"

class Action;
struct Args;


class ScreenMan
{
public: 

    enum Shapes
    {
        CIRCLE = 0,
        SQUARE = 1
    };

    explicit ScreenMan();
    ScreenMan(const ScreenMan& o_) = delete;
    ScreenMan& operator=(const ScreenMan& rhs_) = delete;
    ~ScreenMan() = default;

    using ShapeCreate = std::function<std::shared_ptr<ilrd::IShape>(Args)>;

    void ConfigShape(Shapes name_, ShapeCreate cf_);
    void AddShape(Shapes name_, Args args_);
    void AddAction(std::shared_ptr<Action> act_);
    void Display();

private:

    std::vector<std::shared_ptr<ilrd::IShape>> m_shapes;
    std::vector<std::shared_ptr<Action>> m_acts;

    Factory<Shapes, ilrd::IShape, Args> m_shape_factory;
    
    int m_hight;
    int m_width; 
};

class Action
{
public:

    explicit Action() = default;
    Action(const Action& o_) = delete;
    Action& operator=(const Action& rhs_) = delete;
    virtual ~Action() = default;

    virtual void Act() = 0;
};

struct Args
{
    
};


#endif //__ANER_SCREEN_MAMAGER_HPP__