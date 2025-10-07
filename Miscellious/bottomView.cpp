#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        unordered_map<Node*,int>omap;
        map<int,vector<Node*>>mapForOrder;

        queue<Node*>q;
        q.push(root);
        omap[root]=0;
        mapForOrder[0].push_back(root);

        while(!q.empty()) {
            int counter=q.size();
            for(int i=0;i<counter;i++) {
                Node* vertex=q.front();
                q.pop();
                int location=omap[vertex];
                if(vertex->left!=NULL) {
                    q.push(vertex->left);
                    omap[vertex->left]=location-1;
                    mapForOrder[location-1].push_back(vertex->left);
                }

                if(vertex->right!=NULL) {
                    q.push(vertex->right);
                    omap[vertex->right]=location+1;
                    mapForOrder[location+1].push_back(vertex->right);
                }
            }

        }


        vector<int>ans;

        for(auto i:mapForOrder) {
            ans.push_back(i.second[i.second.size()-1]->data);
        }
        return ans;

    }
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int> result = sol.bottomView(root);

    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}
