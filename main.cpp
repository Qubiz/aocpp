#include <print>

int main() {
    auto lang = "C++";
    std::println("Hello and welcome to {}", lang);

    for (int i = 1; i <= 5; i++) {
        std::println("{}", i);
    }

    return 0;
}