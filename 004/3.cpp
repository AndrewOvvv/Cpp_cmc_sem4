#include <iostream>
#include <set>
#include <map>


int main()
{
    std::map<std::pair<std::string, std::string>, std::string> table;
    std::set<std::string> dates, surnames;

    std::string surname, date, mark;
    while (std::cin >> surname >> date >> mark) {
        if (date.size() != 10) {
            std::string newd = "0000/00/00";
            int cnt_y = 0, cnt_m = 0, cnt_d = 0, cnt_s = 0;
            for (int i = 0; i < (int)date.size(); ++i) {
                if (date[i] == '/') {
                    cnt_s++;
                } else if (cnt_s == 0) {
                    cnt_y++;
                } else if (cnt_s == 1) {
                    cnt_m++;
                } else {
                    cnt_d++;
                }
            }
            for (int i = 4 - cnt_y; i < 4; ++i) {
                newd[i] = date[i - (4 - cnt_y)];
            }
            for (int i = 7 - cnt_m; i < 7; ++i) {
                newd[i] = date[cnt_y + 1 + i - (7 - cnt_m)];
            }
            for (int i = 10 - cnt_d; i < 10; ++i) {
                newd[i] = date[cnt_y + 1 + cnt_m + 1 + i - (10 - cnt_d)];
            }
            date = newd;
        }
        dates.insert(date);
        surnames.insert(surname);
        table[{surname, date}] = mark;
    }
    
    //print first header line
    std::cout << ". ";
    for (auto &v : dates) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    //

    for (auto &v : surnames) {
        std::cout << v << " ";
        for (auto &date : dates) {
            if (table.find({v, date}) != table.end()) {
                std::cout << table[{v, date}] << " ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
