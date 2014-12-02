//
//  main.cpp
//  OJ1020
//
//  Created by irmo on 14/10/20.
//  Copyright (c) 2014年 apple. All rights reserved.
//

#include <iostream>

using namespace std;

class Stack{
private:
    int *stk;
    int top=-1;
    int MAXN;
public:
    Stack(int size){MAXN=size;stk=new int[MAXN];}
    ~Stack(){delete []stk;}
    int push( int x){
        if (top>=MAXN-1)return 1;
        stk[++top]=x;
        return 0;
    }
    
    int pop(){
        if (top==-1)return 1;
        top--;
        return 0;
    }
    
    int getTop(){
        if (top==-1) return -1;
        return stk[top];
    }
    int isEmpty() const{return top==-1;}
    int isFull() const {return top==MAXN-1;}
    
};

int main(int argc, const char * argv[]) {
    int n;
    int flag;
    int x=1;
    while (cin>>n){
        flag=1;
        if (x==0) cout<<endl;
        x=0;
        if (n==0)break;
        while (flag){
            int a[n+1];
            cin>>a[0];
            if (a[0]==0) {flag=0;break;}else a[1]=a[0];
            for (int i=2; i<=n; i++) cin>>a[i];
            //main;
            int p=1;
            Stack s(n);
            for (int i=1;i<=n;i++){
                s.push(i);
                while (!s.isEmpty() && s.getTop()==a[p]){
                    s.pop();
                    p++;
                }
            }
            if (p==n+1) cout<<"Yes\n";else cout<<"No\n";
        }
    }
    return 0;
}
