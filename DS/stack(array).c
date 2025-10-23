
#include<stdio.h>
#include<stdlib.h>
//Coded by:P.Likhitha
#define size 7
int stack[size],top=-1;
void push(int);
int pop();
int peek();
void display();
int isEmpty();
void push(int n)
{
	if(top==size-1)
	{
		printf("\nStack is Overflow");
	}
	else
	{
		top=top+1;
		stack[top]=n;
	}
	printf("Element is inserted\n");
}
int pop()
{
	int x;
	if(top==-1)
	{
		printf("Stack is Empty\n");
		x=0;
	}
	else
	{
		x=stack[top];
		top=top--;
	}
	return x;
}
int peek()
{
	int x;
	if(top==-1)
	{
		printf("stack is underflow\n");
	}
	else
	{
		x=stack[top];
	}
	return x;
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is empty\n");
	}
	else
	{
		int i;
		printf("Stack elements are:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n",stack[i]);
		}
	}
}
int main()
{
	push(12);
	push(44);
	display();
	pop();
	
}
/*int main()
{
	int ch,x;
	do
	{
		printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				    printf("\nEnter element: ");
				    scanf("%d",&x);
				    push(x);
				    break;
			case 2:
			       pop(x);
				    printf("popped element is %d\n",x);
			      break;
			case 3: x=peek();
			       printf("the top most element is %d\n",x);
			       break;
			case 4:display();
			     break;
	        case 5:printf("Thank you!!!!");
	             break;
	        default :printf("Invalid choice\n");     
		}
	}while(ch!=7);
           printf(“Rollno:24B11CS351”);
	return 0;
}*/
