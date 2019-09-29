#include<iostream>
#define MAX_LEN 1001
using namespace std;
class Stack{
    private:
        char stack[MAX_LEN];
        int index;
    public:
        char top(void);
        void push(char c);
        char pop(void);
        bool isEmpty(void);
        bool isFull(void);
        Stack(){ index = -1; }; 
};
char Stack::top(void) {return stack[index];}
bool Stack::isEmpty(void) {return index < 0;}
bool Stack::isFull(void) {return index >= MAX_LEN;}
char Stack::pop(void) {return stack[index--];}
void Stack::push(char c){
    index+=1;
    stack[index] = c;
    return;
}

int priority(char c){
    if(c == '+' || c == '-') return 1;
    else if(c == '*' || c == '/') return 2;
    else if(c == '^') return 3;
    else if(c == '(') return 4;
    else return -1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Stack operators;
    char c;
    while(cin >> c){
        if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '(' || c == ')'){
            if(c == '(') operators.push(c);
            else if(c == ')'){
                char ch;
                while((ch = operators.pop()) != '(') cout << ch;
            }
            else if(priority(c) <= priority(operators.top())){
                while(!operators.isEmpty() && priority(operators.top()) >= priority(c) && operators.top() != '(') cout << operators.pop();
                operators.push(c);
            }
            else operators.push(c);
        }else{
            cout << c;
        }
    }
    while(!(operators.isEmpty())) cout << operators.pop();
    return 0;
}
