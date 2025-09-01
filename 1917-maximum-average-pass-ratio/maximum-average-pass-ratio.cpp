class Solution {
public:
    struct data {
        int a, b;
        double gain;
    };

    struct cmp {
        bool operator()(const data &x, const data &y) const {
            return x.gain < y.gain; 
        }
    };

    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<data, vector<data>, cmp> pq;

        for (auto &c : classes) {
            int a = c[0], b = c[1];
            double g = (double)(a+1)/(b+1) - (double)a/b;
            pq.push({a, b, g});
        }

        while (extraStudents--) {
            auto cur = pq.top(); pq.pop();
            int a = cur.a, b = cur.b;
            a++, b++;
            double g = (double)(a+1)/(b+1) - (double)a/b;
            pq.push({a, b, g});
        }

        double ans = 0;
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            ans += (double)cur.a / cur.b;
        }
        return ans / classes.size();
    }
};
