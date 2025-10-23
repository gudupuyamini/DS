#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
void push(int);
int peek();
int pop();
int evaluation_of_postfix(char*);
int stack[MAX],top=-1;
void push(int n){
	stack[++top]=n;
}
int pop()
{
	return stack[top--];
}
int peek()
{
	return stack[top];
}
int evaluation_of_postfix(char*ex)
{
	int a=0,c=0,i;
	for(i=0;ex[1]!='\0';i++)
	{
		if(isdigit(ex[i]))
		a++;
		else if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%'||ex[i]=='^')
		c++;
	}
	if(a<=c)
	{
		printf("invalid expression\n");
		exit(0);
	}
	for(i=0;ex[i]!='\0';i++)
	{
		if(isdigit(ex[i])||ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%')
		{
			if(isdigit(ex[i]))
			push(ex[i]-'0');
			else
			{
				int x1,x2;
				x1=pop();
				x2=pop();
				switch(ex[i])
				{
					case'+':push(x2+x1);break;
					case'-':push(x2-x1);break;
					case'*':push(x2*x1);break;
					case'/':push(x2/x1);break;
					case'%':push(x2%x1);break;
				}
			}
		}
		else{
			printf("invalid expression\n");
			exit(0);
		}
	}
	if(top!=0)
	{
		printf("invalid expression\n");
		exit(0);
	}
	else
	{
		return stack[top];
	}
}
int main()
{
	char ex[MAX];
	int result;
	printf("enter valid postfix expression:");
	gets(ex);
	result=evaluation_of_postfix(ex);
	printf("result of postfix evaluation is %d\n",result);
	return 0;
}
