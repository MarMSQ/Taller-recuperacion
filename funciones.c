#include <stdio.h>
#include <string.h>
#include "funciones.h"


void verPersonas(char personas[][4][20]){
    printf("Nombre\t\tApellido\t\tCedula\t\tEstado\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\t\t%s\t\t\t%s\t\t%s\n",personas[i][0],personas[i][1],personas[i][2],personas[i][03]);
    }
    
}

void registrarMatrimonio(char personas[][4][20]){
    verPersonas(personas);
    char cedula1[20],cedula2[20];
    int index,index2;
    
    printf("Ingrese la cedula de la primera persona: ");
    scanf("%s", cedula1);
    printf("Ingrese la cedula de la segunda persona: ");
    scanf("%s", cedula2);
    index = buscarPersonaXCedula(personas, cedula1);
    index2 = buscarPersonaXCedula(personas, cedula2);
    if ((index!= -1) && (index2!= -1)) {
        strcpy(personas[index][3], cedula2);
        strcpy(personas[index2][3], cedula1);
    }
}


void verificarPersona(char personas[][4][20]){
    char cedula[20];
    int index;
    printf("Ingrese la cedula de la persona que desea buscar: ");
    scanf("%s", cedula);
    index = buscarPersonaXCedula(personas, cedula);
    if (index != -1) { 
        if (strcmp(personas[index][3], "soltero") == 0) {
            printf("La persona es soltera\n");
        } else {
            int index2 = buscarPersonaXCedula(personas, personas[index][3]);
            printf("La persona es casada con %s %s\n", personas[index2][0], personas[index2][1]);
        }
    }

}


int buscarPersonaXCedula(char personas[][4][20],char cedula[20]) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strcmp(personas[i][2], cedula) == 0) {
            return i;
        }
    }
    return -1;
}