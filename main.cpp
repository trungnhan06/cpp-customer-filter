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

    // Open the input file
    std::ifstream input_file(file_name);
    if (!input_file.is_open()) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    // Read customers from the input file
    std::vector<customer> customers_list = readCustomers(input_file);

    // Prompt the user for the minimum number of purchases
    int num;
    std::cout << "Enter the number of purchase: ";
    std::cin >> num;

    // Search for customers with at least 'num' purchases
    std::vector<customer>searched_customers = search(customers_list, num);
    std::sort(searched_customers.begin(), searched_customers.end(),
              [](const customer& a, const customer& b) {
                  return a.number_of_purchase < b.number_of_purchase;
              });

    // Write the results to an output file
    std::ofstream output_file("result.csv");
    if (!output_file.is_open()) {
        std::cerr << "Error creating output file 'result.csv'\n";
        return 2;
    }

    // Write the searched customers to the output file
    writeCustomers(searched_customers, output_file);

    // Close the files
    input_file.close();
    output_file.close();
    return 0;
}

