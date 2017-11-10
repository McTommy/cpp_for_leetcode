//
// Created by shucheng on 17-11-6.
//
#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
#include <numeric>
#include <algorithm>
#include <cassert>

#include "../stackAndQueue/structure.h"

using namespace std;

namespace dynamicProgramming {
    class Solution {
    private:
        vector<int> memo;

        int calcWays(int n) {
            if (n == 0 || n == 1)
                return 1;
            if (memo[n] == -1)
                memo[n] = calcWays(n - 1) + calcWays(n - 2);
            return memo[n];
        }

        int calMininumTotal(vector<vector<int>> &triangle, int row, int col, vector<vector<int>> mininum) {
            if (row == triangle.size() - 1)
                return triangle[row][col];
            if (mininum[row][col] == -1)
                mininum[row][col] = min(calMininumTotal(triangle, row + 1, col, mininum) + triangle[row][col],
                                        calMininumTotal(triangle, row + 1, col + 1, mininum) + triangle[row][col]);
            return mininum[row][col];
        }

        int max3(int a, int b, int c) {
            return max(a, max(b, c));
        }

        int breakInteger(int n) {
            if (n == 1) return 1;

            int res = -1;
            if (memo[n] != -1)
                return memo[n];
            for (int i = 1; i < n; i++) {
                res = max3(i, i * (n - i), i * breakInteger(n - i));
            }
            memo[n] = res;
            return res;
        }

        int robber2(vector<int> &nums, int start, int end) {
            int pre = 0, cur = 0;
            for (int i = start; i <= end; i++) {
                int temp = max(pre + nums[i], cur);
                pre = cur;
                cur = temp;
            }
            return cur;
        }

    public:
        int fib(int n) {
            vector<int> memo(n + 1, -1);

            memo[0] = 0;
            memo[1] = 1;
            for (int i = 2; i <= n; i++)
                memo[i] = memo[i - 1] + memo[i - 2];

            return memo[n];
        }

        int climbStairs(int n) {
            memo = vector<int>(n + 1, -1);
            return calcWays(n);
        }

        int climbStairs2(int n) {
            vector<int> memo = vector<int>(n + 1, -1);
            memo[1] = 1;
            memo[2] = 2;
            for (int i = 3; i <= n; i++)
                memo[i] = memo[i - 1] + memo[i - 2];
            return memo[n];
        }

        int minimumTotal(vector<vector<int>> &triangle) {
            int length = triangle.size() + 1;
            vector<vector<int>> mininum(length, vector<int>(length, -1));
            return calMininumTotal(triangle, 0, 0, mininum);
        }

        int minimumTotal2(vector<vector<int>> &triangle) {
            vector<vector<int>> res(triangle.size(), vector<int>(triangle.size(), 0));
            if (triangle.empty()) return 0;
            if (triangle.size() == 1) return triangle[0][0];
            for (int i = triangle.size() - 1; i >= 0; i--)
                for (int j = 0; j < triangle[i].size(); j++) {
                    if (i == triangle.size() - 1)
                        res[i][j] = triangle[i][j];
                    else
                        res[i][j] = triangle[i][j] + min(res[i + 1][j], res[i + 1][j + 1]);
                }
            return res[0][0];
        }

        int minPathSum(vector<vector<int>> &grid) {
            vector<vector<int>> res(grid.size(), vector<int>(grid[0].size(), 0));
            if (grid.empty()) return 0;
            for (int i = grid.size() - 1; i >= 0; i--)
                for (int j = grid[0].size() - 1; j >= 0; j--) {
                    if (i == grid.size() - 1 && j == grid[0].size() - 1)
                        res[i][j] = grid[i][j];
                    else if (i == grid.size() - 1)
                        res[i][j] = grid[i][j] + res[i][j + 1];
                    else if (j == grid[0].size() - 1)
                        res[i][j] = grid[i][j] + res[i + 1][j];
                    else
                        res[i][j] = grid[i][j] + min(res[i][j + 1], res[i + 1][j]);
                }
            return res[0][0];
        }

        int integerBreak(int n) {
            memo = vector<int>(n + 1, -1);
            return breakInteger(n);
        }

        int integerBreak2(int n) {
            vector<int> memo(n + 1, -1);

            memo[1] = 1;
            for (int i = 2; i <= n; i++)
                for (int j = 1; j <= i - 1; j++)
                    memo[i] = max3(j * (i - j), j * memo[i - j], memo[i]);
            return memo[n];
        }

        int uniquePaths(int m, int n) {
            vector<vector<int>> res(m, vector<int>(n, 1));

            if (m == 1 || n == 1) return 1;
            for (int i = m - 2; i >= 0; i--)
                for (int j = n - 2; j >= 0; j--)
                    res[i][j] = res[i + 1][j] + res[i][j + 1];
            return res[0][0];
        }

        int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
            vector<vector<int>> res(m, vector<int>(n, 0));

