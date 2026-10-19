#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "CustomerDatabase.hpp"

std::vector<customer> readCustomers(std::ifstream& iFile) {
    std::vector<customer> result;
    std::string line;

    while (std::getline(iFile, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        customer temp;
        std::string purchase;

        if (std::getline(ss, temp.email, ',') &&
            std::getline(ss, purchase, ',') &&
            std::getline(ss, temp.name, ',')) {
            try {
                size_t pos = 0;
                int count = std::stoi(purchase, &pos);
                
                if (pos != purchase.size() || count < 0) {
                    throw std::invalid_argument("Invalid purchase count");
                }
                
                temp.number_of_purchase = std::stoi(purchase);
                result.push_back(temp);
            }
            catch (const std::invalid_argument&) {
                std::cerr << "Invalid purchase count: " << purchase << "\n";
                continue;
            }
            catch (const std::out_of_range&){
                std::cerr << "Purchase count is too large: " << purchase << "\n";
                continue;
            }
        }
        
        
    }

    return result;
}

void writeCustomers(const std::vector<customer>& list, std::ofstream& oFile) {
    for (std::size_t i = 0; i < list.size(); i++) {
    oFile << list[i].email << ", "
                << list[i].number_of_purchase << ", "
                << list[i].name << '\n';
    }   
}
