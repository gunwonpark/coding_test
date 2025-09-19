#include <bits/stdc++.h>

#define FAST ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long

using namespace std;

int n;
vector<vector<int>> save;
vector<vector<int>> pre;

vector<int> add_vec(vector<int>& a, vector<int>& b)
{
	vector<int> result(101, 0);
    for(int i = 0; i < 100; i++)
    {
        int value = a[i] + b[i] + result[i];
		result[i + 1] += value / 10;
        result[i] = value % 10;
	}

    return result;
}

string real_value_to_string(vector<int>& a)
{
    string result = "";
    for (int i = 100; i >= 0; i--)
    {
        if (a[i] != 0)
        {
            for (int j = i; j >= 0; j--)
            {
                result += to_string(a[j]);
            }
            break;
		}
    }
    return result;
}

string add_string(string& a, string& b)
{
    string result = "";
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result += (sum % 10) + '0';
        carry = sum / 10;
    }

    reverse(result.begin(), result.end());
    return result;
}

struct Node
{
    int num;
    vector<int> values;
    vector<int> real_values;
    string str_value;
    string current_value;

	Node(int num, vector<int> values) : num(num), values(values), real_values(101, 0), str_value("0"), current_value("0") {}
	Node() : num(0), values(vector<int>(52, 0)), real_values(101, 0), str_value("0"), current_value("0") {}

    void make_real_value()
    {
        for (int i = 0; i < 51; i++)
        {
            if (values[i] != 0)
            {
                for (int j = 0; j < values[i]; j++)
                {
                    real_values = add_vec(real_values, pre[i]);
                }
            }
        }

		vector<int> temp = real_values;

        for(int i = 0; i < num - 1; i++)
        {
            real_values = add_vec(real_values, temp);
		}

		current_value = real_value_to_string(real_values);
		real_values = temp;

        if (num == 0)
        {
            current_value = "0";
        }

        if (num == 35)
        {
            str_value = "0";
            return;
        }


        for (int i = 0; i < 35 - num - 1; i++)
        {
            real_values = add_vec(real_values, temp);
        }

		str_value = real_value_to_string(real_values);
    }

};

int convert_method(char a)
{
    if (a >= '0' && a <= '9')
    {
        return a - '0';
    }

    return a - 'A' + 10;
}

char to_36_char(int n) {
    if (n >= 0 && n <= 9) {
        return (char)(n + '0');
    }
    else {
        return (char)(n - 10 + 'A');
    }
}

// 매우 큰 10진수 문자열을 36진법으로 변환하는 함수
string convert_ten_to_36(string num_str) {
    if (num_str == "0") {
        return "0";
    }

    string result = "";

    while (!num_str.empty()) {
        long long remainder = 0;
        string next_num_str = "";
        
        for (char digit : num_str) {
            remainder = remainder * 10 + (digit - '0');
            if (remainder / 36 > 0 || !next_num_str.empty()) {
                next_num_str += to_string(remainder / 36);
            }
            remainder %= 36;
        }


        result += to_36_char(remainder);
        num_str = next_num_str;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    FAST;

    cin >> n;
    vector<string> arr(n);

    save.resize(37, vector<int>(52, 0));
    pre.resize(51, vector<int>(101, 0));

    pre[0][0] = 1;
    pre[1][0] = 6;
    pre[1][1] = 3;

    for (int i = 2; i < 51; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            pre[i] = add_vec(pre[i], pre[i - 1]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        for(int j = 0; j < arr[i].size(); j++)
        {
            int num = convert_method(arr[i][j]);
			int index = arr[i].size() - j - 1;
            save[num][index]++;

            if(save[num][index] == 36)
            {
                save[num][index] = 0;
                save[num][index + 1]++;
			}
		}
    }

    vector<Node> nodes;
    for(int i = 0; i < 37; i++)
    {
        nodes.push_back(Node(i, save[i]));
		nodes[i].make_real_value();
	}

    sort(nodes.begin(), nodes.end(), [](Node a, Node b) {
        if (a.str_value == b.str_value)
        {
            return a.num < b.num;
        }
         
        if (a.str_value.size() == b.str_value.size())
        {
            return a.str_value > b.str_value;
        }
        return a.str_value.size() > b.str_value.size();
    });


    string current_total = "";

    for (int i = 0; i < 37; i++)
    {
		current_total = add_string(current_total, nodes[i].current_value);
    }

    int k; cin >> k;

    for (int i = 0; i < k; i++)
    {
        string str_value = nodes[i].str_value;
        if (str_value != "0")
        {
			current_total = add_string(current_total, str_value);
        }
    }
      
	cout << convert_ten_to_36(current_total) << "\n";

    return 0;
}
