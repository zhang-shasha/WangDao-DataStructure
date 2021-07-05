# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int *data;
    int MaxSize;
    int length;
}SeqList;

void Initlize(SeqList &L,int InitSize){
    //使用malloc函数申请一片连续的空间
    L.data = (int *)malloc(sizeof(int)*InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}
//删除最小值的算法
int DeleteMinElement(SeqList &L,int &e){
    if(L.length==0){
        printf("顺序表为空!!");
        exit(1);
    }
    int tempElem = L.data[0];
    int tempLoc = 0;
    for(int i = 0;i<L.length;i++){
        if(L.data[i]>tempElem){
            tempElem = L.data[i];
            tempLoc = i;
        }
    }
    e = L.data[tempLoc];
    L.data[tempLoc] = L.data[L.length-1];
    return e;
}

