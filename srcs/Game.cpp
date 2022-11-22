# include "../includes/Game.hpp"

Game::Game(const SheetMusic &music)
{
    initscr();
    _board = new Board(_sheet_music);
    _sheet_music = music;
    _speed = 1;
}

Game::Game(const Game &copy)
{
    *this = copy;
}

Game::~Game()
{
    delete _board;
}

Game    &Game::operator=(const Game &other)
{
    _board = new Board(*(other._board));
    _sheet_music = other._sheet_music;
    _speed = other._speed;
    return *this;
}

Board   *Game::get_board() const
{
    return _board;
}

SheetMusic  Game::get_sheet_music() const
{
    return _sheet_music;
}

int     Game::get_speed() const
{
    return _speed;
}

void    Game::start_game()
{
    _board->draw_board(_speed);
    getch();
    endwin();
}