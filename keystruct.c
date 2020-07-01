#include "keystruct.h"


struct Key new(char *word, int count) {
    struct Key st = {
        word,
        count
    };
    
    return st;
}
