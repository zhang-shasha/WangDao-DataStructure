#include <stdio.h>
#include <stdlib.h>

typedef struct DNode
{
    int *data;
    struct DNode *next, *prior;
    
}*CircularDLinkList;

bool InitDLink(CircularDLinkList &CDL){
    CDL = (DNode*)malloc(sizeof(DNode));
    if(CDL==NULL){
        return false;
    }
    //这里因为是循环双链表 
    // 头节点的前驱指针要指向为尾节点，
    // 尾节点的后继指向头节点
    CDL->next=CDL;
    CDL->prior=CDL;
    return true;
}
