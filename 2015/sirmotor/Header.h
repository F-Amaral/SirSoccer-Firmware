/*
 *    SIR Lab - Laboratório de Sistemas Inteligentes e Robótica
 *    SirSoccer - 2015
 *    Main authors: Hebert Luiz,Felipe Amaral 
 *    
 *	  SirLab members 2014: Johnathan Fercher, Oscar Neiva, Hebert Luiz and Lucas Marques
 *
 *	  SirLab members 2015: Johnathan Fercher, Oscar Neiva, Hebert Luiz, Felipe Amaral, Manoel Stilpen, Samantha Vilaça, Marina Barros
 *
 *    Implementação da biblioteca de funções do Arduino.
 *    Biblioteca feita para utilização em Arduino Micro mas pode ser facilmente utilizada em outras placas baseadas em Atmega sem dificuldades.
 * 
 *	  Library made for Arduino-side communication with computer-side software, especially developed for interation with SirSoccer.
 *	  This library is made for Arduino Micro/Leonardo, but can be easily adapted to work on other platforms. 
 *   
 */
#ifndef HEADER_H
#define HEADER_H

struct Command{
	int pwmA = 0;
	int pwmB = 0;
	int directionA = 0;
	int directionB = 0;
};


/* Defines encoder pins*/
#define EncoderA1 2 
#define EncoderA2 A0

#define EncoderB1 3
#define EncoderB2 4

/* Defines motor PWM and motor direction*/

#define MotorAPWM 11
#define MotorA1  A4
#define MotorA2	 A5


#define MotorBPWM 13
#define MotorB1  A2
#define MotorB2  A1

/*Stand-By pin*/

#define STDBY A3

#endif
