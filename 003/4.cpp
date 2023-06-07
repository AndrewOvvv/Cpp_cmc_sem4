#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


class Average {
    double sum{};
    int cnt{};

public:
    Average() :
        sum(0),
        cnt(0)
    {}

    void operator() (double v) {
        sum += v;
        ++cnt;
    } 

    double get() {
        if (cnt == 0) {
            return 0;
        }
        return sum / (double)cnt;
    }
};


int main()
{
    std::vector<double> tests;


    //reading data
    double buf;
    while (std::cin >> buf) {
        tests.push_back(buf);
    }
    //reading data
    

    //10% begin and end erase
    int deletion_size = tests.size() / 10;
    tests.erase(tests.begin(), tests.begin() + deletion_size);
    tests.erase(tests.end() - deletion_size, tests.end());
    //10% begin and end erase
    
    //10% low and high erase
    std::sort(tests.begin(), tests.end());
    deletion_size = tests.size() / 10;
    tests.erase(tests.begin(), tests.begin() + deletion_size);
    tests.erase(tests.end() - deletion_size, tests.end());
    //10% low and high erase
    
    auto avr = for_each(tests.begin(), tests.end(), Average());
    
    std::cout << std::fixed << std::setprecision(10) << avr.get() << std::endl;
    return 0;
}

