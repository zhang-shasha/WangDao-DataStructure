# include <stdio.h>
# include <stdlib.h>

typedef struct DNode{
    //数据域
    int *data;
    //前驱指针和后继指针
    struct DNode *prior,*next;

}DNode,*DLinkList;

//初始化双链表
bool InitDoubleList(DLinkList &DL){
    DL=(DNode *)malloc(sizeof(DNode));
    if(DL==NULL){
        printf("内存不足");
        return false;
    }
    DL->prior=NULL;
    DL->next=NULL;
}

//判断双链表是否为空
bool isEmpty(DLinkList &DL){
    if(DL->next==NULL){
        return true;
    }
    return false;
}

//插入操作
bool InsertNextDNode(DNode *p,DNode *s){
    if(p==NULL||s==NULL){
        return false;
    }
    s->next=p->next;
    //判断p是否为最后一个节点
    if(p->next!=NULL){
        p->next->prior=s;
    }
    s->prior=p;
    p->next=s;

    return true;
}

//删除操作指定节点的后继节点
bool DeleteNextNode(DNode *p){
    if(p==NULL){
        return false;
    }
    //找寻p节点的后继节点
    DNode *q = p->next;
    if(q==NULL){
        return false;
    }
    p->next = q->next;
    //p的后继节点是否是最后一个节点
    if(q->next!=NULL){
        q->next->prior = p;
    }
    free(q);
    return true;
}

//销毁双链表
bool DestoryDLink(DLinkList &L){
    while (L->next!=NULL)
    {
        DeleteNextNode(L);
    }
    free(L);
    return true;

}




