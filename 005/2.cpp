#include <iostream>
#include <vector>

template<typename T, typename F>
auto myfilter(const T &container, F filter)
{
    std::vector<typename T::value_type> buffer;
    
    for (const auto &v : container) {
        if (filter(v)) {
            buffer.push_back(v);
        }
    }    

    T result_container(buffer.begin(), buffer.end());
    return result_container;
}
