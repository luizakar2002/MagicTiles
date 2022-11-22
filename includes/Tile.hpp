#ifndef TILE_HPP
# define TILE_HPP

# include "../includes/magic_tiles.hpp"

class Tile
{
    private:
        int             _index_on_board;
        WINDOW          *_tile_win;
        int             _tile_width;
        int             _tile_height;
        int             _tile_win_start_x; //start_x is not needed yet
    public:
        Tile();
        Tile(int);
        Tile(const Tile &);
        ~Tile();

        Tile &operator=(const Tile &);

        void    init_tile_win();
        void    draw_part_of_line(std::string &, int&);

};

#endif  /*TILE_HPP*/