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
    stack<int> B;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
	}

    for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
        if (A[i] == 0) {
            B.push(temp);
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

    
    int count = B.size();

    if (count >= M) {
        for (int i = 0; i < M; ++i) {
            cout << B.top() << " ";
            B.pop();
        }
    }
    else {
        while (B.empty() == false) {
			cout << B.top() << " ";
			B.pop();
		}

        for (int i = 0; i < M - count; ++i) {
			cout << C[i] << " ";
		}
    }
    
    

    return 0;
}



