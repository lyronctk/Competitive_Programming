#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

char conv[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

string convert(string base10) {
  string cur="", base27="";
  while(base10 != "") {

    string temp10 = "";
    for(int i=0; i<=base10.size(); i++) {
      if(cur != ""){
        int n = stoi(cur);
        if(n >= 27){
          int quo = n/27; int remain = n%27;
          temp10 += to_string(quo); cur = to_string(remain);
        }
        else temp10 += '0';
      }
      if(i != base10.size()) cur += base10[i];
    }

    bool flag=false; base10 = "";
    for(int i=0; i<temp10.size(); i++){
      if(temp10[i] != '0') flag = true;
      if(flag) base10 += temp10[i];
    }
    base27 += (char)('A'+stoi(cur));
    cur = "";
  }

  reverse(base27.begin(), base27.end());
  return base27;
}

int f(int val) {
  return ((33*val % (1 << 20)) + 1);
}

char addChar(char a, char b) {
//  return conv[(a - 'A' + b - 'A') % 27];
  int i;
  if (a == ' ') a = '[';
  for(i=0; i<28; i++) if(conv[i] == b) break;
  for(int j = 0; j<(int)(a-'A'); j++) i = (i+1)%27;
  return conv[i];
}


int pow33[(1 << 19) + 1];
int pow33s[(1 << 19) + 1];
int powx[(1 << 19) + 1];

int main() {
  int n, x;
  string s;
  cin >> n >> x;

  cout << "here" << endl;
  getline(cin, s); getline(cin, s);

  cout << "here" << endl;

  vector<int> c_sum; c_sum.resize(x, 0);
  int prev_val;

  cout << "here" << endl;
//  for (int i = 0; i < x; ++i) {
//    for (int j = 0; j < x; ++j) {
//      prev_val = f(prev_val) % (1 << 20);
//      c_sum[j] += prev_val % (1 << 20);
//    }
//  }
//  for (int i = 0; i < x; ++i) {
//    c_sum[0] += (((((int) {pow(33, i)} % (1 << 20)) * (x - i)) % (1 << 20)) + (i > 0 ? 33 * (int) {pow(x} : 0)) % (1 << 20);
//  }
//  cout << c_sum[0] << " ";
  pow33[0] = 1;
  pow33s[0] = 1;
  powx[0] = 1;
  for (int i = 1; i <= (1 << 19); ++i) {
    pow33[i] = (pow33[i - 1] * 33) % (1 << 20);
    pow33s[i] += pow33[i] % (1 << 20);
    powx[i] = (powx[i - 1] * x) % (1 << 20);
  }
  for (int i = 1; i < x; ++i) {
    c_sum[0] += (pow33[i * i] * i) % (1<< 20);
  }
  for (int i = x; i >= 0; --i) {
    c_sum[0] += (pow33[x - i] * i) % (1 << 20);
  }

  for (int i = 1; i < x; ++i) {
    c_sum[i] = (c_sum[i - 1]*33+x) % (1 << 20);
    cout << c_sum[i] << " ";
  }

  cout << endl;
  cout << "here" << endl;
  for (int i = 0; i < x; ++i) {
    c_sum[i] %= (1 << 20);
  }
  cout << "here" << endl;
  string str = "";
  for (int i = 0; i < x; ++i) {
    str += to_string(c_sum[i]);
  }

  cout << "here" << endl;
  str = convert(str);

  cout << "here" << endl;

  for (int i = 0; i < n; ++i) {
    //cout << "adding " << s[i] << " " << str[i] << ": ";
    cout << addChar(s[i], str[i]);
  }
  cout << endl;
}
