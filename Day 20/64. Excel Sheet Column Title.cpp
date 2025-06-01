class Solution {
    string convertToTitle(int n) {
        string result = "";
        while (n > 0) {
            n--; //to shift it into 0-indexed space
            int rem = n % 26; //for curr char
            result += (char)(rem + 'A'); // get the char
            n = n / 26; //move to next digit
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
//TC O(N)
//SC O(N)
