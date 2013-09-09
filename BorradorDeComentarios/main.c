//
//  main.c
//  BorradorDeComentarios
//
//  Created by Omar Gudino on 9/7/13.
//  Copyright (c) 2013 Omar Gudino. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


int main(int argc, const char * argv[])
{
    FILE *ptr_file;
    char buff;
    char *home = getenv("HOME");
    char *path = "/Desktop/Test.txt";
    int canPrint = 1;
    size_t length = strlen(home) + strlen(path) + 1;
    char *full_path = malloc(length);
    
    sprintf(full_path, "%s%s", home, path);
    
    ptr_file = fopen(full_path, "r");

    if (!ptr_file) {
        return 1;
    }
    
    while (1) {
        buff = fgetc(ptr_file);
        
        if (buff == EOF) {
            break;
        }
        if (buff == '/') {
            buff = fgetc(ptr_file);
            if (buff == '*') {
                canPrint = 0;
            } else if (buff == '/') {
                canPrint = 0;
                
                while (1) {
                    buff = fgetc(ptr_file);
                    
                    if (buff == '\n') {
                        canPrint = 1;
                        break;
                    }
                }
            }
        } else if (buff == '*'){
            buff = fgetc(ptr_file);
            if (buff == '/') {
                canPrint = 1;
            }
        }  else {
            if (canPrint) {
                printf("%c", buff);
            }
        }
    }
    

    fclose(ptr_file);
    
    return 0;
}