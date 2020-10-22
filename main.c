/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: agus
 *
 * Created on October 21, 2020, 2:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "emulador.h"

/*
 * 
 */
int main(int argc, char** argv) {

    imprimirPuertos();
    maskOff(PUERTOA, 0xFF);
    imprimirPuertos();
    
    //PRUEBA DE CODIGO DAMI
    
    /*
    printf("\n Prueba del codigo de Damian\n");
    
    bitSet(PUERTOA, 1);
    bitSet(PUERTOB, 1);
    bitSet(PUERTOD, 0);
    bitSet(PUERTOD, 15);
    
    imprimirPuertos();
    
    bitClr(PUERTOA, 1);
    bitClr(PUERTOB, 1);
    bitClr(PUERTOD, 0);
    
    imprimirPuertos();
    
    bitClr(PUERTOD, 15);
    maskToggle(PUERTOA , 0x99);
    maskToggle(PUERTOB , 0x99);
    
    imprimirPuertos();
    
    maskToggle(PUERTOD, 0xFFFF);
    
    imprimirPuertos();
    
    */  
    
    
    return (EXIT_SUCCESS);
}

