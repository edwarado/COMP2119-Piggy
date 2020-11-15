#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <bits/stdc++.h>
#include <fstream>
#include <cstdlib>
#include "cards.h"
#include <sstream>

using namespace std;

//declare dynamic arrays
int *row1 = new int [6];
int *row2 = new int [6];
int *row3 = new int [6];
int *row4 = new int [6];

int *player1 = new int [8];
int *player2 = new int [8];
int *player3 = new int [8];
int *player4 = new int [8];

int player1input=0;
int player2card,player3card,player4card;

int playercardsize = 7;

int playerpiggies[4] = {0,0,0,0};

string playername[4];

int smallestdifference(int player[]){ //this function find the smallest difference between the last card of each row and bot's card
  int min = 0;
  int diff = 1000;
  int tf = 0;
  for (int i=0;i<8;i++){
    if (player[i]>returnlastcardoftherow(row1) or player[i]>returnlastcardoftherow(row2) or player[i]>returnlastcardoftherow(row3) or player[i]>returnlastcardoftherow(row4)){
      tf = 1;
    }
    if (player[i]>returnlastcardoftherow(row1) and player[i]-returnlastcardoftherow(row1)<diff){
      diff = player[i]-returnlastcardoftherow(row1);
      min = player[i];
    }
    if (player[i]>returnlastcardoftherow(row2) and player[i]-returnlastcardoftherow(row2)<diff){
      diff = player[i]-returnlastcardoftherow(row2);
      min = player[i];
    }
    if (player[i]>returnlastcardoftherow(row3) and player[i]-returnlastcardoftherow(row3)<diff){
      diff = player[i]-returnlastcardoftherow(row3);
      min = player[i];
    }
    if (player[i]>returnlastcardoftherow(row4) and player[i]-returnlastcardoftherow(row4)<diff){
      diff = player[i]-returnlastcardoftherow(row4);
      min = player[i];
    }
  }
  if (tf == 0){
    return player[0];
  }
  return min;
}

int leastsumrowno(){//it returns the sum of card of the row
  int sum1=0, sum2=0, sum3=0, sum4=0;
  for (int i=0;i<6;i++){
    sum1 = sum1 + row1[i];
    sum2 = sum2 + row2[i];
    sum3 = sum3 + row3[i];
    sum4 = sum4 + row4[i];
  }
  int sum[4] = {sum1, sum2, sum3, sum4};
  sort(sum, sum+4);
  if (sum1 == sum[0]) return 1;
  if (sum2 == sum[0]) return 2;
  if (sum3 == sum[0]) return 3;
  if (sum4 == sum[0]) return 4;
  return true;
}

