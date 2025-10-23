#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 20
void push();
int peek();
int pop();
int evaluation_of_postfix(char*);
int stack[size],top=-1;
void push(int n){
	stack[++top]=n;
}
int pop()
{
	return stack[top-1];
}
int peek()
{
	return stack[top];
}
int evaluated_of_postfix(char*ex)
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
					case'*':push(x2+x1);break;
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
	char exp[size];
	int result;
	printf("enter valid postfix expression:");
	gets(exp);
	result=evaluation_of_postfix(exp);
	printf("result of postfix evaluation is %d\n",result);
	return 0;
}
