class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int totalQueries = queries.size();
        vector<int> output(totalQueries);
        unordered_map<int, int> colorFrequency;
        unordered_map<int, int> ballColors;

        for (int i = 0; i < totalQueries; i++) {
            int currentBall = queries[i][0], newColor = queries[i][1];

            if (ballColors.count(currentBall)) {
                int previousColor = ballColors[currentBall];
                if (--colorFrequency[previousColor] == 0) {
                    colorFrequency.erase(previousColor);
                }
            }
            
            ballColors[currentBall] = newColor;
            colorFrequency[newColor]++;
            output[i] = colorFrequency.size();
        }
        return output;
    }
};
