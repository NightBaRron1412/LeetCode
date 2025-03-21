class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

    unordered_set<string> supplySet(supplies.begin(), supplies.end());
    unordered_map<string, vector<string>> recipeIngredientsMap;
    unordered_set<string> canMake;
    
    for (int i = 0; i < recipes.size(); i++) {
        recipeIngredientsMap[recipes[i]] = ingredients[i];
    }
    
    queue<string> recipeQueue;
    
    for (const string& supply : supplies) {
        recipeQueue.push(supply);
    }
    
    while (!recipeQueue.empty()) {
        string currentIngredient = recipeQueue.front();
        recipeQueue.pop();
        
        for (auto& [recipe, ingList] : recipeIngredientsMap) {
            if (canMake.find(recipe) == canMake.end()) {
                bool canMakeRecipe = true;
                
                for (const string& ingredient : ingList) {
                    if (supplySet.find(ingredient) == supplySet.end()) {
                        canMakeRecipe = false;
                        break;
                    }
                }
                
                if (canMakeRecipe) {
                    canMake.insert(recipe);
                    supplySet.insert(recipe);
                    recipeQueue.push(recipe);
                }
            }
        }
    }
    
    vector<string> result(canMake.begin(), canMake.end());
    return result;
        
    }
};