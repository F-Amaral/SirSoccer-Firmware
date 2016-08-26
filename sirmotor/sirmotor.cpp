/*
 *    SIR Lab - Laboratório de Sistemas Inteligentes e Robótica
 *    SirSoccer - 2015
 *    Autores: Hebert Luiz e Felipe Amaral 
 *    
 *    Implementação da classe para utilização do chip ponte-H TB6612FNG.
 *    Permite que seja passado somente um inteiro para o motor facilitando a sua utilização.
 *    Biblioteca feita para utilização em Arduino Micro mas pode ser facilmente utilizada em outras placas baseadas em Atmega sem dificuldades.
 *    
 */
#include "Header.h"
#include "Arduino.h"
#include "sirmotor.h"



Motor::Motor(byte pin1_A, byte pin2_A, byte pin3_A, byte pin1_B, byte pin2_B, byte pin3_B, byte STBY)//Construtor para dois motores
{
	PWMA = pin1_A;
	FW_A = pin2_A;
	BW_A = pin3_A;
 	
 	PWMB = pin1_B;
 	FW_B = pin2_B;
 	BW_B = pin3_B;

	ACTIVE = STBY;
}

void Motor::motorInit(){
	pinMode(PWMA, OUTPUT);
	pinMode(FW_A, OUTPUT);
	pinMode(BW_A, OUTPUT);
 	pinMode(PWMB, OUTPUT);
 	pinMode(FW_B, OUTPUT);
 	pinMode(BW_B, OUTPUT);
	pinMode(ACTIVE, OUTPUT);
	digitalWrite(ACTIVE, NO);

}



	void Motor::updateMotor(int directionA, int pwmA, int directionB, int pwmB)
	{ 
		// Método otimizado para motores espelhados. Para Frente no motor A é igual a Trás no motor B

		//Definições do motor A
		if(pwmA == 0 && pwmB == 0){
			//delay(40);
			//digitalWrite(FW_A, YES);
			//digitalWrite(BW_A, YES);				
			stopMotor();
		}

		if (directionA == 0) 
		{
			digitalWrite(FW_A, YES);
			digitalWrite(BW_A, NO);
			analogWrite(PWMA, pwmA);
			//digitalWrite(ACTIVE, YES);

		} else if (directionA == 1)
		{
			digitalWrite(FW_A, NO);
			digitalWrite(BW_A, YES);
			analogWrite(PWMA, pwmA);
			//digitalWrite(ACTIVE, YES);
		}

		//Definições do motor B já otimizada para motores espelhados.
		if (directionB == 0) 
		{
			digitalWrite(FW_B, YES);
			digitalWrite(BW_B, NO);
			analogWrite(PWMB, pwmB);
			//digitalWrite(ACTIVE, YES);

		} else if (directionB == 1)
		{
			digitalWrite(FW_B, NO);
			digitalWrite(BW_B, YES);
			analogWrite(PWMB, pwmB);
			//digitalWrite(ACTIVE, YES);
		}
	
		//digitalWrite(ACTIVE, YES);
	}


	void Motor::stopMotor(){
		digitalWrite(ACTIVE, NO);
	}
	void Motor::startMotor(){
		digitalWrite(ACTIVE, YES);
	}

