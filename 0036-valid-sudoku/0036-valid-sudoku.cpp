class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char value = board[row][col];

                // Empty cells do not need validation.
                if (value == '.') {
                    continue;
                }

                string rowKey = string(1, value) + " in row " + to_string(row);
                string colKey = string(1, value) + " in col " + to_string(col);

                int box = (row / 3) * 3 + (col / 3);
                string boxKey = string(1, value) + " in box " + to_string(box);

                // insert() returns false if the key already exists.
                if (!seen.insert(rowKey).second ||
                    !seen.insert(colKey).second ||
                    !seen.insert(boxKey).second) {
                    return false;
                }
            }
        }

        return true;
    }
};