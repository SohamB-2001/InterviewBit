int Solution::solve(string A) {
    int i = 0, j = A.size()-1;
    bool removed = 0;
    while(i < j) {
        if (A[i] != A[j]) {
            if (!removed) {
                removed = true;
                if (A[i+1] == A[j]) i++;
                else if (A[j-1] == A[i]) j--;   
                else return 0;
            }
            else return 0;
        }
        else {
            i++; j--;
        }
    }
    return 1;
}
