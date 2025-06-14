class Solution {
    int count=0;
public:
    string winningPlayer(int x, int y) {
        if (x<1 || y<4)
        {
            if (count%2==0)
                return "Bob";
            else
                return "Alice";
        }
        count++;
        return winningPlayer(x-1, y-4);
    }
};
//TC O(min(x,y/4))
//SC O(min(x,y/4))

class Solution {
public:
    string winningPlayer(int x, int y) {
        int noOfRounds=min(x, y/4);
        if (noOfRounds%2==0)
            return "Bob";
        return "Alice";
    }
};
