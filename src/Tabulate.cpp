#include <iostream>
#include <algorithm>
#include "../include/Tabulate.h"


/**
 * @brief Construct a new Tabulate::Tabulate object. default border_mode is set to 0
 */
Tabulate::Tabulate()
{
    this->m_border_mode = border_mode::double_grid;
}


/**
 * @brief Destroy the Tabulate:: Tabulate object
 * 
 */
Tabulate::~Tabulate()
{
}


/**
 * @brief Construct a new Tabulate:: Tabulate object. default border_mode is set to 0
 * 
 * @param headers the table header(first row)
 * @param content the table content(without the first row)
 */
Tabulate::Tabulate(const std::vector<std::wstring> &headers, const std::vector<std::vector<std::wstring>> &content)
{
    this->m_border_mode = border_mode::double_grid;
    this->m_headers = headers;
    this->m_content = content;
}


/**
 * @brief Construct a new Tabulate:: Tabulate object.
 * 
 * @param headers the table header(first row)
 * @param content the table content(without the first row)
 * @param border_mode border mode for table subdivision representation.
 */
Tabulate::Tabulate(const std::vector<std::wstring> &headers, const std::vector<std::vector<std::wstring>> &content, int border_mode)
{
    this->m_headers = headers;
    this->m_content = content;
    this->m_border_mode = border_mode;
}


/**
 * @brief Construct a new Tabulate object
 * @details This Constructor take an initialization_list wich must be an iterable(list, vector, array, ...) of w_string. 
 * The headers are the first values of iterable according to <col_nb> the rest are considered as content.  
 * 
 * @param col_nb number of colums the table will contain
 * @param line_nb number of lines the table will contain
 * @param border_mode border mode for table subdivision representation.
 * @param content the next content value(global, including header : from row=0|col=0 to row=0|col=next according to col_nb and row_nb)
 */
Tabulate::Tabulate(int col_nb, int line_nb, int border_mode, std::initializer_list<const std::wstring> content)
{       
    int i = 0, j = 0;
    bool is_init = true;
    std::vector<std::wstring>tmp_vec;
    for(const auto &cell_value : content)
    {
        if (i < col_nb)
        {
            this->m_headers.push_back(cell_value);
            ++i;
        }
        else
        {
            if (!is_init) 
                j = 0;

            if (j < col_nb)
            {
                tmp_vec.push_back(cell_value);
                ++j;
            }
            if (tmp_vec.size() == col_nb)
            {
                this->m_content.push_back(tmp_vec);
                tmp_vec.clear();
                is_init = false;
            }
        }
    }
    this->m_border_mode = border_mode;
}


/**
 * @brief get Global content of the table (headers + content)
 * 
 * @return std::vector<std::vector<std::wstring>> 
 */
std::vector<std::vector<std::wstring>> Tabulate::get_global_content() const noexcept
{
    std::vector<std::vector<std::wstring>> global_content;
    global_content.push_back(this->m_headers);
    std::copy(this->m_content.begin(), this->m_content.end(), std::back_inserter<std::vector<std::vector<std::wstring>>>(global_content));
    return global_content;
}


/**
 * @brief method for getting max size for each column
 * 
 * @param col_id identifier of the column(index)
 * @return int 
 */
int Tabulate::get_col_size(int col_id)
{
    int max_cell_size = this->m_headers[col_id].size();

    for(int i = 0; i < this->m_content.size(); ++i)
        if(max_cell_size <  this->m_content[i][col_id].size())
            max_cell_size = this->m_content[i][col_id].size();  

    return max_cell_size;
}   

/**
 * @brief set border method
 * 
 * @param border_mode 
 */
void Tabulate::set_border_mode(int border_mode)
{
    this->m_border_mode = border_mode;
}

/**
 * @brief set header Method
 * 
 * @param header the header to assign.
 * @exception std::runtime_error if input header not correspond to content
 */
