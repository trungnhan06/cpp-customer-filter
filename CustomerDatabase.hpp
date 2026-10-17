#pragma once
#include <string>
#include <fstream>
#include <vector>

struct customer {
    std::string email;
    int number_of_purchase;
    std::string name;
};

std::vector<customer> readCustomers(std::ifstream& iFile);
void writeCustomers(const std::vector<customer>& list, std::ofstream& oFile);