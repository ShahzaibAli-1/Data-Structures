#include<iostream>
using namespace std;

class stack {

public:
    int size; 
    int top; 
    int * arr;
};
bool isEmpty ( stack *ptr ){

    if (ptr->top == -1){
return 1;
    }
    return 0;
}

bool  isFull ( stack *ptr ){
    if (ptr->top ==ptr->size- 1){
return 1;
    }
    return 0;
}


void push(stack *ptr, int value ){
if(isFull(ptr)){

cout<<"Stack overflow"<<endl;
}
else{

    ptr->top++;
    ptr->arr[ptr->top] = value;

}
}
int pop(stack *ptr ){
if(isEmpty(ptr)){

cout<<"Empty"<<endl;
return -1;
}

    int value = ptr->arr[ptr->top];
    ptr->top--;
    return value;

}
void print(stack *ptr){

    for (int i = 0;i<=ptr->top;i++){
        cout<<ptr->arr[i]<<endl;
    }
}

void peek(stack *ptr, int index){
    if (ptr->top - index+1<0){

        cout<<"Invalid Position"<<endl;
    }
    else{
    int value = ptr->arr[ptr->top - index+1];
    cout<<value<<endl;}
    
}
int main(){

stack s1;
s1.size = 10;
s1.top = -1;
s1.arr = new int (s1.size);


//Pushing an element in stack

s1.arr [0] = 4;
++s1.top ;

push(&s1,10);
push(&s1, 12);
push(&s1, 15);
push(&s1, 18);
print(&s1);

pop(&s1);
print(&s1);
cout<<"Peeking at given index: "<<endl;
peek(&s1, 2);
    return 0;
}