// Brute Force
// Time complexity = exponential 
// Causes TLE
class Solution {
    long long solve(int start , long long point , vector<vector<int>>& questions)
    {
        if (start >= questions.size()) return point;
        long long taken = solve(start + questions[start][1] + 1 ,  point + questions[start][0] , questions);

        long long ignored = solve(start + 1 , point , questions);

        return max(ignored , taken);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        return solve(0 , 0 , questions);
    }
};

// With Memoisation using Hash Map
// Time Complexity : O(n)
class Solution {
    long long solve(int start , long long point , vector<vector<int>>& questions)
    {
        if (start >= questions.size()) return point;
        long long taken = solve(start + questions[start][1] + 1 ,  point + questions[start][0] , questions);

        long long ignored = solve(start + 1 , point , questions);

        return max(ignored , taken);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        return solve(0 , 0 , questions);
    }
};

// Memoisation with vector
// Most effiecient solution
class Solution {
    long long solve(int start , vector<vector<int>>& questions ,vector <long long>&solutions)
    {
        if (start >= questions.size()) return 0;
        if (solutions[start] != -1) return solutions[start];
        long long taken = questions[start][0] + solve(start + questions[start][1] + 1 , questions , solutions);

        long long ignored = solve(start + 1 , questions , solutions);
        solutions[start] = max(ignored , taken);
        return solutions[start];
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector <long long> solutions(questions.size() , -1);
        return solve(0 , questions , solutions);
    }
};
