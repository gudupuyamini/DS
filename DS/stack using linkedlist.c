#include<stdio.h>
#include<stdlib.h>
type def struct stack
{
	int data;
	struct stack *next;
}STACK;
STACK *top=NULL;
int count=0;
void push(int);
int pop();
int peek();
void display();
void push(int info)
{
	STACK *newnode=(STACK*)malloc(sizeof(STACK));
	if(newnode==NULL)
	{
		printf("memory not allocated");
		return;
	}
	newnode->data=info;
	newnode->next=NULL;
	if(top==NULL)
	top=newnode;
	else
	{
		newnode->next=top;
		top=newnode;
	}
	count++;
	printf("%dis pushed to STACK\n",info);
}
int pop()
{
	int ele;
	if(top==NULL)
	printf("stack is overflow");
	else
	{
		STACK*temp=top;
		top=top->next;
		ele=temp->data;
		count--;
		free(temp);
		return ele;
	}
}
int peek()
{
	if(top==NULL)
	printf("stack is empty\n");
	else
	return top->data;
}
void display()
{
	if(top==NULL)
	printf("stack is empty\n");
	else
	{
		STACK *temp=top;
		printf("\n **stack element**\n");
		while(temp!=NULL)
		{
			printf("\t%d\n",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
    int ch, x;
    while (1) 
    {
        printf("\n******* MENU *******");
        printf("\n1.Push\n2.Pop\n3.Peek \n4.Display\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) 
        {
            case 1:
                printf("\nEnter element: ");
                scanf("%d", &x);
                push(x); 
                break;            
            case 2:
                x = pop();
                if(x)
                    printf("Popped element is %d\n", x);
                break;
            case 3:
                x = peek();
                if(x)
                    printf("The topmost element is %d\n", x);
                break;
            case 4: 
                display(); 
                break;
            case 5:
                exit(0); 
                break;
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}
	
