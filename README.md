# Wolf3d
# Get started
## Launch
First, use:
```git clone https://github.com/lojesu/wolf3d.git; cd wolf3d; make```

Then:
```./wolf3d maps/tutorial```

To play with a precise map use
```./wolf3d <map path>```
## Play
In game, you can use:
- <kbd>W</kbd><kbd>A</kbd><kbd>S</kbd><kbd>D</kbd> ----- allow move forward/left/down/right
- <kbd>▲</kbd><kbd>◄</kbd><kbd>▼</kbd><kbd>►</kbd> ----- move the camera
- <kbd>R</kbd> ------------- return to spawn
- <kbd>tab</kbd> ----------- switch mini-map mode
- <kbd>M</kbd> ------------- open/close map
- <kbd>8</kbd><kbd>4</kbd><kbd>5</kbd><kbd>6</kbd>------ move the map (numeric keypad)
- <kbd>esc</kbd>------------ quit the game

|color|map creator id|description|
|:-:|:-:|:-:|
|![#c8c8c8](https://placehold.it/15/c8c8c8/000000?text=+)|0| floor|
|![#ff0044](https://placehold.it/15/ff0044/000000?text=+)|1| wall|
|![#ff5050](https://placehold.it/15/ff5050/000000?text=+)|2| secret wall|
|![#6600ff](https://placehold.it/15/6600ff/000000?text=+)|3| button breaking secret wall|
|![#c8c8c8](https://placehold.it/15/c8c8c8/000000?text=+)|4| secret floor|
|![#ff0066](https://placehold.it/15/ff0066/000000?text=+)|5| button creating wall in secret floor|
|![#00ccff](https://placehold.it/15/00ccff/000000?text=+)|6| return to spawn|
|![#9933ff](https://placehold.it/15/9933ff/000000?text=+)|7| button unlocking the end|
|![#66ff33](https://placehold.it/15/66ff33/000000?text=+)|8| goal|
|![#ffff00](https://placehold.it/15/ffff00/000000?text=+)|9| spawn|
|![#800000](https://placehold.it/15/800000/000000?text=+)|R| right speedwalk|
|![#993333](https://placehold.it/15/993333/000000?text=+)|L| left speedwalk|
|![#996633](https://placehold.it/15/996633/000000?text=+)|D| down speedwalk|
|![#663300](https://placehold.it/15/663300/000000?text=+)|U| up speedwalk|
|![#e55555](https://placehold.it/15/e55555/000000?text=+)|r| right cannon|
|![#ee8888](https://placehold.it/15/ee8888/000000?text=+)|l| left cannon|
|![#eebb88](https://placehold.it/15/eebb88/000000?text=+)|d| down cannon|
|![#bb8855](https://placehold.it/15/bb8855/000000?text=+)|u| up cannon|
|![#f9c8a7](https://placehold.it/15/f9c8a7/000000?text=+)|s| stop canon tile|
## Create map
### This section is for mappers:

You have to create your map in a file with some containts:
- she must be rectangular
- she must be surrounded by wall `1`
- she must own a __SINGLE__ spawn `9`

You can create a random maze if you go in maps directory and use:

``` python3 maze.py [lenght] [height] > [name_of_your_map]```

An example of maze map will look like this:

![#https://raw.githubusercontent.com/lojesu/wolf3d/master/screenshot/map2.png](https://raw.githubusercontent.com/lojesu/wolf3d/master/screenshot/map2.png)

#### Specials tips
- If you don't put a *goal*, your player canot end, and will have to exit his self with esc.
- You can pace 2 differents button, one for enable goal, the other for breaking all secret wall
- If you don't place end button, your goal will be automatically unlocked
- Speedwalk are locking your movement. So on, if you put a speedwalk in front of a wall, the player will be stuck (he still can use reset `R`)
- If the player reset, all your buttons who have been actived will still be actived

## Textures
![#https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/brown.bmp](https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/brown.bmp)
![#https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/green.bmp](https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/green.bmp)
![#https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/yellow.bmp](https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/yellow.bmp)
![#https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/magenta.bmp](https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/magenta.bmp)
![#https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/purple.bmp](https://raw.githubusercontent.com/lojesu/wolf3d/master/textures/purple.bmp)

## Are you still reading ?
If you are reading this, then :
![#https://raw.githubusercontent.com/lojesu/wolf3d/master/screenshot/bravo_sky.png](https://raw.githubusercontent.com/lojesu/wolf3d/master/screenshot/bravo_sky.png)

## Contributors
- lojesu
- glegendr

