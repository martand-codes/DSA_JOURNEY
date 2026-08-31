class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int asteroid : asteroids) {
            bool isCrashed = false;
            while (!s.empty() && s.top() > 0 && asteroid < 0) {
                if(s.top() < abs(asteroid)) {
                    s.pop();
                } else if(s.top() == abs(asteroid)) {
                    s.pop();
                    isCrashed = true;
                    break;
                } else {
                    isCrashed = true;
                    break;
                }
            }
            if(!isCrashed) {
                s.push(asteroid);
            }
        }

        vector<int> result(s.size());
        for(int i = s.size() - 1; i >= 0; i--) {
            result[i] = s.top();
            s.pop();
        }
        return result; 
            
    }
};