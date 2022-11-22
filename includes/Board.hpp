#ifndef BOARD_HPP
# define BOARD_HPP

// # include "../includes/magic_tiles.hpp"

# include "../includes/SheetMusic.hpp"
class Tile;
// class SheetMusic;

class Board
{
    private:
        std::map<int, Tile *>     _tiles;
        SheetMusic              _sheet_music;
        Board();
    public:
        Board(const SheetMusic &);
        Board(const Board &);
        ~Board();

        Board   &operator=(const Board &);

        void    init_tiles();
        void    draw_sheet_line();
        void    draw_board(int);
        void    draw_current_board(int);
        void    draw_sheet_line(std::string &, int &);
};

# include "../includes/Tile.hpp"

#endif  /*BOARD_HPP*/