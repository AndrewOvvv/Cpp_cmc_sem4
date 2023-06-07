#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>


template<typename It, typename F>
auto selection_sort(It begin, It end, F cmp)
{
    auto current_element = begin;
    while (current_element != end) {
        auto selected = current_element;
        auto finder = current_element;
        while (finder != end) {
            if (cmp(*finder, *selected)) {
                selected = finder;
            }
            ++finder;
        }
        std::swap(*current_element, *selected);
        ++current_element;
    }
}


template<typename It>
auto selection_sort(It begin, It end)
{
    auto current_element = begin;
    while (current_element != end) {
        auto selected = current_element;
        auto finder = current_element;
        while (finder != end) {
            if (*finder < *selected) {
                selected = finder;
            }
            ++finder;
        }
        std::swap(*current_element, *selected);
        ++current_element;
    }
}
