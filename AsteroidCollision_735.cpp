/*
~ Author    : https://leetcode.com/tridib_2003/
~ Problem   : 735. Asteroid Collision
~ Link      : https://leetcode.com/problems/asteroid-collision/
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;

        for (int i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] > 0)
                res.emplace_back(asteroids[i]);
            else {
                while (!res.empty() && res.back() > 0 && res.back() < abs(asteroids[i]))
                    res.pop_back();

                if (res.empty() || res.back() < 0)
                    res.emplace_back(asteroids[i]);
                else if (!res.empty() && res.back() == abs(asteroids[i]))
                    res.pop_back();
            }
        }

        return res;
    }
};

// Time Complexity - O(n)
// Auxiliary Space - O(n)
