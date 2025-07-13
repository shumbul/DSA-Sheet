class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size(), "");
        priority_queue<pair<int, int>> marks;
        for (int i=0;i<score.size();i++)
        {
            marks.push({score[i], i});
        }
        int count=1;
        while (!marks.empty())
        {
            if (count==1)
            {
            ans[marks.top().second]="Gold Medal";
            count++;
            marks.pop();
            }
            else if (count==2)
            {
                 
            ans[marks.top().second]="Silver Medal";
            count++;
            marks.pop();
            }
            else if (count==3)
            {
                 
            ans[marks.top().second]="Bronze Medal";
            count++;
            marks.pop();
            }
            else
            {
                ans[marks.top().second]=to_string(count);
            count++;
            marks.pop();
            }
        }
        return ans;
    }
};
