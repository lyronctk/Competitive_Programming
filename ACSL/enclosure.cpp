#include <stack>
#include <iostream>
using namespace std;

const char ENCS[] = {'(', ')', '[', ']', '{', '}'};
bool present[6];
char getMissing(string s) {
    for(int i=0; i<6; i++) present[i] = false;
    for(char c : s) for(int i=0; i<6; i++) if(ENCS[i] == c) present[i] = true;
    for(int i=0; i<6; i+=2) {
        if(present[i] && !present[i+1]) return ENCS[i+1];
        else if(!present[i] && present[i+1]) return ENCS[i];
    }
    return ENCS[0];
}

// 1=open enclosure | 2=close enclosure | 3=operator | 4=number
int symType(char c) {
    if(c == '(' || c == '[' || c == '{') return 1;
    if(c == ')' || c == ']' || c == '}') return 2;
    if(c == '+' || c == '-' || c == '*' || c == '/') return 3;
    return 4;
}

bool complement(char open, char close) {
    for(int i=0; i<6; i+=2) 
        if(open == ENCS[i] && close == ENCS[i+1]) 
            return true;
    return false;
}

bool validExpression(string s) {
    for(int i=1; i<s.size()-1; i++) {
        if((symType(s[i]) == 1 || symType(s[i]) == 2) &&
           (symType(s[i-1]) == 4 && symType(s[i+1]) == 4)) return false;
        if(symType(s[i]) == 1 && symType(s[i+1]) == 3) return false;
        if(symType(s[i]) == 2 && symType(s[i-1]) == 3) return false;
    }

    int numCtr = 0;
    stack<pair<char, int> > st;
    for(int i=0; i<s.size(); i++) {
        if(symType(s[i]) == 1) st.push({s[i], numCtr});
        else if(symType(s[i]) == 2) {
            if(st.empty() || !complement(st.top().first, s[i]) || 
               st.top().second > numCtr-2)
                return false;
            st.pop();
        }
        else if(symType(s[i]) == 4 && (i == s.size()-1 || symType(s[i+1]) != 4))
            numCtr++;
    }
    return st.empty();
}

int main() {
    freopen("in.txt", "r", stdin);

    for(int i=0; i<5; i++) {
        string s; cin >> s;
        bool firstFlag=false;
        char m = getMissing(s);
        for(int j=0; j<=s.size(); j++) 
            if(validExpression(s.substr(0, j)+m+s.substr(j, s.size()-j))) {
                if(!firstFlag) {printf("%d", j+1); firstFlag=true;}
                else printf(", %d", j+1);
            }
        printf("\n");
    }
    return 0;
}