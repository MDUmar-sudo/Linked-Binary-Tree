#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LinkedTree lt;

struct LinkedTree{
    char data;
    struct LinkedTree *left;
    struct LinkedTree *right;
};

lt *root=NULL;

lt *NewNode(char data){

  lt *node = (lt*)malloc(sizeof(lt));
  node->data = data;
  node->left=NULL;
  node->right=NULL;
  return node;

}

typedef struct queue sq;

struct queue{
    lt* *arr;
    int front,rear,size;
};

sq *NewQueue(){
    sq *queue = (sq*)malloc(sizeof(sq));
    queue->front=-1;
    queue->rear=queue->size=0;
    queue->arr = (lt**)malloc(100*sizeof(lt*));
    return queue;
}

void enqueue(sq *queue,lt* temp){
    queue->arr[queue->rear++]=temp;
    queue->size++;
}

lt *dequeue(sq *queue){
    queue->size--;
    return queue->arr[++queue->front];

}


void insertNode(char);
void printPreOrder(lt*);
void printPostOrder(lt*);
void printInOrder(lt*);

int main()
{
    /*        2
            /  \
           3    4
          / \  / \
         1   67   9
    */
    //PreOrder:2 3 1 6 4 7 9
    //InOrder:1 3 6 2 7 4 9
    //PostOrder:1 6 3 7 9 4 2

    int choice;
    printf("---------------------\n");
    printf("LINKED BINARY TREE\n");
    printf("---------------------\n");

    do{
    printf("\n____________________________");
    printf("\nCHOOSE AN OPERATION\n(1)INSERT\n(2)DELETE\n(3)DISPLAY\n(4)EXIT\n");
    printf("____________________________");

    printf("\nENTER YOUR CHOICE :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:{
                char val;
                printf("\nENTER A NODE: ");
                scanf(" %c",&val);
                insertNode(val);
               }
               break;

    case 2:
            break;

    case 3: {
                printf("\n----------------------------");
                printf("\nCHOOSE A DISPLAY OPERATION\n\n(1)PRINT TREE\n(2)PRINT PREORDER\n(3)PRINT INORDER\n(4)PRINT POSTORDER\n(5)EXIT\n");
                printf("\n----------------------------");
                int option;
                printf("\nENTER YOUR CHOICE :");
                scanf("%d",&option);
                printf("\n----------------------------");
                switch(option){
                    case 1:
                            break;

                    case 2: printf("\nPRE-ORDER TRAVERSAL OF BINARY TREE : ");
                            printPreOrder(root);
                            break;

                    case 3: printf("\nIN-ORDER TRAVERSAL OF BINARY TREE : ");
                            printInOrder(root);
                            break;

                    case 4: printf("\nPOST-ORDER TRAVERSAL OF BINARY TREE : ");
                            printPostOrder(root);
                            break;

                    case 5: printf("\nEXIT\n");
                            break;

                    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");
                }

            }
            break;

    case 4: printf("\nEXIT");
             break;

    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");

    }
  }while(choice!=4);




    getch();
    return 0;
}



void printPreOrder(lt *node){

    if(root==NULL) printf("\nBINARY TREE EMPTY");

    else{
            printf("%c ",node->data);

            if(node->left!=NULL)
            printPreOrder(node->left);

            if(node->right!=NULL)
            printPreOrder(node->right);
        }

}



void printInOrder(lt *node){
    if(root==NULL) printf("\nBINARY TREE EMPTY");

    else{
        if(node->left!=NULL)
        printInOrder(node->left);

        printf("%c ",node->data);

        if(node->right!=NULL)
        printInOrder(node->right);

    }

}



void printPostOrder(lt *node){
    if(root==NULL) printf("\nBINARY TREE EMPTY");

    else{
        if(node->left!=NULL)
        printPostOrder(node->left);

        if(node->right!=NULL)
        printPostOrder(node->right);

        printf("%c ",node->data);
    }


}



void insertNode(char data) {

    lt *temp = NewNode(data);

    if(root == NULL){
        root = temp;
        return;
    }
    else {
        //Queue will be used to keep track of nodes of tree level-wise
        sq* queue = NewQueue();
        //Add root to the queue
        enqueue(queue, root);

        while(true){
            lt *node = dequeue(queue);
            //If node has both left and right child, add both the child to queue
            if(node->left != NULL && node->right != NULL) {
                enqueue(queue, node->left);
                enqueue(queue, node->right);
            }
            else {
                //If node has no left child, make temp as left child
                if(node->left == NULL) {
                    node->left = temp;
                    enqueue(queue, node->left);
                }
                //If node has left child but no right child, make temp as right child
                else {
                    node->right = temp;
                    enqueue(queue, node->right);
                }
                break;
            }
        }
    }
}








