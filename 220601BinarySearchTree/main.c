#include <stdio.h>
#include <stdlib.h>

typedef struct node * treePointer;
struct node {
    int data;
    treePointer leftChild, rightChild;
};
treePointer modifiedSearch(treePointer tree, int key);
void insert(treePointer * node, int key);
void deleteData(treePointer * ptr, int key);
void inorder(treePointer *ptr);
int main(void){
    treePointer root=NULL;
    int a;
    char b;
    printf("Enter 's' if you want to print Tree:");
    scanf("%c",&b);
    while(b!='s'){
        scanf("%d",&a);
        if(b=='i'){
            insert(&root,a);
            printf("Enter 's' if you want to print Tree:");
        }else if(b=='d'){
            deleteData(&root,a);
            printf("Enter 's' if you want to print Tree:");
        }
        scanf("%c",&b);
    }
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

void deleteData(treePointer * ptr, int key){
    treePointer temp = *ptr;
    treePointer pre, next, prenext;
    int direction, found=0;

    while( (temp!=NULL) && !found){ //find key
        if(key==temp->data){
            found = 1;
        }else if(key > temp->data){
            pre = temp;
            temp=temp->rightChild;
            direction=1;
        }else{
            pre = temp;
            temp=temp->leftChild;
            direction=0;
        }
    }

    if(!found){
        return;
    }else{//found=1

        if( temp->rightChild==NULL && temp->leftChild==NULL ){ //key has no Child

            if(temp==*ptr){//key=root
                *ptr=NULL;
            }else{
                if(direction==1){
                    pre->rightChild=NULL;
                }else{
                    pre->leftChild=NULL;
                }
            }

        }

        if( temp->rightChild!=NULL && temp->leftChild==NULL ){ //key has rightChild
            if(temp==*ptr){ //key=root
                *ptr=(*ptr)->rightChild;
            }else{
                if(direction==1){ //key is pre's rightChild
                    pre->rightChild=temp->rightChild;
                }else{
                    pre->leftChild=temp->rightChild;
                }
            }
        }

        if( temp->rightChild==NULL && temp->leftChild!=NULL ){ //key has leftChild
            if(temp==*ptr){ //key=root
                *ptr=(*ptr)->leftChild;
            }else{
                if(direction==1){ //key is pre's rightChild
                    pre->rightChild=temp->leftChild;
                }else{
                    pre->leftChild=temp->leftChild;
                }
            }
        }

        if( temp->rightChild!=NULL && temp->leftChild!=NULL ){ //key has rightChild and leftChild
            next=temp->leftChild;
            if(next->rightChild==NULL){ //next has no rightChild
                next->rightChild = temp->rightChild;
                if(temp==*ptr){ //key=root
                    *ptr=next;
                }else{
                    if(direction==1){ //key is pre's rightChild
                        pre->rightChild=next;
                    }else{
                        pre->leftChild=next;
                    }
                }
            }else{ //next has rightChild
                while(next->rightChild!=NULL){
                    prenext=next;
                    next=next->rightChild;
                }
                prenext->rightChild=next->leftChild;
                next->leftChild=temp->leftChild;
                next->rightChild=temp->rightChild;
                if(temp==*ptr){
                    *ptr=next;
                }else{
                    if(direction==1){
                        pre->rightChild=next;
                    }else{
                        pre->leftChild=next;
                    }
                }
            }
        }
    }

    free(temp);
    return;
}

void inorder(treePointer *ptr){
    if(*ptr){
        inorder(&(*ptr)->leftChild);
        printf("%d ",(*ptr)->data);
        inorder(&(*ptr)->rightChild);
    }
}