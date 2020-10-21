/***************************************************************************//**
  @file     +Nombre del archivo (ej: template.c)+
  @brief    +Descripcion del archivo+
  @author   +Nombre del autor (ej: Salvador Allende)+
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
	
} bits8_t;

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
	
} bits16_t;

typedef union {			//estructura de los puertos A y B

	bits8_t bits;					//Ejemplo de acceso: puertoD.byte.A.bits
	uint8_t word;				//Ejemplo de acceso: puertoD.byte.A.word

} puerto_8b;

typedef struct {			//estructura de un puerto de 16bits (A y B juntos) 

	puerto_8b A;
	puerto_8b B;
	
} puerto_16b;

typedef union {					//definicion e inicializacion del puerto D

	bits16_t bits;			
	puerto_16b byte;
	uint16_t word; 

} puerto16bits_t;




/*******************************************************************************
 * VARIABLES WITH GLOBAL SCOPE
 ***************************************************************************


/*******************************************************************************
 * FUNCTION PROTOTYPES FOR PRIVATE FUNCTIONS WITH FILE LEVEL SCOPE
 ******************************************************************************/

static void dec2bin(uint8_t *buffer, uint16_t num);


/*******************************************************************************
 * ROM CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

// +ej: static const int temperaturas_medias[4] = {23, 26, 24, 29};+


/*******************************************************************************
 * STATIC VARIABLES AND CONST VARIABLES WITH FILE LEVEL SCOPE
 ******************************************************************************/

static puerto16bits_t puertoD;


/*******************************************************************************
 *******************************************************************************
                        GLOBAL FUNCTION DEFINITIONS
 *******************************************************************************
 ******************************************************************************/

uint8_t bitGet(uint8_t puerto, uint8_t bit){
    
    uint8_t lectura;
    
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
            default:
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
            default:
                break;
        }
        
    }
    else{
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
            default:
                break;
        }
        
    }
    
    return lectura;
}


void maskOff(uint8_t puerto, uint16_t mascara){
    
    if(puerto == PUERTOA){
        puertoD.byte.A.word = puertoD.byte.A.word & (~((uint8_t)mascara));
    }
    else if(puerto == PUERTOB){
        puertoD.byte.B.word = puertoD.byte.B.word & (~((uint8_t)mascara));
    }
    else{
        puertoD.word = puertoD.word & (~mascara);
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
    
    if (num < 256){
        for(i = 7; i >= 0; i--){
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

 