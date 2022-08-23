#include <stdio.h>
#include <stdlib.h>

typedef struct node * treePointer;
struct node {
    int data;
    treePointer leftChild, rightChild;
};
treePointer modifiedSearch(treePointer tree, int key);
void insert(treePointer * node, int key);
void deleteRightMin(treePointer * ptr);
void inorder(treePointer * ptr);
int main(void){
    treePointer root=NULL;
    int a[8];
    for(int i=0; i<8; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<8; i++){
        insert(&root,a[i]);
    }
    inorder(&root);
    printf("\n");
    deleteRightMin(&root);
    inorder(&root);

    return 0;
}

treePointer modifiedSearch(treePointer tree, int key){
    treePointer current, temp;
    if(!tree){
        return NULL;
    }else{
        current=tree;
    }

    if(key==current->data){
        return NULL;
    }
    if(key<current->data){
        temp=current->leftChild;
    }else{
        temp=current->rightChild;
    }

    while(temp){
        current = temp;
        if(key==current->data){
            return NULL;
        }
        if(key<current->data){
            temp=current->leftChild;
        }else{
            temp=current->rightChild;
        }
    }
    return current;
}
void insert(treePointer * node, int key){
    treePointer ptr;
    treePointer temp = modifiedSearch(*node,key);
    if(temp){
        ptr=(treePointer) malloc (sizeof (node));
        ptr->data = key;
        ptr->leftChild=ptr->rightChild=NULL;
        if(key<temp->data){
            temp->leftChild = ptr;
        }else{
            temp->rightChild = ptr;
        }
    }else{//temp=NULL
        if(!(*node)){
            ptr=(treePointer) malloc (sizeof (node));
            ptr->data = key;
            ptr->leftChild=ptr->rightChild = NULL;
            *node = ptr;
        }
    }
}

void deleteRightMin(treePointer * ptr){
    treePointer temp=*ptr;
    treePointer pre;
    int direction;
    if(temp->rightChild==NULL){
        printf("The node has no right subtree");
        return;
    }else{
        pre=temp;
        temp=temp->rightChild;
        direction=1;
        while(temp->leftChild!=NULL){
            pre=temp;
            temp=temp->leftChild;
            direction=0;
        }
        if(temp->rightChild==NULL && temp->leftChild==NULL){
            if(direction==1){
                pre->rightChild=NULL;
            }else{
                pre->leftChild=NULL;
            }
        }
        if(temp->rightChild!=NULL && temp->leftChild==NULL){
            if(direction==1){
                pre->rightChild=temp->rightChild;
            }else{
                pre->leftChild=temp->rightChild;
            }
        }

        free(temp);

    }

    return;
}

void inorder(treePointer * ptr){
    if(*ptr){
        inorder(&(*ptr)->leftChild);
        printf("%d ",(*ptr)->data);
        inorder(&(*ptr)->rightChild);
    }
}
