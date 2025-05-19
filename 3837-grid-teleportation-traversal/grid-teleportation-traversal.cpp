class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> sc(n, vector<int>(m, INT_MAX));
        unordered_map<char, vector<pair<int, int>>> portals;
        unordered_set<char> usedTeleport;

        // push all portals into the array
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                if (isalpha(matrix[i][j])) // only portals
                    portals[matrix[i][j]].push_back({i, j});

            }

        }
//    NOTE:- Humne deque liya hai kuki ye 0-1 BFS hai , matlab  issme wait ya to 1 hai to move to adjecent cell , ya to teleportation hai , issme wait 0 hai
        // deque: {time, x, y}
        deque<tuple<int,int,int>>dq;
        dq.push_front({0, 0, 0});
        sc[0][0] = 0;

        vector<pair<int, int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!dq.empty()) {
            auto [time,x,y]=dq.front();
        // int time=dq.front().first; 
        // int x=dq.front(); 
        // int  y= dq.front()[2]; 
            
            dq.pop_front();

            // Skip if this cell is already has lowest time 
            if (sc[x][y] < time) continue;

            // Instant teleportation eak baar karna hai iss liye usedTeleport map me insert kar dena hai
            char ch = matrix[x][y];
            // ch char hona chahiye and used nahi hona chahiye
            if (isalpha(ch) && usedTeleport.find(ch) == usedTeleport.end()) {
                // har eak portal me jake efficent time ko replace kar do , or queue me daal do kuki isse hum aage travers kr sakte hai
                for (auto& [tx, ty] : portals[ch]) {
                    if (sc[tx][ty] > time) {
                        sc[tx][ty] = time;
                        dq.push_front({time, tx, ty});
                    }
                }
                usedTeleport.insert(ch); // mark kardo ki vo used ho gaya hai as per question
            }
            // Move to 4 adjacent cells  (ye  all 4 cell me jane ka short code hai with the help of loop)
            for (auto [dx, dy] : dirs) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && matrix[nx][ny] != '#') {
                    if (sc[nx][ny] > time + 1) {
                        sc[nx][ny] = time + 1;
                        dq.push_back({time + 1, nx, ny});
                    }
                }
            }

           
        }
// agar hum last corner tak nahi pahuch paye to vi INR_MAX hi reh jayega , nahi to minimum value dega
        return sc[n - 1][m - 1] == INT_MAX ? -1 : sc[n - 1][m - 1];
    }
};
