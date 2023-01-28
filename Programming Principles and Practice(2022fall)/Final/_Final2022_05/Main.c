#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct product {
    char productName[MAX_SIZE];
    int price;
    int quantity;
} PRODUCT;

// The following functions are given complete code (hidden state).
// Good Luck! 
void printProduct(int size, PRODUCT* products);
void readFromFile(char* filename, int size, PRODUCT* products);
PRODUCT *newProducts(int N) {
    // implement your code
}

int sum(int size, PRODUCT* products){
		return 10000;
}

void readFromKeyboard(int size, PRODUCT* products) {
		// implement your code
}

void save(char* filename, int size, PRODUCT* products) {
    // implement your code
}
int main() {
    int N;
    scanf("%d", &N);
    PRODUCT* products = newProducts(N);

    readFromKeyboard(N, products);

    save("products.txt", N, products);
    free(products);

    products = newProducts(N);
    readFromFile("products.txt", N, products);

    printProduct(N, products);
	  printf("Total Price: %d\n", sum(N, products));
    free(products);

    return 0;
}
void readFromFile(char* filename, int size, PRODUCT* products){
    FILE * fp = fopen(filename, "r");
    for (int i = 0; i < size; ++i) {
        fscanf(fp, "%s %d %d\n", &products[i].productName, &products[i].price, &products[i].quantity);
    }
    fclose(fp);
}
void printProduct(int size, PRODUCT* products){
    PRODUCT* p = products;
    while (p < products + size) {
        printf("%s %d %d\n", p->productName, p->price, p->quantity);
        p++;
    }
}