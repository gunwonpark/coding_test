#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

char dic[26]{};
int reverse_dic[4]{ 'A', 'C', 'G', 'T' };

struct Trie
{
	Trie* next[4]{};
	int cnt = 0;

	void insert(const char* c)
	{
		if (*c == 0)
		{
			return;
		}

		int index = *c - '0';

		if (next[index] == nullptr)
		{
			next[index] = new Trie();
			cnt++;
		}

		next[index]->insert(c + 1);
	}
};


int main() {
	FAST;

	dic['A' - 'A'] = 0;
	dic['C' - 'A'] = 1;
	dic['G' - 'A'] = 2;
	dic['T' - 'A'] = 3;



	string s; cin >> s;
	for (char& c : s)
	{
		c = dic[c - 'A'] + '0';
	}
	
	Trie* root = new Trie();
	for (int i = 0; i < s.size(); i++)
	{
		root->insert(s.substr(i).c_str());
	}

	queue<pair<Trie*, string>> q;
	q.push({ root, "" });

	while (!q.empty())
	{
		pair<Trie*,string> cur = q.front();
		q.pop();

		if (cur.first->cnt == 4)
		{
			q.push({ cur.first->next[0], cur.second + '0' });
			q.push({ cur.first->next[1], cur.second + '1' });
			q.push({ cur.first->next[2], cur.second + '2' });
			q.push({ cur.first->next[3], cur.second + '3' });
		}
		else
		{
			for(int i = 0; i < 4; i++)
			{
				if (cur.first->next[i] == nullptr)
				{
					for(char& c : cur.second)
					{
						cout << (char)(reverse_dic[c - '0']);
					}

					cout << (char)(reverse_dic[i]);
					return 0;
				}
			}
		}
	}

	return 0;
}
