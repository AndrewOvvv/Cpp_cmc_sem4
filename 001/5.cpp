#include <iostream>
#include <ostream>
#include <vector>
#include <string>

using std::string;


class BinaryNumber
{
    std::vector<char> n;
    int size;
public:
    BinaryNumber(const string &s) {
        size = s.size();
        n.resize(size);
        for (int i = size - 1; i > -1; --i) {
            n[size - i - 1] = s[i];
        }
    }
    operator string () const {
        string result = "";
        for (int i = size - 1; i > -1; --i) {
            result += n[i];
        }
        return result;
    }
    const BinaryNumber &operator++() {
        int current = 0;
        while (current < size && n[current] == '1') {
            n[current] = '0';
            ++current;
        }
        if (current < size) {
            n[current] = '1';
        } else {
            n.resize(size + 1);
            ++size;
            n[current] = '1';
        }
        return *this;
    }
};
