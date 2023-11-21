# CUB3D - A 3D Raycaster Game set up

CUB3D is C graphics project using the 42 library MINILIBX and is similar to the famous WOLFENSTEIN3D. It is about creating a 3D maze in the first player perspective using the raycasting method.

## Idea of the project

The idea is to create a 3D map from a given file. The map is made of 1s and 0s for walls and floor respectively. Secondly the file stores data about the floor and ceiling color, as well as the texture paths for the walls and the original player location and POV.

## Raycasting 

Raycasting is used to find the walls from the view of the players position. This happens by sending rays in a 60° range around the player to the end of the map. By going in small incrementations, seperated in x and y direction, the walls will be found with the right distance to the player. With those distances the specific wall, floor and ceiling heights can be calculated for the 3D look.

[Source](https://github.com/vinibiavatti1/RayCastingTutorial)
[Source](https://en.wikipedia.org/wiki/Ray_casting)


## 3D Game result

At the end stage, the player can move through any given maze with ASWD and change view with left and right arrows. 

![Screenshot 2023-11-16 at 10 42 07](https://github.com/emmameinert/cub3d/assets/110816436/2540f912-35f0-456a-a6c5-6f128a8d6066)
