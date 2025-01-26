/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* locateNode(TreeNode* root, int value) {
       
        if (!root || root->val == value) {
            return root;
        }


        TreeNode* leftResult = locateNode(root->left, value);
        if (leftResult) return leftResult;

        return locateNode(root->right, value);
    }

    unordered_map<TreeNode*, vector<TreeNode*>> adjacencyMap;
    void createAdjacencyList(TreeNode* currentNode, TreeNode* parentNode) {
        if (!currentNode) return;

        if (adjacencyMap.find(currentNode) == adjacencyMap.end()) {
            adjacencyMap[currentNode] = {};

            if (parentNode) {
                adjacencyMap[currentNode].push_back(parentNode);
                adjacencyMap[parentNode].push_back(currentNode);
            }

            createAdjacencyList(currentNode->left, currentNode);
            createAdjacencyList(currentNode->right, currentNode);
        }
    }

    
    void simulateBurn(TreeNode* root, TreeNode* startNode, vector<vector<int>>& levels) {
        if (!root) return;

       
        createAdjacencyList(root, nullptr);

        if (adjacencyMap.find(startNode) == adjacencyMap.end()) return;

        unordered_set<TreeNode*> visitedNodes;
        queue<TreeNode*> bfsQueue;

        visitedNodes.insert(startNode);
        bfsQueue.push(startNode);

        while (!bfsQueue.empty()) {
            vector<int> currentLevel;
            int nodesAtCurrentLevel = bfsQueue.size();

            for (int i = 0; i < nodesAtCurrentLevel; i++) {
                TreeNode* currentNode = bfsQueue.front();
                bfsQueue.pop();

                currentLevel.push_back(currentNode->val);

                for (TreeNode* neighbor : adjacencyMap[currentNode]) {
                    if (visitedNodes.find(neighbor) == visitedNodes.end()) {
                        visitedNodes.insert(neighbor);
                        bfsQueue.push(neighbor);
                    }
                }
            }

            levels.push_back(currentLevel);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> burnLevels;

      
        TreeNode* startNode = locateNode(root, start);
        if (!startNode) return 0;

       
        simulateBurn(root, startNode, burnLevels);

       
        return burnLevels.empty() ? 0 : burnLevels.size() - 1;
    }
};