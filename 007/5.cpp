#include <iostream>
#include <chrono>


int64_t mabs(int64_t x) 
{
    if (x < 0) {
        return -x;
    }
    return x;
}


int main()
{
    char sep;
    int64_t sum = 0, year, month, day;
    std::cin >> year >> sep >> month >> sep >> day;

    std::chrono::year_month_day current_date{std::chrono::year(year), std::chrono::month(month), std::chrono::day(day)};
    while (std::cin >> year >> sep >> month >> sep >> day) {
        std::chrono::year_month_day next_date{std::chrono::year(year), std::chrono::month(month), std::chrono::day(day)};
        sum += mabs((std::chrono::sys_days(next_date) - std::chrono::sys_days(current_date)).count());
        current_date = next_date;
    }
    std::cout << sum << std::endl;
    return 0;
}
