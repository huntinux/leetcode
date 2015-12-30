
/*
   Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

   push(x) -- Push element x onto stack.
   pop() -- Removes the element on top of the stack.
   top() -- Get the top element.
   getMin() -- Retrieve the minimum element in the stack.
   */

// 栈中的元素为 (val, minbelow)  val: 元素值 minbelow: 栈底到该位置时的最小值

class MinStack {
    public:
        void push(int x) {
            if (!stk.empty())
                stk.push(make_pair(x, min(x, stk.top().second)));
            else
                stk.push(make_pair(x, x));
        }

        void pop() {
            stk.pop(); 
        }

        int top() {
            return stk.top().first; 
        }

        int getMin() {
            return stk.top().second;
        }

    private:
        stack<pair<int, int>> stk;
};

