#include<bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

using namespace std;

struct Node {
    string key;
    map<string, Node*, greater<string>> children;
    Node(string key) :key(key) {};
};

int main() {
    FAST;
    
    int T;
    cin >> T;
    
    Node* root = new Node("root");
    Node* iter = root;

    while (T--) {
        int N;
        cin >> N;

        iter = root;
        while (N--) {
            string input;
            cin >> input;

            //경로가 존재할 경우
            if (iter->children.find(input) == iter->children.end()) {
                 iter->children[input] = new Node(input);
            }
            
            iter = iter->children[input];
        }
    }
    
    stack<pair<Node*, int>> st;
    for (auto& node : root->children) {
        st.push({ node.second, 0 });
    }

    while (!st.empty()) {
        pair<Node*, int> top = st.top();
        st.pop();

        Node* cur = top.first;
        int depth = top.second;

        for (auto& node : cur->children) {
            st.push({ node.second, depth + 1 });
        }

        for (int i = 0; i < depth; i++) {
            cout << "--";
        }

        cout << cur->key << '\n';
    }
    return 0;
}