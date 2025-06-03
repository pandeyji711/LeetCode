class LockingTree {
public:
    vector<int> parent;
    vector<vector<int>> children;
    vector<int> lockUser;  // lockUser[i] == 0 means unlocked

    LockingTree(vector<int>& parent) : parent(parent), lockUser(parent.size(), 0) {
        children.resize(parent.size());
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] != -1)
                children[parent[i]].push_back(i);
        }
    }

    bool lock(int num, int user) {
        if (lockUser[num] != 0) return false;
        lockUser[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (lockUser[num] == user) {
            lockUser[num] = 0;
            return true;
        }
        return false;
    }

    bool upgrade(int num, int user) {
        if (lockUser[num] != 0) return false;
        if (!areAllAncestorsUnlocked(num)) return false;

        vector<int> lockedDescendants;
        getLockedDescendants(num, lockedDescendants);

        if (lockedDescendants.empty()) return false;

        // Unlock all locked descendants
        for (int node : lockedDescendants)
            lockUser[node] = 0;

        lockUser[num] = user;
        return true;
    }

private:
    bool areAllAncestorsUnlocked(int node) {
        while (parent[node] != -1) {
            node = parent[node];
            if (lockUser[node] != 0) return false;
        }
        return true;
    }

    void getLockedDescendants(int node, vector<int>& lockedNodes) {
        for (int child : children[node]) {
            if (lockUser[child] != 0)
                lockedNodes.push_back(child);
            getLockedDescendants(child, lockedNodes);
        }
    }
};
