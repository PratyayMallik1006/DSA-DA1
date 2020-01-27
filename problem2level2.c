#include<stdio.h> 
#include<stdlib.h> 
#define SIZE 100 
int for[100],back[100],curr,ch,top=-1,top=-1; 
void push_for() { 
 if(top+1>=SIZE) 
 printf("\nOverflow\n"); 
 else{ 
 top++; 
 for[top]=curr;
 } 
} 
 
void backpuch() { 
 if(top+1>=SIZE) 
 printf("\nOverflow\n"); 
 else { 
 top++; back[top]=curr; 
 } 
} 
 
void forpop() { 
 top--; 
} 
 
void backpop() { 
 back[top]=curr; 
 top--;
} 
 
int main() { 
 printf("Enter your current element\n"); 
 scanf("%d",&curr); 
 flag: printf("Press 'f' for forard or 'b' for backward?"); 
 scanf("%s",&ch); 
 if(ch=='F' || ch=='f' || ch=='B' || ch=='b'){
 switch(ch) { 
 case 'F': 
 case 'f':
 printf("Enter your element\n"); 
 backpuch(); 
 forpop(); 
 scanf("%d",&curr); 
 if(top==-1) 
 printf("Current=%d backward=%d\n",curr,back[top]); 
 else 
 printf("Current=%d Back=%d forard=%d\n",curr,back[top],for[top]); 
 goto flag; 
 case 'B': 
 case 'b':
 push_for(); 
 backpop(); 
 if(top==-1) 
 printf("Current=%d forard=%d\n",curr,for[top]); 
 else
 printf("Current=%d Back=%d forard=%d\n",curr,back[top],for[top]); 
 goto flag; 
 } 
 } 
 else 
 exit(0); 
} 