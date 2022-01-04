/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode*, RandomListNode*> mp;
    RandomListNode* ogCurr = A, *cpCurr = NULL;
    while(ogCurr) {
        cpCurr = new RandomListNode(ogCurr->label);
        mp[ogCurr] = cpCurr;
        ogCurr = ogCurr->next;
    }
    ogCurr = A;
    while(ogCurr) {
        cpCurr = mp[ogCurr];
        cpCurr->next = mp[ogCurr->next];
        cpCurr->random = mp[ogCurr->random];
        ogCurr = ogCurr->next;
    }
    return mp[A];
}
