#include <vector>
#include <queue>

class LockingTree {
public:
    std::vector<std::vector<int>> children; // Adjacency list
    std::vector<int> parent;                // Parent of each node
    std::vector<int> lockUser;              // Lock status: -1 = unlocked, else user ID

    LockingTree(std::vector<int>& parent) {
        this->parent = parent;
        int n = parent.size();
        lockUser = std::vector<int>(n, -1);
        children = std::vector<std::vector<int>>(n);

        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);
            }
        }
    }

    bool lock(int num, int user) {
        if (lockUser[num] != -1) return false; // Already locked
        lockUser[num] = user;
        return true;
    }

    bool unlock(int num, int user) {
        if (lockUser[num] != user) return false; // Locked by someone else or already unlocked
        lockUser[num] = -1;
        return true;
    }

    bool hasLockedAncestor(int node) {
        while (parent[node] != -1) {
            node = parent[node];
            if (lockUser[node] != -1) return true;
        }
        return false;
    }

    bool collectLockedDescendants(int node, std::vector<int>& lockedNodes) {
        std::queue<int> q;
        q.push(node);
        bool found = false;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int child : children[current]) {
                if (lockUser[child] != -1) {
                    lockedNodes.push_back(child);
                    found = true;
                }
                q.push(child);
            }
        }
        return found;
    }

    bool upgrade(int num, int user) {
        if (lockUser[num] != -1) return false;          // Node is already locked
        if (hasLockedAncestor(num) == true) return false; // One of its ancestors is locked

        std::vector<int> lockedDescendants;
        if (!collectLockedDescendants(num, lockedDescendants)) return false; // No locked descendants

        // Unlock all locked descendants
        for (int node : lockedDescendants) {
            lockUser[node] = -1;
        }

        // Lock the current node
        lockUser[num] = user;
        return true;
    }
};
