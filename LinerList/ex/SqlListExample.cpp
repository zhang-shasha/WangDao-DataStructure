# include <stdio.h>
# include <stdlib.h>
# 
# define MaxSize 10

typedef struct{
    int data[MaxSize];
    int length;
}SeqList;

//初始化方法
void InitLize(SeqList &L){
    L.length=0;
}
// 插入元素
bool ListInsert(SeqList &L,int i ,int e){
    //判断插入位置是否合法
    if(i<1||i>L.length+1){
        return false;
    }
    //判断线性表是否满
    if(L.length==MaxSize){
        return false;
    }
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
//删除操作
bool ListDelete(SeqList &L , int i , int &e){
    if(i<1||i>L.length+1){
        return false;
    }
    e = L.data[i-1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
    
}
int DeleteMinElement(SeqList &L,int &e){
    if(L.length==0){
        printf("顺序表为空!!");
        exit(1);
    }
    int tempElem = L.data[0];
    int tempLoc = 0;
    for(int i = 0;i<L.length;i++){
        if(L.data[i]<tempElem){
            tempElem = L.data[i];
            tempLoc = i;
        }
    }
    e = tempElem;
    L.data[tempLoc] = L.data[L.length-1];
    L.length--;
    return e;
}

int main(){
    SeqList L;
    int e = -1;
    InitLize(L);
    ListInsert(L,1,2);
    ListInsert(L,2,5);
    ListInsert(L,3,6);
    DeleteMinElement(L,e);
    for (int i = 0; i < L.length+1; i++)
    {
        printf("data[%d] --> %d\n",i,L.data[i]);
    }
    
    printf("%d",e);
    
    return 0;
}
