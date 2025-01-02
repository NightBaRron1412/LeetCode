class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        vector<int> prefix_sum(words.size() + 1, 0);

        for (size_t i = 0; i < words.size(); i++){
            if(isVowel(words[i].front()) && isVowel(words[i].back())){
                prefix_sum[i + 1] = prefix_sum[i] + 1;
            }
            else{
                prefix_sum[i + 1] = prefix_sum[i];
            }
        }

        vector<int> result(queries.size(), 0);

        for (size_t i = 0; i < queries.size(); i++){
           result[i] = prefix_sum[queries[i][1] + 1] - prefix_sum[queries[i][0]];
        }
        return result;
    }

    private:
        bool isVowel(char c){
        return (c =='a' || c =='e'
                || c =='i' || c =='o'
                || c =='u');
    }
};