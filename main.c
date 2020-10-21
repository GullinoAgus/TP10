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
    
    return (EXIT_SUCCESS);
}

