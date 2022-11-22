# include "../includes/SheetMusic.hpp"

SheetMusic::SheetMusic()
{
    _path_to_input_file = "./notes/music1.txt";
    _sheet_length = 0;
    fill_sheet_content();
}

SheetMusic::SheetMusic(char *path)
{
    _path_to_input_file = std::string(path);
    _sheet_length = 0;
    fill_sheet_content();
}

SheetMusic::SheetMusic(const SheetMusic &copy)
{
    *this = copy;
}

SheetMusic::~SheetMusic()
{
}

SheetMusic  &SheetMusic::operator=(const SheetMusic &other)
{
    _path_to_input_file = other._path_to_input_file;
    return *this;
}

void    SheetMusic::fill_sheet_content()
{
    FILE* fp = fopen(_path_to_input_file.c_str(), "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    char* line = NULL;
    size_t len = 0;

    while ((getline(&line, &len, fp)) != -1)
    {
        _sheet_content.push_back(line);
        ++_sheet_length;
    }
    fclose(fp);
    if (line)
        free(line);
}

std::string     SheetMusic::get_path_to_input_file() const
{
    return _path_to_input_file;
}

std::vector<std::string>     SheetMusic::get_sheet_content() const
{
    return _sheet_content;
}

int     SheetMusic::get_sheet_length() const
{
    return _sheet_length;
}

std::vector<std::string>  SheetMusic::parse_sheet_line(std::string &line)
{
    std::vector<std::string>    substr_for_each_tile = split(line, '_');
    return substr_for_each_tile;
}