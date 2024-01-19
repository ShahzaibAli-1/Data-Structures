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
    if (ptr->top == -1){
return 0;
    }
    return 1;
}
int main(){

stack s1;
s1.size = 10;
s1.top = -1;
s1.arr = new int (s1.size);


//Pushing an element in stack

s1.arr [0] = 4;
s1.top++ ;
cout<<s1.arr[0]<<endl;
cout<<s1.top<<endl;

if (isEmpty(&s1)){
    cout<<"This stack is empty "<<endl;
}

else{
    cout<<"This stack is not empty"<<endl;
}

    return 0;
}