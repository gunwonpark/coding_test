#include <iostream>
#include <vector>
#include <queue>
#include <stack>


#define ll long long

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);    

    int N;

    cin >> N;

    vector<int> A; // stack : 1 or queue : 0
    deque<int> B;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
	}

    for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
        if (A[i] == 0) {
            B.push_back(temp);
        }
    }


    int M;

    cin >> M;

    vector<int> C;

    for(int i = 0; i < M; i++) {
        int temp;
		cin >> temp;
		C.push_back(temp);
    }

    
    for(int i : C) {
        B.push_front(i);
        cout << B.back() << " ";
        B.pop_back();
	}
    
    

    return 0;
}



