class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int common {0};
        vector<int> prefixCommonArray(A.size());
        unordered_set<int> seenA, seenB;

        for (size_t i = 0; i < A.size(); i++)
        {
            seenA.insert(A[i]);
            seenB.insert(B[i]);

            if (seenB.count(A[i]))
            {
                common++;
            }
            if (seenA.count(B[i]) && A[i] != B[i])
            {
                common++;
            }

            prefixCommonArray[i] = common;
        }
        return prefixCommonArray;
    }
};
