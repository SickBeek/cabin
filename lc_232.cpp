#include <iostream>
#include <assert.h>
#include <stack>
using namespace std;

#define Element int

class MyQueue {
	private:
		stack<Element> st_in;
		stack<Element> st_out;
	public:
		MyQueue(){};

		void push(Element x){
			st_in.push(x);
		}

		Element pop(){
			if (st_out.empty()){
				while (!st_in.empty()){
					st_out.push(st_in.top());
					st_in.pop();
				}
			}

			Element result=st_out.top();
			st_out.pop();
			return result;
		}

		int peek(){
			/*
			if (st_out.empty()){
				while (!st_in.empty()){
					st_out.push(st_in.top());
					st_in.pop();
				}
			}
			*/
			Element tmp=this->pop();
			// this->push(tmp);   wrong
			st_out.push(tmp);
			return tmp;

		}

		bool empty(){
//			if (!st_in.empty() && !st_out.empty())
//				return true;
//			return false;
			
			return st_in.empty() && st_out.empty();
		}

};

int main (){
	MyQueue q =MyQueue();
	int target=0;

	return 0;
}

