# PIGGY
 
 
Cheung Hoi Ki (3035705075) <br/>
Lo Kai Yeung (3035708962)
 
 
 
## 1. Game Description
 
A total of 99 cards from the number of piggies 1 to 99. A total of 4 players including 1 real player and 3 bots. 
 
 
### Preparation
 
The player will choose the name first. The cards would be shuffled and distribute 8 cards to all players. The cards would not be shown to other players.
 
 
### Gameplay
 
Each player has to choose one card from his hand. The player’s card with the lowest number will need to place his card to one of the four rows. The player with the second-lowest number will be the next one to be placed next to one rows until all cards played from each player has been added to the rows. Cards are placed next to each other in a row. The game continues until all 8 cards from each player have been played so there will be 8 rounds in total.
 
 
### Rule 1: Ascending order
 
The number of the card that is placed next to each card in the row must be larger than the current last card in the row.
 
 
### Rule  2: the smallest difference
 
A card must be put to the row with the smallest difference between the current last card and the new card.
 
### Rule  3: Full row
 
A row with 5 cards is full. If Rule No. 2 would put the fifth card in such a row, the player who played that card must take all four cards of the full row and place those cards in the player’s lost zone. His card then becomes the first in the new row.
 
 
### Rule 4: the smallest card
 
If one player plays a card with a number that is smaller than the last current card in each row. That player needs to pick up all the cards of a row and the player has a choice to pick which row. The player’s card will become the first card of the new row.
 
 
### End of the game
 
The game will be over when all players played all 8 cards. The final scores will be calculated by the number of piggies each player has. The one with the lowest piggies will win the game.



## 2. Game Features

### Generation of random game sets or events
To make sure that each game will have a different game set, During the preparation, the cards will be shuffled and randomly distributed to the players and the initial rows.
 
### Data structures for storing game status
We use arrays to store card information. We also create 4 independent arrays to store cards in the hand of each player and 4 arrays to store cards on each row. An array with 4 slots are used to store the number of piggies players have. String variables are used to store the name of the player.


### Dynamic memory management
Cards in hand and cards on each row would be stored as dynamic arrays.
 
 
### File input/output (e.g., for loading/saving game status)
Once the program is run, we will generate a file to store game information. When a game has ended, we write the game result into the textfile. When the program is loaded next time, it will check if there is an existing file of game history. Data in the file will be retrieved and printed out.
 
 
### Program codes in multiple files
We will split our program into mainly two parts, the main algorithm of the game and cards functions(e.g. print cards with graphics, return positions of cards). By doing so, the main algorithm can be reused to write other programs but with different features customized. 

