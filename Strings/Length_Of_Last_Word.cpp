int Solution::lengthOfLastWord(const string A) {
    stringstream s(A);
    string word, last;
    while(s >> word) {
        last = word;
    }
    return last.length();
}
