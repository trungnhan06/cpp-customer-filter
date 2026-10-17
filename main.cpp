#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

#define MAX_LENGTH 100
#define MAX_CUSTOMERS 1000

struct customer {
    std::string email;
    int number_of_purchase;
    std::string name;
};

std::vector<customer> search(std::vector<customer>& list, int num);

int main() {
    char file_name[MAX_LENGTH];

    std::cout << "Enter the file name: ";
    std::cin >> file_name;

    std::ifstream in_file(file_name);
    if (!in_file.is_open()) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    std::vector<customer> customers;
    std::vector<customer> searched_customers;
    std::string line;

    while (std::getline(in_file, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        customer temp;
        std::string purchase;

        if (std::getline(ss, temp.email, ',') &&
            std::getline(ss, purchase, ',') &&
            std::getline(ss, temp.name, ',')) {
            temp.number_of_purchase = std::stoi(purchase);
            customers.push_back(temp);
        }
    }

    int num;
    std::cout << "Enter the number of purchase: ";
    std::cin >> num;

    searched_customers = search(customers, num);
    std::sort(searched_customers.begin(), searched_customers.end(),
              [](const customer& a, const customer& b) {
                  return a.number_of_purchase < b.number_of_purchase;
              });

    std::ofstream output_file("result.csv");
    if (!output_file.is_open()) {
        std::cerr << "Error creating output file 'result.csv'\n";
        return 2;
    }

    for (std::size_t i = 0; i < searched_customers.size(); ++i) {
        output_file << searched_customers[i].email << ", "
                    << searched_customers[i].number_of_purchase << ", "
                    << searched_customers[i].name << '\n';
    }

    output_file.close();
    return 0;
}

std::vector<customer> search(std::vector<customer>& list, int num) {
    std::vector<customer> result;
    for (std::size_t i = 0; i < list.size(); ++i) {
        if (list[i].number_of_purchase >= num) {
            result.push_back(list[i]);
        }
    }
    return result;
}