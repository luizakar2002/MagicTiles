#ifndef GAME_HPP
# define GAME_HPP

// # include "../includes/magic_tiles.hpp"
# include "../includes/SheetMusic.hpp"

class Board;
// class SheetMusic;

class Game
{
    private:
        // Menu    menu;
        Board       *_board;
        SheetMusic  _sheet_music;
        int         _speed;
        Game();
    public:
        Game(const SheetMusic &);
        Game(const Game &);
        ~Game();

        Game    &operator=(const Game &);
        
        //GETTERS
        Board       *get_board() const;
        SheetMusic  get_sheet_music() const;
        int         get_speed() const;

        void    start_game();

};

# include "../includes/Board.hpp"
#endif  /*GAME_HPP*/