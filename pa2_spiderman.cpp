#include<iostream>
#include<stack>
#include<math.h>
#define MAX_LEN 1000001
using namespace std;
class Stack{
    private:
        long stack[MAX_LEN];
        int index;
    public:
        Stack(){ index = -1; }; 
        long top(void) {return stack[index];}
        void push(long l){
            index+=1;
            stack[index] = l;
            return;
        }
        long pop(void) {return stack[index--];}
        bool isEmpty(void) {return index < 0;}
        bool isFull(void) {return index >= MAX_LEN;}
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int s;
    cin >> s;
    
    long t;
    while(s--)
    {
       cin>>t;
       long a[t], b[t]={0};
        
       Stack s;
       for(int i=0;i<t;i++)
       {
           cin>>a[i];
       }
       for(int i=0;i<t;i++)
       {
           while(!s.isEmpty() && a[s.top()] <= a[i])
           {
               s.pop();
           }
           if(s.isEmpty())
           {
               b[i] = 1+i;
           }
           else
           {
               b[i]=abs(i-s.top());
           }
           s.push(i);
       }
       for(int i=0; i<t; i++)
            cout << b[i] << "\n";
    }
}
