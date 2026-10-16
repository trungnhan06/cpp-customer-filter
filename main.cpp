#include <iostream>
#include <cstdlib>

#define MAX_LENGTH 100
#define MAX_CUSTOMERS 1000

struct customer {
    char email[MAX_LENGTH];
    int number_of_purchase;
    char name[MAX_LENGTH];
};

struct customers[] search(struct customer list[], int n, int num);
int compare(const void* p, const void* q);

int main() {
    char file_name[MAX_LENGTH];
    // Get file name
    std::cout << "Enter the file name: ";
    std::cin >> file_name;

    // Open file in read-only mode
    FILE *pFile = open(file_name, "r");

    // Check if the file was opened successfully
    if (pFile == nullptr) {
        std::cout << "Error opening input file";
        return 1;
    }

    struct customer customers[MAX_CUSTOMERS];
    struct customer searched_customers[MAX_CUSTOMERS];

    while(fcanf(pFile, "%[^,],%d,%[^\n]\n", customers[count].email, 
        &customers[count].number_of_purchase, customers[count].name))

    int num;
    std::cout << "Enter the number of purchase: ";
    std::cin >> num;

    searched_customers = search(customers, customers.size(), num);
    qsort(searched_customers, searched_customers.size(), sizeof(struct customer), compare);

    FILE *output_file = open("result.csv", 'w');
    if(output_file == nullptr) {
        std::cout << "Error creating output file 'result.csv'";
        return 2;
    }

    for(int i = 0; i < searched_customers.size(); i++) {
        fprintf(output_file, "%s, %d, %s\n", searched_customers[i].email, searched_customers[i].number_of_purchase
                searched_customers[i].name);
    
    }

    fclose(pFile);
    fclose(output_file);

    return 0;
}


struct customers[] search(struct customer list[], int n, int num) {
    std::vector<struct customer> result;
    for(int i = 0; i < list.size(); i++) {
        if(list[i].number_of_purchase >= num) {
            result.push_back(list[i];)
        }
    }
    return result;
}

int compare(const void* p, const void* q) {
    p = (struct customer*)p;
    q = (struct customer*)q;

    return (p->number_of_purchase - q->number_of_purchase);
}