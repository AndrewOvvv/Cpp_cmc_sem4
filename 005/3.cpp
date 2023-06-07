#include <iostream>
#include <vector>


template<typename It, typename F>
void myapply(It first, It last, F applier) 
{
    auto iter = first;
    while (iter != last) {
        applier(*iter);
        ++iter;
    }
}

template<typename It, typename F>
auto myfilter2(It first, It last, F filter)
{
    auto iter = first;
    std::vector<std::reference_wrapper<typename It::value_type>> result_container;
    while (iter != last) {
        if (filter(*iter)) {
            result_container.emplace_back(*iter);
        }
        ++iter;
    }
    return result_container;
}

template<typename T, typename F>
auto myfilter2(T *first, T *last, F filter) 
{
    auto iter = first;
    std::vector<std::reference_wrapper<T>> result_container;
    while (iter != last) {
        if (filter(*iter)) {
            result_container.emplace_back(*iter);
        }
        ++iter;
    }
    return result_container;
}
