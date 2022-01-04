int Solution::strStr(const string B, const string A) {
    if (!A.length() && !B.length()) return -1;
    if (!A.length()) return -1;
    for(int i=0; i<B.length(); i++) {
        if (B[i] == A[0]) {
            if (B.substr(i, A.length()) == A) return i;
        }
    }
    return -1;
}
