#include <stdio.h>
#include <stdlib.h>

typedef struct LNode{
    //数据域
    int data;
    //指针域
    struct LNode *next;
    
}*LinkList;
//这里 LNode * L <==> LinkList L

//初始化(不带头结点)
bool InitList(LinkList &L){
    L = NULL;
    return true;
}

//初始化(带头结点)
bool InitListWithHeadNode(LinkList &L){
    //在内存中申请头结点空间
    L = (LNode *)malloc(sizeof(LNode));
    if(L==NULL){
        return false;
    }
    L->next = NULL;
    return true;
}

//在 i 位置插入元素 e(带头结点)
bool ListInsertWithHeadNode(LinkList &L,int i,int e){
    if(i<1){
        return false;
    }
    LNode *p;   //指向当前扫描到的节点
    int j = 0;  //当前 p 指向的是第几个节点
    p = L;      //p指向的是头结点
    while(p!=NULL&&j<i-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
    
}

//在 i 位置插入元素 e(不带头结点)
bool ListInsertNoHeadNode(LinkList &L,int i,int e){
    if(i<1){
        return false;
    }
    //当在第一个位置插入元素师的时候
    if(i==1){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data=e;
        s->next=L;
        L=s;
        return true;
    }
    LNode *p;
    int j = 1;  //这里j=1是因为我们没有头结点
    p=L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
    
}

//在p节点后插入元素e
bool InsertNextNode(LNode *p,int e){
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL){
        return false;
    }
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}

//指定节点前面插入元素e
bool InsertPriorNode(LNode *p,int e){
    if(p==NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL){
        return false;
    }
    //偷天换日大法
    s->next=p->next;
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}

//删除指定位置(带头结点)
bool LinkListDelete(LinkList &L,int i,int &e){
    if(i<1){
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while(p!=NULL&&j<i-1){
        p=p->next;
        j++;
    }
    LNode *q=p->next;
    e = q->data;
    p->next=q->next;
    free(q);
    return true;
}

//删除指定节点
bool DeleteNode(LNode *p){
    if(p==NULL){
        return false;
    }
    LNode *q = p->next;
    p->data=p->next->data;
    p->next=q->next;
    free(q);
    return true;
}

//按位查找
LNode *GetElem(LinkList &L,int i){
    if(i<0){
        return NULL; 
    }
    LNode *p;
    int j =0;
    p=L;
    while(p!=NULL&&j<i){
        p=p->next;
        j++;
    }
    return p;
}

//按值查找
LNode *LocateElem(LinkList &L,int e){
    LNode *p = L->next;
    while(p!=NULL&&p->data!=e){
        p=p->next;
    }
    return p;
}

//求表长
int length(LinkList &L){
    int len = 0;
    LNode *p = L;
    if(p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

//尾插法建立单链表
LinkList ListTailInsert(LinkList &L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    LNode *r,*s=L;
    scanf("%d",&x);
    while(x!=20){
        s = (LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}

//头插法建立单链表
LinkList ListHeadInsert(LinkList &L){
    int x;
    LNode *s;
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
    scanf("%d",&x);
    while (x!=20)
    {
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        s->next=L->next;
        L->next=s;
        scanf("%d",&x);
    }
    return L;
    
}

int main(int argc, char const *argv[])
{
    LinkList L;
    // int e;
    // InitListWithHeadNode(L);
    // ListInsertWithHeadNode(L,1,2);
    // LinkListDelete(L,1,e);
    ListTailInsert(L);

    return 0;
}
