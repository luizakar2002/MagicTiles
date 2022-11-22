# Magic Tiles       [NOT READY YET]

Magic Tiles is a music piano game. It is written in C++ and is displayed in terminal with the help of <ncurses.h> library.

## Installation
You need to install ncurses and make.

```bash
sudo apt-get install libncurses5-dev
sudo apt-get install make
```

## Usage
Run these commands in terminal.
```bash
make
```
Run the executable file with/without arguments.
```bash
./magic_tiles
```
```bash
./magic_tiles <path_to_sheet_music_file>
```

## Class Hierarchy
SheetMusic: parses the input
Game:       manages user data and the Board
Board:      controls outputting current board according to SheetMusic
Tile:       responsible for working with a quarter of the Board

## TODO
1. Add multithreading for every Tile.
2. Add Menu.
3. Add User data control.
4. Improve the design.
