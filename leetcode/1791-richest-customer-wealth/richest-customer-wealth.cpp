class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;

        for (const auto& row : accounts) {  // auto& == vector<int>
            int sum = 0;

            for (int column : row) {
                sum += column;
            }
            result = max(result, sum);
        }

        return result;
    }
};