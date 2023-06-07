#include <iostream>
#include <string>
#include <vector>


bool is_operation(char symbol) 
{
    return (symbol == '/') || (symbol == '*') || (symbol == '-') || (symbol == '+');
}


int main()
{
    std::string str{}, ans{}; 
    std::vector<std::string> polish_stack;
    
    char current;
    while (std::cin >> current) {
        if (is_operation(current)) {
            std::string ops = polish_stack.back();
            polish_stack.pop_back();
            std::string opf = polish_stack.back();
            polish_stack.pop_back();

            polish_stack.push_back("(" + opf + current + ops + ")");
        } else {
            polish_stack.push_back({current});
        }
    }

    std::cout << polish_stack.back() << std::endl;

    return 0;
}
