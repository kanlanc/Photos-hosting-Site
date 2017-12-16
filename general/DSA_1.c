#include<stdio.h>
#include<stdlib.h>
struct sNode
{
    int data;
    struct sNode *next;
};
void push(struct sNode** top_ref, int new_data);
int pop(struct sNode** top_ref);
struct queue
{
    struct sNode *stack1;
    struct sNode *stack2;
};
void enQueue(struct queue *q, int x)
{
    push(&q->stack1, x);
}
int deQueue(struct queue *q)
{
    int x;
    if(q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("Q is empty");
        getchar();
        exit(0);
    }
if(q->stack2 == NULL)
{
    while(q->stack1 != NULL)
    {
        x = pop(&q->stack1);
        push(&q->stack2, x);

    }
}

x = pop(&q->stack2);
return x;
}
void push(struct sNode** top_ref, int new_data)
{
    struct sNode* new_node =
        (struct sNode*) malloc(sizeof(struct sNode));
        if(new_node == NULL)
        {
            printf("Stack overflow \n");
            getchar();
            exit(0);

        }
new_node->data = new_data;
new_node->next = (*top_ref);
(*top_ref) = new_node;
}
int pop(struct sNode** top_ref)
{
    int res;
    struct sNode *top;
    if(*top_ref == NULL)
    {
        printf("Stack overflow \n");
        getchar();
        exit(0);

    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;

    }
}
int main()
{   int n;
    int i;
    int o;
    int value;
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    scanf("%d",&n);
     q->stack1 = NULL;
    q->stack2 = NULL;
    for(i=0;i<n;i++)
    {
        scanf("%d",&o);
        if(o==1)
        {   scanf("%d",&value);
             enQueue(q,value);
        }
        else{
            deQueue(q);
        }

    }
    return 0;
}
