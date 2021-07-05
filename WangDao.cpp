#include <stdio.h>
#include <stdlib.h>

int main(){
    int x = 2;
    int count = 0;
    int n = 128;
    while(x<n/2){
        x= x*2;
        count ++;
        printf("执行了 %d 次\n",count);
    }
    return 0;
}