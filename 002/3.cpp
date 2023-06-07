#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <memory>
#include <vector>
#include <map>
#include <functional>


namespace numbers 
{
complex eval(const std::vector<std::string> &args, const complex &z) {
    complex_stack Pst;

    std::map<const char, std::function<void(complex_stack&, const std::string&, const complex&)>> polish_operations;

    // stack changing
    polish_operations.emplace('z', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { Pst = Pst << z; });
    polish_operations.emplace('(', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { Pst = Pst << complex(arg); });
    polish_operations.emplace('!', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { Pst = Pst << Pst[Pst.size() - 1]; });
    polish_operations.emplace(';', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { Pst = ~Pst; });

    // binary complex operations
    polish_operations.emplace('+', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { 
                complex new_value = Pst[Pst.size() - 1] + Pst[Pst.size() - 2];
                Pst = ~(~Pst);
                Pst = Pst << new_value; 
            });
    polish_operations.emplace('-', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { 
                complex new_value = Pst[Pst.size() - 1] - Pst[Pst.size() - 2];
                Pst = ~(~Pst);
                Pst = Pst << new_value;
            });
    polish_operations.emplace('*', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { 
                complex new_value = Pst[Pst.size() - 1] * Pst[Pst.size() - 2];
                Pst = ~(~Pst);
                Pst = Pst << new_value;
            });
    polish_operations.emplace('/', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { 
                complex new_value = Pst[Pst.size() - 1] / Pst[Pst.size() - 2];
                Pst = ~(~Pst);
                Pst = Pst << new_value;
            });

    // unary complex operations
    polish_operations.emplace('~', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { 
               complex new_value = ~Pst[Pst.size() - 1];
               Pst = ~Pst;
               Pst = Pst << new_value;
            });
    polish_operations.emplace('#', 
            [](complex_stack &Pst, const std::string &arg, const complex &z) { 
                complex new_value = -Pst[Pst.size() - 1];
                Pst = ~Pst;
                Pst = Pst << new_value;
            });

    for (int i = 0; i < int(args.size()); ++i) {
        polish_operations[args[i][0]](Pst, args[i], z);
    }

    return Pst[Pst.size() - 1];
}
}
