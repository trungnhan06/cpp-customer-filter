#include <cassert>
#include <iostream>
#include <vector>

#include "../filterByMinPurchases.hpp"

void testSearch() {
    std::vector<customer> customers = {
        {"alice@gmail.com", 2, "Alice"},
        {"bob@gmail.com", 8, "Bob"},
        {"charlie@gmail.com", 10, "Charlie"}
    };

    std::vector<customer> result = search(customers, 5);

    assert(result.size() == 2);
    assert(result[0].name == "Bob");
    assert(result[1].name == "Charlie");

    std::cout << "testSearch passed.\n";
}

int main() {
    testSearch();
    std::cout << "All tests passed.\n";
    return 0;
}