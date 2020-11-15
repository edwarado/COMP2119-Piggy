#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include "cards.h"

using namespace std;

int zeroarrsize8(int arr[], int pos){ //initialize row arrays with 0s
  for (int i=pos;i<8;i++){
    arr[i]=0;
  }
  return true;
}

int returnposofplayercard(int card, int player[]){ 
  //return the position of the targeted card of player
  for (int i=0;i<8;i++){
    if (card == player[i]){
      return i;
    }
  }
  return true;
}

int returnposoflastcardoftherow(int row[]){
  // return the position of last card of the required row
  for (int i=0;i<6;i++){
    if (row[i] == 0){
      return i-1;
    }
  }
  return true;
}

int returnlastcardoftherow(int row[]){
  // return the last card of the required row
  for (int i=0;i<6;i++){
    if (row[i] == 0){
      return row[i-1];
    }
  }
  return true;
}

void printrow(int row[]){
  // print the row with graphics
  int count=0;
  for (int i=0;i<6;i++){ //find the number of cards in the row
    if (row[i] != 0){
      count++;
    }
  }
  for (int j=0;j<count;j++){
    cout << "┌──┐ "; //print the upper part of the cards
  }
  cout << endl;
  for (int j=0;j<count;j++){ //print the card numbers
    if (row[j]<10) cout << "│0" << row[j] <<"│ ";
    else cout << "│" << row[j] <<"│ ";
  }
  cout << endl;
  for (int j=0;j<count;j++){
    cout << "└──┘ "; //print the lower part of the cards
  }
  cout<<endl;
}

void printplayer(int player[]){
  // print the cards in hand of player with graphics
  int count=0;

  for (int i=0;i<8;i++){ //find the number of cards in hand
    if (player[i]!=0){
      count++;
    }
  }

  for (int j=0;j<count;j++){
    cout << "┌──┐ "; //print the upper part of the cards
  }
  cout << endl;
  for (int j=0;j<count;j++){ //print the card numbers
    if (player[j]<10) cout << "│0" << player[j] <<"│ ";
    else cout << "│" << player[j] <<"│ ";
  }
  cout << endl;
  for (int j=0;j<count;j++){ //print the lower part of the cards
    cout << "└──┘ ";
  }
  cout<<endl;
}
