#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#define TWCR (*(volatile u8*) 0x56)
#define TWDR (*(volatile u8*) 0x23)
#define TWAR (*(volatile u8*) 0x22)
#define TWSR (*(volatile u8*) 0x21)	//Status reg
#define TWBR (*(volatile u8*) 0x20)	//Bit Rate Reg

//TWCR

#define TWINT	7 //Interrupt Flag
#define TWEA	6 //Enable Ack
#define TWSTA	5 //Start cond. bit
#define TWSTO	4 //Stop cond. bit
#define TWWC	3 //write collision flag
#define TWEN	2 //Enable TWI
#define TWIE	0 //Interrupt Enable

//TWSR status register

#define TWPS0	0
#define TWPS1	1


#define ACK_ENABLED		0
#define ACK_DISABLED	1

#define START		0x08
#define RSTART		0x10
#define SLA_ACK		0x18
#define SLA_NACK	0x20
#define DATA_ACK	0x28
#define DATA_NACK	0x30

#define PRESCALER_1		0
#define PRESCALER_4		1
#define PRESCALER_16	2
#define PRESCALER_64	3

enum bool {FALSE , TRUE};

#endif
