/***************************************************************************//**
  @file     +emulador.h+
  @brief    +Header del modulo emulador de puerto de un microcontrolador.+
  @author   +Grupo 1+
 ******************************************************************************/

#ifndef _EMULADOR_H_
#define _EMULADOR_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include <stdio.h>
#include <stdint.h>

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

//Constantes para ingresar puertos en las funciones
#define PUERTOA 'A'                     //Puerto de 8 bits
#define PUERTOB 'B'                     //Puerto de 8 bits
#define PUERTOD 'D'                     //Conjuncion de A y B, por ende puerto de 16 bits

#define ON 1
#define OFF 0


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/* Constantes para indicar el numero de bit a seleccionar.
 */
enum {BIT0=0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7, BIT8, BIT9, BIT10, BIT11, BIT12, BIT13, BIT14, BIT15};


/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/


uint8_t bitGet(uint8_t puerto, uint8_t bit);
/**
 * @brief bitGet Devuelve el valor del bit del puerto que se pase. Si alguno de los parametros es invalido devuelve 0xFF
 * @param puerto el puerto del cual se desee saber el valor del bit como caracter mayuscula A, B o D. A y B 8bits, D(A+B) 16bits
 * @param bit el numero del bit a saber. 0-7 para los puertos A y B, 0-15 para el puerto D
 * @return valor del bit solicitado
*/
void bitSet (uint8_t puerto, uint8_t bit);
/**
 * @brief bitSet Dado un puerto y un numero de bit, cambia su estado a 1. Si la entrada es incorrecta, entonces no hace nada
 * @param puerto el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D. A y B 8bits, D(A+B) 16bits
 * @param bit el numero del bit a cambiar. 0-7 para los puertos A y B, 0-15 para el puerto D
*/
void bitClr (uint8_t puerto, uint8_t bit);
/**
 * @brief bitClr Dado un puerto y un numero de bit, cambia su estado a 1. Si la entrada es incorrecta, entonces no hace nada
 * @param puerto el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D. A y B 8bits, D(A+B) 16bits
 * @param bit el numero del bit a cambiar. 0-7 para los puertos A y B, 0-15 para el puerto D
*/
void bitToggle (uint8_t puerto, uint8_t bit);
/**
 * @brief bitToggle Dado un puerto y un número de bit, debe cambiar al estado opuesto en el que está (si está en 0 pasar a 1, y si está en 1 pasar a 0).
 * @param puerto el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D. A y B 8bits, D(A+B) 16bits
 * @param bit el numero del bit a cambiar. 0-7 para los puertos A y B, 0-15 para el puerto D
*/
void maskOn(uint8_t puerto, uint16_t mascara);
/**
 * @brief maskOn Dado un puerto y una máscara, debe prender todos aquellos bits que estén prendidos en la máscara, sin cambiar el estado de los restantes.
 * @param puerto el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D. A y B 8bits, D(A+B) 16bits
 * @param mascara La mascara que contiene la informacion de los bits los cuales se desea invertir su estado
*/
void maskOff(uint8_t puerto, uint16_t mascara);
/**
 * @brief maskOff Dado un puerto y una máscara, debe apagar todos aquellos bits que estén prendidos en la máscara, sin cambiar el estado de los restantes.
 * @param puerto el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D. A y B 8bits, D(A+B) 16bits
 * @param mascara Mascara de 16 bits a utilizar(en puertos de 8 bits se ignora el byte mas significativo
*/
void maskToggle(uint8_t puerto, uint16_t mascara);
/**
 * @brief maskToggle Dado un puerto y una mascara, invierte los todos los bits que esten en 1 de la mascara. Logicamente, realiza la operacion 
 *        EOR entre la mascara y el puerto.   
 * @param puerto el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D. A y B 8bits, D(A+B) 16bits
 * @param mascara La mascara que contiene la informacion de los bits los cuales se desea invertir su estado
*/

void imprimirPuertos(void);
/**
 * @brief imprimirPuertos Imprime el valor de todos los puertos en formato de numero binario.
*/

/*******************************************************************************
 ******************************************************************************/

#endif // _EMULADOR_H_