void Tabulate::set_headers(const std::vector<std::wstring> &header)
{
    if(header.size() != this->m_content.size())
        throw std::runtime_error("Error : The input size is not the same as the content(column number)");
    else
        this->m_headers = header;
}


/**
 * @brief set header method
 * 
 * @param header the header to assign. must be an iterable (list, array, valarray, vector, etc)
 * @exception std::runtime_error if input header size not correspond to content size (number of comumns)
 */
void Tabulate::set_headers(const std::initializer_list<std::wstring> &header)
{
    if(header.size() != (*(this->m_content.begin())).size())
        throw std::runtime_error("Error : The input header size is not the same as the content(number of comlums)");
    else
    {
        this->m_headers.clear();    // we start by clearing the values.
        for(const auto &header_val : header)
            this->m_headers.push_back(header_val);
    } 
}


/**
 * @brief Set content method
 * 
 * @param content the content to assign. 
 * @exception std::runtime_error if input content size not correspond to header size (column number)
 */
void Tabulate::set_content(const std::vector<std::vector<std::wstring>> &content)
{
    if(content.size() != this->m_headers.size())
        throw std::runtime_error("Error : The input content size is not the same as the header(number of comlums)");
    else
        this->m_content = content;
}


/**
 * @brief Set content method
 * 
 * @param content the content to assign. must be an iterable container(list, array, vector, valarray, etc).
 * @exception std::runtime_error if input content size not correspond to header size (column number).
 */
void Tabulate::set_content(const std::initializer_list<std::wstring> &content)
{
    this->m_content.clear(); // we start by clearing the values.
    int j = 0;
    bool is_init = true;
    std::vector<std::wstring> tmp_vec;
    for (const auto &cell_val : content)
    {
        if (!is_init) j = 0;
        if (j < this->m_headers.size())
        {
            tmp_vec.push_back(cell_val);
            ++j;
        }
        if (tmp_vec.size() == this->m_headers.size())
        {
            this->m_content.push_back(tmp_vec);
            tmp_vec.clear();
            is_init = false;
        }
    }
}


/**
 * @brief get output string method.
 * 
 * @return std::wstring 
 */
