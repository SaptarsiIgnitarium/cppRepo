#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX));

    //base case: 0 coins needed to make amount
    for (int i = 0; i <= coins.size(); i++)
    {
        dp[i][0] = 0;
    }

    //iterating through each coin denomination and amount
    for (int i = 1; i <= coins.size(); ++i) 
    {
        for (int j = 1; j <= amount; ++j) 
        {
            if (j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT_MAX) 
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
            } 
            else 
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[coins.size()][amount] == INT_MAX ? -1 : dp[coins.size()][amount];   
}

int main() {
    vector<int> coins = {1, 2, 5}; // Example denominations
    int amount = 11; // Example total amount
    
    int minCoins = coinChange(coins, amount);
    
    if (minCoins == -1) {
        cout << "It's not possible to make up the amount using given coins." << endl;
    } else {
        cout << "Minimum number of coins needed: " << minCoins << endl;
    }
    
    return 0;
}