# include "../includes/Board.hpp"

Board::Board(const SheetMusic &music)
{
    init_tiles();
    _sheet_music = music;
}

Board::Board(const Board &copy)
{
    *this = copy;
}

Board::~Board()
{
    // delete _tiles
}

Board   &Board::operator=(const Board &other)
{
    _tiles = other._tiles;
    return *this;
}

void    Board::init_tiles()
{
    for (int i = 1; i <= N_OF_TILES; ++i)
        _tiles.insert(std::pair<int, Tile *>(i, new Tile(i)));
}

void    Board::draw_sheet_line(std::string &sheet_line, int &sheet_line_idx)
{
    std::vector<std::string> substr_for_each_tile = _sheet_music.parse_sheet_line(sheet_line);

    for (int idx = 1; idx <= N_OF_TILES; ++idx)
        _tiles[idx]->draw_part_of_line(substr_for_each_tile[idx-1], sheet_line_idx);
}

void    Board::draw_current_board(int sheet_line_idx)
{
    for(int i = sheet_line_idx; i < (sheet_line_idx + BOARD_HEIGHT); ++i)
    {
        draw_sheet_line(_sheet_music.get_sheet_content().at(i), i);
    }
}

void    Board::draw_board(int speed)
{
    for(int sheet_line_idx = 0; sheet_line_idx < _sheet_music.get_sheet_length() - BOARD_HEIGHT; ++sheet_line_idx)
    {
        sleep(speed);
        draw_current_board(sheet_line_idx);
    }
}