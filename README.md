# Tower Of Dave
A procedurally generated, 2.5D tower climbing platformer inspired by Jump King and Jetpack Joyride.
![image](https://github.com/kp4ws/tower-of-dave/assets/58745400/f51b3159-25c3-4bbf-9e1b-0a6b6703b5b3)

## Gameplay Reveal
https://www.youtube.com/watch?v=_9NgzkpGpyE

## Backstory
This project was developed for our CSCI265 (Software Engineering) course.

## Development Team
- Chris Lawrence
- Kent Pawson
- Kieran Paauwe
- Sooriya Narendran
- Connor Hengstler
- Mohamad Sheikho Al Jasem

## Technologies
- Unreal Engine

## Notable Features
- 3D shop with different upgrades for your character
- Procedurally generated platforms and objects
- AI radio generated from real voice lines

## Version Control Workflow
- Master branch is used for production ready code
- Staging branch is used for testing code. After tests have passed, code is merged into the master branch
- Dev branch is used for development changes. Once changes have been made, dev is merged into staging for testing

## Player
- Charged jump mechanic
- 2D with rigged animations
- Basic movement
- UI / HUD
![image18](https://github.com/kp4ws/tower-of-dave/assets/58745400/02bc0eb5-668a-456a-9035-520ee7dd98f5)

## Music
- Made using RVC
- Trained on phonetically balanced harvard sentences
- Played through jukebox  
![image](https://github.com/kp4ws/tower-of-dave/assets/58745400/d16fb5b0-b42a-4c2b-9019-b4fe0d4c25e1)  
![image](https://github.com/kp4ws/tower-of-dave/assets/58745400/0d0e0c23-9557-4e97-883b-1301d9ec2102)


## Death Mechanic
- **Fall Damage:** Occurs if the fall height is greater or equal to the max jump height.
- **Regular Damage:** Occurs from spikes or turrets.
- **Player Death:** Occurs when player's health reaches 0. The player explodes and level restarts.
![image16](https://github.com/kp4ws/tower-of-dave/assets/58745400/d72d396e-e84e-49c4-b036-de3add155406)


## World Generation
- Procedurally generated world
- Platform sockets allowing for generation of items on top of the platforms
- Spawnable one-way platforms at every milestone  
![image20](https://github.com/kp4ws/tower-of-dave/assets/58745400/2b350043-9466-42a1-bb6f-7994a1b2bea6)  


## Abilities
#### Jetpack Ability
- Main powerup of the game
- Can be bought in the shop
- Allows you to fly until fuel runs out   
![image14](https://github.com/kp4ws/tower-of-dave/assets/58745400/278f2a2d-5f95-4c21-a8b5-d487625a12f0)  

#### Health Potion Ability
- Secondary powerup of the game
- Can be purchased in the shop
- Spawns a health potion in front of the player  
![image19](https://github.com/kp4ws/tower-of-dave/assets/58745400/30d8d5c4-f82a-42a1-b57d-58ce14ce1641)  

## General Testing
- Implemented as a table of detailed user scripts
![image12](https://github.com/kp4ws/tower-of-dave/assets/58745400/11d643ec-7659-43a1-a98f-2a4a48d9ce52)
