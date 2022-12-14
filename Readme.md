## ๐ Resume <a name = "resume"></a>

    C++ Tabulate - Pretty-print tabular data.
    This is a little C++ plugin, to construct a pretty TableFormat from input data.
    
##  โโ Features <a name = "features">

    - Format a fixed width table for pretty printing.
    - Get output string in a table format from separated input
    - Six(06) format modes are avaible(simple_grid, rounded_grid, double_grid, ...)
    - Possibility to define your own table charset
    - Fixed width cells
    - Auto detect and auto ajust table width(fixed)

## โ๏ธ Built With C++ [GNU GCC] <a name = "tech_stack"></a>

    Makefile provided.

## โจ Getting started <a name = "getting_started"></a>

    No special installation nedded, just set your console output to utf-8 chars by adding
    this line : `_setmode(_fileno(stdout), _O_U16TEXT);`

## โ๏ธ Authors <a name = "authors"></a>

    [@igorgreenIGM](https://github.com/igorgreenIGM) - Idea & Initial work

## ๐ Examples <a name = "example"></a>

    This table was generated with the rounded_grid mode.
    Source can be found in the main.cpp file     
    โญโโโโโโโโโโโโโโโโโโโโฌโโโโโโโโโฌโโโโโโโโโโโฎ
    โHeader 1           โHeader 2โHeader 3  โ
    โโโโโโโโโโโโโโโโโโโโโผโโโโโโโโโผโโโโโโโโโโโค
    โCell 1             โCell2   โCell 3    โ
    โโโโโโโโโโโโโโโโโโโโโผโโโโโโโโโผโโโโโโโโโโโค
    โCell 4             โCell 5  โCell 6    โ
    โโโโโโโโโโโโโโโโโโโโโผโโโโโโโโโผโโโโโโโโโโโค
    โA too much big cellโCell 7  โ          โ
    โโโโโโโโโโโโโโโโโโโโโผโโโโโโโโโผโโโโโโโโโโโค
    โS. Cell            โ        โCell 8    โ
    โโโโโโโโโโโโโโโโโโโโโผโโโโโโโโโผโโโโโโโโโโโค
    โCell 9             โCell 10 โFINAL CELLโ
    โฐโโโโโโโโโโโโโโโโโโโโดโโโโโโโโโดโโโโโโโโโโโฏ
