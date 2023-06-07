#include <iostream>
#include <stdint.h>
#include <vector>


namespace {
    size_t DUMP_SIZE = 16;
    size_t UINT_SIZE = 4;

    uint32_t STEP_SIZE = 16 * 16;
};



int main()
{
    size_t cnt = 0;
    uint32_t current_number = 0;
    uint32_t hex_step = 0;

    std::vector<uint32_t> readed(4); 

    while (std::cin >> std::hex >> hex_step) {
        for (size_t i = 0; i < DUMP_SIZE; ++i) {
            if (!(std::cin >> std::hex >> readed[cnt++])) {
                break;
            } else if (cnt == UINT_SIZE) {
                cnt = 0;
                current_number = 0;
                for (size_t i = 0; i < UINT_SIZE; ++i) {
                    current_number *= STEP_SIZE;
                    current_number += readed[i]; 
                }
                std::cout << std::dec << current_number << std::endl;
            }
        }
    }
    return 0;
}