void putcards(int card){ //it puts the card to one of the rows
  int thisroundplayer;
  int diff = 1000;
  int row = 0;

  if (card==player1input) thisroundplayer=0; //find out who is playing in this round
  else if (card==player2card) thisroundplayer=1;
  else if (card==player3card) thisroundplayer=2;
  else if (card==player4card) thisroundplayer=3;

  if (card < returnlastcardoftherow(row1) and card < returnlastcardoftherow(row2) and card < returnlastcardoftherow(row3) and card < returnlastcardoftherow(row4)){
    // if the card is smaller than the last current card in each row, player picks up a row
    if (leastsumrowno() == 1){
      for (int i=0;i<6;i++){
        playerpiggies[thisroundplayer]+=row1[i];
      }
      row1[0] = card;
      for (int i=1;i<6;i++){
        row1[i] = 0;
      }
      cout <<  playername[thisroundplayer] << " picks up row 1's cards" << endl;
      cout << playername[thisroundplayer] << " now has " << playerpiggies[thisroundplayer] << " piggies" << endl;
    }
    if (leastsumrowno() == 2){
      for (int i=0;i<6;i++){
        playerpiggies[thisroundplayer]+=row2[i];
      }
      row2[0]=card;
      for (int i=1;i<6;i++){
        row2[i]=0;
      }
      cout << playername[thisroundplayer] << " picks up row 2's cards" << endl;
      cout << playername[thisroundplayer] << " now has " << playerpiggies[thisroundplayer] << " piggies" << endl;
    }
    if (leastsumrowno() == 3){
      for (int i=0;i<6;i++){
        playerpiggies[thisroundplayer]+=row3[i];
      }
      row3[0]=card;
      for (int i=1;i<6;i++){
        row3[i]=0;
      }
      cout << playername[thisroundplayer] << " picks up row 3's cards" << endl;
      cout << playername[thisroundplayer] << " now has " << playerpiggies[thisroundplayer] << " piggies" << endl;
    }
    if (leastsumrowno() == 4){
      for (int i=0;i<6;i++){
        playerpiggies[thisroundplayer]+=row4[i];
      }
      row4[0]=card;
      for (int i=1;i<6;i++){
        row4[i]=0;
      }
      cout << playername[thisroundplayer] << " picks up row 4's cards" << endl;
      cout << playername[thisroundplayer] << " now has " << playerpiggies[thisroundplayer] << " piggies" << endl;
    }
  }
  //decide which row to put the card
  if (card > returnlastcardoftherow(row1) and card-returnlastcardoftherow(row1)<diff){
    diff = card-returnlastcardoftherow(row1);
    row=1;
  }
  if (card > returnlastcardoftherow(row2) and card-returnlastcardoftherow(row2)<diff){
    diff = card-returnlastcardoftherow(row2);
    row=2;
  }
  if (card > returnlastcardoftherow(row3) and card-returnlastcardoftherow(row3)<diff){
    diff = card-returnlastcardoftherow(row3);
    row=3;
  }
  if (card > returnlastcardoftherow(row4) and card-returnlastcardoftherow(row4)<diff){
    diff = card-returnlastcardoftherow(row4);
    row=4;
  }
  if (row == 1){
    row1[returnposoflastcardoftherow(row1)+1]=card;
  }
  if (row == 2){
    row2[returnposoflastcardoftherow(row2)+1]=card;
  }
  if (row == 3){
    row3[returnposoflastcardoftherow(row3)+1]=card;
  }
  if (row == 4){
    row4[returnposoflastcardoftherow(row4)+1]=card;
  }
  // if the row is full, player picks up the row
  if (row1[4] != 0){
    cout << playername[thisroundplayer] << " picks up row 1's cards" << endl;
    for (int i=0;i<4;i++){
      playerpiggies[thisroundplayer]+=row1[i];
    }
    cout << playername[thisroundplayer] << " now has " << playerpiggies[thisroundplayer] << " piggies" << endl;
    row1[0]=row1[4];
    for (int i=1;i<6;i++){
      row1[i]=0;
    }
  }
  if (row2[4] != 0){
    cout << playername[thisroundplayer] << " picks up row 2's cards" << endl;
    for (int i=0;i<4;i++){
      playerpiggies[thisroundplayer]+=row2[i];
    }
    cout << playername[thisroundplayer] << " now has " << playerpiggies[thisroundplayer] << " piggies" << endl;
    row2[0]=row2[4];
    for (int i=1;i<6;i++){
      row2[i]=0;
    }
  }
  if (row3[4] != 0){
    cout << playername[thisroundplayer] << " picks up row 3's cards" << endl;
    for (int i=0;i<4;i++){
      playerpiggies[thisroundplayer]+=row3[i];
    }
    cout << playername[thisroundplayer] << " now has " << playerpiggies[thisroundplayer] << " piggies" << endl;
    row3[0]=row3[4];
    for (int i=1;i<6;i++){
      row3[i]=0;
    }
  }
  if (row4[4] != 0){
    cout << playername[thisroundplayer] << " picks up row 4's cards" << endl;
    for (int i=0;i<4;i++){
      playerpiggies[thisroundplayer]+=row4[i];
    }
    cout << playername[thisroundplayer] << " now has " << playerpiggies[thisroundplayer] << " piggies" << endl;
    row4[0]=row4[4];
    for (int i=1;i<6;i++){
      row4[i]=0;
    }
  }
}


