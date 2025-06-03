class LockingTree {
public:
    vector<int> parent;
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> lockmap;  // node -> user

    LockingTree(vector<int>& parent) : parent(parent) {
        int n = parent.size();
        for (int i = 0; i < n; i++) {
            if (parent[i] != -1)
                adj[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lockmap.count(num)) return false;
        lockmap[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (lockmap.count(num) && lockmap[num] == user) {
            lockmap.erase(num);
            return true;
        }
        return false;
    }

    // Checks if any ancestor is locked
    bool hasLockedAncestor(int num) {
        int curr = parent[num];
        while (curr != -1) {
            if (lockmap.count(curr)) return true;
            curr = parent[curr];
        }
        return false;
    }

    // Checks for locked descendants and unlocks them
    bool unlockDescendants(int num) {
        bool foundLocked = false;
        queue<int> q;
        q.push(num);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int child : adj[node]) {
                if (lockmap.count(child)) {
                    lockmap.erase(child);
                    foundLocked = true;
                }
                q.push(child);
            }
        }
        return foundLocked;
    }

    bool upgrade(int num, int user) {
        if (lockmap.count(num)) return false;
        if (hasLockedAncestor(num)) return false;

        // Unlock descendants and check if at least one was locked
        if (!unlockDescendants(num)) return false;

        // Lock current node
        lockmap[num] = user;
        return true;
    }
};
