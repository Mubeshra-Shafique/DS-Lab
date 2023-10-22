#include<iostream>
using namespace std;
class Stack{
	public:
int stack[100],n=100,top=-1;
void push(int val){
	if(top>=n-1){
		cout<<"Stack Overflow";
	}
	else{
		top++;
		stack [top]=val;
	}
}
void pop(){
	if(top<=-1){
		cout<<"stack underflow";	
	}
	else{
		cout<<"Stack poped elements are:"<<stack[top]<<endl;
		top--;
	}
}
void display(){
	if(top>=0){
		cout<<"STack elements are:";
		for(int i=top; i>=0; i--){
			cout<<stack[i];
			cout<<endl;
		}
	}
	else
	cout<<"empty";
}
	
};
int main(){
	Stack n;
	n.push(1);
	n.push(2);
	n.push(3);
	n.push(4);
	n.display();
	n.pop();
	n.pop();
	
	return 0;
}