void shiftcard(int card, int arr[]){ //it shifts some elements in the player card array to the left
  for (int i=returnposofplayercard(card, arr);i<7;i++){
    arr[i] = arr[i+1];
  }
  for(int j=playercardsize;j<8;j++){
    arr[j] = 0;
  }
}

int main() {
  string line, line1;
  int linenum = 0;
  int numofrow=0;
  int temforrandomcard=0;
  int cards[100]={};
  
  ofstream fout;
  fout.open("records.txt", ios::app); // it opens the file file "records.txt" to write into result of the gamplay

  if (fout.fail()){
    cout<<"Error in file opening"<<endl;
    exit(1);
  }

  ifstream fin;
  ifstream fin1;
  fin.open("records.txt");
  fin1.open("records.txt");

  if (fin.fail()){ // print out error if the file cannot be opened
    cout<<"Error in file opening"<<endl;
    exit(1);
  }

  if (fin1.fail()){
    cout<<"Error in file opening"<<endl;
    exit(1);
  }
  
  for (int i = 0;i < 6;i++){
  row1[i]=0;
  row2[i]=0;
  row3[i]=0;
  row4[i]=0;
  }

  for (int j=0;j<8;j++){
    player1[j]=0;
    player2[j]=0;
    player3[j]=0;
    player4[j]=0;
  }
  
  for(int i=0;i<100;i++){
    cards[i]=i+1;
  }

  srand(time(NULL)); //it randoms the cards' number for each round
  for (int j=0;j<5000;j++){ // shuffle the cards by swapping the positons of two cards 5000 times
    int x=rand()%99;
    int y=rand()%99;
    temforrandomcard = cards[x];
    cards[x]=cards[y];
    cards[y]=temforrandomcard;
  }

  for (int i=0;i<8;i++){ //initialise the card of the player
    player1[i]=cards[i+10];
  }

  for (int i=0;i<8;i++){
    player2[i]=cards[i+20];
  }

  for (int i=0;i<8;i++){
    player3[i]=cards[i+30];
  }

  for (int i=0;i<8;i++){
    player4[i]=cards[i+40];
  }

  row1[0]=cards[60];
  row2[0]=cards[61];
  row3[0]=cards[62];
  row4[0]=cards[63];

  cout<<" W         W   EEEEEE       L               CCCC      OOOOOOOOO      MM    M M     EEEEE           TTTTTTTTT   OOOOOOOOO"<<endl;
  cout<<" W        W    E            L              C    C    OO       OO     M M   M M     E                  T       OO       OO"<<endl;
  cout<<" W        W    E            L             C          OO       OO     M  M M  M     E                  T       OO       OO"<<endl;
  cout<<" W   W   W     EEEEEE       L             C          OO       OO     M   M   M     EEEEE              T       OO       OO"<<endl;
  cout<<" W   WW  W     E            L             C          OO       OO     M       M     E                  T       OO       OO"<<endl;
  cout<<" W  W  W W     E             L             C    C    OO       OO     M       M     E                  T       OO       OO"<<endl;
  cout<<" WWW    WW     EEEEEEE       LLLLLLLLL      CCCC        OOOOO        M       M     EEEEEE             T         OOOOOOO"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"PPPPPP     IIIII       GGGGG         GGGGG        Y      Y"<<endl;
  cout<<"P    P       I        G     G        G     G      Y      Y"<<endl;
  cout<<"P    P       I       G              G              Y    Y"<<endl;
  cout<<"PPPPPP       I       G    G G       G    G G        Y   Y "<<endl;
  cout<<"P            I       G      G       G      G         YY"<<endl;
  cout<<"P            I        G     G        G     G         YY"<<endl;
  cout<<"P          IIIII        GGGG           GGGG          YY"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<"Hope You Like Playing The Game!!!"<<endl;
  cout<<endl;
  cout<<"What is your name? ";
  cin >> playername[0];
  cout << "Let's start, " << playername[0] << "!" <<endl;
  playername[1]="Player 2";
  playername[2]="Player 3";
  playername[3]="Player 4";
  cout<<endl;
  
  //retreive the last round number from the textfile
  string str; 
    while(getline(fin1, line1)){ // get the line of "records.txt"
    numofrow = numofrow - 1;
    if (numofrow == 1){ 
      linenum = line1.find("P");
    }
  }
  
  str =  line1.substr(0, linenum-1);
  string str1 = str;
  
  stringstream sstream(str1); //convert the string to integer
  int roundnum;
  sstream >> roundnum; 
  cout << "This is round " << roundnum+1 << "." <<endl;
  cout << endl;
  
  //sort the cards in hand of all players
  sort(player1, player1+8);
  sort(player2, player2+8);
  sort(player3, player3+8);
  sort(player4, player4+8);


  for (int k=0;k<8;k++){ //loop to play 8 rounds
    cout << "Row 1: " << endl; //print rows
    printrow(row1);
    cout << "Row 2: "<< endl;
    printrow(row2);
    cout << "Row 3: "<< endl;
    printrow(row3);
    cout << "Row 4: "<< endl;
    printrow(row4);

    cout<<endl;
    cout << "Your cards in hand: " << endl;
    printplayer(player1);
    
    cout<<endl;
    cout<<"What card do you wanna play?? ";
 
    bool ra=false;
    while (!ra){ //if the player enter the wrong card, it asks the player to enter again until the player enters the correct card
      cin>>player1input;
      for (int i=0;i<8;i++){
        if (player1input==player1[i]) ra = true;
      }
      if (!ra) cout << "You dont have this card! Please try again" << endl;
      cin.clear();
      cin.ignore(80,'\n');
    }
    
    //Bots choose the card to put by the function smallestdifference()
    player2card = smallestdifference(player2);
    player3card = smallestdifference(player3);
    player4card = smallestdifference(player4);

   
    shiftcard(player1input, player1);
    shiftcard(player2card, player2);
    shiftcard(player3card, player3);
    shiftcard(player4card, player4);

    playercardsize = playercardsize - 1;


    int playerorder[4] = {player1input, player2card, player3card, player4card};

    sort(playerorder, playerorder+4); //sort cards in ascending order

    cout<<"Player 2 -> "<<player2card<<endl;
    cout<<"Player 3 -> "<<player3card<<endl;
    cout<<"Player 4 -> "<<player4card<<endl;
    cout<<"The play order -> "<<playerorder[0]<<" - > "<<playerorder[1]<<" - > "<<playerorder[2]<<" - > "<<playerorder[3]<<endl;


    putcards(playerorder[0]); //put cards to the rows according to the play order
    putcards(playerorder[1]);
    putcards(playerorder[2]);
    putcards(playerorder[3]);

    cout<<endl; 
  }
  
  //after 8 rounds, print the results(num of piggies)
  cout << endl;
  cout << "Results:" << endl;
  for (int counter=0; counter<4; counter++){
    cout << playername[counter] << " piggies = " << playerpiggies[counter] << endl;
  }

  int minn = playerpiggies[0];
  
  for (int i=1; i<4;i++){ //find the player who has the least number of piggies
    if (playerpiggies[i]<minn){
      minn=playerpiggies[i];
      }
  }

  for (int i=0; i<4;i++){
    if (playerpiggies[i]==minn) cout << playername[i] << ", ";
  }
  cout << "win(s) the game !" << endl;

  while (getline(fin, line)){
    numofrow++;
  }

  roundnum++;
  fout<<endl;
  fout<<roundnum;
  fout <<" Player ";
  for (int i=0; i<4;i++){
    if (playerpiggies[i]==minn) fout << i+1 << ", ";
  }
  fout << "win(s) the game !";

  fout.close();
  fin.close();
  fin1.close();

  delete [] row1;  //delete the row to free up memory
  delete [] row2;
  delete [] row3;
  delete [] row4;
  delete [] player1;
  delete [] player2;
  delete [] player3;
  delete [] player4;
}
