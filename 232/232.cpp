class Queue {
    public:
        // Push element x to the back of queue.
        void push(int x) {
            in.push(x);
        }

        // Removes the element from in front of queue.
        void pop(void) {
            if(out.empty()) transfer();
            out.pop();
        }

        void transfer(void)
        {
            while(!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
        }

        // Get the front element.
        int peek(void) {
            if(out.empty()) transfer();
            return out.top();
        }

        // Return whether the queue is empty.
        bool empty(void) {
            return in.empty() && out.empty(); 
        }
    private:
        stack<int> in;
        stack<int> out;
};
