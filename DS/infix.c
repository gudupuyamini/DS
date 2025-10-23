#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20
int top=-1;
int stack[SIZE];
int precedence(char);
void push(char);
char pop();
char peek();
void infix_to_postfix(char*);
int precedence(char ch)
{
	switch(ch)
	{
		case'+':
		case'-':return 1;
		case'*':
		case'/':
		case'%':return 2;
		case'^':return 3;
		dafault:return 0;
	}
}
void push(char ch)
{
	top++;
	stack[top]=ch;
}
char pop()
{
	return stack[top--];
}
char peek()
{
	return stack[top];
}
void infix_to_postfix(char *ex)
{
	char postfix[SIZE];
	int n=strlen(ex),i,j=0;
	for(i=0;ex[i]!='\0';i++)
	{
		if(ex[i]=='('||ex[i]==')'||isalnum(ex[i])||ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%'||ex[i]=='^')
		{
			if(isalnum(ex[i]))
			postfix[j++]=ex[i];
			else if(ex[i]=='(')
			push(ex[i]);
			else if(ex[i]==')')
			{
				while(top!=-1&&peek()!='(')
				postfix[j++]=pop();
				if(top==-1)
				{
					printf("invalid expression\n");
					exit(0);
				}
				pop();
			}
			else
			{			
         	    while(top!=-1&&precedence(peek())>precedence(ex[i]))
				postfix[j++]=pop();
				push(ex[i]);
			}
		}
		else
		{
			printf("invalid expression\n");
			exit(0);
		}//end of for loop
	}
		while(top!=-1)
		{
			char ch=pop();
			if(ch=='(')
			{
				printf("invalid expression\n");
				exit(0);
			}
			postfix[j++]=ch;
		}
		postfix[j]='\0';
		printf("postfix expression is %s \n",postfix);
}
int main()
{
	char ex[SIZE];
	printf("enter a valid expression:");
	gets(ex);
	infix_to_postfix(ex);
	
}
