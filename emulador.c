/***************************************************************************//**
  @file     +emulador.c+
  @brief    +Definicion de funciones y estructuras que utiliza el emulador+
  @author   +Grupo 1+
 ******************************************************************************/

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

#include "emulador.h"

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

#define NUM2CHAR(a) ((a) + '0')

/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

typedef struct{

	uint8_t b0 : 1;				//Ejemplo de acceso: puertoD.byte.A.bits.b0
	uint8_t	b1 : 1;
	uint8_t	b2 : 1;
	uint8_t	b3 : 1;
	uint8_t	b4 : 1;
	uint8_t	b5 : 1;
	uint8_t	b6 : 1;
	uint8_t	b7 : 1;
	
} bits8_t;                                      //Bitfield de 8 bits para simular un puerto

typedef struct{

	uint16_t        b0  : 1;		//Ejemplo de acceso: puertoD.bits.b0	
	uint16_t	b1  : 1;
	uint16_t	b2  : 1;
	uint16_t	b3  : 1;
	uint16_t	b4  : 1;
	uint16_t	b5  : 1;
	uint16_t	b6  : 1;
	uint16_t	b7  : 1;
	uint16_t	b8  : 1;
	uint16_t	b9  : 1;
	uint16_t	b10 : 1;
	uint16_t	b11 : 1;
	uint16_t	b12 : 1;
	uint16_t	b13 : 1;
	uint16_t	b14 : 1;
	uint16_t	b15 : 1;	
	
} bits16_t;                                             //Bitfield para simular el conjunto de dos puertos de 8 bits

typedef union {                                         

	bits8_t bits;					//Ejemplo de acceso: puertoD.byte.A.bits
	uint8_t word;                                   //Ejemplo de acceso: puertoD.byte.A.word

} puerto_8b;                                            //Union para crear un puerto de 8 bits con control de byte y de bits

typedef struct {                                         

        puerto_8b B;
	puerto_8b A;
	
} puerto_16b;                                           //Estructura de un puerto de 16bits (A y B juntos)

typedef union {                                         

	bits16_t bits;			
	puerto_16b byte;
	uint16_t word; 

} puerto16bits_t;                                       //Union de estructua para un puerto de 16 bits, bitfield para coontrol nivel bit y un entero de 16 bits para control de palabra


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/
/* Funcion para convertir de decimal a binario. Recibe un puntero a un arreglo vacio
 * con 17 u 9 espacios dependiendo del numero a convertir(uno de los lugares es para el terminador);
 * tambien se recibe el numero a convertir. Se devuelve el numero convertido a binario en formato string con terminador NULL
 * en el arreglo pasado. Sol ose manejan numeros que se puedan representar como maximo con 16 bits.
 */
static void dec2bin(uint8_t *buffer, uint16_t num);


/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static puerto16bits_t puertoD;                      //Declaracion de la estructura para simulacion del puerto de un microcontrolador


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

void bitSet (uint8_t puerto, uint8_t bit){
    
    if (puerto == PUERTOA){   
        switch(bit){
            case BIT0:
                 puertoD.byte.A.bits.b0 = ON;
                break;
            case BIT1:
                 puertoD.byte.A.bits.b1 = ON;
                break;
            case BIT2:
                 puertoD.byte.A.bits.b2 = ON;
                break;
            case BIT3:
                 puertoD.byte.A.bits.b3 = ON;
                break;
            case BIT4:
                 puertoD.byte.A.bits.b4 = ON;
                break;
            case BIT5:
                 puertoD.byte.A.bits.b5 = ON;
                break;
            case BIT6:
                 puertoD.byte.A.bits.b6 = ON;
                break;
            case BIT7:
                 puertoD.byte.A.bits.b7 = ON;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-7 entonces no hago nada
                break;
        }
    }
    else if (puerto == PUERTOB){
        switch(bit){
            case BIT0:
                 puertoD.byte.B.bits.b0 = ON;
                break;
            case BIT1:
                 puertoD.byte.B.bits.b1 = ON;
                break;
            case BIT2:
                 puertoD.byte.B.bits.b2 = ON;
                break;
            case BIT3:
                 puertoD.byte.B.bits.b3 = ON;
                break;
            case BIT4:
                 puertoD.byte.B.bits.b4 = ON;
                break;
            case BIT5:
                 puertoD.byte.B.bits.b5 = ON;
                break;
            case BIT6:
                 puertoD.byte.B.bits.b6 = ON;
                break;
            case BIT7:
                 puertoD.byte.B.bits.b7 = ON;
                break;
            default:     //SI NO SE ESCRIBIO un numero entre 0-7 entonces no hago nada
                break;
        }
        
    }
    else if (puerto == PUERTOD){
        switch(bit){
            case BIT0:
                 puertoD.bits.b0 = ON;
                break;
            case BIT1:
                 puertoD.bits.b1 = ON;
                break;
            case BIT2:
                 puertoD.bits.b2 = ON;
                break;
            case BIT3:
                 puertoD.bits.b3 = ON;
                break;
            case BIT4:
                 puertoD.bits.b4 = ON;
                break;
            case BIT5:
                 puertoD.bits.b5 = ON;
                break;
            case BIT6:
                 puertoD.bits.b6 = ON;
                break;
            case BIT7:
                 puertoD.bits.b7 = ON;
                break;
            case BIT8:
                 puertoD.bits.b8 = ON;
                break;
            case BIT9:
                 puertoD.bits.b9 = ON;
                break;
            case BIT10:
                 puertoD.bits.b10 = ON;
                break;
            case BIT11:
                 puertoD.bits.b11 = ON;
                break;
            case BIT12:
                 puertoD.bits.b12 = ON;
                break;
            case BIT13:
                 puertoD.bits.b13 = ON;
                break;
            case BIT14:
                 puertoD.bits.b14 = ON;
                break;
            case BIT15:
                 puertoD.bits.b15 = ON;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-15 entonces no hago nada
                break;
        }
    }
    else{
        //SI NO SE ESCRIBIO A,B o D entonces no hago nada
    }
}

