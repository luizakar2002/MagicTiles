#ifndef SHEETMUSIC_HPP
# define SHEETMUSIC_HPP

# include "../includes/magic_tiles.hpp"

class SheetMusic
{
    private:
        std::string                 _path_to_input_file;
        std::vector<std::string>    _sheet_content;
        int                         _sheet_length;
    public:
        SheetMusic();
        SheetMusic(char *);
        SheetMusic(const SheetMusic &);
        ~SheetMusic();

        SheetMusic &operator=(const SheetMusic &);
        
        //GETTERS
        std::string                 get_path_to_input_file() const;
        std::vector<std::string>    get_sheet_content() const;
        int                         get_sheet_length() const;

        void                        fill_sheet_content();
        std::vector<std::string>    parse_sheet_line(std::string &);
};

#endif  /*SHEETMUSIC_HPP*/