#include <stack>
#include <exception>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

template <typename T> class StackQueue {
 public:
  void appendTail(const T& node);
  T deleteHead();

 private:
  stack<T> stack1;
  stack<T> stack2;
};

template<typename T> void StackQueue<T>::appendTail(const T& element) {
  stack1.push(element);
}

template<typename T> T StackQueue<T>::deleteHead() {
  if (stack2.size() <= 0) {
    while(stack1.size() > 0) {
      T& data = stack1.top();
      stack1.pop();
      stack2.push(data);
    }
  }

  if(stack2.size() == 0)
    throw std::runtime_error("test");

  T head = stack2.top();
  stack2.pop();

  return head;
}

int main() {
  StackQueue<int> q;
  q.appendTail(100);
  cout << "head is " << q.deleteHead() << endl;
  return 0;
}
