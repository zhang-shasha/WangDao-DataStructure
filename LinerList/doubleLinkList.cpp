# include <stdio.h>
# include <stdlib.h>

typedef struct DNode{
    //数据域
    int *data;
    //前驱指针和后继指针
    struct DNode *prior,*next;

}DNode,*DLinkList;

bool InitDoubleList(DLinkList &DL,int InitSize){
    DL=(DNode *)malloc(sizeof(DNode)*InitSize);
    if(DL==NULL){
        printf("内存不足");
        return false;
    }
    DL->prior=NULL;
    DL->next=NULL;
}


