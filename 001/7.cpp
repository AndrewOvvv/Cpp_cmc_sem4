#include <iostream>
#include <vector>

using std::vector;

class Matrix {
    vector<vector<int>> mt{3, vector<int>(3, 0)};
public:
    int& operator[] (int row, int col) {
        return mt[row][col];
    }


//Iterator for class
    auto begin() { 
        return mt.begin(); 
    }

    auto end() { 
        return mt.end(); 
    }
};
