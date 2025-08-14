class Solution {
public:
    string largestGoodInteger(string num) {
        string best = "";
        for (int i = 0; i + 2 < num.size(); i++) {
            // Check if we have three identical consecutive characters
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string triple = num.substr(i, 3);
                if (triple > best) { // Lexicographical comparison works for same-length strings
                    best = triple;
                }
            }
        }
        return best;
    }
};
