#include <iostream>
#include <string>

constexpr auto MAXSTACK = 100;

struct MyStack {
    int tos = -1; //top of stack
    char s[MAXSTACK]{}; //MAXSTACK is 100.
};

void pushS(MyStack& S, char item) {
    S.s[++S.tos] = item;
}

const static int TOWER_CNT = 3;


int maxHeight(const MyStack(&towers)[TOWER_CNT])
{
    auto res = 0;
    for (const auto& tower : towers) {
        res = std::max(res, tower.tos + 1);
    }
    return res;
}

int baseWidth(const MyStack(&towers)[TOWER_CNT])
{
    auto res = 0;
    for (const auto& tower : towers) {
        auto base = ((tower.tos == -1) ? 1 : tower.s[0]);
        res = std::max(res, base);
    }
    return res;
}


void printTowers(const MyStack(&towers)[TOWER_CNT]) {
    auto height = maxHeight(towers);
    auto base = baseWidth(towers);

    for ([[maybe_unused]] const auto& _ : towers) {
        std::cout << std::string((base) / 2, ' ')
            << std::string(1, '^')
            << std::string((base - 1) / 2, ' ') << "   ";
    }
    std::cout << std::endl;
    for ([[maybe_unused]] const auto& _ : towers) {
        std::cout << std::string((base) / 2, ' ')
            << std::string(1, '|')
            << std::string((base - 1) / 2, ' ') << "   ";
    }
    std::cout << std::endl;

    for (int j = 0; j != height; ++j) {
        for (const auto& tower : towers) {
            auto plate_index = height - j - 1;
            auto count = ((plate_index < tower.tos + 1) ? tower.s[plate_index] : 0);

            std::cout << std::string(base / 2 - count / 2, ' ')
                << std::string(count / 2, '*')
                << std::string(1, count == 1 ? '*' : '|')
                << std::string((count - 1) / 2, '*')
                << std::string((base - 1) / 2 - (count - 1) / 2, ' ') << "   ";
        }
        std::cout << std::endl;
    }
    for ([[maybe_unused]] const auto& _ : towers) {
        std::cout << std::string(base, '=') << "   ";
    }
    std::cout << std::endl;
}

int main()
{
    MyStack towers[TOWER_CNT];

    pushS(towers[0], 9);
    pushS(towers[0], 7);
    pushS(towers[0], 3);

    pushS(towers[1], 11);
    pushS(towers[1], 1);

    pushS(towers[2], 13);
    pushS(towers[2], 4);

    printTowers(towers);
}