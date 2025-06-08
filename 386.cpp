// https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2025-06-08
// inTS
function lexicalOrder(n: number): number[] {
    let A = [];
    for (let i = 1 ; i <= n ; i++ )
    {
        A.push(i);
    }
    A.sort();
    return A;
};

// in cpp
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector <string> temp;
        for (int i = 1 ; i <= n ; i++)
        {
            temp.push_back(to_string(i));
        }
        sort(temp.begin() , temp.end());

        vector <int> ans;
        for (auto &i : temp)
        {
            ans.push_back(stoi(i));
        }
        return ans;
    }
};
// in JS
/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    let A = [];
    for (let i = 1 ; i <= n ;i++)
    {
        A.push(i);
    }
    A = A.sort();
    return A;
};