void bitClr (uint8_t puerto, uint8_t bit){
    
    if (puerto == PUERTOA){   
        switch(bit){
            case BIT0:
                puertoD.byte.A.bits.b0 = OFF;
                break;
            case BIT1:
                 puertoD.byte.A.bits.b1 = OFF;
                break;
            case BIT2:
                 puertoD.byte.A.bits.b2 = OFF;
                break;
            case BIT3:
                 puertoD.byte.A.bits.b3 = OFF;
                break;
            case BIT4:
                 puertoD.byte.A.bits.b4 = OFF;
                break;
            case BIT5:
                 puertoD.byte.A.bits.b5 = OFF;
                break;
            case BIT6:
                 puertoD.byte.A.bits.b6 = OFF;
                break;
            case BIT7:
                 puertoD.byte.A.bits.b7 = OFF;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-7 entonces no hago nada
                break;
        }
    }
    else if (puerto == PUERTOB){
        switch(bit){
            case BIT0:
                 puertoD.byte.B.bits.b0 = OFF;
                break;
            case BIT1:
                 puertoD.byte.B.bits.b1 = OFF;
                break;
            case BIT2:
                 puertoD.byte.B.bits.b2 = OFF;
                break;
            case BIT3:
                 puertoD.byte.B.bits.b3 = OFF;
                break;
            case BIT4:
                 puertoD.byte.B.bits.b4 = OFF;
                break;
            case BIT5:
                 puertoD.byte.B.bits.b5 = OFF;
                break;
            case BIT6:
                 puertoD.byte.B.bits.b6 = OFF;
                break;
            case BIT7:
                 puertoD.byte.B.bits.b7 = OFF;
                break;
            default:    //SI NO SE ESCRIBIO un numero entre 0-7 entonces no hago nada
                break;
        }
        
    }
    else if (puerto == PUERTOD) {
        switch(bit){
            case BIT0:
                 puertoD.bits.b0 = OFF;
                break;
            case BIT1:
                 puertoD.bits.b1 = OFF;
                break;
            case BIT2:
                 puertoD.bits.b2 = OFF;
                break;
            case BIT3:
                 puertoD.bits.b3 = OFF;
                break;
            case BIT4:
                 puertoD.bits.b4 = OFF;
                break;
            case BIT5:
                 puertoD.bits.b5 = OFF;
                break;
            case BIT6:
                 puertoD.bits.b6 = OFF;
                break;
            case BIT7:
                 puertoD.bits.b7 = OFF;
                break;
            case BIT8:
                 puertoD.bits.b8 = OFF;
                break;
            case BIT9:
                 puertoD.bits.b9 = OFF;
                break;
            case BIT10:
                 puertoD.bits.b10 = OFF;
                break;
            case BIT11:
                 puertoD.bits.b11 = OFF;
                break;
            case BIT12:
                 puertoD.bits.b12 = OFF;
                break;
            case BIT13:
                 puertoD.bits.b13 = OFF;
                break;
            case BIT14:
                 puertoD.bits.b14 = OFF;
                break;
            case BIT15:
                 puertoD.bits.b15 = OFF;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-15 entonces no hago nada
                break;
        }
    }
    else{
        //SI NO SE ESCRIBIO A,B o D entonces no hago nada
    }
}

