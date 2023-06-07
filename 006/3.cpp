#include <iostream>
#include <numbers>
#include <string>
#include <sstream>
#include <map>
#include <memory>
#include <functional>
#include <vector>
#include <algorithm>


class Factory {
public:
    static Factory& Instance() {
        static Factory SingleFactory;
        return SingleFactory;
    }

    Figure* make(char type, std::string params) {
        return make_[type](params);
    }
private:
    Factory() {}
    Factory(const Factory& arg) = delete;
    Factory& operator=(const Factory&) = delete;
    
    std::map<char, std::function<Figure*(std::string)>> make_{   {'R', Rectangle::make},
                                                                {'S', Square::make},
                                                                {'C', Circle::make}};

    
};


bool cmp(const std::unique_ptr<const Figure> &arg1, const std::unique_ptr<const Figure> &arg2) {
    return arg1->get_square() < arg2->get_square();
}


int main()
{
    std::vector<std::unique_ptr<const Figure>> figures;

    char type;
    while (std::cin >> type) {
        std::string params;
        std::getline(std::cin, params);
        figures.push_back(std::unique_ptr<const Figure>(Factory::Instance().make(type, params)));
    }

    std::stable_sort(figures.begin(), figures.end(), cmp);

    for (auto &figure : figures) {
        std::cout << figure->to_string() << std::endl;
    }
    return 0;
}
