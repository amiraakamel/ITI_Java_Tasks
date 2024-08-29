#include<iostream>
using namespace std;


class Stack {

private:
	int top;
	int size;
	int* ptr;

public:
	Stack();
	Stack(int n);
	Stack(Stack& s);
	~Stack();
	int isFull();
	int isEmpty();
	int push(int num);
	int pop();
	friend void viewContent(Stack s); 
	//friend void viewContent(Stack& s);

};

Stack::Stack() {
	top = 0;
	size = 10;
	ptr = new int[size];
	cout << "default cons" << endl;
}
Stack::Stack(Stack& s) {
	top = s.top;
	size = s.size;
	ptr = new int[size];
	for (int i = 0; i < top; i++) {
		ptr[i] = s.ptr[i];
	}

	cout << "copy constructor" << endl;
}

Stack::Stack(int n) {
	top = 0;
	size = n;
	ptr = new int[size];
	cout << "parameterized cons" << endl;
}

Stack::~Stack() {
	delete[] ptr;
	cout << "destructor" << endl;
}

int Stack::isFull() {
	return (top == size);
}

int Stack::isEmpty() {
	return (top == 0);
}

int Stack::push(int num) {
	if (isFull()) {
		return 0;
	}
	ptr[top] = num;
	top++;
	return num;
}
int Stack::pop() {
	if (isEmpty()) {
		return 0;
	}
	top--;
	return ptr[top];
}

void viewContent(Stack s) {
	for (int i = 0; i < s.top; i++) {
		cout << s.ptr[i] << endl;
	}
}

/*call by reference 
void viewContent(Stack& s) {
	for (int i = 0; i < s.top; i++) {
		cout << s.ptr[i] << endl;
	}
}*/

int main() {

	Stack s;
	s.push(6);
	s.push(5);
	s.push(7);

	viewContent(s);

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	
	return 0;
}