std::wstring Tabulate::get_output_str() 
{
    std::wstring str_output;
    wchar_t top_l, top_r, top_m, bottom_l, bottom_r, bottom_m, middle, middle_l, middle_r, vertical, horizontal; //charset
    wchar_t space = L' ', line_feed = L'\n';

    std::vector<int> col_size; // getting each max colum size
    for(int i = 0; i < this->m_headers.size(); ++i)
        col_size.push_back(get_col_size(i));

    for(int i = 0; i < this->m_content.size(); ++i) // setting header cells width
        if(this->m_headers[i].size() < col_size[i])
            for(int j = this->m_headers[i].size(); j < col_size[i]; ++j)
                this->m_headers[i].push_back(space);

    for(int i = 0; i < this->m_content.size(); ++i) // setting contain cells width
        for(int j = 0; j < this->m_headers.size(); ++j)
            if(this->m_content[i][j].size() < col_size[j])
                for(int k = this->m_content[i][j].size(); k < col_size[j]; ++k)
                    this->m_content[i][j].push_back(space);

    switch (this->m_border_mode) // for selected border mode ...
    {
        case border_mode::double_grid :
            top_l = L'╔', top_r = L'╗', top_m = L'╦';
            bottom_l = L'╚', bottom_r = L'╝', bottom_m = L'╩';
            middle = L'╬', middle_l = L'╠', middle_r = L'╣';
            vertical = L'║', horizontal = L'═'; 
        break;

        case border_mode::grid :
            top_l = L'+', top_r = L'+', top_m = L'-';
            bottom_l = L'+', bottom_r = L'+', bottom_m = L'-';
            middle = L'+', middle_l = L'+', middle_r = L'+';
            vertical = L'|', horizontal = L'-'; 
        break;

        case border_mode::simple_grid :
            top_l = L'┌', top_r = L'┐', top_m = L'─';
            bottom_l = L'└', bottom_r = L'┘', bottom_m = L'┴';
            middle = L'┼', middle_l = L'├', middle_r = L'┤';
            vertical = L'│', horizontal = L'─'; 
        break;

        case border_mode::fancy_grid :
            top_l = L'╒', top_r = L'╕', top_m = L'╤';
            bottom_l = L'╘', bottom_r = L'╛', bottom_m = L'╧';
            middle = L'╪', middle_l = L'╞', middle_r = L'╡';
            vertical = L'│', horizontal = L'═'; 
        break;

        case border_mode::heavy_grid :
            top_l = L'┏', top_r = L'┓', top_m = L'┳';
            bottom_l = L'┗', bottom_r = L'┛', bottom_m = L'┻';
            middle = L'╋', middle_l = L'┣', middle_r = L'┫';
            vertical = L'┃', horizontal = L'━'; 
        break;

        case border_mode::rounded_grid :
            top_l = L'╭', top_r = L'╮', top_m = L'┬';
            bottom_l = L'╰', bottom_r = L'╯', bottom_m = L'┴';
            middle = L'┼', middle_l = L'├', middle_r = L'┤';
            vertical = L'│', horizontal = L'─'; 
        break;
        
        default:
            top_l = L'+', top_r = L'+', top_m = L'-';
            bottom_l = L'+', bottom_r = L'+', bottom_m = L'-';
            middle = L'+', middle_l = L'+', middle_r = L'+';
            vertical = L'|', horizontal = L'-'; 
        break;
    }

    //first line (headers cells)
    str_output.push_back(top_l); 
    for(int i = 0; i < this->m_headers.size(); ++i) // up subdiv bar
    {
        for(int j = 0; j < this->m_headers[i].size(); ++j)
            str_output.push_back(horizontal);
        str_output.push_back(top_m);
    }
    str_output.pop_back(); 
    str_output.push_back(top_r);
    str_output.push_back(line_feed);

    for(int i = 0; i < this->m_headers.size(); ++i) // writing header cells values. 
    {
        str_output.push_back(vertical);
        str_output.append(this->m_headers[i]);
    }
    str_output.push_back(vertical);
    str_output.push_back(line_feed);
    str_output.push_back(middle_l);

    for(int i = 0; i < this->m_headers.size(); ++i) // down subdiv bar
    {
        for(int j = 0; j < this->m_headers[i].size(); ++j)
            str_output.push_back(horizontal);
        str_output.push_back(middle);
    }
    str_output.pop_back();
    str_output.push_back(middle_r);

    for(int i = 0; i < this->m_content.size(); ++i) // writing contain cells values.
    {
        str_output.push_back(line_feed);
        str_output.push_back(vertical);

        for(int j = 0; j < this->m_content[i].size(); ++j) 
        {   
            str_output.append(this->m_content[i][j]);
            str_output.push_back(vertical);
        }

        str_output.push_back(line_feed);
        str_output.push_back(middle_l);
        for(int j = 0; j < this->m_content[i].size(); ++j)  
        {
            for(int k = 0; k < col_size[j]; ++k)
                str_output.push_back(horizontal);
            str_output.push_back(middle);
        }
        str_output.pop_back();
        str_output.push_back(middle_r);
    }

    for(auto it = str_output.rbegin(); it != str_output.rend(); ++it) // deleting the last line
    {
        if(*it == line_feed)
            break;
        str_output.pop_back();
    }

    str_output.push_back(bottom_l);    // re-writing the last line with closing table chars.
    for(auto nb_spaces : col_size)
    {
        for(int j = 0; j < nb_spaces; ++j)
            str_output.push_back(horizontal);
        str_output.push_back(bottom_m);
        
    }
    str_output.pop_back();
    str_output.push_back(bottom_r);

    return str_output;
}