            for (int i = m - 1; i >= 0; i--)
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1)
                        res[i][j] = obstacleGrid[i][j] == 1 ? 0 : 1;
                    else if (i == m - 1)
                        res[i][j] = obstacleGrid[i][j] == 1 ? 0 : res[i][j + 1];
                    else if (j == n - 1)
                        res[i][j] = obstacleGrid[i][j] == 1 ? 0 : res[i + 1][j];
                    else
                        res[i][j] = obstacleGrid[i][j] == 1 ? 0 : res[i + 1][j] + res[i][j + 1];
                }
            return res[0][0];
        }

        int numDecodings(string s) {
            int size = s.length();
            if (size == 0 || s[0] == '0') return 0;
            vector<int> res(size + 1, 1);
            res[size - 1] = s[size - 1] == '0' ? 0 : 1;
            if (size == 1) return res[0];
            for (int i = size - 2; i >= 0; i--) {
                if (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')
                    res[i] = res[i + 1] + res[i + 2];
                else if (s[i] == '0')
                    res[i] = 0;
                else
                    res[i] = res[i + 1];
            }
            return res[0];
        }

        int numSquares(int n) {
            if (n == 0) return 0;
            vector<int> res(n + 1, INT32_MAX);
            res[0] = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j * j <= i; j++)
                    res[i] = min(res[i], res[i - j * j] + 1);
            return res[n];
        }

        int rob(vector<int> &nums) {
            int size = nums.size();
            if (size == 0) return 0;
            if (size == 1) return nums[0];
            vector<int> res(size + 1, 0);
            res[0] = nums[0];
            res[1] = max(nums[0], nums[1]);
            if (size == 2) return res[1];
            for (int i = 2; i < size; i++)
                res[i] = max(res[i - 1], nums[i] + res[i - 2]);

            return res[size - 1];
        }

        int rob2(vector<int> &nums) {
            int size = nums.size();
            if (size < 2) return size ? nums[0] : 0;
            return max(robber2(nums, 0, size - 2), robber2(nums, 1, size - 1));
        }

        int rob3(TreeNode *root) {
            if (!root) return 0;
            if (!root->right && !root->left) return root->val;
            int l = 0, r = 0, ll = 0, lr = 0, rl = 0, rr = 0;
            if (root->left) {
                l = rob3(root->left);
                ll = rob3(root->left->left);
                lr = rob3(root->left->right);
            }
            if (root->right) {
                r = rob3(root->right);
                rl = rob3(root->right->left);
                rr = rob3(root->right->right);
            }
            return max(root->val + ll + lr + rr + rl, l + r);
        }

        int maxProfit(vector<int> &prices) {
            int size = prices.size();
            if (size < 2) return 0;
            vector<int> coolDown(prices.size(), 0);
            vector<int> buy(prices.size(), 0);
            vector<int> sell(prices.size(), 0);
            coolDown[0] = 0;
            buy[0] = -prices[0];
            sell[0] = 0;
            for (int i = 1; i <= size - 1; i++) {
                coolDown[i] = max(coolDown[i - 1], sell[i - 1]);
                buy[i] = max(buy[i - 1], coolDown[i - 1] - prices[i]);
                sell[i] = buy[i - 1] + prices[i];
            }
            return max(coolDown[size - 1], sell[size - 1]);
        }

        //0-1背包问题 (1)
        int knapsack01(const vector<int> &w, const vector<int> &v, int c) {
            int n = w.size();
            if (n == 0)
                return 0;
            vector<vector<int>> memo(n, vector<int>(c + 1, -1));

            for (int j = 0; j <= c; j++)
                memo[0][j] = j >= w[0] ? v[0] : 0;

            for (int i = 1; i < n; i++)
                for (int j = 0; j <= c; j++) {
                    memo[i][j] = memo[i - 1][j];
                    if (j >= w[i])
                        memo[i][j] = max(memo[i][j], v[i] + memo[i - 1][j - w[i]]);
                }
            return memo[n - 1][c];
        }

        //0-1背包问题 (2) 空间优化O(n) -> O(c)
        int knapsack01_2(const vector<int> &w, const vector<int> &v, int c) {
            int n = w.size();
            if (n == 0)
                return 0;
            vector<int> memo(c + 1, -1);

            for (int j = 0; j <= c; j++)
                memo[j] = j >= w[0] ? v[0] : 0;

            for (int i = 1; i < n; i++)
                for (int j = c; j >= w[i]; j--)
                    memo[j] = max(memo[j], v[i] + memo[j - w[i]]);
            return memo[c];
        }

        bool canPartition(vector<int> &nums) {
            int sum = 0;
            for (int n : nums)
                sum += n;

            if (sum % 2 != 0) return false;
            int c = sum / 2;

            vector<bool> memo(c + 1, false);
            for (int i = 0; i <= c; i++)
                memo[i] = (nums[0] == i);

            for (int i = 1; i < nums.size(); i++)
                for (int j = c; j >= nums[i]; j--) {
                    memo[j] = memo[j] || memo[j - nums[i]];
                }
            return memo[c];
        }
    };
}
