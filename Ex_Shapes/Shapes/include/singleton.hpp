/******************************************************************************/
//Author : anern13
//Project : Shapes
//Date : 26 / 06 / 22 
//Version : 1.0
/******************************************************************************/
#ifndef __ANER_SINGLETON_HPP__
#define __ANER_SINGLETON_HPP__

#include <mutex> //std::mutex
#include <atomic>//std::atomic_thread_fence std::memory_order_acquire std::atomic_thread_fence std::memory_order_release

//compile with -E --export-dynamic
//for dynamic loading support

/******************************************************************************/
template <class T>//T must have a default constructor must support new, delete
class Singleton
{
public:
    static T* GetInstance();
    //noncopyable
    Singleton(Singleton<T>& other_)= delete;
    Singleton<T>& operator=(Singleton<T>& rhs_)= delete;
private:    
    explicit Singleton();
    ~Singleton();

    static std::mutex s_mutex;
    static T* s_instance;
    class Destroyer;
};
/***********************************/
template <class T>
T* Singleton<T>::s_instance = nullptr;

template <class T>
std::mutex Singleton<T>::s_mutex;
/******************************CLASS DESTROYER*********************************/
template <class T>
class Singleton<T>::Destroyer
{
public:
    Destroyer();
    ~Destroyer();
    Destroyer(Destroyer& other_) = delete;
    Destroyer& operator=(Destroyer& rhs_) = delete;
    T* Get();
private:
    T* m_obj;
};
/******************************CLASS DESTROYER*********************************/
template <class T>
Singleton<T>::Destroyer::Destroyer()
    : m_obj(new T) {}//empty

template <class T>
Singleton<T>::Destroyer::~Destroyer()
{
    delete m_obj;
}

template <class T>
T* Singleton<T>::Destroyer::Get()
{
    return m_obj;
}
/******************************************************************************/
/******************************CLASS SINGLETON*********************************/
template <class T>
T* Singleton<T>::GetInstance()
{
    std::atomic_thread_fence(std::memory_order_acquire);
    if(!s_instance)
    {
        s_mutex.lock();
        if(!s_instance)
        {
            static Singleton<T>::Destroyer destroyer;
            s_instance = destroyer.Get();
        }
        s_mutex.unlock();
    }
    std::atomic_thread_fence(std::memory_order_release);

    return s_instance;
};

#endif//__ANER_SINGLETON_HPP__