void bitToggle (uint8_t puerto, uint8_t bit){
    
    if (puerto == PUERTOA){   
        switch(bit){
            case BIT0:
                puertoD.byte.A.bits.b0 ^= ON;
                break;
            case BIT1:
                puertoD.byte.A.bits.b1 ^= ON;
                break;
            case BIT2:
                puertoD.byte.A.bits.b2 ^= ON;
                break;
            case BIT3:
                puertoD.byte.A.bits.b3 ^= ON;
                break;
            case BIT4:
                puertoD.byte.A.bits.b4 ^= ON;
                break;
            case BIT5:
                puertoD.byte.A.bits.b5 ^= ON;
                break;
            case BIT6:
                puertoD.byte.A.bits.b6 ^= ON;
                break;
            case BIT7:
                puertoD.byte.A.bits.b7 ^= ON;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-7 entonces no hago nada
                break;
        }
    }
    else if (puerto == PUERTOB){
        switch(bit){
            case BIT0:
                puertoD.byte.B.bits.b0 ^= ON;
                break;
            case BIT1:
                puertoD.byte.B.bits.b1 ^= ON;
                break;
            case BIT2:
                puertoD.byte.B.bits.b2 ^= ON;
                break;
            case BIT3:
                puertoD.byte.B.bits.b3 ^= ON;
                break;
            case BIT4:
                puertoD.byte.B.bits.b4 ^= ON;
                break;
            case BIT5:
                puertoD.byte.B.bits.b5 ^= ON;
                break;
            case BIT6:
                puertoD.byte.B.bits.b6 ^= ON;
                break;
            case BIT7:
                puertoD.byte.B.bits.b7 ^= ON;
                break;
            default:     //SI NO SE ESCRIBIO un numero entre 0-7 entonces no hago nada
                break;
        }
        
    }
    else if (puerto == PUERTOD){
        switch(bit){
            case BIT0:
                puertoD.bits.b0 ^= ON;
                break;
            case BIT1:
                puertoD.bits.b1 ^= ON;
                break;
            case BIT2:
                puertoD.bits.b2 ^= ON;
                break;
            case BIT3:
                puertoD.bits.b3 ^= ON;
                break;
            case BIT4:
                puertoD.bits.b4 ^= ON;
                break;
            case BIT5:
                puertoD.bits.b5 ^= ON;
                break;
            case BIT6:
                puertoD.bits.b6 ^= ON;
                break;
            case BIT7:
                puertoD.bits.b7 ^= ON;
                break;
            case BIT8:
                puertoD.bits.b8 ^= ON;
                break;
            case BIT9:
                puertoD.bits.b9 ^= ON;
                break;
            case BIT10:
                puertoD.bits.b10 ^= ON;
                break;
            case BIT11:
                puertoD.bits.b11 ^= ON;
                break;
            case BIT12:
                puertoD.bits.b12 ^= ON;
                break;
            case BIT13:
                puertoD.bits.b13 ^= ON;
                break;
            case BIT14:
                puertoD.bits.b14 ^= ON;
                break;
            case BIT15:
                puertoD.bits.b15 ^= ON;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-15 entonces no hago nada
                break;
        }
    }
    else{
        //SI NO SE ESCRIBIO A,B o D entonces no hago nada
    }
}

