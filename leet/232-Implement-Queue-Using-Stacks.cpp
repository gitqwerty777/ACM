class Queue {
public:
  vector<int> v;
  // Push element x to the back of queue.
  void push(int x) {
    v.push_back(x);
  }
  // Removes the element from in front of queue.
  void pop(void) {
    v.erase(v.begin());
  }
  // Get the front element.
  int peek(void) {
    return v[0];
  }
  // Return whether the queue is empty.
  bool empty(void) {
    return v.size() == 0;
  }
};
