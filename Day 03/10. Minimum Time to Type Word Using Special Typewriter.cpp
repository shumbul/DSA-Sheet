class Solution 
{
public:
    int minTimeToType(string word) 
    {
        int count = word.size();
        //seconds to type each letter
        if (word[0] >= 'a' && word[0] <= 'm')
            count = count + (word[0] - 'a');
        else
            count = count + abs(abs(word[0] - 'a') - 26);
        //pointer ko a se 1st letter tak le jaana hai
        for (int i = 0; i < word.size() - 1; i++) 
        {
            if (abs(word[i + 1] - word[i]) > 13 || word[i + 1] - word[i] < -13) 
            {
                int now = abs(word[i + 1] - word[i]) - 26;
                //for anticlockwise
                count = count + abs(now);
            } 
            else 
            {
                count = count + (abs(word[i + 1] - word[i]));
                //for clockwise
            }
        }
        return count;
    }
};
//TC O(N)
//SC O(1)
