class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        int i = 0;
        for (int x : pushed) {
            stack.push(x);
            while (stack.size() && stack.top() == popped[i]) {
                stack.pop();
                i++;
            }
        }
        return stack.size() == 0;
    }
};

//source => Leetcode
//explanation => https://www.youtube.com/watch?v=vHKXT0cSI54
