#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<windows.h>
float calculate(float x,char op,float y)
{
	float result;
	switch(op)
	{
	case'+':result = x + y;break;
	case'-':result = x - y;break;
	case'*':result = x * y;break;
	case'/':result = x / y;break;
	}
	return result;
}
float calculate2(float x,char op2,float y)
{
	float result;
	switch(op2)
	{
	case'+':result = x + y;break;
	case'-':result = x - y;break;
	case'*':result = x * y;break;
	case'/':result = x / y;break;
	}
	return result;
}
int createnumber()
{
	return rand() % 100+1;
}

int createnumber2()
{
	return rand() % 20+1;
}

char createnumberop()
{
	int op;
	op=rand() % 4+1;
	switch(op)
	{
	case 1:return'+';
	case 2:return'-';
	case 3:return'*';
	case 4:return'/';
	}
	return 0;
}

void exercises(int n)
{
	int i,right=0,wrong=0;
	float a,b,c,answer,result1,result2;
	char op,op2;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		a=(float)createnumber();
		b=(float)createnumber();
		c=(float)createnumber();
		op=createnumberop();
		op2=createnumberop();
		result1=calculate2(calculate(a,op,b),op2,c);
		result2=calculate(a,op,calculate2(b,op2,c));
		if(result1 < 0 || result2 <0)
		{
			i--;
			continue;
		}
		else{
			printf("%.f %c %.f %c %.f = ",a,op,b,op2,c);
			scanf("%f",&answer);
			if((op=='+' || op=='-') && (op2=='*' || op2=='/'))
			{
				if((int)(100.0*answer+0.5)/100.0==(int)(100.0*result2+0.5)/100.0 && result2 >=0)
				{
					printf("\n【回答正确!】\n\n");
					right++;
				}
				else
				{
					printf("\n【回答错误!答案是：%.2f】\n\n",(int)(100.0*result2+0.5)/100.0);
					wrong++;
				}
			}
			else
			{
				if((int)(100.0*answer+0.5)/100.0==(int)(100.0*result1+0.5)/100.0 && result1 >=0)
				{
					printf("\n【回答正确!】\n\n");
					right++;
				}
				else
				{printf("\n【回答错误!答案是：%.2f】\n\n",(int)(100.0*result1+0.5)/100.0);
					wrong++;
				}
			}
		}
		printf("\n你答对了%d题，答错了%d题\n\n",right,wrong);
	}
}

double gongbeishu(double b,double d)
{
	double i,max;
	max=b>d?b:d;
	for(i=max;;i++)
		if((int)(i)%(int)(b)==0 && (int)(i)%(int)(d)==0)
			break;
		return i;
}

double gongyueshu(double a,double c)
{
	double i,min;
	min=a<c?a:c;
	for(i=2;i<=min;i++)
		if((int)(a)%(int)(i)==0 && (int)(c)%(int)(i)==0)
			break;
		if(i>min)
			i=1;
		return i;
}


int main()
{
	int n;
	printf("\n——————————————四则运算-------------------------------------------\n");
	printf("\n\n|                     欢迎进入四则运算小程序！                                 |\n");
	printf("\n——————————————---------------------------------------------------\n");
	while(1)
	{
		do{
			printf("\n请输入四则运算的数目：");
			scanf("%d",&n);
			if(n<=0)
				printf("数目有误，请重新输入!\n");
			if(n>5)
				printf("最多不能超过5个题目，请重新输入!\n");
	}while(n<=0 || n>5);
	exercises(n);
	}
}


