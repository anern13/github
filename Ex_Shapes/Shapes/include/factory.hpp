/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 26 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef __ANER_FACTORY_HPP__
#define __ANER_FACTORY_HPP__

#include <unordered_map> //std::unordered_map
#include <memory>        //std::shared_ptr
#include <functional>    //std::function

#include "singleton.hpp"

/******************************************************************************/
template <typename KEY, typename BASE, typename ARGS>
class Factory
{
public:
    //Base must contain static CreateFunc  
    using CreateFunc = std::function<std::shared_ptr<BASE>(ARGS args_)>;

    //overrides a current method if already exists
    void Add(const KEY& key_, CreateFunc create_func_);
    // Create may throw exception
    std::shared_ptr<BASE> Create(const KEY& key_, ARGS args_);


    Factory(const Factory& other_) = delete;
    Factory& operator=(const Factory& other_) = delete;
private:
    ~Factory() = default;
    explicit Factory() = default;

    std::unordered_map<KEY, CreateFunc> m_map;
    friend class Singleton<Factory>;
};
/******************************************************************************/
template <typename KEY, typename BASE, typename ARGS>
void Factory<KEY,BASE,ARGS>::Add(const KEY& key_, CreateFunc create_func_)
{
    m_map[key_] = create_func_;
}
/******************************************************************************/
template <typename KEY, typename BASE, typename ARGS>
std::shared_ptr<BASE> Factory<KEY,BASE,ARGS>::Create(const KEY& key_,ARGS args_)
{
    CreateFunc create = m_map[key_];

    return create(args_);
}
/******************************************************************************/

#endif//__ANER_FACTORY_HPP__