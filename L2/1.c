#include <iostream>

int maxProduct(int v[], int size, int* a, int* b, int* c){
    int p;
    int pmax = -1;
    for (int i = 0; i < size-2; i++){
        for (int j = 0; j < size-1; j++){
            for(int k = 0; k < size; k++){
                *a = v[i];
                *b = v[j];
                *c = v[k];
                p = *a * *b * *c;
                if (p > pmax){
                    pmax = p;
                }
            }
        }
    }
    return pmax;
}

int main(){
    int* v = (int *) malloc(50*sizeof(int));
    int size = 10;
    for(int i = 0; i < size; i++){
        v[i] = i;
    }
    int a, b, c;
    int product = maxProduct(v, size, &a, &b, &c);
    printf("Max product is %d with a = %d, b = %d, c = %d\n", product, a, b, c);
}