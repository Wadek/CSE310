#include <stdio.h>
#include <malloc.h>

using namespace std;

int main() {
    int * var = (int*) malloc(10 * sizeof(int));
    int sum = 0;

    for(int index = 0; incdex < 10; index++) {
        var(index) = index;
        printf("%d\n", var(index));
        sum = sum + var(index);
    }
    printf("%d\", sum);
    free(var);
}
