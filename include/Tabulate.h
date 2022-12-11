#ifndef _TABULATE_H_INCLUDED_
#define _TABULATE_H_INCLUDED_

#include <string>
#include <vector>
#include <fcntl.h>
#include <initializer_list>

class Tabulate
{
    public:
        Tabulate(); //okk
        Tabulate(const std::vector<std::wstring> &headers, const std::vector<std::vector<std::wstring>> &content); //okk
        Tabulate(int col_nb, int line_nb, int border_mode, std::initializer_list<const std::wstring> content_next); //okk
        Tabulate(const std::vector<std::wstring> &headers, const std::vector<std::vector<std::wstring>> &content, int border_mode); //okk
        ~Tabulate(); //okk

        std::wstring get_output_str(); //okk
        std::vector<std::vector<std::wstring>> get_global_content() const noexcept; //okk

        void set_border_mode(int border_mode); //okk
        void set_headers(const std::vector<std::wstring> &headers); //okk
        void set_headers(const std::initializer_list<std::wstring> &header); //okk
        void set_content(const std::initializer_list<std::wstring> &content); //okk
        void set_content(const std::vector<std::vector<std::wstring>> &content); //okk
        
    private:
        int m_border_mode;
        std::vector<std::wstring> m_headers;
        std::vector<std::vector<std::wstring>> m_content;

        int get_col_size(int col_id); //okk
};

namespace border_mode
{
    enum border_mode {grid = 1, simple_grid, rounded_grid, heavy_grid, double_grid, fancy_grid};  
}

#endif //_TABULATE_H_INCLUDED_