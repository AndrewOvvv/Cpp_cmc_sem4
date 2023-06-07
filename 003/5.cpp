#include <iostream>
#include <list>


int main()
{
    std::list<int> lst;

    //reading data
    int v; std::cin >> v;
    while (v != 0) {
        lst.push_back(v);
        std::cin >> v;
    }
    //reading data
    

    //quering
    int op_type;
    while (std::cin >> op_type) {
        int data = std::abs(op_type);
        if (op_type > 0) {
            std::cin >> data;
            --op_type;
            if (op_type >= (int)lst.size()) {
                lst.push_back(data);
            } else {
                auto insert_it = lst.begin();
                std::advance(insert_it, op_type);
                lst.insert(insert_it, data);
            }
        } else {
            --data;
            if (data >= (int)lst.size()) {
                continue;
            }
            auto deletion_it = lst.begin();
            std::advance(deletion_it, data);
            lst.erase(deletion_it);
        }
    }

    for (auto it : lst) {
        std::cout << it << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

