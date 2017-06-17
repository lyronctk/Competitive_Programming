/*
Lyron Co Ting Keh
Crescenta Valley High School 
Senior Division
*/

#include <iostream>
#include <string>
using namespace std;

string str;
char getNext(bool left){
  char c;
  if(left){
    c = str[0];
    str.erase(0, 1);
  }
  else{
    c = str[str.length()-1];
    str.erase(str.length()-1);
  }
  return c;
}
void checkZero(){
  for(char c : str)
    if(c != '0')
      return;
  cout << "0";
}
int main(){
   string curNum, lastNum;
   bool left;
   for(int i=0; i<5; i++){
     cin >> str;
     checkZero();
     left = true; 
     lastNum = "0";
     while(str.length()){
       curNum = getNext(left);
       while(str.length() && stoi(curNum) <= stoi(lastNum))
         curNum += getNext(left);
       if(stoi(curNum) <= stoi(lastNum))
         break;
       cout << stoi(curNum) << " ";
       lastNum = curNum;
       left = !left;
     }
     cout << endl;
   }
}