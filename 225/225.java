class MyStack {

    // Push element x onto stack.
    public void push(int x) {
        if (!Q1.isEmpty()) 
            Q1.add(x);
        else
            Q2.add(x);
    }

    // Removes the element on top of the stack.
    public void pop() {
        if (!Q1.isEmpty())
        {
            while(!Q1.isEmpty())
            {
                int last = Q1.peek();
                Q1.remove();
                if (!Q1.isEmpty())
                    Q2.add(last);
            }
        }
        else
        {
            while(!Q2.isEmpty())
            {
                int last = Q2.peek();
                Q2.remove();
                if (!Q2.isEmpty())
                    Q1.add(last);
            }
        }
    }

    // Get the top element.
    public int top() {
        int last = 0;
        if (!Q1.isEmpty())
        {
            while(!Q1.isEmpty())
            {
                last = Q1.peek();
                Q1.remove();
                Q2.add(last);
                if (Q1.isEmpty())
                    break;
            }
        }
        else
        {
            while(!Q2.isEmpty())
            {
                last = Q2.peek();
                Q2.remove();
                Q1.add(last);
                if (Q2.isEmpty())
                    break;
            }
        }
        return last;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        return Q1.isEmpty() && Q2.isEmpty();   
    }
    private LinkedList<Integer> Q1 = new LinkedList<Integer>();
    private LinkedList<Integer> Q2 = new LinkedList<Integer>();
}

