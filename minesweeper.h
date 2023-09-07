#ifndef MINESWEEPER_H
#define MINESWEEPER_H
#include <stddef.h>

char **annotate(const char **minefield, const size_t rows);
void free_annotation(char **annotation, const size_t rows);
char **create_board( const char **minefield, const size_t rows);
void change_board( const char **minefield, const size_t rows, char **annotate);

#endif
