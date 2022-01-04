int evalExp(int x, int y, string sign) {
    if (sign == "+") return x+y;
    else if (sign == "-") return x-y;
    else if (sign == "*") return x*y;
    else return x/y;
}
int Solution::evalRPN(vector<string> &A) {
    stack<int> digits;
    for(int i=0; i<A.size(); i++) {
        if (!(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/")) digits.push(stoi(A[i]));
        else {
            int x = digits.top();
            digits.pop();
            int y = digits.top();
            digits.pop();
            digits.push(evalExp(y, x, A[i]));
        }
    }
    return digits.top();
}
