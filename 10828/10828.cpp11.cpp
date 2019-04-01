#include <stdio.h>
#include <cstring>
using namespace std;
class Stack {
    private:
   int array[10001];
   int topIndex = -1;
    public:
   void push(int num) {
         ++topIndex;
         array[topIndex] = num;
      }
   int pop() {
         if (topIndex == -1)
            return -1;
         else {
                  int popNum = array[topIndex];
                  --topIndex;
                  return popNum;
               }
      }
   int size() {
         return topIndex + 1;
      }
   int empty() {
         if (topIndex == -1) return 1;
         else return 0;
      }
   int top() {
         if (topIndex == -1)
            return -1;
         else
            return array[topIndex];
      }
};
int main() {
   Stack stack;
   int orderNum;
   scanf("%d", &orderNum);
   for (int i = 0; i < orderNum; ++i) {
       char order[6];
       scanf("%s", order);
       if (!strcmp(order, "push")) {
           int num;
           scanf("%d", &num);
           stack.push(num);
       }
       else if (!strcmp(order, "pop")) {
           printf("%d\n", stack.pop());
       }
       else if (!strcmp(order, "size")) {
           printf("%d\n", stack.size());
       }
       else if (!strcmp(order, "empty")) {
           printf("%d\n", stack.empty());
       }
       else if (!strcmp(order, "top")) {
           printf("%d\n", stack.top());
       }
   }
   return 0;
}
