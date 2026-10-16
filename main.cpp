#include <iostream>

#define MAX_LENGTH 100
#define MAX_CUSTOMERS 1000

struct customer {
    char email[MAX_LENGTH];
    int number_of_purchase;
    char name[MAX_LENGTH];
};

int search(struct customer list[], int n, int num, struct customer result[]);

int main() {
    
    return 0;
}
