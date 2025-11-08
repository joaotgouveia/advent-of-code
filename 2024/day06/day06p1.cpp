#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main() {
    std::ifstream input("day06/day06.in");
    std::vector<std::string> map;
    std::vector<std::vector<bool>> not_visited;
    std::pair<int, int> pos;
    std::pair<int, int> dir;

    int i = 0;
    for (std::string line; std::getline(input, line); ++i) {
        not_visited.emplace_back();
        for (int j = 0; j < line.size(); ++j) {
            not_visited[i].push_back(true);
            switch (line[j]) {
            case '>':
                pos = {i, j};
                dir = {0, 1};
                break;
            case '<':
                pos = {i, j};
                dir = {0, -1};
                break;
            case '^':
                pos = {i, j};
                dir = {-1, 0};
                break;
            case 'v':
                pos = {i, j};
                dir = {1, 0};
                break;
            default:
                break;
            }
        }
        map.push_back(line);
    }

    int visited_positions = 1;
    while (pos.first + dir.first > -1 && pos.first + dir.first < map.size() &&
           pos.second + dir.second > -1 &&
           pos.second + dir.second < map[0].size()) {
        if (map[pos.first + dir.first][pos.second + dir.second] == '#') {
            const int x = dir.first;
            dir.first = dir.second;
            dir.second = -x;
        } else {
            pos.first += dir.first;
            pos.second += dir.second;
            if (not_visited[pos.first][pos.second]) {
                not_visited[pos.first][pos.second] = false;
                ++visited_positions;
            }
        }
    }
    std::cout << visited_positions << "\n";
}
