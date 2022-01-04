stack<int> s;
stack<int> minst;
MinStack::MinStack() {
    while(!s.empty()) s.pop();
    while(!minst.empty()) minst.pop();
}

void MinStack::push(int x) {
    s.push(x);
    if (minst.empty() || x < minst.top()) minst.push(x);
}

void MinStack::pop() {
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        if (minst.top() == x) minst.pop();
    }
}

int MinStack::top() {
    return s.empty() ? -1 : s.top();
}

int MinStack::getMin() {
    return minst.empty() ? -1 : minst.top();
}

