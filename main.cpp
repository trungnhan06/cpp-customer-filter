#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#include "CustomerDatabase.hpp"
#include "filterByMinPurchases.hpp"

int main() {
    std::string file_name;

    std::cout << "Enter the file name: ";
    std::cin >> file_name;

    std::ifstream in_file(file_name);
    if (!in_file.is_open()) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    std::vector<customer> customers_list = readCustomers(in_file);

    int num;
    std::cout << "Enter the number of purchase: ";
    std::cin >> num;

    std::vector<customer>searched_customers = search(customers_list, num);
    std::sort(searched_customers.begin(), searched_customers.end(),
              [](const customer& a, const customer& b) {
                  return a.number_of_purchase < b.number_of_purchase;
              });

    std::ofstream output_file("result.csv");
    if (!output_file.is_open()) {
        std::cerr << "Error creating output file 'result.csv'\n";
        return 2;
    }

    writeCustomers(searched_customers, output_file);

    output_file.close();
    return 0;
}

