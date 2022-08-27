/*
Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

Mainly the following three basic operations are performed in the stack:

Push: Adds an item in the stack. If the stack is full, then it is said to be an Overflow condition.
Pop: Removes an item from the stack. The items are popped in the reversed order in which they are pushed. If the stack is empty, then it is said to be an Underflow condition.
Peek or Top: Returns top element of stack.
isEmpty: Returns true if stack is empty, else false.
Note:push(), pop(), isEmpty() and peek() all take O(1) time. We do not run any loop in any of these operations.
Sample Input: 
push(1)
push(2)
push(3)
push(4)
push(5)
push(6)
push(7)
push(8)
push(9)
push(10)
top()
push(6)
pop()
pop()
pop()
top()
pop()
pop()
pop()
pop()
top()
isEmpty()

Sample Output: 
10
8
4
0

This is implementation of the Stack data structure using Array:
*/

#include<iostream>
#include<algorithm>
#include<climits>
#define fio ios_base :: sync_with_stdio(false)
#define ct cin.tie(NULL)
using namespace std;
class Stack{
    int capacity;
    int* data;
    int nextIndex;
   
    public:
    Stack(){
        this -> capacity = 5;
        data = new int[capacity];
        nextIndex = 0;
    }
   
    int size(){
        return nextIndex;
    }
    
    bool isEmpty(){
        return nextIndex == 0;
    }
   
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
            return INT_MIN;
        }
        return data[nextIndex - 1];
    }
    
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty!"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }
    
    void push(int element){
        if(nextIndex == capacity){
            int *newData = new int[capacity * 2];
            for(int i=0; i<capacity; i++){
                newData[i] = data[i];
            }
            delete [] data;
            capacity = capacity * 2;
            data = newData;    
        }
        data[nextIndex] = element;
        nextIndex++;
    }

};

int main() {
    fio; ct;
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.push(8);
	s1.push(9);
	s1.push(10);
	cout<<s1.top()<<endl;
	s1.push(6);
	s1.pop();
	s1.pop();
	s1.pop();
	cout<<s1.top()<<endl;
	s1.pop();
	s1.pop();
	s1.pop();
	s1.pop();
    cout<<s1.top()<<endl;
    cout<<s1.isEmpty()<<endl;
	return 0;
}
