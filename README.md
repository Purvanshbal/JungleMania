
# JungleMania
This project is an attempt to represent an action game using cinder. The player gives input using the arrow keys to move the player on the screen. Passing each level displays a new level until the final level is reached and won. Along the way, the player can collect coins and powerups to increase their score and health respectively. The game also includes simulation of enemies that reduce the health of the player and can be defeated by jumping on them.

## Game Description
The game starts at level 1 on the exit door. The player can see multiple platforms with coins, powerups, and enemies on them and a door identical to the start door. In order to finish the level the player needs to reach the other door. The player might choose to do this directly or collect coins on the way.  In the current implementation of the game, the player needs to finish three levels to win the game. A reduction in the health below the minimum health level or falling below the start door will result in player losing the game.

## Code Description
The game runs using the app class in cinder. The game logic is placed under the game engine class, which holds three variables: the current level, the current player, and the current layout. The layout object in turn is a container object that holds various vectors of objects such as enemies, coins, and powerups, all of which extend one common class called Entity. All the logic that operates on individual entity objects is encapsulated in the entity class, and all logic handling user input and game updation is encapsulated in the game engine.


## Dependencies
This project was created using C++ 11 and relies on a widely used library in C++ called Cinder. Cinder is a free and open source library for professional-quality creative coding in C++ that is used to generate graphical simulations. The project also uses CMake for supporting the graphical simulation and the Catch2 library for testing.


## Installation

### Cinder
Download the cinder zip folder relevant to your OS and unzip the file to form a Cinder folder. Follow Cinder installtion guidelines on this page for better guidance: https://courses.grainger.illinois.edu/cs126/sp2021/notes/cinder-installation-notes/. 

### Cloning the Repo
After successfully installing cinder, clone this repo under a newly made my-projects folder and run the simulation using any IDE that supports C++11 and Cinder<img width="1097" alt="Screen Shot 2021-05-04 at 11 30 48 PM" src="https://user-images.githubusercontent.com/69343344/117097277-ccbe6f80-ad30-11eb-9577-73f4b8a0442e.png">
