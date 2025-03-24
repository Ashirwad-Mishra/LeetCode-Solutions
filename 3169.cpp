class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());
        int start = meetings[0][0];
        int end = meetings[0][1];
        int ans = 0;
        if (start > 1) ans += start - 1;
        for (int i = 1 ; i < meetings.size() ; i++)
        {
            if (meetings[i][0] > end)
            {
                ans += meetings[i][0] - end - 1;
            }
            end = max(end , meetings[i][1]);
        }
        if (end < days) ans += days - end;
        return ans;
    }
};
