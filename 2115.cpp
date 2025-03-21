class Solution {
    bool CBM(int i, vector<vector<string>>& ingredients, unordered_set<string>& supplies) {
        for (const string &s : ingredients[i]) 
        {
            if (supplies.find(s) == supplies.end()) 
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> supplySet(supplies.begin(), supplies.end()); 
        vector<string> ans;
        bool added = true; 

        while (added) 
        {
            added = false;
            for (int i = 0; i < recipes.size(); i++) 
            {
                if (supplySet.find(recipes[i]) == supplySet.end() && CBM(i, ingredients, supplySet)) 
                {
                    supplySet.insert(recipes[i]);
                    ans.push_back(recipes[i]);
                    added = true;
                }
            }
        }
        return ans;
    }
};