uint8_t bitGet(uint8_t puerto, uint8_t bit){
    
    uint8_t lectura = 0xFF;
    
    if (puerto == PUERTOA){   
        switch(bit){
            case BIT0:
                lectura = puertoD.byte.A.bits.b0;
                break;
            case BIT1:
                lectura = puertoD.byte.A.bits.b1;
                break;
            case BIT2:
                lectura = puertoD.byte.A.bits.b2;
                break;
            case BIT3:
                lectura = puertoD.byte.A.bits.b3;
                break;
            case BIT4:
                lectura = puertoD.byte.A.bits.b4;
                break;
            case BIT5:
                lectura = puertoD.byte.A.bits.b5;
                break;
            case BIT6:
                lectura = puertoD.byte.A.bits.b6;
                break;
            case BIT7:
                lectura = puertoD.byte.A.bits.b7;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-7 entonces no hago nada
                break;
        }
    }
    else if (puerto == PUERTOB){
        switch(bit){
            case BIT0:
                lectura = puertoD.byte.B.bits.b0;
                break;
            case BIT1:
                lectura = puertoD.byte.B.bits.b1;
                break;
            case BIT2:
                lectura = puertoD.byte.B.bits.b2;
                break;
            case BIT3:
                lectura = puertoD.byte.B.bits.b3;
                break;
            case BIT4:
                lectura = puertoD.byte.B.bits.b4;
                break;
            case BIT5:
                lectura = puertoD.byte.B.bits.b5;
                break;
            case BIT6:
                lectura = puertoD.byte.B.bits.b6;
                break;
            case BIT7:
                lectura = puertoD.byte.B.bits.b7;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-7 entonces no hago nada
                break;  
        }
        
    }
    else if (puerto == PUERTOD){
        switch(bit){
            case BIT0:
                lectura = puertoD.bits.b0;
                break;
            case BIT1:
                lectura = puertoD.bits.b1;
                break;
            case BIT2:
                lectura = puertoD.bits.b2;
                break;
            case BIT3:
                lectura = puertoD.bits.b3;
                break;
            case BIT4:
                lectura = puertoD.bits.b4;
                break;
            case BIT5:
                lectura = puertoD.bits.b5;
                break;
            case BIT6:
                lectura = puertoD.bits.b6;
                break;
            case BIT7:
                lectura = puertoD.bits.b7;
                break;
            case BIT8:
                lectura = puertoD.bits.b8;
                break;
            case BIT9:
                lectura = puertoD.bits.b9;
                break;
            case BIT10:
                lectura = puertoD.bits.b10;
                break;
            case BIT11:
                lectura = puertoD.bits.b11;
                break;
            case BIT12:
                lectura = puertoD.bits.b12;
                break;
            case BIT13:
                lectura = puertoD.bits.b13;
                break;
            case BIT14:
                lectura = puertoD.bits.b14;
                break;
            case BIT15:
                lectura = puertoD.bits.b15;
                break;
            default:        //SI NO SE ESCRIBIO un numero entre 0-15 entonces no hago nada
                break;
        }
        
    }
    else{
           //SI NO SE ESCRIBIO A,B o D entonces no hago nada
    }
    
    return lectura;
}

void maskOn(uint8_t puerto, uint16_t mascara){
    
    if(puerto == PUERTOA){
        puertoD.byte.A.word = puertoD.byte.A.word | ((uint8_t)mascara);
    }
    else if(puerto == PUERTOB){
        puertoD.byte.B.word = puertoD.byte.B.word | ((uint8_t)mascara);
    }
    else if (puerto == PUERTOD){
        puertoD.word = puertoD.word | mascara;
    }
    else{
        //SI NO SE ESCRIBIO A,B o D entonces no hago nada
    }
    
}

void maskOff(uint8_t puerto, uint16_t mascara){
    
    if(puerto == PUERTOA){
        puertoD.byte.A.word = puertoD.byte.A.word & (~((uint8_t)mascara));
    }
    else if(puerto == PUERTOB){
        puertoD.byte.B.word = puertoD.byte.B.word & (~((uint8_t)mascara));
    }
    else if (puerto == PUERTOD){
        puertoD.word = puertoD.word & (~mascara);
    }
    else{
        //SI NO SE ESCRIBIO A,B o D entonces no hago nada
    }
    
}

void maskToggle(uint8_t puerto, uint16_t mascara){
    
    if(puerto == PUERTOA){
        
        puertoD.byte.A.word = puertoD.byte.A.word ^ mascara;
    }
    
    else if(puerto == PUERTOB){
        
        puertoD.byte.B.word = puertoD.byte.B.word ^ mascara;
    }
    
    else if(puerto == PUERTOD){
        
        puertoD.word = puertoD.word ^ mascara;
    }
    else{
        //SI NO SE ESCRIBIO A,B o D entonces no hago nada
    }
}

void imprimirPuertos(void){
    uint8_t bufferPuerto[17];
    
    printf("Puerto D:");
    dec2bin(bufferPuerto, puertoD.word);
    printf("%s\n", bufferPuerto);
    printf("Puerto A:");
    dec2bin(bufferPuerto, puertoD.byte.A.word);
    printf("%s\n", bufferPuerto);
    printf("Puerto B:");
    dec2bin(bufferPuerto, puertoD.byte.B.word);
    printf("%s\n", bufferPuerto);
}
/*******************************************************************************
 *******************************************************************************
                        LOCAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

static void dec2bin(uint8_t *buffer, uint16_t num){
    
    int8_t i;
    
    if (num < 256){                                         //Obtengo el valor de cada bit a traves del resto de dividir por 2
        for(i = 7; i >= 0; i--){                            //Convierto el valor a caracter y lo apendiso al string.
            buffer[i] = NUM2CHAR(num%2);
            num /= 2;
        }
        buffer[8] = '\0';
    }
    else{
        for(i = 15; i >= 0; i--){
            buffer[i] = NUM2CHAR(num%2);
            num /= 2;
        }
        buffer[16] = '\0';
    }
}

 