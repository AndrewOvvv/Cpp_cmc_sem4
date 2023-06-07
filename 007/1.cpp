#include <iostream>
#include <string>
#include <exception>


class StringStorage {
private:
    std::string in;
public:
    StringStorage (std::string &s) : in(s) {}

    ~StringStorage() {
        std::cout << in << std::endl;
    }
};


void ReadPrint() {
    std::string s;
    if (std::cin >> s) {
        StringStorage readed(s);
        ReadPrint();
    }
    throw std::domain_error("you died");
}


int main()
{
    try {
        ReadPrint();
    } 
    catch (...) {}
    return 0;
}
