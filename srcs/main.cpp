# include "../includes/magic_tiles.hpp"
# include "../includes/SheetMusic.hpp"
# include "../includes/Game.hpp"

int main(int argc, char **argv)
{
    SheetMusic  sheet_music(argv[1]);
    Game        magic_tiles(sheet_music);

    magic_tiles.start_game();

    return 0;
}