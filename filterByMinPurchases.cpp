#include "filterByMinPurchases.hpp"

std::vector<customer> search(std::vector<customer>& list, int num) {
    std::vector<customer> result;
    for (std::size_t i = 0; i < list.size(); ++i) {
        if (list[i].number_of_purchase > num) {
            result.push_back(list[i]);
        }
    }
    return result;
}