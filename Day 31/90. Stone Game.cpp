class Solution {
    int sumA = 0;
    int sumB = 0;
    int count = 1; //Odd = A’s turn, Even = B’s turn
    int idxf = 0;
    int idxl = 0;
public:
    bool stoneGame(vector<int>& piles) {
        idxl = piles.size() - 1;
        if (count % 2 != 0) { //if alice's turn
        //pick larger value
            if (piles[idxf] > piles[idxl]) {
                sumA += piles[idxf];
                idxf++;
                count++;
            } else if (piles[idxf] < piles[idxl]) {
                sumA += piles[idxl];
                idxl--;
                count++;
            //don't let bob take a larger value when it's his turn
            } else {
                if (piles[idxf + 1] >= piles[idxl - 1]) {
                    sumA += piles[idxl];
                    idxl--;
                    count++;
                } else {
                    sumA += piles[idxf];
                    idxf++;
                    count++;
                }
            }
        } else { //bob's turn
            if (piles[idxf] > piles[idxl]) {
                sumB += piles[idxf];
                idxf++;
                count++;
            } else if (piles[idxf] < piles[idxl]) {
                sumB += piles[idxl];
                idxl--;
                count++;
            } else {
                if (piles[idxf + 1] >= piles[idxl - 1]) {
                    sumB += piles[idxl];
                    idxl--;
                    count++;
                } else {
                    sumB += piles[idxf];
                    idxf++;
                    count++;
                }
            }
        }
        if (sumA>sumB)
            return true;
        return false;
    }
};

class Solution {
    int sumA = 0;
    int sumB = 0;
    int count = 1;
    int idxf = 0;
    int idxl = 0;
public:
    bool stoneGame(vector<int>& piles) {
        idxl = piles.size() - 1;
        while (idxf <= idxl) {
            if (count % 2 != 0) {  // Alice's turn
                if (piles[idxf] > piles[idxl]) {
                    sumA += piles[idxf];
                    idxf++;
                } else if (piles[idxf] < piles[idxl]) {
                    sumA += piles[idxl];
                    idxl--;
                } else {  // Equal values at both ends
                    if (idxf + 1 <= idxl - 1 && piles[idxf + 1] >= piles[idxl - 1]) {
                        sumA += piles[idxl];
                        idxl--;
                    } else {
                        sumA += piles[idxf];
                        idxf++;
                    }
                }
            } else {  // Bob's turn
                if (piles[idxf] > piles[idxl]) {
                    sumB += piles[idxf];
                    idxf++;
                } else if (piles[idxf] < piles[idxl]) {
                    sumB += piles[idxl];
                    idxl--;
                } else {  // Equal values at both ends
                    if (idxf + 1 <= idxl - 1 && piles[idxf + 1] >= piles[idxl - 1]) {
                        sumB += piles[idxl];
                        idxl--;
                    } else {
                        sumB += piles[idxf];
                        idxf++;
                    }
                }
            }
            count++;  // Switch turn
        }
        return sumA > sumB;
    }
};

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int result = helper(0, piles.size() - 1, piles); //net advantage 
        return (result > 0); //alice wins if true
    }
    int helper(int left, int right, const vector<int>& piles) 
    { //returns the difference in score between the current player and the opponent assuming both play optimally
     //to compute the max diff in score the current player can enforce, from piles[left] to piles[right]
        if (left == right) 
            return piles[left];
        // Player chooses either left or right, opponent plays optimally
        int pickLeft = piles[left] - helper(left + 1, right, piles);
        //current player gets piles[left], opponent then plays optimally in [left + 1, right], so the net gain is piles[left] - opponent’s optimal response.
        int pickRight = piles[right] - helper(left, right - 1, piles);
        //similarly
        return max(pickLeft, pickRight);
    }
};
//TC O(2^n)
//SC O(n)

class Solution {
    vector<vector<int>> dp;
    int idxf = 0;
    int idxl = 0;

public:
    bool stoneGame(vector<int>& piles) {
        dp.resize(piles.size()+1, vector<int> (piles.size()+1, -1));
        for (int i=0;i<piles.size();i++)
        {
            dp[i][i]=piles[i];
        }
        idxl = piles.size() - 1;
        if (helper(idxf, idxl, piles)>0)
            return true;
        return false;
    }
    int helper(int idxf, int idxl, vector<int>& piles)
    { //max score diff current player can force
        if (dp[idxf][idxl]!=-1)
            return dp[idxf][idxl];
        int first=piles[idxf]- helper(idxf+1, idxl, piles); //subtract opponent's best score from our gain
        int last=piles[idxl]- helper(idxf, idxl-1, piles);
            return dp[idxf][idxl]=max(first, last);
    }
};
//TC O(n^2)
//SC O(n^2)
