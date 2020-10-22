/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.h)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
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

#define PUERTOA 'A'
#define PUERTOB 'B'
#define PUERTOD 'D'

#define ON 1
#define OFF 0


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

enum {BIT0=0, BIT1, BIT2, BIT3, BIT4, BIT5, BIT6, BIT7, BIT8, BIT9, BIT10, BIT11, BIT12, BIT13, BIT14, BIT15};

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/



/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
uint8_t bitGet(uint8_t puerto, uint8_t bit);
/**
 * @brief ATENTO DEVOLVERIA 0XFF SI EL PARAMETROS ES ERRONEO
 * @param el puerto del cual se desee saber el valor del bit como caracter mayuscula A, B o D
 * @param el numero del bit a saber. 0-7 para los puertos A y B, 0-15 para el puerto D
 * @return Descripcion valor que devuelve
*/
void bitSet (uint8_t puerto, uint8_t bit);
/**
 * @brief Dado un puerto y un numero de bit, cambia su estado a 1. Si la entrada es incorrecta, entonces no hace nada
 * @param el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D
 * @param el numero del bit a cambiar. 0-7 para los puertos A y B, 0-15 para el puerto D
*/
void bitClr (uint8_t puerto, uint8_t bit);
/**
 * @brief Dado un puerto y un numero de bit, cambia su estado a 1. Si la entrada es incorrecta, entonces no hace nada
 * @param el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D
 * @param el numero del bit a cambiar. 0-7 para los puertos A y B, 0-15 para el puerto D
*/

/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/

/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
void maskOff(uint8_t puerto, uint16_t mascara);
/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
void maskToggle(uint8_t puerto, uint16_t mascara);
/**
 * @brief dado un puerto y una mascara, invierte los todos los bits que esten en 1 de la mascara. Logicamente, realiza la operacion 
 *        EOR entre la mascara y el puerto.   
 * @param el puerto del cual se desee cambiar el bit como caracter mayuscula A, B o D
 * @param La mascara que contiene la informacion de los bits los cuales se desea invertir su estado
*/

/**
 * @brief TODO: completar descripcion
 * @param param1 Descripcion parametro 1
 * @param param2 Descripcion parametro 2
 * @return Descripcion valor que devuelve
*/
void imprimirPuertos(void);

/*******************************************************************************
 ******************************************************************************/

#endif // _EMULADOR_H_
