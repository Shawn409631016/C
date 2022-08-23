#include <stdio.h>
#include <stdlib.h>

typedef struct node *treePointer;
struct node{
    int data;
    treePointer leftChild, rightChild;
};
treePointer queue[4];
int front=0, rear=0;


void createBinaryTree(treePointer *ptr);
void inorder(treePointer *ptr);
void preorder(treePointer *ptr);
void postorder(treePointer *ptr);
void levelorder(treePointer *ptr);
int main() {
    treePointer  root,temp;
    createBinaryTree(&root);
    printf("========================\n");
    printf("Inorder Traversal:\n");
    temp=root;
    inorder(&temp);
    printf("\n========================\n");
    printf("Preorder Traversal:\n");
    temp=root;
    preorder(&temp);
    printf("\n========================\n");
    printf("postorder Traversal:\n");
    temp=root;
    postorder(&temp);
    printf("\n========================\n");
    printf("levelorder Traversal:\n");
    temp=root;
    levelorder(&temp);
    printf("\n========================\n");
    system("PAUSE");
    return 0;
}
void createBinaryTree(treePointer *ptr){
    treePointer left_subtree, left_subtree2, right_subtree, newnode;
    newnode=(treePointer)malloc(sizeof (struct node));
    left_subtree=(treePointer)malloc(sizeof (struct node));
    left_subtree2=(treePointer)malloc(sizeof (struct node));
    right_subtree=(treePointer)malloc(sizeof (struct node));
    *ptr=newnode;
    (*ptr)->data = 30;
    left_subtree->data = 5;
    right_subtree->data = 40;
    left_subtree2->data = 2;
    (*ptr)->leftChild = left_subtree;
    (*ptr)->rightChild = right_subtree;
    left_subtree->leftChild = left_subtree2;
    left_subtree->rightChild = NULL;
    right_subtree->leftChild = NULL;
    right_subtree->rightChild = NULL;
    left_subtree2->leftChild = NULL;
    left_subtree2->rightChild = NULL;
}
void inorder(treePointer *ptr){
    if(*ptr){
        inorder(&(*ptr)->leftChild);
        printf("%d ",(*ptr)->data);
        inorder(&(*ptr)->rightChild);
    }
}
void preorder(treePointer *ptr){
    if(*ptr){
        printf("%d ",(*ptr)->data);
        preorder(&(*ptr)->leftChild);
        preorder(&(*ptr)->rightChild);
    }
}
void postorder(treePointer *ptr){
    if(*ptr){
        postorder(&(*ptr)->leftChild);
        postorder(&(*ptr)->rightChild);
        printf("%d ",(*ptr)->data);
    }
}
void addq(treePointer *ptr){
    if(rear==4){
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
    for(int i=0; i<4; i++){
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