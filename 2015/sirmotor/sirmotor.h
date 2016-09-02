/*
 *    SIR Lab - Laboratório de Sistemas Inteligentes e Robótica
 *    SirSoccer - 2015
 *    Autores: Hebert Luiz e Felipe Amaral 
 *    
 *    Classe para utilização do chip ponte-H TB6612FNG.
 *    Permite que seja passado somente um inteiro para o motor facilitando a sua utilização.
 *    Biblioteca feita para utilização em Arduino Micro mas pode ser facilmente utilizada em outras placas baseadas em Atmega sem dificuldades.
 *    
 */

#ifndef SIRMOTORTB6612FNG_H 
#define SIRMOTORTB6612FNG_H
#include <Arduino.h>
#include "Header.h"

#define YES HIGH
#define NO LOW


class Motor
{
 private:
   byte PWMA;
   byte PWMB;
   byte FW_A;
   byte BW_A;
   byte FW_B;
   byte BW_B;
   byte ACTIVE;
   
 public:
   
   //Contrutores recebem os pinos usados no arduino que serão definidos como saídas
   Motor(byte pin1_A, byte pin2_A, byte pin3_A, byte pin1_B, byte pin2_B, byte pin3_B, byte STBY); //Construtor para dois motores
   void motorInit(); //Inicia o motor no setup
   void updateMotor(int directionA, int pwmA, int directionB,int pwmB); // receberá os valor inteiros para o motor se forem entre 0-255 vai para FW e 256-510 vai para Trás
   void stopMotor(); // coloca o motor em standby parando os motores YESultaneamente.
   void startMotor();
};
#endif
