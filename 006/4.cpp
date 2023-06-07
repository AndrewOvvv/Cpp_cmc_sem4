#include <iostream>
#include <queue>
#include <vector>


namespace Game 
{
    template<typename T>
    class Coord {
    public:
        using value_type = T;

        T row, col;

        Coord() : row(), col() {}
        Coord(T x_) : row(x_), col() {}
        Coord(T x_, T y_) : row(x_), col(y_) {} 
    };

    template<typename T>
    bool in_field(Coord<T> vertex, Coord<T> size) {
        return (T(0) <= vertex.row && vertex.row <= size.row) && (T(0) <= vertex.col && vertex.col <= size.col);
    }

    template<typename T>
    auto dist(Coord<T> size, Coord<T> start, Coord<T> finish) {
        std::deque<std::pair<Coord<T>, T>> queue;
        std::vector<std::vector<bool>> used(size.row + 1, std::vector<bool>(size.col + 1, false));

        queue.push_back({start, 0});
        used[start.row][start.col] = true;

        std::vector<std::vector<std::pair<int, int>>> changes(2);
        changes[0] = {{-1, 0}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        changes[1] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}};

        bool finish_reached = false;
        while (!finish_reached && !queue.empty()) {
            auto [current_v, current_dist] = queue[0];
            queue.pop_front();

            if (current_v.row == finish.row && current_v.col == finish.col) {
                return current_dist;
            }

            for (auto coord_change : changes[current_v.col % 2]) {
                Coord next_v(current_v.row + coord_change.first, current_v.col + coord_change.second);
                if (!used[next_v.row][next_v.col] && in_field(next_v, size)) {
                    used[next_v.row][next_v.col] = true;
                    queue.push_back({next_v, current_dist + 1});
                }
            } 
        }

        return T(0);
    }
}
