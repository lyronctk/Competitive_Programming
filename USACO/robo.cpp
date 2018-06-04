//#include <cstdio>
#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    int N;
    cin >> N;
    
    stack<int> s;
    string cur;
    int counter=1;
    for(int i=0; i<N; i++){
        cin >> cur;
        if(cur == "ADD"){
//            cout << "added " << counter << endl;
            s.push(counter);
            counter++;
        }
        else{
//            cout << "popped " << s.top() << endl;
            s.pop();
        }
    }
//    cout << "SiZE IS " << s.size() << endl;
    int size = s.size();
    int output[1000010];
    for(int i=size-1; i>=0; i--){
        output[i] = s.top();
        s.pop();
    }
    cout << size << endl;
    for(int i=0; i<size; i++)
        cout << output[i] << endl;
}