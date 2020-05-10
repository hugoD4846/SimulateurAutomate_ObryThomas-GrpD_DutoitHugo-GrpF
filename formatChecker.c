#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool contains(char letter, char *alphabet){
    int i = 0;
    while(alphabet[i] != '\0'){
        if(alphabet[i] == letter) return true;
        i++;
    }
    return false;
}

bool alphabetCheck(char *line){
    if(strlen(line) > 1 && strlen(line) <= 9){
        int i = 0;
        while(line[i] != '\n'){
            if(!((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= '0' && line[i] <= '9'))){
                return false;
            }
            i++;
        }
    }else{
        printf("Mauvais format d'alphabet (ligne 1)");
        return false;
    }
    printf("alpha ok\n");
    return true;
}

bool initialStateCheck(char *line){
    if(strlen(line) == 2){
        if(line[0] >= '0' && line[0] <= '4'){
            printf("initial ok\n");
            return true;
        }

    }
    printf("Mauvais format d'état initial (ligne 2");
    return false;
}

bool acceptingStatesCheck(char *line){
    if(strlen(line) > 1 && strlen(line) <= 6){
        int i = 0;
        while(line[i] != '\n'){
            if(line[i] < '0' || line[i] > '4'){
                printf("Mauvais format d'états acceptants (ligne 3)");
                return false;
            }
            i++;
        } 
    }else{
        printf("Mauvais format d'états acceptants (ligne 3)\n");
        return false;
    }
    printf("accept ok\n");
    return true;
}

bool transitionsCheck(char *line, char *alphabet){
    int cpt = 0; int i = 0;
    while(line[i] != '\n' && line[i] != EOF){
        if(line[i] == ';') cpt++;
        i++;
    }
    printf("%d\n", cpt);
    if(cpt == 4){
        printf("4 ; rencontres\n");
        i = 0;
        while(line[i] != '\n' && line[i] != EOF){
            if(!contains(line[i], alphabet) && line[i] != ';'){
                printf("Mauvais format de transitions\n");
                return false;
            }
            i++;
        };
        return true;
    }   
    printf("Mauvais format de transitions\n");
    return false;
}

bool goodFormat(FILE *file){
    char checkedLine[100];
    fgets(checkedLine, 1000, file);
    char alphabet[100];
    strcpy(alphabet, checkedLine);
    printf("%s", alphabet);
    if(alphabetCheck(checkedLine)){
        fgets(checkedLine, 1000, file);
        if(initialStateCheck(checkedLine)){
            fgets(checkedLine, 1000, file);
            if(acceptingStatesCheck(checkedLine)){
                for(int i = 0; i < 5; i++){
                    fgets(checkedLine, 1000, file);
                    printf("%s", checkedLine);
                    if(!transitionsCheck(checkedLine, alphabet)){
                        printf("Int Foo a encore gagne : transi\n");
                        return false;
                    }
                }
                return true;
            }else printf("Int Foo a encore gagne : accept\n");
        }else printf("Int Foo a encore gagne : initial\n");
    }else printf("Int Foo a encore gagne : alphabet\n");
    return false;
}

/*int main(int argc, char **argv){
    if(goodFormat(fopen(argv[1],"a+"))){
        printf("Format accepte, bien joue et nique ta mere Int Foo\n");
    }else printf("Int Foo a encore gagne : main general return false\n");
    return 0;
}*/