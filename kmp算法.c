#include<stdio.h>
#include<stdlib.h>
typedef struct String{
    char*data;
	int len;
}String;
String* initString()
{
	String*s=(String*)malloc(sizeof(String));
	s->data=NULL;
	s->len=0;
	return s;
}
void StringAssign(String*s,char* data)
{   
	int len=0;
	int i;
	char* tmp=data;
	if(s->data)
		free(s->data);
	
	while(*tmp)
	{	len++;tmp++;}
	if(len==0)
	{s->data=NULL;
	s->len=0;}
	else{
	tmp=data;
	s->len=len;
	s->data=(char*)malloc(sizeof(char)*(len+1));
	for(i=0;i<len;i++)
	s->data[i]=tmp[i];
	}

}
void printit(String*s)
{
	int i=0;
	for(;i<s->len;i++)
		printf("%c\t",s->data[i]);
	printf("\n");
}
int* getnext(String*s)
{
	int*next=(int*)malloc(sizeof(int)*(s->len));
	int i=0;
	int j=-1;
	next[i]=j;
	while(i<s->len-1){
	  if(j==-1||s->data[i]==s->data[j])
	  {i++;j++;next[i]=j;}
	  else{j=next[j];}
	}
	return next;
}
void printNext(int*next,int len)
{
int i=0;
	for(;i<len;i++)
		printf("%d\t",next[i]);
	printf("\n");}
void kmpMatch(String*master,String* sub,int*next)
{   
	int i=0;
    int j=0;
	if(sub->len>master->len)
		printf("∆•≈‰≥ˆ¥Ì\n");
	while(i<master->len && j<sub->len)
	{   
		if(j==-1)
		{j=0;i++;}
		if(master->data[i]==sub->data[j])
		{
			i++;
			j++;
		}
		else{
			j=next[j];
		}
	}
    if(j==sub->len)
		printf("∆•≈‰≥…π¶£°\n");
	else
		printf("∆•≈‰ ß∞‹\n");
}
int main()
{   
	String*s= initString();
	String*yuan= initString();
    StringAssign(s,"aba");
	StringAssign(yuan,"adyuabadcababcccc");
    kmpMatch(yuan,s,getnext(s));
	return 0;
}