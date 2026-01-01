#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

bool prime[100001];

void calc_prime()
{
    fill(prime, prime + 100001, true);
	prime[0] = prime[1] = false;
    for (int i = 2; i <= 100000; i++)
    {
        if (prime[i])
        {
            for (int j = i + i; j <= 100000; j += i)
            {
				prime[j] = false;
            }
        }
    }
    return;
}

bool is_special_number[100001];

void calc_special_number()
{
    fill(is_special_number, is_special_number + 100001, true);

    is_special_number[0] = false;

    for (int i = 1; i <= 100000; i++)
    {
        int target = i;

        int div = 10;
        
        int tail = 1;
        int head = target;
        
        while (head > 0)
        {
            int number = head * tail + 1;

            if (prime[number] == false)
            {
                is_special_number[i] = false;
                break;
            }
            
            tail = target % div;
            head = target / div;
            div *= 10;
        }
    }
    return;
}

int count_special_number[100001];

void calc_special_number_count()
{
    for (int i = 1; i <= 100000; i++)
    {
        if(is_special_number[i])
        {
            count_special_number[i] = count_special_number[i - 1] + 1;
        }
        else
        {
            count_special_number[i] = count_special_number[i - 1];
		}
    }
}

int main() {
    FAST;
    
    calc_prime();
	calc_special_number();
	calc_special_number_count();

    int t; cin >> t;

    while (t--)
    {
        int n; cin >> n;
		cout << count_special_number[n] << '\n';
    }


    return 0;
}