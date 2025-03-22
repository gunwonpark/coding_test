#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int N, Q;
vector<vector<int>> children;
vector<bool> expanded; // false: folded, true: expanded

// DFS를 이용해 현재 보이는 목록을 구성 (1번 폴더는 표시하지 않음)
void dfs(int cur, vector<int>& view) {
    view.push_back(cur);
    if (expanded[cur]) {
        for (int child : children[cur]) {
            dfs(child, view);
        }
    }
}

vector<int> getView() {
    vector<int> view;
    // 1번 폴더의 자식들을 순서대로 추가
    for (int child : children[1]) {
        dfs(child, view);
    }
    return view;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    children.resize(N + 1);
    expanded.assign(N + 1, false);

    // 폴더의 계층 구조 입력 (1번부터 N번)
    for (int i = 1; i <= N; i++) {
        int cnt;
        cin >> cnt;
        children[i].resize(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> children[i][j];
        }
    }

    // 초기 목록: 1번 폴더의 하위 폴더 목록
    vector<int> view = getView();
    // 커서는 목록의 첫번째 항목을 가리킴
    int cursor = 0;

    string cmd;
    for (int i = 0; i < Q; i++) {
        cin >> cmd;
        if (cmd == "move") {
            int k;
            cin >> k;
            // 이동: 범위를 벗어나지 않도록 clamp
            int newCursor = cursor + k;
            if (newCursor < 0) newCursor = 0;
            if (newCursor >= (int)view.size()) newCursor = view.size() - 1;
            cursor = newCursor;
            cout << view[cursor] << "\n";
        }
        else if (cmd == "toggle") {
            // 커서가 가리키는 폴더 토글
            int folder = view[cursor];
            expanded[folder] = !expanded[folder];
            // 목록 재구성
            view = getView();
            // 토글한 폴더의 새 위치 찾기
            for (int j = 0; j < (int)view.size(); j++) {
                if (view[j] == folder) {
                    cursor = j;
                    break;
                }
            }
        }
    }
    return 0;
}