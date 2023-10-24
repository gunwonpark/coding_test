#include <iostream>
using namespace std;
#include <vector>

//스스로가 너무 한심한 코드임을 알고 있다
//추후 수정하도록 하겠다
enum Command{
    Command_Push = 1,
    Command_Pop,
    Command_Count,
    Command_IsEmpty,
    Command_Top,
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //명령의 수
    int n;
    cin >> n; 
    //명령
    int command;
    vector<int> stack;
    for(int i = 0; i < n; i++){
        cin >> command;
        //todo
        int num;
        switch(command)
        {
            case static_cast<int>(Command_Push):
                cin >> num;
                stack.push_back(num);
                break;
            case static_cast<int>(Command_Pop):
                if(stack.empty()){
                    cout << -1 << "\n";
                }else{
                    cout << stack.back() << "\n";
                    stack.pop_back();
                }
                break;
            case static_cast<int>(Command_Count):
                cout << stack.size() << "\n";
                break;
            case static_cast<int>(Command_IsEmpty):
                cout << stack.empty() << "\n";
                break;
            case static_cast<int>(Command_Top):
                if(stack.empty()){
                    cout << -1 << "\n";
                }else{
                    cout << stack.back() << "\n";
                }
                break;
        }
    }
    return 0;
}
/*
void Push(){}
void Pop(){}
void Count(){}
void IsEmpty(){}
void Top(){}
*/
/*
1 X: 정수 X를 스택에 넣는다. (1 ≤ X ≤ 100,000)
2: 스택에 정수가 있다면 맨 위의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
3: 스택에 들어있는 정수의 개수를 출력한다.
4: 스택이 비어있으면 1, 아니면 0을 출력한다.
5: 스택에 정수가 있다면 맨 위의 정수를 출력한다. 없다면 -1을 대신 출력한다.
*/
