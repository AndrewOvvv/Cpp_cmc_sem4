#include <iostream>
#include <map>


int main()
{
    std::map<std::string, std::pair<int, int>> results;

    std::string surname;
    int mark;

    while (std::cin >> surname >> mark) {
        results[surname].first += mark;
        results[surname].second++;
    }

    for (auto &[surname, result] : results) {
        std::cout << surname << " " << double(result.first) / double(result.second) << std::endl;
    }
    return 0;
}
