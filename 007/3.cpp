#include <iostream>


class S {
public:
    int value{};
    bool completed_read = true;
    bool empty = true;

    operator bool() const {
        return completed_read;      
    }

    S() {
        if (!(std::cin >> value)) {
            completed_read = false;
        } 
    }

    S(S &&other) {
        empty = false;
        if (!(std::cin >> value)) {
            completed_read = false;
            value = 0;
        } 
        value += other.value;
    }

    ~S() {
        if (!completed_read && !empty) {
            std::cout << value;
        }
    }
};

