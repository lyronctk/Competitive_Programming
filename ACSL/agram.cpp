#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
using namespace std;

struct card{
   char suit;
   int rank;
};
card opponent, cards[5];

char ranks[13] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
int getRankValue(char c){
   for(int i=0; i<13; i++)
      if(ranks[i]==c) return i;
   return -1;
}

char suits[4] = {'C', 'D', 'H', 'S'};
int getSuitValue(char c){
   for(int i=0; i<4; i++)
      if(suits[i]==c) return i;
   return -1;
}

card getSameSuit(){
   card higher, lowest;
   higher.suit = 'L';
   lowest.suit = 'L';
   for(int i=0; i<5; i++)
      if(cards[i].suit == opponent.suit){
         if(cards[i].rank>opponent.rank && (higher.suit=='L' || cards[i].rank<higher.rank)){
            higher = {cards[i].suit, cards[i].rank};
         }
         else if(lowest.suit=='L' || cards[i].rank<lowest.rank){
            lowest = {cards[i].suit, cards[i].rank};
         }
      }
   if(higher.suit != 'L') return higher;
   return lowest;
}

card getLowest(){
   card output = {cards[0].suit, cards[0].rank};
   for(int i=1; i<5; i++){
      if(cards[i].rank<output.rank)
         output = {cards[i].suit, cards[i].rank};
      else if(cards[i].rank==output.rank && getSuitValue(cards[i].suit)<getSuitValue(output.suit))
         output = {cards[i].suit, cards[i].rank};
   }
   return output;
}

int main(){
   card pick;
   char curRank, curSuit;
   for(int i=0; i<5; i++){
      scanf(" %c%c", &curRank, &curSuit);
      opponent = {curSuit, getRankValue(curRank)};
      for(int j=0; j<5; j++){
         scanf(" , %c%c", &curRank, &curSuit);
         cards[j] = {curSuit, getRankValue(curRank)};
      }
      pick = getSameSuit();
      if(pick.suit != 'L'){
         printf("%c%c\n", ranks[pick.rank], pick.suit);
         continue;
      }
      pick = getLowest();
      printf("%c%c\n", ranks[pick.rank], pick.suit);
   }
}