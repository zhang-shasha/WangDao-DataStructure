#include <stdio.h>
#include <stdlib.h>
# define InitSize 10
typedef struct{
    int *data;
    int MaxSize;
    int length;
}SeqList;


//初始化
void Initlize(SeqList &L){
    //使用malloc函数申请一片连续的空间
    L.data = (int *)malloc(sizeof(int)*InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

//增加动态数组长度
void IncreaseSize(SeqList &L,int len){
    int *p=L.data;
    L.data = (int *)malloc((L.MaxSize+len)*sizeof(int));
    for(int i = 0;i<L.length;i++){
        L.data[i]=p[i];
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
}

//按位查找
int LocateElem(SeqList L,int i){
    return L.data[i-1];
}

//按值查找
int LocateElemByElem(SeqList L,int e){
    for(int i = 0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return -1;
}

int main(){
    SeqList L;
    Initlize(L);
    IncreaseSize(L,5);
    for (int i = 0;i<L.MaxSize; i++) {
        L.data[i]=i+1;
        printf("data[%d]=%d\n",i,L.data[i]);
    }
    return 0;
}