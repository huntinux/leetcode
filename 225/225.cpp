/*
   Implement the following operations of a stack using queues.

   push(x) -- Push element x onto stack.
   pop() -- Removes the element on top of the stack.
   top() -- Get the top element.
   empty() -- Return whether the stack is empty.

Notes:

You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).

Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack. 
*/


// ��ջ�� �ҵ�Q1 Q2�в�Ϊ�յĽ��� ��ջ , �����Ϊ�գ���ѡ��Q2 ��ջ
// ��ջ�����Q1��Ϊ�գ���ô Q1 -> Q2 (���һ��Ԫ�ز�����Q2) ; Q1Ϊ�գ����Q2����ǰ��Ĳ���
// top�� ���Q1��Ϊ�գ���ô Q1 -> Q2 (���һ��Ԫ��, ��Ϊ����ֵ����Ԫ��Ҳ����Q2); Q1Ϊ�գ����Q2����ǰ��Ĳ���

class Stack {
    public:
        // Push element x onto stack.
        void push(int x) {
            if (!Q1.empty()) 
                Q1.push(x);
            else 
                Q2.push(x);
        }

        // Removes the element on top of the stack.
        void pop() {
            if (!Q1.empty())
            {
                // q1->q2
                // out last in q1
                while(!Q1.empty())
                {
                    int last = Q1.front();
                    Q1.pop();
                    if (!Q1.empty())
                        Q2.push(last);
                }

            }
            else
            {
                // q2->q1
                // out last in q2
                while(!Q2.empty())
                {
                    int last = Q2.front();
                    Q2.pop();
                    if (!Q2.empty())
                        Q1.push(last);
                }
            }
        }

        // Get the top element.
        int top() {
            if (!Q1.empty())
            {
                // q1->q2
                // out last in q1
                while(!Q1.empty())
                {
                    int last = Q1.front();
                    Q1.pop();
                    Q2.push(last);
                    if (Q1.empty()) return last;
                }

            }
            else
            {
                // q2->q1
                // out last in q2
                while(!Q2.empty())
                {
                    int last = Q2.front();
                    Q2.pop();
                    Q1.push(last);
                    if (Q2.empty())  return last;
                }
            }

        }

        // Return whether the stack is empty.
        bool empty() {
            return Q1.empty() && Q2.empty();
        }
    private:
        queue<int> Q1;
        queue<int> Q2;
};
