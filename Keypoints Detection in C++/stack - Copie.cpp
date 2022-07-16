// Create a simple stack using arrays

#include<stdio.h>
#include<iostream>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top=-1;

void Push(int x) {
    A[++top] = x;
    if(top==MAX_SIZE-1){
        std::cout << "ERROR : Stack Overflow!" << std::endl;
    }
};

void Pop() {
    if(top==0){
        std::cout << "Error : No Element to pop!" << std::endl;
    }
    top=top-1;
};

int Top(){
    return A[top];
};

void Print() {
    int i;
    std::cout<<"Stack"<<std::endl;
    for(i=0; i<=top; i++){
        std::cout<<A[i]<<std::endl;
    }
}
 
int main() {
    Push(4);
    Push(5);
    Push(6);
    Print();
}