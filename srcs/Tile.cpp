# include "../includes/Tile.hpp"

Tile::Tile(int index)
{
    _index_on_board = index;
    _tile_height = BOARD_HEIGHT;
    _tile_width = 8;
    init_tile_win();
}

Tile::Tile(const Tile &copy)
{
    *this = copy;
}

Tile::~Tile()
{
}

Tile &Tile::operator=(const Tile &other)
{
    _index_on_board = other._index_on_board;
    _tile_win = other._tile_win;
    _tile_width = other._tile_width;
    _tile_height = other._tile_height;
    _tile_win_start_x = other._tile_win_start_x;
    return *this;
}

void    Tile::init_tile_win()
{
    _tile_win_start_x = _index_on_board * Tile::_tile_width;

    _tile_win = newwin(_tile_height, _tile_width, 0, _tile_win_start_x);
    refresh();
    box(_tile_win, 0, 0);
}

void    Tile::draw_part_of_line(std::string &part, int &sheet_line_idx)
{
    mvwprintw(_tile_win, sheet_line_idx % BOARD_HEIGHT, 0, part.c_str());
    wrefresh(_tile_win);
}