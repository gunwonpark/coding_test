#include <bits/stdc++.h>
#include <unordered_map>
#define FAST std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
typedef long long ll;

using namespace std;

unordered_map<string, char> L_PATTERN = {
    {"0001101", '0'}, {"0011001", '1'}, {"0010011", '2'}, {"0111101", '3'}, {"0100011", '4'},
    {"0110001", '5'}, {"0101111", '6'}, {"0111011", '7'}, {"0110111", '8'}, {"0001011", '9'}
};
unordered_map<string, char> R_PATTERN = {
    {"1110010", '0'}, {"1100110", '1'}, {"1101100", '2'}, {"1000010", '3'}, {"1011100", '4'},
    {"1001110", '5'}, {"1010000", '6'}, {"1000100", '7'}, {"1001000", '8'}, {"1110100", '9'}
};

vector<string> lpatterns = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011" };
vector<string> rpatterns = { "1110010", "1100110", "1101100", "1000010", "1011100", "1001110", "1010000", "1000100", "1001000", "1110100" };

vector<vector<string>> l_patterns;
vector<vector<string>> r_patterns;

vector<string> lanswers;
vector<string> ranswers;

vector<string> decoder(string s, bool reverse = false) {
    vector<string> result;
    for (int i = 0; i < 10; i++) {
        string pattern = lpatterns[i];
		if (reverse) {
			pattern = rpatterns[i];
		}
        bool can = true;
        for (int j = 0; j < 7; j++) {
            if (s[j] != '?' && s[j] != pattern[j]) {
				can = false;
				break;
            }
        }
        if (can) {
            result.push_back(pattern);
        }
    }
	return result;
}

bool check_sum(string s) {
    int sum = 0;
    for (int i = 0; i < 11; i++) {
        if (i % 2 == 0) {
            sum += (s[i] - '0') * 3;
        }
        else {
            sum += s[i] - '0';
        }
    }

    sum %= 10;

    if (sum != 0) {
        sum = (10 - sum);
    }

    return sum == (s[11] - '0');
}


string value = "";

void ltravel(int index, vector<vector<string>> patterns) {
    if (lanswers.size() == 9) {
        return;
    }

	if (index == 12) {
		if (check_sum(value)) {
            lanswers.push_back(value);
		}
		return;
	}

    char key;
	for (int i = 0; i < patterns[index].size(); i++) {
		if (index < 6) {
			key = L_PATTERN[patterns[index][i]];
		}
		else {
			key = R_PATTERN[patterns[index][i]];
		}
		value += key;
		ltravel(index + 1, patterns);
		value.pop_back();
	}
}

void rtravel(int index, vector<vector<string>> patterns) {
    if (ranswers.size() == 9) {
        return;
    }

    if (index == 12) {
        if (check_sum(value)) {
            ranswers.push_back(value);
        }
        return;
    }

    char key;
    for (int i = 0; i < patterns[index].size(); i++) {
        if (index < 6) {
            key = L_PATTERN[patterns[index][i]];
        }
        else {
            key = R_PATTERN[patterns[index][i]];
        }
        value += key;
        rtravel(index + 1, patterns);
        value.pop_back();
    }
}



int main() {
    FAST;
    int T; cin >> T;

    while (T--) {
        // 서로 보수형태기 때문에 어처피 하나만 둘중 하나만 된다
        string s50, s45; cin >> s50 >> s45;

		if (s50.substr(0, 3) != "101" || s45.substr(42, 3) != "101") {
			cout << 0 << '\n';
			continue;
		}

        if (s50.substr(45, 5) != "01010") {
			cout << 0 << '\n';
			continue;
        }

        l_patterns.clear();
		r_patterns.clear();
        lanswers.clear();
		ranswers.clear();

        l_patterns.resize(12);
		r_patterns.resize(12);

        bool can_l = true;
        bool can_r = true;

        for (int i = 0; i < 6; i++) {
            string l = s50.substr(3 + i * 7, 7);
			
            vector<string> l_temp = decoder(l);
			
			if (l_temp.size() == 0) {
				can_l = false;
				break;
			}

			l_patterns[i] = l_temp;
        }

        for (int i = 0; i < 6; i++) {
            string r = s45.substr(i * 7, 7);

            vector<string> r_temp = decoder(r, true);

			if (r_temp.size() == 0) {
				can_l = false;
				break;
			}

			l_patterns[i + 6] = r_temp;
        }

        for (int i = 5; i >= 0; i--) {
            string l = s45.substr(i * 7, 7);
			reverse(l.begin(), l.end());

			vector<string> l_temp = decoder(l);

            if (l_temp.size() == 0) {
                can_r = false;
                break;
            }

			r_patterns[5 - i] = l_temp;
        }

        for (int i = 5; i >= 0; i--) {
            string r = s50.substr(3 + i * 7, 7);
            reverse(r.begin(), r.end());

            vector<string> r_temp = decoder(r, true);

            if (r_temp.size() == 0) {
                can_r = false;
                break;
            }

            r_patterns[5 - i + 6] = r_temp;
        }

		if (!can_l && !can_r) {
			cout << 0 << '\n';
			continue;
		}

        if (can_l) {
            ltravel(0, l_patterns);
		}

		if (can_r) {
			rtravel(0, r_patterns);
        }
		
		set<string> answers(lanswers.begin(), lanswers.end());

        for (int i = 0; i < ranswers.size(); i++) {
            answers.insert(ranswers[i]);
        }

        if (answers.size() == 0) {
            cout << 0 << '\n';
        }
        else {
			int n = answers.size();

            if (n > 9) n = 9;

            cout << n;
			cout << '\n';

            if (n == 9) {
                n--;
            }

			for (auto it = answers.begin(); n > 0; it++, n--) {
				cout << *it << '\n';
			}
        }
    }
    
    return 0;
}