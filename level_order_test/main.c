#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct node * treePointer;
struct node {
    int data;
    treePointer leftChild, rightChild;
};
treePointer modifiedSearch(treePointer tree, int key);
void insert(treePointer * node, int key);
void deleteLeftMax(treePointer * ptr);
void levelorder(treePointer *ptr);

treePointer queue[MAX];
int front=0, rear=0;

int main(void){
    treePointer root=NULL;

    int a[MAX];
    for(int i=0; i<5; i++){
        scanf("%d",&a[i]);
    }
    for(int i=0; i<5; i++){
        insert(&root,a[i]);
    }
    deleteLeftMax(&root);
    levelorder(&root);


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

void deleteLeftMax(treePointer * ptr){
    treePointer temp=*ptr;
    treePointer pre;
    int direction;
    if(temp->leftChild==NULL){
        printf("The node has no left subtree");
        return;
    }else{
        pre=temp;
        temp=temp->leftChild;
        direction=0;
        while(temp->rightChild!=NULL){
            pre=temp;
            temp=temp->rightChild;
            direction=1;
        }
        if(temp->rightChild==NULL && temp->leftChild==NULL){
            if(direction==1){
                pre->rightChild=NULL;
            }else{
                pre->leftChild=NULL;
            }
        }
        if(temp->rightChild==NULL && temp->leftChild!=NULL){
            if(direction==1){
                pre->rightChild=temp->leftChild;
            }else{
                pre->leftChild=temp->leftChild;
            }
        }

        free(temp);

    }

    return;
}

void addq(treePointer *ptr){
    if(rear==MAX){
        printf("queue full");
    }
    queue[rear]=*ptr;
    rear++;
}
treePointer deleteq(void){
    if(front==rear){
        printf("queue empty");
    }
    return queue[front++];
}
void levelorder(treePointer *ptr){
    if((*ptr)==NULL){
        printf("Nothing in the tree");
    }
    addq(&(*ptr));
    for(int i=0; i<MAX; i++){
        *ptr=deleteq();
        if(ptr){
            printf("%d \n",(*ptr)->data);
            if((*ptr)->leftChild){
                addq(&(*ptr)->leftChild);
            }
            if((*ptr)->rightChild){
                addq(&(*ptr)->rightChild);
            }
        }else{
            break;
        }
    }
}
