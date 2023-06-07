#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>


int main()
{
    std::unordered_map<std::string, std::vector<std::pair<char, std::string>>> graph;
    std::string cur, next;
    char sym;


    std::cin >> cur;
    while (cur != "END") {
        std::cin >> sym >> next;
        if (graph.find(cur) == graph.end()) {
            graph[cur] = {};
        }
        graph[cur].push_back({sym, next});
        std::cin >> cur;
    }

    std::vector<std::string> end_states;
    std::string end_state{};
    std::cin >> end_state;
    while (end_state != "END") {
        end_states.push_back(end_state);
        std::cin >> end_state; 
    }

    std::string current_state; std::cin >> current_state;

    int number = 0;
    char current;
    while (std::cin >> current) {
        bool find_path = false;
        for (auto &p : graph[current_state]) {
            if (p.first == current) {
                ++number;
                current_state = p.second;
                find_path = true;
            }
        }
        if (!find_path) {
            std::cout << 0 << std::endl;
            std::cout << number << std::endl;
            std::cout << current_state << std::endl;
            return 0;
        }
    }

    bool finished = false;
    for (auto &end : end_states) {
        if (current_state == end) {
            finished = true;
        }
    }


    if (finished) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    std::cout << number << std::endl;
    std::cout << current_state << std::endl;
    return 0;
}
