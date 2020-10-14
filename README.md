# piggy

Cheung Hoi Ki (3035705075)
Lo Kai Yeung (3035708962)

## 1. Game Description

A total of 99 cards from the number ‘1’ to ‘99’. Each card will not randomly be assigned piggy. A total of 4 players including 1 real player and 3 computer players. 


### PREPARATION
The player chooses his name first prior to the start of the game. Shuffle the cards and deal 8 cards to the 4 players. Do not show the cards to the others.


Make four rows
Four cards from the remaining deck would be shown. Each of these cards is the first card in a row, in which there may not be more than 5 cards, including this first one. 

Each player then has to choose one card from his hand. The player whose card is the lowest number will need to add his card to one of the four rows. The player with the second-lowest number will be the next one and so on until all cards played this round has been added to the rows. Cards are placed next to each other in a row. The game continues in this way round by round, until all 8 cards in each player have been played.


Rule No. 1: “Ascending order”
The number of the card that is placed next to each card must be larger than the current last card in the row.


Rule No. 2: “Small difference”
A card must always be placed to the row with the smallest difference between the current last card and the new card.


Rule No. 3: “Full row”
A row with 5 cards is full. If Rule No. 2 would put the fifth card in such a row, the player who played that card must take all four cards of the full row. His card then becomes the first in the new row.


Rule 4: “Lowest card”
If one player plays a card with a number that is lower than the last current card in each row. He needs to pick up all the cards of a row and he has a choice to pick which row. His card will become the first card of the new row.


End of the game
The game will be over when all players played all 8 cards. The final scores will be calculated by the number of piggies each player has. The one with the lowest piggies will lose the game.


## 2. Game Features

Generation of random game sets or events
To make sure that each game will have a different game set, first of all, each card(1-99) will be assigned a random number of piggies(1-5). During the preparation, the cards will be randomly shuffled and distributed to players. Bots also play by picking cards randomly according to the chosen difficulty. 
 
Data structures for storing game status
We use parallel arrays to store card information and the number of piggies of each card. We also create 4 independent arrays to store cards in hand of each player and 4 arrays to store cards on each row. Integer variables are used to store how many piggies a player has. String variables are used to store the name of the player.
 
Dynamic memory management
After each round, data stored in arrays will be updated constantly by using pointers, including existing cards in a row,  how many cards are left in hand for each player. 
 
We will use pointer to store the cards the player has lost.
 
File input/output (e.g., for loading/saving game status)
As variables in a program are volatile, we need a file to save unfinished game status. Once the program is run, we will generate a file to store game information. When the player inputs a command to leave the game halfway, the program will store the necessary data into the file such as existing cards in a row,  how many cards are left in hand for each player. When the program is loaded next time, it will check if there is an existing file to resume a game. Data in the file will be retrieved and put into the variables again.
 
Program codes in multiple files
We will split our program into mainly three parts, preparation(shuffling and distributing card), the main algorithm of the game and file input and output process. By doing so, the main algorithm can be reused to write other programs but with different features customized. 
