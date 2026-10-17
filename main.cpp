#include <iostream>
#include <cstdlib>
#include <vector>

#define MAX_LENGTH 100
#define MAX_CUSTOMERS 1000

struct customer {
    char email[MAX_LENGTH];
    int number_of_purchase;
    char name[MAX_LENGTH];
};

std::vector<struct customer> search(std::vector<struct customer> &list, int num);
int compare(const void* p, const void* q);

int main() {
    char file_name[MAX_LENGTH];
    // Get file name
    std::cout << "Enter the file name: ";
    std::cin >> file_name;

    // Open file in read-only mode
    FILE *pFile = fopen(file_name, "r");

    // Check if the file was opened successfully
    if (pFile == nullptr) {
        std::cout << "Error opening input file";
        return 1;
    }

    std::vector<struct customer> customers;
    std::vector<struct customer> searched_customers;

    struct customer temp;
    int count = 0;
    while(fscanf(pFile, "%[^,],%d,%[^\n]\n", temp.email, 
        &temp.number_of_purchase, temp.name) == 3) {
            count++;
            customers.push_back(temp);
        }

    int num;
    std::cout << "Enter the number of purchase: ";
    std::cin >> num;

    searched_customers = search(customers, num);
    qsort(searched_customers.data(), searched_customers.size(), sizeof(struct customer), compare);

    FILE *output_file = fopen("result.csv", "w");
    if(output_file == nullptr) {
        std::cout << "Error creating output file 'result.csv'";
        return 2;
    }

    for(int i = 0; i < searched_customers.size(); i++) {
        fprintf(output_file, "%s, %d, %s\n", searched_customers[i].email, searched_customers[i].number_of_purchase,
                searched_customers[i].name);
    
    }

    fclose(pFile);
    fclose(output_file);

    return 0;
}


std::vector<struct customer> search(std::vector<struct customer> &list, int num) {
    std::vector<struct customer> result;
    for(int i = 0; i < list.size(); i++) {
        if(list[i].number_of_purchase >= num) {
            result.push_back(list[i]);
        }
    }
    return result;
}

int compare(const void* p, const void* q) {
    const struct customer* a = (const struct customer*)p;
    const struct customer* b = (const struct customer*)q;

    return (a->number_of_purchase - b->number_of_purchase);
}