class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        vector<int> ast;
        int i = 0;

        // hadle negative integers at starting
        for (int i = 0; i < n; i++)
        {
            if (asteroids[i] < 0)
            {
                ast.push_back(asteroids[i]);
            }
            else
            {
                break;
            }
        }
        int k = i;
        for (; i < n; i++)
        {
            if (asteroids[i] > 0)
            {
                ast.push_back(asteroids[i]);
            }
            else if (asteroids[i] < 0)
            {
                if (asteroids[i] + ast[ast.size() - 1] > 0)
                {
                    continue;
                }
                else if (asteroids[i] + ast[ast.size() - 1] <= 0)
                {
                    for (int j = ast.size() - 1; j >= k; j--)
                    {
                        if (asteroids[i] + ast[j] == 0)
                        {
                            ast.pop_back();
                            break;
                        }
                        else if (asteroids[i] + ast[j] > 0)
                        {
                            ast.pop_back();
                            break;
                        }
                        else
                        {
                            ast.pop_back();
                        }
                        ast.push_back(asteroids[i]);
                    }
                }
            }
        }

        return ast;
    }
};