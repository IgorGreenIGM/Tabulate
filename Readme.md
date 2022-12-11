## 📚 Resume <a name = "resume"></a>

    C++ Tabulate - Pretty-print tabular data.
    This is a little C++ plugin, to construct a pretty TableFormat from input data.
    
##  ✔✔ Features <a name = "features">

    - Format a fixed width table for pretty printing.
    - Get output string in a table format from separated input
    - Six(06) format modes are avaible(simple_grid, rounded_grid, double_grid, ...)
    - Possibility to define your own table charset
    - Fixed width cells
    - Auto detect and auto ajust table width(fixed)

## ⛏️ Built With C++ [GNU GCC] <a name = "tech_stack"></a>

    Makefile provided.

## ⌨ Getting started <a name = "getting_started"></a>

    No special installation nedded, just set your console output to utf-8 chars by adding
    this line : `_setmode(_fileno(stdout), _O_U16TEXT);`

## ✍️ Authors <a name = "authors"></a>

    [@igorgreenIGM](https://github.com/igorgreenIGM) - Idea & Initial work

## 📂 Examples <a name = "example"></a>

    This table was generated with the rounded_grid mode.
    Source can be found in the main.cpp file     
    ╭───────────────────┬────────┬──────────╮
    │Header 1           │Header 2│Header 3  │
    ├───────────────────┼────────┼──────────┤
    │Cell 1             │Cell2   │Cell 3    │
    ├───────────────────┼────────┼──────────┤
    │Cell 4             │Cell 5  │Cell 6    │
    ├───────────────────┼────────┼──────────┤
    │A too much big cell│Cell 7  │          │
    ├───────────────────┼────────┼──────────┤
    │S. Cell            │        │Cell 8    │
    ├───────────────────┼────────┼──────────┤
    │Cell 9             │Cell 10 │FINAL CELL│
    ╰───────────────────┴────────┴──────────╯
