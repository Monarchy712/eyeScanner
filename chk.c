#include <stdio.h>

char stack[100][300];
int top=-1;

int mylen(char s[]){int i=0;while(s[i]!='\0')i++;return i;}
void mycopy(char d[],char s[]){int i=0;while(s[i]!='\0'){d[i]=s[i];i++;}d[i]='\0';}
void mycat(char d[],char s[]){int i=mylen(d),j=0;while(s[j]!='\0')d[i++]=s[j++];d[i]='\0';}

void push(char s[]){top++;mycopy(stack[top],s);}
void mypop(char r[]){mycopy(r,stack[top]);top--;}

int isOperand(char c){
    return (c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9');
}
int main()
{
    char postfix[100];
    int i,l;
    printf("Enter postfix expression: ");
    scanf("%s",postfix);
    for(i=0;postfix[i]!='\0';i++){
        char c=postfix[i];
        if(isOperand(c)){
            char tmp[3]={c,'\0'};
            push(tmp);
        }
        else{
            char b[300],a[300],res[300],op[3]={c,'\0'};
            mypop(b);mypop(a);
            res[0]='(';res[1]='\0';
            mycat(res,a);mycat(res,op);mycat(res,b);
            l=mylen(res);res[l]=')';res[l+1]='\0';
            push(res);
        }
    }
    printf("Infix: %s\n",stack[top]);
}