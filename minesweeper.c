#include "minesweeper.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};

char **annotate(const char **minefield, const size_t rows)
{
    //crear matriz y copiar el tablero
    char **annotate = (char**) malloc( rows * sizeof(char*));
    assert( annotate != NULL);
    for( size_t i = 0; i < rows; i++){
        *(annotate + i) = (char*) malloc( strlen( *(minefield + i) + 1 ) * sizeof(char));
        assert( *(annotate + i) != NULL);
        strcpy( *(annotate + i), *(minefield + i));
    }

    if( rows == 0 ){
        return NULL;
    }

    //cambiar tablero a números
    for(size_t i = 0; i < rows; i++){
        size_t cols = strlen( *(minefield + i));
        for(size_t j = 0; j < cols; j++){
            if( *(*(minefield + i) + j) == ' '){
                int count = 0;
                for( int k = 0; k < 8; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if( x >= 0 && (size_t)x < cols && y >= 0 && (size_t)y < rows && *(*(minefield + x) + y) == '*'){
                        count++;
                    }
                }
                if(count > 0){
                    *(*(annotate + i) + j) = count + '0';
                }
            }
        }
    }
    return annotate;
}

void free_annotation(char **annotation, const size_t rows)
{
    for (size_t i = 0; i < rows; i++) {
        free(annotation[i]);
    }
    free(annotation);
}

