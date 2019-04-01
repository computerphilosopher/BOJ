#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ELEMENT 10000
#define EMPTY -1

typedef int element;

typedef struct StackType{
	int top;
	element stack[MAX_ELEMENT];
	
}StackType;

void init(StackType *s){
	
	s->top = -1;

	for(int i=0; i<MAX_ELEMENT; i++){
		s->stack[i] = 0;
	}
}

bool is_empty(StackType s){
	return s.top == -1;
}

bool is_full(StackType s){
	return s.top == MAX_ELEMENT-1;
}

void push(StackType *s, element data){

	if(is_full(*s)){
		
		return;
	}

	else{
		(s->top)++;
		s->stack[s->top] = data;
	}

}

int pop(StackType *s){
	if(is_empty(*s)){
		return -1;	

	}
	else{
		
		int temp = s->stack[s->top--];
		return temp;
	}

}

int seek(StackType s){

	if(is_empty(s)){
		return -1;	

	}
	else{
		return s.stack[s.top];
	}

}

int size(StackType s){
	return (s.top)+1;
}


int main(){

	int n = 0;
	StackType s;

	init(&s);

	scanf("%d", &n);

	for(int i= 0; i<n; i++){
		char command[10] = {0};
		scanf("%s", command);

		if(strcmp(command, "push") == 0){
			int temp = 0;
			scanf("%d", &temp);

			push(&s, temp);

		}

		else if(strcmp(command, "pop") == 0){
			printf("%d\n", pop(&s));
		}
		
		else if(strcmp(command, "size") == 0){
			printf("%d\n", size(s));
		}
		
		else if(strcmp(command, "empty") == 0){
			printf("%d\n", is_empty(s));
		}
		
		else if(strcmp(command, "top") == 0){
			printf("%d\n",seek(s));
		}
	}

	return 0;
}
