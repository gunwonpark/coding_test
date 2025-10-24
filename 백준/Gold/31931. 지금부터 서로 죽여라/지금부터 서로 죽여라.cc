#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int main() {
    FAST;

    int q; cin >> q;
    while (q--)
    {
        ll X, Y; cin >> X >> Y;
        ll x_a, x_r, y_a, y_r; cin >> x_a >> x_r >> y_a >> y_r;

        if (x_a >= Y)
        {
            cout << "NARUTO" << '\n';
            continue;
        }

        if (x_a == y_r)
        {
            if (X + x_r <= y_a)
            {
                cout << "SASUKE" << '\n';
            }
            else if (y_a <= x_r)
            {
                cout << "DRAW" << '\n';
            }
            else
            {
                // 나루토가 공격을 처음 했을때도 이기고 나루토가 회복을 처음했을때도 이기면 이길수 있다 아니면 비긴다

                // 공격을 처음 했을경우
                bool attack_first = false;
                ll x_a_count = (Y - x_a) / x_a + ((Y - x_a) % x_a != 0);
                ll y_a_count = X / y_a + (X % y_a != 0);

                if (x_a_count >= y_a_count) attack_first = true;

                // 회복을 처음 했을경우
                bool recover_first = false;
                x_a_count = Y / x_a + (Y % x_a != 0);
                y_a_count = (X + x_r) / y_a + ((X + x_r) % y_a != 0);

                if (x_a_count >= y_a_count) recover_first = true;
                if (attack_first && recover_first)
                {
                    cout << "SASUKE" << '\n';
                }
                else
                {
                    cout << "DRAW" << '\n';
                }
            }
        }
        else if (x_a < y_r)
        {
            if (x_r >= y_a)
            {
                cout << "DRAW" << '\n';
            }
            else
            {
                cout << "SASUKE" << '\n';
            }
        }
        else
        {
            if (x_r > y_a)
            {
                cout << "NARUTO" << '\n';
            }
            else if (x_r == y_a)
            {
                ll x_a_count = Y / x_a + (Y % x_a != 0);
                ll y_a_count = X / y_a + (X % y_a != 0);
                if (x_a_count <= y_a_count)
                {
                    cout << "NARUTO" << '\n';
                }
                else
                {
                    cout << "DRAW" << '\n';
                }
            }
            else
            {
                ll x_a_count = Y / x_a + (Y % x_a != 0);
                ll y_a_count = X / y_a + (X % y_a != 0);
                if (x_a_count <= y_a_count)
                {
                    cout << "NARUTO" << '\n';
                }
                else
                {
                    cout << "SASUKE" << '\n';
                }
            }
        }
    }

    return 0;
}
