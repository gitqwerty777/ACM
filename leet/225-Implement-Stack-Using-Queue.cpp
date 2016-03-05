class Stack {
public:
  vector<int> v;
  // Push element x onto stack.
  void push(int x) {
    v.push_back(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    v.pop_back();
  }

  // Get the top element.
  int top() {
    return v[v.size()-1];
  }

  // Return whether the stack is empty.
  bool empty() {
    return v.size() == 0;
  }
};
