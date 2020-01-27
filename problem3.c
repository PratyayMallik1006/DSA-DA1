#include<stdio.h>  
#include<string.h>
#include <ctype.h>
#define SIZE 50 
 
char s[SIZE]; int top=-1;  
char infix[50],prefix[50],postfix[50],ch,ele; 
int i=0,k=0; 
void push(char ele) { 
 s[++top]=ele; 
} 
char pop() { 
 return(s[top--]); 
} 
int pr(char ele) { 
 switch(ele) { 
 case '#': return 0; 
 case '(': return 1; 
 case '+': 
 case '-': return 2; 
 case '*': 
 case '/': return 3; 
}
}
 
void main() {  
int z;
printf("1.postfix or 2.prefix\n"); 
scanf("%d",&z);
switch(z) { 
 case 1: 
 printf("\n\nRead the Infix Expression ? "); 
 scanf("%s",infix); push('#'); 
 while( (ch=infix[i++]) != '\0') { 
 if( ch == '(') 
 push(ch); 
 else if(isalnum(ch)) 
 postfix[k++]=ch; 
 else 
 if( ch == ')') { 
 while( s[top] != '(') 
 postfix[k++]=pop(); 
 ele=pop(); 
 } 
 else { 
 while( pr(s[top])>=pr(ch) )
 postfix[k++]=pop();
 push(ch); 
 }
 }
 while( s[top] != '#')     
 postfix[k++]=pop(); 
 postfix[k]='\0';    
 printf("\n\nFor the given Infix Expn: %s  the Postfix Expn: %s\n",infix,postfix);
 break;
 case 2: 
 printf("\n\nRead the Infix Expression ? ");
 scanf("%s",infix); push('#'); 
 strrev(infix); 
 while( (ch=infix[i++]) != '\0') { 
 if( ch == ')') 
 push(ch); 
 else 
 if(isalnum(ch)) 
 prefix[k++]=ch; 
 else if( ch == '(') { 
 while( s[top] != ')') 
 prefix[k++]=pop(); 
 ele=pop(); 
 } 
 else{ 
 while( pr(s[top]) >= pr(ch) ) 
 prefix[k++]=pop();
 push(ch);
 }
 } 
 while( s[top] != '#') 
 prefix[k++]=pop(); 
 prefix[k]='\0';  
 strrev(prefix); 
 strrev(infix); 
 printf("\n\nGiven Infix Expn: %s  Prefix Expn:%s\n",infix,prefix);}
}