# include <stdio.h>
# include <stdlib.h>

# define MaxSize 10

typedef struct{
    int data[MaxSize];
    int length;
}SeqList;

//初始化方法
void InitLize(SeqList &L){
    L.length=0;
}

//删除所有指定元素的方法
bool DleteSameElem(SeqList &L,int element){
    int count = 0;
    for (int i = 0; i < L.length; i++)
    {
        if(L.data[i]!=element){
            L.data[count]=L.data[i];
            count++;
        }
        L.length=count;
    }
    
    
}