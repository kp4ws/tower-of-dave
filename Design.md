# Design Overview


## Table of Contents
- Design Overview
- Player
- Basic Movement
- Jump
- Move 
- Abilities
- Interactions
- Interactables
- David Wessels
- World
- Tower Boundary
- Random Platform Spawner
- One Way Platform
- Platform Socket
- Level-traversing Door
- Shop  
Physical Design
- Overview
- Structure of Directories
- C++ Classes

Contact Info: hengstler2005@gmail.com

![image2](https://github.com/kp4ws/project-jump/assets/58745400/7b71a24e-04b5-49e9-bfaa-5e7e028ba360)

---

## Player:
Player is all systems inside of, and directly interacting with the player. This is broken down further into Basic Movement, Abilities, Widgets, and Interactions.

![image5](https://github.com/kp4ws/project-jump/assets/58745400/bac0901e-03d1-48cf-bf0b-2402f832d652)

### Basic Movement:
Basic Movement is responsible for basic movement components of the player such as move, sprite flipping,  and jump. It works with the interact system, to make sure that the player can't do any basic movement while interacting.

Jump: Jump is a blueprint implemented function and charges while the player holds space, then launches in the air with a force determined by how long the player held the button. The jump mechanic interacts with the move to make sure the player cannot move while charging the jump, as well as the interactables to make sure the player can't jump while interacting. 
The force goes up to a max of 1000 units, which is held in the variable JumpStrength

Move: This is blueprint implemented and moves the player left or right. It works with the interaction system to make sure the player can't move while in the shop or interacting, as well as the jump system to be able to move while in the air jumping.
### Abilities:
Abilities will interact with the player class, and the shop in interactables, and the widgets to display that the player has unlocked an ability. The shop will set bools for whether a player has an ability or not. When the bool is true, the player will be able to use the ability with a set keybind. What the abilities will be is undetermined but this is how they will interact.

Jetpack: This is a blueprint implemented ability that can be bought by going into the shop, talking to dave on the left side of the building and purchasing for 200 coins in the shop pop-up. Once it has been purchased, a bool hasJetpack is switched to true and can now be used for climbing in game. It is used by holding down the jump button when you are either in the middle of a jump or falling down. Using the jetpack makes your player float upwards at the same vertical velocity as your jump, and can continue to bring you up as long as you have fuel, which is set as a base of 10, and goes down by 2 for every second it is held down, meaning you can have 5 seconds of continuous fuel before it runs out and you have to buy it again. You should be able to purchase upgrades for your jetpack that increase fuel size or flight speed, to make your tower traversal even easier.

### Widgets:
Widgets are how the UI works in Unreal. Widgets will be added to the player and when they are needed will be switched from/to visible/invisible. This is done to visualise data for the users to make it easier to digest and be aware of game mechanics such as health of the player. This will interact with Interactables to tell when to display what widgets, as well as the abilities to display widgets that let the user know they have unlocked an ability. The HUD object is used to handle logic of widgets.

HUD:
The HUD is a blueprint object that handles all logic of widgets for the player, adding to viewport and updating values and images of the widgets. It adds the UIs to the players viewport, then checks if they have abilities so it can add the UI for those.

Start Screen: When the player opens the game they are shown the main menu screen where they have two options, play the game or exit out. Exiting out closes the game but play game brings you into our main level where you can begin to play the game. The map is spawned in, money and abilities are loaded, and music begins playing. 

UI: Once you clear out of the start menu, your health and current coins are shown on the bottom left of your screen, as well as any abilities you have so far are shown on the bottom right. These variables are tracked and changed as the game goes on, updating when conditions change (take damage, collect a coin, purchase or use an ability).
### Interactions:
Interactions handling in the player include two functions which are Interact and InteractCheck. 
Interact check is called every tick and checks if an object directly behind the player is castable to an Interactables class, if it is it updates the InteractHitResult on the line trace channel in unreal to the object.
Interact is called when the player clicks the interact button E, it calls the function OnInteract that is in the Interactables object and that object executes its function.

### Save Game
The save game module is implemented in 3 different functions, loadGame, gameSave, and clearGame, they modify and store the wallet value of the player, as well as if they have any specific abilities unlocked.  gameSave stores these into a saveGame blueprint object, which is saved to the hard drive of the user to keep progress between plays, loadGame calls the object and sets the value of the player to these, and clearGame resets all values of both player and the SaveGame object
## Interactables: 

Interactables is a class of objects that each object we want the player to interact with inherits from. This class has one function which is OnInteract, since this function is inherited, every interactable has it and when it is called it calls the native function of whatever object to execute their function.
The Interactables heavily interact with the World to place these objects in the world and procedurally generate them, as well as the player who initiates calls for these objects. Widgets are also used for some of these objects. Currently there are 2 interactables implemented DaveWessel and shopLevelDoor.

![image4](https://github.com/kp4ws/project-jump/assets/58745400/6abb650b-7e7a-46f4-9a2d-20f16c26fba5)

### DaveWessel: 
When Dave Wessel is interacted with, the players camera is changed to Dave's camera and the player can no longer move. It also pulls up the Widget for the shop. When the player presses the interact button again their camera switches back to the default for the player camera and it is able to move again. Dave works with the player using its widgets, and interact, as well as stopping it from moving.

### shopLevelDoor:
ShopLevelDoor is an object that will move players from one location to another. This will utilise the interact feature from the player interacting with the door, at which point the player will be “teleported” to the shop level or back to the main level, depending on where they are. Walking through this door loads an entire new map and spawns the player right in front of the opposite door in the new level.

## World:
World is the physical level that the player will be moving around inside during the game experience. Players will spawn into an initial level that will contain different objects: Tower Boundary, Random Platform Spawner, One Way Platform, Level Traversing Door, and Shop.

![image3](https://github.com/kp4ws/project-jump/assets/58745400/2e16d80a-be37-49d3-bc53-b183526148f1)

### Tower Boundary:
The tower boundary is a class that takes in max X and Y values and generates the borders of our tower by spawning in blocks repeatedly, starting one where the next one finishes, up to a defined Max value. This border prevents the player from walking through and creates the level of our game.

### Random Platform Spawner:
	The random platform spawner is another blueprint class in our world folder that takes in the following variables to create a random level upon compile time: 
Max Blocks: The maximum amount of blocks that can spawn per floor
Chance of spawning: The chance of a block spawning in a specific position on each floor, can be altered to make the game easier or harder. Increasing this number too much will cause the platforms to spawn heavily on the right hand side as that is where the iteration starts.
This system randomly generates a new level with every compile and placement and so the player will never play the exact same level twice, which increases the difficulty and strategy of our game. This random platform spawner blueprint also takes into consideration the current level counter, tracked by the one way platform, and decreases by 3% the chances of a platform spawning at each level, in theory, making the game only progressable at very high level counts with abilities, this way the player will need to play through the game a few times to acquire enough money to unlock abilities, bringing them to new heights and new environments.

### One Way Platform:
	The one way platform class was implemented early on in our project as a basic floor/roof of each level. Once the player jumps and reaches the bottom of this platform, a function recognizes this overlap and allows the player sprite to pass through until it is clear above the platform. Once it does this and the overlap ends, the player cannot pass back through. This platform has a feature where it sends out a signal whenever a player passes through it which is used for queuing the generation of the next level. This way the map will continue to build infinitely as the player jumps higher and higher, incrementing a variable called level count for every instance that is created. This level count variable is used to alter the continuing levels to increase the difficulty by spawning less platforms, and more traps, as well as increasing the amount of coins that are spawned. Once this signal is received, A new random level, tower boundary, traps, coins, background panel, and a one way platform are all spawned on top of the current level, allowing for a seamless jump into newly created levels.

### Platform Sockets
    An invisbile box that provides the ability to spawn entities on platforms.
    In order to spawn items such as spikes, health potions, and coins on our randomly generated platforms, we need to have a socket be attached to each platform who's location can be accesed and used to replace the invisible socket box with the entity that we want to spawn in there. So within the random platform generator, there will be a function that gets the locations of every single one of these sockets and using a random chance, spawns in one of these entities or doesnt spawn anything at all. This implementation increases the uniqueness of every level and ensures that the odds of the same level spawning are extremely low, so the player always has to adapt to their surroundings. 
    Specs/Design: This random chance will be set per level, starting with 10% and increasing by 2% with every consecutive level. A tally will also be kept track of so that for every level there is no more than 20 spawnable entities so that the levels are not swarmed with other blocks. There will be 2 sockets per platform, so there is a chance that multiple objects can spawn on the same platform, increasing the difficultyin later levels when the spawn chance is higher, meaning the player could run into a platform that has two spikes on it, making it a risky jump.

### Shop:
The shop will be a location the player can access in order to purchase power ups using currency collected during the game. This shop will be accessed via a interactable door at the base of each tower level. The door will be an interactable object that spawns the player into a specific location within the shop. Once the player walks through the door in the main level that says shop, their scene will switch to the shop where they can talk to dave to purchase abilities if they have enough money.

### Background
In the background there is a ruler that can be seen far behind the tower that shows how high the player has gone up, as well as seeing the height in the UI, this ruler will also be an aesthetic way of showing the player just high up they have gone because they will be able to see how far up the ruler they climb.
There is also going to be a background design that gets recreated at the same time that a new level is generated, so that the background looks flush and continues for as far up as the player climbs.

### Spike Trap
A simple spike trap that subtracts a 4th of the player health if the player bumps into it while they are climbing. Will be random as level difficulty increases.

# Physical Design

We are implementing our project using unreal engine 5, which uses a collaboration between blueprints and C++. There are some features that are much easier to implement using blueprints and some that are much easier using C++ classes so we have decided that using a mixture of both provides the most efficient procedure to completing our game. Blueprints are an unreal specific visual style coding practice, where you can see the actual flow of the code and track how events are performed. These blueprint classes mimic C++ logic and the actions we wish to implement can be written both ways.

- The directories for most of the file structure is inherent to our Unreal Engine 5 project. The directories created for our unreal project are:
    - Config
    - Content
        - ExternalActors
        - ExternalObjects
        - Adventurer-1.5
        - Blueprint
            - Player
            - World 
            - Main Menu
            - Background 
            - Interactables
            - Shop Assets
        - EPMasterMaterials
        - PlayerSprites
        - StarterContent
    - Intermediate
        - Build
        - ShaderAutogen
    - Saved
    - Source  
- The important part of the directories of our concern are contained inside the Blueprints folder and the Source folder.
    - Blueprints folder contains all .uasset files which are Unreal Engine 5’s way of saving our blueprints we create inside the Unreal Engine 5 UI. These are important components to the functioning of our game.
    - In the Source folder we have our C++ implementations inside the Private folder, and our C++ header files inside the Public folder so the classes and Our public classes currently Include MyPlayerClass, Interactables, and DaveWessel.
## MyPlayerClass
The player class has 3 public functions currently. SetCanMove, SetInteractWidgetVisibility, and Interact.

### SetCanMove: Input(bool)
This parameter is used to determine whether the player can move or not based on the input value.

### SetInteractWidgetVisibility: Input(bool)
This parameter changes whether the interact widget is visible or not based on the input value.

### Interact:
Interact is used to call the interact function of an object that is line traced behind the player. There is no input and no output, it simply calls the object's function.
## Interactables
There is only one public function for interactables which is InteractReceived.
### InteractReceived:
This function does not do anything but log to the console that its called. This is simply so that there is a common function within every interactable object for the player to call when they want to interact.
## DaveWessel
Public methods for Dave are only InteractReceived. 
### InteractReceived: 
This is the inherited function from the Interactables class, when the player Interacts with Dave, this function is called and then it calls the native class of OnInteract.
