#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>


void dfs(char state, std::unordered_map<char, std::vector<std::string>> &graph, std::unordered_map<char, bool> &used)
{
    used[state] = true;
    for (auto &next_str : graph[state]) {
        for (int i = 0; i < int(next_str.size()); ++i) {
            if ('A' <= next_str[i] && next_str[i] <= 'Z' && !used[next_str[i]]) {
                dfs(next_str[i], graph, used);
            }
        }
    }
}


int main()
{
    std::unordered_map<char, std::vector<std::string>> graph;
    std::unordered_map<char, bool> used;


    char term;
    std::string nws;
    while (std::cin >> term >> nws) {
        if (graph.find(term) == graph.end()) {
            graph[term] = {};
        }
        graph[term].push_back(nws);
        used[term] = false;
    }

    
    dfs('S', graph, used);
    for (auto &item : graph) {
        if (used[item.first]) {
            for (auto &res : item.second) {
                std::cout << item.first << " " << res << std::endl;
            }
        }
    }
    return 0;
}
