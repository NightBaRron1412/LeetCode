class Solution {
public:
    vector<int> constructDistancedSequence(int targetNumber) {
        int length = targetNumber * 2 - 1;
        vector<int> sequence(length, 0);
        vector<bool> usedNumbers(targetNumber + 1, false);
        generateSequence(0, sequence, usedNumbers, targetNumber);
        return sequence;
    }

private:
    bool generateSequence(int index, vector<int>& sequence, vector<bool>& usedNumbers, int targetNumber) {
        if (index == sequence.size()) return true;
        if (sequence[index] != 0) return generateSequence(index + 1, sequence, usedNumbers, targetNumber);

        for (int num = targetNumber; num >= 1; num--) {
            if (usedNumbers[num]) continue;
            if (num == 1) {
                sequence[index] = 1;
                usedNumbers[1] = true;
                if (generateSequence(index + 1, sequence, usedNumbers, targetNumber)) return true;
                sequence[index] = 0;
                usedNumbers[1] = false;
            } 
            else {
                int secondPosition = index + num;
                if (secondPosition < sequence.size() && sequence[secondPosition] == 0) {
                    sequence[index] = sequence[secondPosition] = num;
                    usedNumbers[num] = true;
                    if (generateSequence(index + 1, sequence, usedNumbers, targetNumber)) return true;
                    sequence[index] = sequence[secondPosition] = 0;
                    usedNumbers[num] = false;
                }
            }
        }
        return false;
    }
};