#include <string>
#include <fcntl.h>
#include <iostream>

#include "../include/Tabulate.h"

/**
 * @brief Example code, for any error or proble, please report to https://github.com/igorgreenIGM
 * 
 */
int main(int argc, char *argv[])
{
    _setmode(_fileno(stdout), _O_U16TEXT); // utf-16 console setting

    // cell contain
    std::initializer_list<const std::wstring> init ={L"Header 1", L"Header 2", L"Header 3",  
                                                     L"Cell 1", L"Cell2", L"Cell 3", 
                                                     L"Cell 4", L"Cell 5", L"Cell 6", 
                                                     L"A too much big cell", L"Cell 7", L"",
                                                     L"S. Cell", L"", L"Cell 8",
                                                     L"Cell 9", L"Cell 10", L"FINAL CELL"
                                                    };

    Tabulate my_tab(3, 4, border_mode::rounded_grid, init);  
    auto str = my_tab.get_output_str();

    std::wcout << str; // printing output

    return 0;
}
