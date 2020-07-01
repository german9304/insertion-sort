#include <string.h>
#include<stdio.h> 
#include<stdlib.h>
#include<ctype.h> 
#include <assert.h>
#include "keystruct.h"

#define MAXWORD 1000
#define WORDTOTAL 4

int error_handler(FILE *fp) {
   if(fp == NULL) {
     return -1;
   } 
   return 0;
}


FILE* get_file(char* filename) {
   FILE * fp = fopen(filename, "r");
   if(error_handler(fp) == -1) {
     // displays error to screen 
     fprintf(stderr, "FILE DOES NOT EXISTS!!! %s \n", filename);
      return NULL;
   }
   return fp;  
}

char *file_name(char *argv[], int argc) {
  // if file name is not entered
  if(argc < 2) {
      return "poem.txt";
  }
  return argv[1];
}


// reads the word from file
int getword(char *word, FILE *fp) {
    char c;
    while((c = getc(fp)) != EOF) {
        if(c  != '\n') {
            *word++ = c;
        } else {
            *word++ = '\0';
            return c;
        }
    }
    return c;
}

int  read_file(FILE *fp, char *files[]) {
  char word[MAXWORD];
  int i = 0;

  while((getword(word, fp)) != EOF) {
      files[i] = (char*) malloc(sizeof(char*));
      strcpy(files[i], word);
      i++;
  }

  return 0;
}


void print_words(char *words[]) {
    for(int i = 0; i < 4; i++) {
        printf("%s \n", words[i]);
    }
}

void free_words(char *words[], int n) {
    for(int i = 0; i < n; i++) {
        free(words[i]);
    }
}

void insertion_sort(char *words[]) {
// invariants
// array is sorted first
    for(int i = 1; i < WORDTOTAL; i++) {

        char *current = words[i];
        int iter = i; 

        while(iter > 0 &&  strcmp(words[iter - 1], current) > 0) {
            words[iter] = words[iter - 1]; 
            iter--;
        }

        words[iter] = current;
     }
}

int main(int argc, char *argv[]) {

  char *filename = file_name(argv, argc);
  FILE *fp = get_file(filename);
  if(fp == NULL) {
    return -1;
  }
  
  char *words[WORDTOTAL];
  
  int r = read_file(fp, words);
  if(r) {
      fprintf(stderr, "error reading file");
  }

  insertion_sort(words);

  print_words(words);

  free_words(words, WORDTOTAL);

}
