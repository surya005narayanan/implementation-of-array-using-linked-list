#include <stdio.h>
#include <stdlib.h>
struct dlist {
    int data;
    struct dlist* next;
};
typedef struct dlist node;
node *top=NULL;
int isfull(){
	return (top !=NULL);
}
int isempty(){
    return (top == NULL);
}
void push(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("empty bro");
        return;
    }
    newnode->data = data;
    newnode->next = top;
    top = newnode;
    printf("Pushed\n");
}
void pop(){
    if (isempty()) {
        printf("Stack is gaali");
        return;
    }
    node* temp = top;
    printf("Popped \n");
    top = top->next;
    free(temp);
}
void peek(){
    if (isempty()) {
        printf("Stack is empty");
        return;
    }
     node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp= temp->next;
    }
    printf("\n");
}
int main() {
    int ch, data;
    while (1) {
        printf("1)Push an element\n");
        printf("2.Pop an element\n");
        printf("3. Peek the elements\n");
        printf("4.) Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
