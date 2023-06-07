#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

template<typename It, typename Itrm>
auto myremove(It for_deletion_left, It for_deletion_right, Itrm d_left, Itrm d_right)
{
    std::vector<typename It::value_type> indexes;
    auto iter = for_deletion_left;
    while (iter != for_deletion_right) {
        indexes.emplace_back(*iter);
        ++iter;
    }
    

    std::sort(indexes.begin(), indexes.end());
    std::reverse(indexes.begin(), indexes.end());
    auto end_it = std::unique(indexes.begin(), indexes.end());

    int size = 0;

    auto it = indexes.begin();
    while (it != end_it) {
        ++size;
        auto loc_it = d_left;
        for (int i = 0; i < *it; ++i) ++loc_it;
        auto nxt_swp = loc_it;
        ++nxt_swp;

        while (nxt_swp != d_right) {
            std::swap(*loc_it, *nxt_swp);
            ++loc_it;
            ++nxt_swp;
        }
        ++it;
    }

    auto res = d_right;
    for (int i = 0; i < size; ++i) --res;

    return res;
}

