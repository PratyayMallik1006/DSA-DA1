
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50
#define limit 25

char stack[max][50];
int top=-1;
int timestamp=-1;
int top1=max;

int BackisEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

int ForisEmpty(){
    if(top==max){
        return 1;
    }
    else{
        return 0;
    }
}

int BackisFull(){
    if(top<limit-1){
        return 0;
    }
    else{
        return 1;
    }
}

int ForisFull(){
    if(top==limit){
        return 1;
    }
    else{
        return 0;
    }
}

int backward(){
    if(top==-1){
        printf("\nBackward stack is empty\n");
        return 0;

    }
    else if(ForisFull()){printf("\nForward is full");}
    else{
        strcpy(stack[--top1],stack[top--]);
        return 0;
    }

return 0;
}

int forward(){
    if(top1==max-1){
        printf("\nForward stack is empty\n");
    }
    else if(BackisEmpty()){printf("\nBackward is full\n");}
    else{
        strcpy(stack[++top],stack[top1++]);
    }

return 0;

}
int Browse(){
    while(!ForisEmpty()){
        forward();
    }
    if (BackisFull()){
        printf("The stack is full\n");
        return 0;
    }
    else{
		char reg[50];
		printf("Enter website\n");
        scanf("%s",reg);
        top=top+1;
        printf("\n%d\n",top);
        strcpy(stack[top],reg);
        return 0;
    }
}


/*int Backpop(){
    if (isEmpty()){
        printf("the stack is empty\n");
        return 0;
    }
    else
    {
        printf("item poped:%s\n",stack[top]);
        top=top-1;
        timestamp=top;
        printf("\n%d\n",timestamp);
        return 0;
    }

}

int Forpop(){
    if (isEmpty()){
        printf("the stack is empty\n");
        return 0;
    }
    else
    {
        printf("item poped:%s\n",stack[top]);
        top=top+1;
        timestamp=top;
        printf("\n%d\n",timestamp);
        return 0;
    }

}

*/
int peek(){
    if (!BackisEmpty()){
    printf("the top element:%s\n",stack[timestamp]);
    }

    else{
        printf("Empty\n");
    }

    return 0;
}

int display(){
    int i;

    if(top==-1){
        printf("backward stack is empty\n");
    }
    else{
    for(i=top;i>=0;i--){
        printf("%s\n",stack[i]);
    }
    }

    printf("\nForward Stack\n");
    if(top1==max){
        printf("forward stack is empty\n");
    }
    else{
    for(i=max-1;i<=top1;i++){
        printf("%s\n",stack[i]);
    }
    }


    return 0;
}

int query(char stu[50]){
    int flag=0;

        int i;
        for(i=0;i<top+1;i++){
            if(!strcmp(stu,stack[i])){
                flag=1;
                break;
            }
            else{
                flag=2;
            }
        }
        if(flag==1){
        printf("YES the website %s has has been searched\n",stack[i]);
        }
        else if(flag==2){
        printf("NO the website %s has not been searched\n",stack[i]);
        }




    return 1;
}

void displayn(int n){

	if(timestamp>=n){
            while(timestamp>n){
		printf("\n\tthe student %s is poped",stack[top]);
		top--;
		}
	}
	else{
        printf("\n\tThe stack contains less than %d assignments",n);
	}
}


int main(){
    int login,ch,chh;
    int a;
    int loop=1;
    char reg[50];
    char pass[50];
    char stu[50];
    do{ printf("\n1-Browse \n");
                   printf("2-Backward \n");

                   printf("3-Last searched website\n");
                  printf("4-forward \n");
                   printf("5-query\n");
                   printf("6-Display\n");
                   printf("7-to exit\n");

                   scanf("%d",&ch);
                 switch(ch){
                       case 1:Browse();
                             display();
                              break;
                       case 2:backward();
                            display();
                              break;
                        case 4:forward();
                                display();
                              break;

                       case 3:peek();
                              break;

                       case 5:printf("ENTER THE WEBSITE\n");
                              scanf("%s",stu);
                              query(stu);
                              break;
                            case 6:display(); break;

                       case 7:printf("EXIT");loop=0;
                              break;
                       default:printf("invalid statement\n");
                               loop=0;
                              break;
                   }






    }while(loop);

    return 1;
}

