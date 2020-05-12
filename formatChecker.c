#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "automate.h"
#include "formatChecker.h"
#include "readAuto.h"
#include "printAuto.h"
#include "solveAuto.h"
bool contains(char letter, char *alphabet){ // vérifie si letter est bien compris dans la chaîne alphabet
    int i = 0;
    while(alphabet[i] != '\0'){
        if(alphabet[i] == letter) return true;
        i++;
    }
    return false;
}

bool alphabetCheck(char *line){ // vérifie le format de l'alphabet passé en paramètre sous forme de chaîne de carctères : seulement des lettres, minuscules ou majuscules, ou des chiffres de 0 à 9, et 8 caractères maximum (+ \n capturé par la fonction fgets)
    if(strlen(line) > 1 && strlen(line) <= 9){
        int i = 0;
        while(line[i] != '\n'){
            if(!((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z') || (line[i] >= '0' && line[i] <= '9'))){
                return false;
            }
            i++;
        }
    }else{
        return false;
    }
    return true;
}

bool initialStateCheck(char *line){ // vérifie si la chaîne passée en paramètre ne fournit bien qu'un seul état initial sous forme d'entier, et s'il est bien compris entre 0 et 4
    if(strlen(line) == 2){
        if(line[0] >= '0' && line[0] <= '4'){
            return true;
        }

    }
    return false;
}

bool acceptingStatesCheck(char *line){ // vérifie que la chaîne passée en paramètre (ligne des étas acceptants) fournit seulement des entiers compris entre 0 et 4
    if(strlen(line) > 1 && strlen(line) <= 6){
        int i = 0;
        while(line[i] != '\n'){
            if(line[i] < '0' || line[i] > '4'){
                return false;
            }
            i++;
        } 
    }else{
        return false;
    }
    return true;
}

bool transitionsCheck(char *line, char *alphabet){ // vérifie que la ligne de transition passée en paramètre respecte les contraintes des transitions de l'automate, soit 4 ';' entrecoupés de 1 ou plusieurs caractères, compris dans l'alphabet passé en seconde paramètre
    int cpt = 0; int i = 0;
    while(line[i] != '\n' && line[i] != EOF){
        if(line[i] == ';') cpt++;
        i++;
    }
    if(cpt == 4){
        i = 0;
        while(line[i] != '\n' && line[i] != EOF){
            if(!contains(line[i], alphabet) && line[i] != ';'){
                return false;
            }
            i++;
        };
        return true;
    }
    return false;
}

bool goodFormat(FILE *file){ // capture les lignes du fichier passé en paramètre une à une et vérifie leur format
    char checkedLine[100];
    fgets(checkedLine, 1000, file);
    char alphabet[100];
    strcpy(alphabet, checkedLine);
    if(alphabetCheck(checkedLine)){
        fgets(checkedLine, 1000, file);
        if(initialStateCheck(checkedLine)){
            fgets(checkedLine, 1000, file);
            if(acceptingStatesCheck(checkedLine)){
                for(int i = 0; i < 5; i++){
                    fgets(checkedLine, 1000, file);
                    if(!transitionsCheck(checkedLine, alphabet)){
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

