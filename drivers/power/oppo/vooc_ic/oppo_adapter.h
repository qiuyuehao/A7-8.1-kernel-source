#ifndef _OPPO_VOOC_ADAPTER_H_
#define _OPPO_VOOC_ADAPTER_H_

#include "../oppo_vooc.h"

//ap_data---->rx     ap_clk---->tx
#define BIT_0						0
#define BIT_1						1
#define BIT_2						2
#define BIT_3						3
#define BIT_4						4
#define BIT_5						5
#define BIT_6						6
#define BIT_7						7
#define BIT_STOP					8
#define BIT_IDLE					9
#define BIT_START					10

#define UART_NOACK					0
#define UART_ACK					1

#define FW_VER_LOW					14
#define FW_VER_HIGH					15
#define FW_EXIST_LOW				16
#define FW_EXIST_HIGH				17

#define Tx_Read_Addr_Line       	0x01  
#define Tx_Write_Addr_Line     	 	0x02 
#define Tx_Erase_Addr_Line      	0x03
#define Tx_Read_All            		0x04
#define Tx_Erase_All            	0x05
#define Tx_Boot_Over            	0x06
#define Tx_Cmd_Invalid				0xff

#define Rx_Read_Addr_Line       	0x01  
#define Rx_Write_Addr_Line     	 	0x02 
#define Rx_Erase_Addr_Line      	0x03
#define Rx_Read_All            		0x04
#define Rx_Erase_All            	0x05
#define Rx_Boot_Over            	0x06
#define Rx_Cmd_Invalid				0xff

#define Read_Addr_Line_Cmd        	0xF501  
#define Write_Addr_Line_Cmd       	0xF502 
#define Erase_Addr_Line_Cmd       	0xF503
#define Read_All_Cmd              	0xF504
#define Erase_All_Cmd             	0xF505
#define Boot_Over_Cmd             	0xF506
#define Last_Line_Addr				0x9FF0

#define Read_Addr_Line_Cmd_Count	2000		//physical test: 27
#define Write_Addr_Line_Cmd_Count	18000		//physical test:8720
#define Erase_Addr_Line_Cmd_Count	16000		//physical test:7657
#define Read_All_Cmd_Count			2000		//physical test:27
#define Erase_All_Cmd_Count			180000		//physical test:86916
#define Boot_Over_Cmd_Count			2000		//physical test:34
#define Other_Cmd_count				2000

extern void oppo_adapter_init(struct oppo_adapter_chip *chip);

//fw_ver must be 0x0b/0x0c/0x0d/0x0e/0x0f because of pic1508/stm8s

static unsigned char adapter_stm8s_firmware_data[] = {
0x00,0x8c,0x82,0x00,0x9F,0x20,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,
0x20,0x8C,0x82,0x00,0x93,0xBC,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,
0x40,0x8C,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,
0x60,0x8C,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,0x82,0x00,0x9F,0xCF,
0x80,0x8C,0x3B,0x00,0x08,0x3F,0x08,0x20,0x0C,0x3D,0x08,0x26,0x03,0xCD,0x93,0x70,0xA6,0x14,0xCD,0x9E,0xA4,0xB6,0x08,0xA1,0x02,0x27,0x2A,0xCD,0x9F,0xC1,0xCD,0x91,0x69,0xAE,
0xA0,0x8C,0x00,0x12,0xCD,0x91,0x2C,0xB7,0x08,0xA1,0x02,0x26,0x04,0xA6,0x01,0x20,0x14,0xA1,0x01,0x26,0x05,0xCD,0x92,0xDD,0x20,0xD6,0xA1,0x03,0x26,0xCB,0xA6,0x01,0xCD,0x92,
0xC0,0x8C,0xF6,0x20,0xCB,0x32,0x00,0x08,0x81,0xCD,0x9A,0x2A,0xCD,0x99,0xF2,0xBF,0x0A,0x90,0xBF,0x08,0xB7,0x0D,0x3F,0x0C,0xCD,0x9F,0xC1,0xB6,0x0D,0xCD,0x8D,0xAE,0xA6,0x02,
0xE0,0x8C,0xCD,0x93,0x29,0xBF,0x00,0xB3,0x0A,0x2F,0x06,0xBE,0x08,0xB3,0x00,0x2E,0x74,0xBE,0x00,0xB3,0x0A,0x2E,0x5C,0x3D,0x0D,0x27,0x49,0xA6,0x04,0xCD,0x93,0x29,0xA3,0x07,
0x00,0x8D,0x03,0x24,0x60,0xC6,0x00,0x31,0xA1,0x05,0x24,0x09,0xC6,0x00,0x31,0x4C,0xC7,0x00,0x31,0x20,0x15,0xC6,0x00,0x32,0xA1,0x0A,0x24,0x0E,0xC6,0x00,0x32,0x4C,0xC7,0x00,
0x20,0x8D,0x32,0xCD,0x92,0xDD,0x72,0x5F,0x00,0x31,0xC6,0x00,0x32,0xA1,0x0A,0x26,0x0A,0x35,0x0B,0x00,0x32,0x35,0x05,0x00,0x31,0x20,0x2A,0xC6,0x00,0x32,0xA1,0x0B,0x25,0x23,
0x40,0x8D,0x20,0x0A,0xA6,0x04,0xCD,0x93,0x29,0xA3,0x07,0x2C,0x24,0x40,0xCD,0x92,0xDD,0x20,0x12,0xBE,0x08,0xB3,0x00,0x2E,0x0C,0xB6,0x0D,0xCD,0x92,0xF6,0x20,0x05,0xA6,0x02,
0x60,0x8D,0xCD,0x9E,0xA4,0xB6,0x0C,0x4C,0xB7,0x0C,0xA6,0x02,0xCD,0x93,0x29,0xA3,0x05,0xBF,0x2F,0x14,0xC6,0x00,0x28,0xAB,0xF7,0xCD,0x93,0x1B,0xB6,0x0D,0xCD,0x8D,0xAE,0xA6,
0x80,0x8D,0x14,0xCD,0x9E,0xA4,0x20,0x06,0xB6,0x0C,0xA1,0x0A,0x25,0xD2,0xA6,0x04,0xCD,0x93,0x29,0x3D,0x0D,0x27,0x06,0x90,0xAE,0x07,0x2B,0x20,0x04,0x90,0xAE,0x07,0x4E,0xBF,
0xA0,0x8D,0x00,0x90,0xB3,0x00,0x2E,0x05,0xB6,0x0D,0xCD,0x92,0xF6,0xCC,0x9A,0x7E,0xA1,0x01,0x27,0x2F,0xA6,0x04,0xCD,0x93,0x29,0xA3,0x05,0x54,0x24,0x21,0xA6,0x02,0xCD,0x93,
0xC0,0x8D,0x29,0xA3,0x02,0x8F,0x25,0x17,0xC6,0x00,0x30,0xA1,0x46,0x24,0x08,0xC6,0x00,0x30,0x4C,0xC7,0x00,0x30,0x81,0xCD,0x8E,0xAD,0xCD,0x8D,0xE2,0x20,0xFB,0x72,0x5F,0x00,
0xE0,0x8D,0x30,0x81,0xCD,0x99,0xED,0x3B,0x00,0x0A,0x52,0x04,0x35,0x01,0x00,0x0A,0x90,0xAE,0x9F,0xCB,0x96,0x5C,0x89,0xA6,0x04,0xCD,0x9F,0x5F,0x85,0xCD,0x9F,0xC1,0xCD,0x8F,
0x00,0x8E,0x12,0x7B,0x01,0xA1,0x1D,0x26,0x12,0x7B,0x02,0xA1,0x05,0x26,0x0C,0x7B,0x03,0xA1,0x14,0x26,0x06,0x7B,0x04,0xA1,0x08,0x27,0x4B,0xCD,0x9F,0xC1,0x7B,0x01,0xA1,0x1D,
0x20,0x8E,0x27,0x13,0xCD,0x9F,0xC1,0x96,0x5C,0xCD,0x8E,0xC0,0x96,0x1C,0x00,0x02,0xBF,0x08,0x4D,0x26,0xE9,0x20,0x37,0xBE,0x08,0xCD,0x8E,0xC0,0xBE,0x08,0x5C,0xBF,0x08,0x4D,
0x40,0x8E,0x26,0x02,0x3F,0x0A,0xCD,0x8E,0xC0,0xBE,0x08,0x5C,0xBF,0x08,0x4D,0x26,0x02,0x3F,0x0A,0xCD,0x8E,0xC0,0xBE,0x08,0x5C,0xBF,0x08,0x4D,0x26,0x02,0x3F,0x0A,0x3D,0x0A,
0x60,0x8E,0x26,0x9F,0x20,0x08,0x35,0x01,0x00,0x2F,0x4F,0xCD,0x8E,0x74,0x5B,0x04,0x32,0x00,0x0A,0xCC,0x9A,0x85,0x4D,0x27,0x03,0xCD,0x8E,0xAD,0xC6,0x00,0x2F,0x26,0x03,0xCD,
0x80,0x8E,0x93,0x70,0xCD,0x9F,0xC1,0xCD,0x9F,0x9B,0x72,0x1C,0x50,0x5B,0x72,0x1D,0x50,0x5C,0x72,0x5F,0x9F,0xFC,0x72,0x5F,0x9F,0xFD,0x72,0x5F,0x9F,0xFE,0x72,0x5F,0x9F,0xFF,
0xA0,0x8E,0xCD,0x9F,0xC1,0xC6,0x50,0x5F,0xA5,0x05,0x27,0xF9,0xCC,0x93,0x70,0xA6,0x01,0xCD,0x94,0x82,0xA6,0x14,0xCD,0x9E,0xA4,0xA6,0xC8,0xCD,0x93,0x1B,0x4F,0xCC,0x95,0x1B,
0xC0,0x8E,0xCD,0x99,0xED,0x3B,0x00,0x0A,0xBF,0x08,0xC6,0x52,0x30,0xB7,0x0A,0xCD,0x9F,0xC1,0x20,0x08,0xCD,0x9F,0xC1,0xC6,0x52,0x30,0xB7,0x0A,0xB6,0x0A,0xA5,0x20,0x27,0xF2,
0xE0,0x8E,0xB6,0x0A,0xA5,0x09,0x27,0x09,0xC6,0x52,0x31,0x92,0xC7,0x08,0x4F,0x20,0x08,0xC6,0x52,0x31,0x92,0xC7,0x08,0xA6,0x01,0x32,0x00,0x0A,0xCC,0x9A,0x85,0x72,0x5F,0x52,
0x00,0x8F,0x34,0x72,0x5F,0x52,0x36,0x72,0x5F,0x52,0x33,0x72,0x5F,0x52,0x32,0x72,0x5F,0x52,0x35,0x81,0x72,0x5F,0x50,0x12,0x72,0x5F,0x50,0x13,0x35,0x02,0x50,0x11,0x72,0x19,
0x20,0x8F,0x52,0x34,0xC6,0x52,0x36,0xC7,0x52,0x36,0x35,0x01,0x52,0x33,0x35,0x34,0x52,0x32,0xC6,0x52,0x35,0xAA,0x0C,0xC7,0x52,0x35,0x81,0xCD,0x99,0xED,0xBF,0x08,0xCD,0x92,
0x40,0x8F,0x4D,0xBE,0x08,0xCD,0x92,0x33,0xA1,0x00,0x26,0x04,0x4F,0xCC,0x9A,0x85,0xBE,0x08,0x1C,0x00,0x08,0xF6,0x48,0x88,0xBE,0x08,0x1C,0x00,0x07,0xF6,0x48,0x48,0xB7,0x01,
0x60,0x8F,0x84,0xBA,0x01,0xBE,0x08,0x1C,0x00,0x09,0xFA,0x90,0x5F,0x90,0x97,0xAE,0x00,0x52,0xBF,0x00,0x93,0xCD,0x9C,0x69,0x1C,0x03,0xD4,0xCF,0x00,0x26,0xCE,0x00,0x26,0x1C,
0x80,0x8F,0xFF,0xCF,0xCF,0x00,0x24,0xCE,0x00,0x24,0xA3,0x04,0xEB,0x2F,0x06,0xAE,0x04,0xEA,0xCF,0x00,0x24,0xCE,0x00,0x26,0xA3,0x05,0x1C,0x2F,0x06,0xAE,0x05,0x1B,0xCF,0x00,
0xA0,0x8F,0x26,0xA6,0x01,0xCC,0x9A,0x85,0x72,0x5F,0x00,0x1F,0x72,0x5F,0x00,0x20,0x35,0x01,0x00,0x21,0x35,0x01,0x00,0x22,0xAE,0x00,0x1C,0xCC,0x92,0x9B,0x35,0x01,0x00,0x1F,
0xC0,0x8F,0x72,0x5F,0x00,0x20,0x72,0x5F,0x00,0x21,0x35,0x01,0x00,0x22,0xAE,0x00,0x1C,0xCC,0x92,0x9B,0xCD,0x99,0xED,0xBF,0x08,0xCD,0x92,0x4D,0xBE,0x08,0xCD,0x92,0x33,0xA1,
0xE0,0x8F,0x00,0x27,0x08,0xBE,0x08,0x1C,0x00,0x03,0x7D,0x26,0x04,0x4F,0xCC,0x9A,0x85,0xA6,0x01,0xCC,0x9A,0x85,0x72,0x5F,0x00,0x1F,0x35,0x01,0x00,0x20,0x35,0x01,0x00,0x21,
0x00,0x90,0x72,0x5F,0x00,0x22,0xAE,0x00,0x1C,0xCC,0x92,0x9B,0xCD,0x99,0xED,0xBF,0x08,0xCD,0x92,0x4D,0xBE,0x08,0xCD,0x92,0x33,0xA1,0x00,0x26,0x04,0x4F,0xCC,0x9A,0x85,0xBE,
0x20,0x90,0x08,0x1C,0x00,0x04,0x7D,0x26,0x0D,0xBE,0x08,0x1C,0x00,0x05,0x7D,0x27,0x05,0xA6,0x02,0xCC,0x9A,0x85,0xA6,0x01,0xCC,0x9A,0x85,0x35,0x01,0x00,0x1F,0x72,0x5F,0x00,
0x40,0x90,0x20,0x72,0x5F,0x00,0x21,0x72,0x5F,0x00,0x22,0xAE,0x00,0x1C,0xCC,0x92,0x9B,0xCD,0x99,0xED,0xBF,0x08,0xCD,0x92,0x4D,0xBE,0x08,0xCD,0x92,0x33,0xA1,0x00,0x27,0x15,
0x60,0x90,0xBE,0x08,0x1C,0x00,0x04,0x7D,0x26,0x0D,0xBE,0x08,0x1C,0x00,0x05,0x7D,0x27,0x05,0xA6,0x01,0xCC,0x9A,0x85,0x4F,0xCC,0x9A,0x85,0xC6,0x9F,0xFC,0xB7,0x00,0x44,0x44,
0x80,0x90,0x44,0xA4,0x01,0xC7,0x00,0x1F,0xB6,0x00,0x44,0x44,0xA4,0x01,0xC7,0x00,0x20,0xB6,0x00,0x44,0xA4,0x01,0xC7,0x00,0x21,0xB6,0x00,0xA4,0x01,0xC7,0x00,0x22,0xAE,0x00,
0xA0,0x90,0x1C,0xCC,0x92,0x9B,0xCD,0x99,0xED,0xBF,0x08,0xCD,0x92,0x4D,0xBE,0x08,0xCD,0x92,0x33,0xA1,0x00,0x26,0x05,0xA6,0x02,0xCC,0x9A,0x85,0xBE,0x08,0x1C,0x00,0x04,0xF6,
0xC0,0x90,0xC7,0x00,0x2D,0xBE,0x08,0x1C,0x00,0x03,0x7D,0x26,0x04,0x4F,0xCC,0x9A,0x85,0xBE,0x08,0x1C,0x00,0x05,0xF6,0x4E,0xA4,0xF0,0xC7,0x00,0x29,0xBE,0x08,0x1C,0x00,0x06,
0xE0,0x90,0xF6,0x48,0x48,0x48,0xCA,0x00,0x29,0xC7,0x00,0x29,0xBE,0x08,0x1C,0x00,0x07,0xF6,0x48,0x48,0xCA,0x00,0x29,0xC7,0x00,0x29,0xBE,0x08,0x1C,0x00,0x08,0xF6,0x48,0xCA,
0x00,0x91,0x00,0x29,0xC7,0x00,0x29,0xBE,0x08,0x1C,0x00,0x09,0xF6,0xCA,0x00,0x29,0xC7,0x00,0x29,0xA6,0x01,0xCC,0x9A,0x85,0x72,0x5F,0x00,0x1F,0x35,0x01,0x00,0x20,0x72,0x5F,
0x20,0x91,0x00,0x21,0x72,0x5F,0x00,0x22,0xAE,0x00,0x1C,0xCC,0x92,0x9B,0xCD,0x99,0xED,0xBF,0x08,0xCD,0x92,0x4D,0xBE,0x08,0xCD,0x92,0x33,0xA1,0x00,0x27,0x28,0xBE,0x08,0x1C,
0x40,0x91,0x00,0x04,0xF6,0x48,0xBE,0x08,0x1C,0x00,0x05,0xFA,0xA1,0x03,0x26,0x05,0xA6,0x02,0xCC,0x9A,0x85,0xA1,0x02,0x26,0x05,0xA6,0x03,0xCC,0x9A,0x85,0xA1,0x01,0x26,0x05,
0x60,0x91,0xA6,0x01,0xCC,0x9A,0x85,0x4F,0xCC,0x9A,0x85,0x72,0x5F,0x00,0x1F,0x72,0x5F,0x00,0x20,0x35,0x01,0x00,0x21,0x72,0x5F,0x00,0x22,0xAE,0x00,0x1C,0xCC,0x92,0x9B,0xCD,
0x80,0x91,0x99,0xED,0xBF,0x08,0xCD,0x92,0x4D,0xBE,0x08,0xCD,0x92,0x33,0xA1,0x00,0x26,0x03,0xCC,0x92,0x19,0xBE,0x08,0x1C,0x00,0x03,0x7D,0x27,0x7E,0xBE,0x08,0x1C,0x00,0x05,
0xA0,0x91,0xF6,0x5F,0x97,0xCD,0x9C,0xA9,0xBF,0x00,0xBE,0x08,0x1C,0x00,0x04,0xF6,0x5F,0x97,0xCD,0x9C,0xA8,0x01,0xBA,0x01,0x01,0xBA,0x00,0x01,0x90,0x93,0xBE,0x08,0x1C,0x00,
0xC0,0x91,0x06,0xF6,0x5F,0x97,0x58,0x58,0x58,0xBF,0x00,0x93,0x01,0xBA,0x01,0x01,0xBA,0x00,0x01,0x90,0x93,0xBE,0x08,0x1C,0x00,0x07,0xF6,0x5F,0x97,0x58,0x58,0xBF,0x00,0x93,
0xE0,0x91,0x01,0xBA,0x01,0x01,0xBA,0x00,0x01,0x90,0x93,0xBE,0x08,0x1C,0x00,0x08,0xF6,0x5F,0x97,0x58,0xBF,0x00,0x93,0x01,0xBA,0x01,0x01,0xBA,0x00,0x01,0x90,0xBE,0x08,0x72,
0x00,0x92,0xA9,0x00,0x09,0x90,0xF6,0x90,0x5F,0x90,0x97,0x90,0xBF,0x00,0x01,0xBA,0x01,0x02,0xCD,0x9C,0xA9,0x1C,0x0D,0x4C,0xCC,0x9A,0x85,0x5F,0xCC,0x9A,0x85,0x72,0x5F,0x00,
0x20,0x92,0x1F,0x72,0x5F,0x00,0x20,0x72,0x5F,0x00,0x21,0x35,0x01,0x00,0x22,0xAE,0x00,0x1C,0xCC,0x92,0x9B,0xF6,0xA1,0x01,0x26,0x13,0x90,0x93,0x90,0x5C,0x90,0x7D,0x26,0x0B,
0x40,0x92,0x1C,0x00,0x02,0xF6,0xA1,0x01,0x26,0x03,0xA6,0x01,0x81,0x4F,0x81,0xCD,0x9A,0x2A,0x3B,0x00,0x0C,0xBF,0x08,0xCD,0x94,0xD9,0xCD,0x9F,0x52,0x3F,0x0C,0x20,0x19,0xCD,
0x60,0x92,0x9F,0x6C,0x5F,0x41,0xB6,0x0C,0x41,0x72,0xBB,0x00,0x08,0xBF,0x0A,0xCD,0x94,0xA0,0x92,0xC7,0x0A,0xB6,0x0C,0x4C,0xB7,0x0C,0xB6,0x0C,0xA1,0x0A,0x24,0x17,0x4F,0xCD,
0x80,0x92,0x94,0xE6,0xCD,0x9F,0x45,0xA6,0x01,0xCD,0x94,0xE6,0x3D,0x0C,0x26,0xD1,0xA6,0x04,0xCD,0x9E,0xA4,0x20,0xCD,0x32,0x00,0x0C,0xCC,0x9A,0x7A,0xCD,0x99,0xED,0x3B,0x00,
0xA0,0x92,0x0A,0xBF,0x08,0xCD,0x94,0xC8,0xCD,0x94,0xF3,0xCD,0x9F,0x52,0x3F,0x0A,0x20,0x21,0x4F,0xCD,0x94,0xE6,0x5F,0x41,0xB6,0x0A,0x41,0x72,0xBB,0x00,0x08,0xF6,0xCD,0x94,
0xC0,0x92,0xAA,0xCD,0x9F,0x45,0xA6,0x01,0xCD,0x94,0xE6,0xCD,0x9F,0x6C,0xB6,0x0A,0x4C,0xB7,0x0A,0xB6,0x0A,0xA1,0x08,0x25,0xD9,0x32,0x00,0x0A,0xCC,0x9A,0x85,0xC6,0x00,0x28,
0xE0,0x92,0xA1,0xFF,0x27,0x07,0xC6,0x00,0x28,0x4C,0xC7,0x00,0x28,0xAE,0x00,0x28,0x35,0x01,0x00,0x00,0x4F,0xCC,0x9A,0x96,0x4D,0x26,0x0A,0xA6,0x04,0xCD,0x93,0x29,0xA3,0x04,
0x00,0x93,0xC7,0x25,0x17,0xC6,0x00,0x28,0x27,0x07,0xC6,0x00,0x28,0x4A,0xC7,0x00,0x28,0xAE,0x00,0x28,0x35,0x01,0x00,0x00,0x4F,0xCD,0x9A,0x96,0x81,0xC7,0x00,0x28,0xAE,0x00,
0x20,0x93,0x28,0x35,0x01,0x00,0x00,0x4F,0xCC,0x9A,0x96,0xCD,0x9A,0x2A,0xB7,0x08,0xA6,0x03,0xCD,0x93,0x59,0xBF,0x0A,0x26,0x04,0x5F,0x5C,0xBF,0x0A,0xB6,0x08,0xCD,0x93,0x59,
0x40,0x93,0xBF,0x02,0x5F,0xBF,0x00,0xBF,0x08,0xCD,0x98,0x07,0x00,0x00,0x09,0xC4,0xCD,0x9A,0x89,0xCD,0x98,0x91,0xBE,0x02,0xCC,0x9A,0x7A,0xCD,0x99,0xED,0xB7,0x08,0xCD,0x9F,
0x60,0x93,0xC1,0xB6,0x08,0xCD,0x9C,0xAE,0xBF,0x08,0xCD,0x9F,0xC1,0xBE,0x08,0xCC,0x9A,0x85,0x35,0x7F,0x50,0xD2,0x35,0x80,0x50,0xD1,0x35,0x7F,0x50,0xD2,0x81,0xCD,0x95,0x28,
0x80,0x93,0xCD,0x95,0x0E,0xCD,0x94,0xD9,0xCD,0x94,0x71,0xCD,0x94,0x8F,0xCD,0x94,0xC8,0xCD,0x94,0xF3,0xA6,0x01,0xCD,0x94,0xAA,0xA6,0x01,0xCD,0x94,0xE6,0xCD,0x94,0x53,0x35,
0xA0,0x93,0x01,0x00,0x1C,0x72,0x5F,0x00,0x1D,0x35,0x01,0x00,0x1E,0x72,0x5F,0x00,0x2A,0x72,0x5F,0x00,0x2B,0x72,0x5F,0x00,0x2D,0x72,0x5F,0x00,0x2F,0x81,0x8A,0x84,0xA4,0xBF,
0xC0,0x93,0x88,0x86,0xCD,0x9A,0x20,0xCD,0x9A,0x25,0xC6,0x00,0x2A,0xA1,0x01,0x27,0x5E,0xC6,0x00,0x2B,0x4C,0xC7,0x00,0x2B,0xC6,0x00,0x2B,0xA1,0x33,0x24,0x50,0xA6,0x02,0xCD,
0xE0,0x93,0x95,0x39,0xCD,0x95,0x04,0xB7,0x00,0xC6,0x00,0x10,0xA1,0x02,0x26,0x05,0xB6,0x00,0xC7,0x00,0x10,0x3D,0x00,0x26,0x07,0xC6,0x00,0x10,0xA1,0x01,0x27,0x0B,0xB6,0x00,
0x00,0x94,0xA1,0x01,0x26,0x0C,0xC6,0x00,0x10,0x26,0x07,0xC6,0x00,0x2C,0x4C,0xC7,0x00,0x2C,0xC6,0x00,0x2C,0xA1,0x14,0x25,0x11,0x72,0x5F,0x00,0x2C,0x35,0x02,0x00,0x10,0x35,
0x20,0x94,0x01,0x00,0x2A,0xCD,0x94,0x34,0x20,0x05,0xB6,0x00,0xC7,0x00,0x10,0xCD,0x9A,0x5C,0xCD,0x9A,0x51,0x80,0xCD,0x94,0xF3,0xA6,0x62,0xCC,0x95,0x39,0x9B,0x72,0x1B,0x50,
0x40,0x94,0x11,0x72,0x1B,0x50,0x12,0x72,0x1A,0x50,0x13,0xC6,0x50,0xA0,0xA4,0x3F,0xC7,0x50,0xA0,0x9B,0x81,0x9B,0x72,0x1B,0x50,0x11,0x72,0x1B,0x50,0x12,0x72,0x1A,0x50,0x13,
0x60,0x94,0xC6,0x50,0xA0,0xA4,0x3F,0xC7,0x50,0xA0,0x72,0x1C,0x50,0xA0,0x9A,0x81,0xCC,0x94,0xB7,0x72,0x1E,0x50,0x0C,0x72,0x1E,0x50,0x0D,0x72,0x1F,0x50,0x0E,0x72,0x1F,0x50,
0x80,0x94,0x0A,0x81,0x4D,0x27,0x05,0x72,0x16,0x50,0x0A,0x81,0x72,0x17,0x50,0x0A,0x81,0x72,0x16,0x50,0x0C,0x72,0x16,0x50,0x0D,0x72,0x17,0x50,0x0E,0x72,0x17,0x50,0x0A,0x81,
0xA0,0x94,0x72,0x0D,0x50,0x10,0x03,0xA6,0x01,0x81,0x4F,0x81,0x4D,0x27,0x05,0x72,0x1C,0x50,0x0F,0x81,0x72,0x1D,0x50,0x0F,0x81,0x72,0x1C,0x50,0x11,0x72,0x1C,0x50,0x12,0x72,
0xC0,0x94,0x1D,0x50,0x13,0x72,0x1C,0x50,0x0F,0x81,0x72,0x1C,0x50,0x11,0x72,0x1C,0x50,0x12,0x72,0x1D,0x50,0x13,0x72,0x1D,0x50,0x0F,0x81,0x72,0x1D,0x50,0x11,0x72,0x1D,0x50,
0xE0,0x94,0x12,0x72,0x1D,0x50,0x13,0x81,0x4D,0x27,0x05,0x72,0x1A,0x50,0x0F,0x81,0x72,0x1B,0x50,0x0F,0x81,0x72,0x1A,0x50,0x11,0x72,0x1A,0x50,0x12,0x72,0x1B,0x50,0x13,0x72,
0x00,0x95,0x1B,0x50,0x0F,0x81,0x72,0x0B,0x50,0x10,0x03,0xA6,0x01,0x81,0x4F,0x81,0x72,0x1B,0x50,0x11,0x72,0x1B,0x50,0x12,0x72,0x1B,0x50,0x13,0x81,0x4D,0x27,0x05,0x72,0x18,
0x20,0x95,0x50,0x0F,0x81,0x72,0x19,0x50,0x0F,0x81,0x72,0x18,0x50,0x11,0x72,0x18,0x50,0x12,0x72,0x19,0x50,0x13,0x72,0x19,0x50,0x0F,0x81,0xCD,0x99,0xED,0xB7,0x09,0x3F,0x08,
0x40,0x95,0x4F,0xB7,0x08,0xB6,0x08,0xB1,0x09,0x24,0x0B,0xCD,0x9F,0x6C,0xB6,0x08,0xAB,0x01,0xB7,0x08,0x20,0xEF,0xCC,0x9A,0x85,0xCD,0x9A,0x2A,0xCD,0x9A,0x2F,0x52,0x05,0x4F,
0x60,0x95,0x6B,0x03,0x6B,0x02,0x3F,0x0C,0x3F,0x0D,0x6B,0x01,0x3F,0x0A,0x3F,0x0B,0xCD,0x9F,0xC1,0xA6,0x28,0xCD,0x9E,0xA4,0xCD,0x8F,0xA6,0xAE,0x00,0x12,0xCD,0x8F,0x39,0xA1,
0x80,0x95,0x00,0x26,0x03,0xCD,0x93,0x70,0x4F,0xCD,0x94,0x82,0xC6,0x00,0x29,0x90,0x5F,0x90,0x97,0xAE,0x00,0x05,0xBF,0x00,0x93,0xCD,0x9C,0x69,0x1C,0x01,0x04,0x1F,0x04,0x20,
0xA0,0x95,0x10,0x0D,0x01,0x26,0x03,0xCD,0x8E,0xAD,0xA6,0x01,0x6B,0x01,0xA6,0x1E,0xCD,0x9E,0xA4,0xCD,0x9F,0xC1,0xA6,0x0F,0xCD,0x9E,0xA4,0xCD,0x92,0x1D,0xAE,0x00,0x12,0xCD,
0xC0,0x95,0x91,0x7F,0xBF,0x08,0x26,0x03,0xCC,0x97,0x01,0xA3,0x11,0x2C,0x26,0x06,0x35,0x01,0x00,0x0A,0x20,0x13,0x3D,0x0A,0x27,0x0B,0xA3,0x0D,0x9C,0x26,0x06,0x35,0x01,0x00,
0xE0,0x95,0x0B,0x20,0x04,0x3F,0x0A,0x3F,0x0B,0x3D,0x0A,0x27,0x04,0x3D,0x0B,0x26,0xB2,0x0D,0x01,0x26,0xAE,0xB6,0x0D,0xA1,0x1E,0x24,0x06,0x4C,0xB7,0x0D,0xCC,0x96,0x82,0x3F,
0x00,0x96,0x0D,0xA6,0x02,0xCD,0x93,0x29,0x1C,0xFE,0x16,0x90,0xAE,0x00,0x52,0xCD,0x9C,0x87,0xA3,0x00,0x00,0x2F,0x10,0x1C,0x00,0x07,0xBF,0x00,0x1E,0x04,0x57,0x57,0xCD,0x9C,
0x20,0x96,0x69,0xBF,0x0E,0x20,0x08,0x1E,0x04,0x57,0x72,0xFB,0x04,0xBF,0x0E,0xCD,0x9F,0x52,0xA6,0x04,0xCD,0x93,0x29,0xBF,0x02,0xAE,0x00,0x0B,0xBF,0x00,0xBE,0x02,0xCD,0x9C,
0x40,0x96,0x69,0x90,0xAE,0x00,0x0E,0xCD,0x9C,0x87,0x90,0x93,0xBE,0x02,0x58,0xBF,0x00,0x93,0x72,0xBB,0x00,0x00,0xBF,0x00,0xBE,0x0E,0x72,0xBB,0x00,0x08,0xB3,0x00,0x2E,0x20,
0x60,0x96,0xB6,0x0C,0x4C,0xB7,0x0C,0xA1,0x0B,0x25,0x19,0xCD,0x8F,0xBC,0x4F,0xCD,0x94,0xE6,0xCD,0x9F,0x52,0xA6,0x01,0xCD,0x94,0xE6,0xCD,0x9F,0x52,0xCD,0x93,0x70,0x20,0x02,
0x80,0x96,0x3F,0x0C,0xA6,0x08,0xCD,0x9E,0xA4,0x0D,0x03,0x27,0x0F,0xA6,0x01,0x90,0xAE,0x02,0xF0,0xAE,0x02,0x8E,0xCD,0x8C,0xC7,0xCC,0x95,0xB1,0x0D,0x02,0x27,0x1E,0xBE,0x08,
0xA0,0x96,0xA3,0x10,0xE1,0x2E,0x17,0xCE,0x00,0x26,0xA3,0x04,0x36,0x2E,0x2A,0xA6,0x01,0x90,0xCE,0x00,0x26,0xCE,0x00,0x24,0xCD,0x8C,0xC7,0xCC,0x95,0xB1,0xBE,0x08,0xA3,0x10,
0xC0,0x96,0xCC,0x2F,0xEA,0x1C,0xEF,0x34,0xA3,0x00,0x15,0x24,0x1B,0xA6,0x01,0x6B,0x02,0xCE,0x00,0x26,0xA3,0x04,0x36,0x2F,0xD6,0xA6,0x01,0x90,0xAE,0x04,0x36,0xAE,0x03,0xD4,
0xE0,0x96,0xCD,0x8C,0xC7,0xCC,0x95,0xB1,0xBE,0x08,0xA3,0x10,0xE1,0x2E,0x03,0xCC,0x95,0xB1,0xA6,0x01,0x6B,0x03,0x90,0xAE,0x02,0xF0,0xAE,0x02,0x8E,0xCD,0x8C,0xC7,0xCC,0x95,
0x00,0x97,0xB1,0xCD,0x93,0x70,0xCC,0x95,0xB1,0xCD,0x9A,0x2A,0xCD,0x99,0xF2,0x3B,0x00,0x0E,0x3F,0x0C,0x3F,0x0E,0x3F,0x0D,0x3F,0x0B,0x3F,0x0A,0xCD,0x9F,0x33,0xA6,0x01,0xCD,
0x20,0x97,0x94,0x82,0xA6,0xFF,0xCD,0x93,0x1B,0xA6,0x14,0xCD,0x9E,0xA4,0x4F,0xCD,0x94,0x82,0xCD,0x9F,0xC1,0xA6,0xC8,0xCD,0x9E,0xA4,0xA6,0xC8,0xCD,0x9E,0xA4,0xCD,0x9F,0xC1,
0x40,0x97,0xA6,0xC8,0xCD,0x9E,0xA4,0xA6,0xB4,0xCD,0x9E,0xA4,0xA6,0x01,0xCD,0x95,0x1B,0x20,0x0D,0xCD,0x94,0x6E,0x3F,0x0C,0x3F,0x0E,0x3F,0x0D,0x72,0x5F,0x00,0x2E,0xCD,0x9F,
0x60,0x97,0xC1,0xCD,0x8E,0xFD,0x4F,0x90,0xAE,0x03,0x10,0xAE,0x02,0x8E,0xCD,0x8C,0xC7,0xA6,0x14,0xCD,0x9E,0xA4,0xA6,0x02,0xCD,0x93,0x29,0xBF,0x08,0xA3,0x00,0x41,0x2E,0x20,
0x80,0x97,0xB6,0x0B,0x4C,0xB7,0x0B,0xA1,0x03,0x25,0x19,0x35,0x03,0x00,0x0B,0x72,0x5F,0x00,0x2B,0x72,0x5F,0x00,0x2A,0x3F,0x0A,0x72,0x5F,0x00,0x2C,0xCD,0x94,0x53,0x20,0x02,
0xA0,0x97,0x3F,0x0B,0xBE,0x08,0xA3,0x01,0x46,0x2E,0x05,0xC6,0x00,0x2A,0x27,0xA3,0x3D,0x0E,0x26,0x12,0xB6,0x0D,0xA1,0xC8,0x24,0xA6,0xCD,0x9F,0x84,0xB7,0x0E,0xB6,0x0D,0x4C,
0xC0,0x97,0xB7,0x0D,0x20,0x9A,0xC6,0x00,0x2A,0x26,0x11,0xB6,0x0C,0xA1,0x64,0x24,0x05,0x4C,0xB7,0x0C,0x20,0x8A,0x35,0x64,0x00,0x0C,0x20,0x15,0x3D,0x0A,0x26,0x11,0x35,0x01,
0xE0,0x97,0x00,0x0A,0xA6,0xC8,0xCD,0x9E,0xA4,0xA6,0xC8,0xCD,0x9E,0xA4,0xCD,0x9F,0xC1,0xCD,0x94,0x3C,0xCD,0x98,0xFE,0xA1,0x00,0x27,0x08,0xA6,0x50,0xCD,0x9E,0xA4,0xCC,0x97,
0x00,0x98,0x5E,0x32,0x00,0x0E,0xCC,0x9A,0x7E,0xCD,0x9F,0x90,0x89,0xFE,0xBF,0x04,0x85,0xEE,0x02,0xBF,0x06,0xB6,0x00,0xBE,0x06,0x42,0x9F,0xB7,0x00,0xB6,0x01,0xBE,0x05,0x42,
0x20,0x98,0x9F,0xBB,0x00,0xB7,0x00,0xB6,0x02,0xBE,0x04,0x42,0x9F,0xBB,0x00,0xB7,0x00,0xB6,0x03,0xBE,0x03,0x42,0x9F,0xBB,0x00,0xB7,0x00,0xB6,0x01,0xBE,0x06,0x42,0x3F,0x01,
0x40,0x98,0x72,0xBB,0x00,0x00,0xBF,0x00,0xB6,0x02,0xBE,0x05,0x42,0x72,0xBB,0x00,0x00,0xBF,0x00,0xB6,0x03,0xBE,0x04,0x42,0x72,0xBB,0x00,0x00,0xBF,0x00,0xB6,0x02,0xBE,0x06,
0x60,0x98,0x42,0x3F,0x02,0x72,0xBB,0x00,0x01,0xBF,0x01,0x24,0x02,0x3C,0x00,0xB6,0x03,0xBE,0x05,0x42,0x72,0xBB,0x00,0x01,0xBF,0x01,0x24,0x02,0x3C,0x00,0xB6,0x03,0xBE,0x06,
0x80,0x98,0x42,0x3F,0x03,0x72,0xBB,0x00,0x02,0xBF,0x02,0x24,0x05,0xBE,0x00,0x5C,0xBF,0x00,0x81,0xBE,0x00,0x26,0x1E,0x90,0xBE,0x04,0x26,0x0C,0xBE,0x02,0x90,0xBE,0x06,0x65,
0xA0,0x98,0xBF,0x02,0x90,0xBF,0x06,0x81,0xBF,0x04,0x45,0x02,0x06,0x45,0x03,0x07,0xBF,0x00,0xBF,0x02,0x81,0xA6,0x20,0x3D,0x00,0x26,0x0D,0xBE,0x01,0xBF,0x00,0x45,0x03,0x02,
0xC0,0x98,0x3F,0x03,0x3A,0x03,0xA0,0x08,0x5F,0x90,0x5F,0x99,0x20,0x17,0x90,0x59,0x59,0xB3,0x04,0x26,0x03,0x90,0xB3,0x06,0x25,0x0B,0x72,0xB2,0x00,0x06,0x24,0x01,0x5A,0x72,
0xE0,0x98,0xB0,0x00,0x04,0x39,0x03,0x39,0x02,0x39,0x01,0x39,0x00,0x4A,0x2A,0xDE,0xBF,0x04,0x90,0xBF,0x06,0xBE,0x00,0x53,0xBF,0x00,0xBE,0x02,0x53,0xBF,0x02,0x81,0xCD,0x9F,
0x00,0x99,0xC1,0xCD,0x91,0x16,0xAE,0x00,0x12,0xCD,0x90,0xA4,0x4D,0x26,0x1C,0xC6,0x00,0x2D,0x26,0x03,0xCC,0x99,0xEA,0xA6,0x1E,0xCD,0x9E,0xA4,0xCD,0x90,0x79,0xAE,0x00,0x12,
0x20,0x99,0xCD,0x90,0x4F,0xC7,0x00,0x2E,0xCC,0x99,0xEA,0xA1,0x01,0x27,0x03,0xCC,0x99,0xEA,0xC6,0x00,0x2E,0x27,0x23,0xA6,0x1E,0xCD,0x9E,0xA4,0xCD,0x90,0x39,0xAE,0x00,0x12,
0x40,0x99,0xCD,0x90,0x0A,0xA1,0x02,0x26,0x0B,0x35,0x01,0x00,0x2F,0xA6,0x01,0xCD,0x8E,0x74,0x20,0x06,0x4D,0x26,0x03,0xCD,0x93,0x70,0xA6,0x1E,0xCD,0x9E,0xA4,0xC6,0x00,0x29,
0x60,0x99,0xA1,0x05,0x26,0x31,0xA6,0xFF,0xCD,0x93,0x1B,0x20,0x0E,0x35,0x02,0x00,0x11,0xA6,0x50,0xCD,0x9E,0xA4,0xA6,0x01,0xCD,0x8D,0xAE,0xCD,0x9F,0xC1,0xCD,0x8F,0xF4,0xAE,
0x80,0x99,0x00,0x12,0xCD,0x8F,0xD2,0xA1,0x00,0x26,0xE2,0xC6,0x00,0x11,0xA1,0x02,0x26,0x5A,0xCD,0x93,0x70,0x20,0xE4,0xA6,0x01,0xCD,0x94,0x82,0xA6,0x0A,0xCD,0x9E,0xA4,0xA6,
0xA0,0x99,0xEB,0xCD,0x93,0x1B,0xA6,0x0A,0xCD,0x9E,0xA4,0xA6,0xDC,0xCD,0x93,0x1B,0xA6,0x0A,0xCD,0x9E,0xA4,0xA6,0xCD,0xCD,0x93,0x1B,0xA6,0x0A,0xCD,0x9E,0xA4,0xA6,0xBE,0xCD,
0xC0,0x99,0x93,0x1B,0xA6,0x0A,0xCD,0x9E,0xA4,0xA6,0xAF,0xCD,0x93,0x1B,0xA6,0x0A,0xCD,0x9E,0xA4,0xA6,0xA0,0xCD,0x93,0x1B,0xA6,0x14,0xCD,0x9E,0xA4,0xCD,0x8C,0x80,0xA1,0x00,
0xE0,0x99,0x27,0x05,0xCD,0x95,0x57,0x4F,0x81,0xCD,0x93,0x70,0xA6,0x01,0x81,0x88,0xA6,0x08,0x20,0x05,0x88,0xA6,0x0C,0x20,0x00,0x88,0x7B,0x02,0x88,0x7B,0x02,0x89,0x1E,0x06,
0x00,0x9A,0x1F,0x04,0x5F,0x97,0xFE,0x1F,0x06,0x85,0x84,0x81,0x89,0x1E,0x05,0xBF,0x08,0x20,0x07,0x89,0x1E,0x05,0xBF,0x0C,0x20,0x00,0x1E,0x03,0x1F,0x05,0x85,0x5B,0x02,0x81,
0x20,0x9A,0x88,0xA6,0x00,0x20,0x0F,0x88,0xA6,0x04,0x20,0x0A,0x88,0xA6,0x08,0x20,0x05,0x88,0xA6,0x0C,0x20,0x00,0x88,0x89,0x7B,0x04,0x88,0x7B,0x04,0x89,0x1E,0x08,0x1F,0x04,
0x40,0x9A,0x5F,0x97,0x1F,0x08,0xFE,0x1F,0x06,0x1E,0x08,0x5C,0x5C,0xFE,0x1F,0x08,0x85,0x84,0x81,0x89,0x1E,0x05,0xBF,0x00,0x1E,0x07,0xBF,0x02,0x20,0x16,0x89,0x1E,0x05,0xBF,
0x60,0x9A,0x04,0x1E,0x07,0xBF,0x06,0x20,0x0B,0x89,0x1E,0x05,0xBF,0x08,0x1E,0x07,0xBF,0x0A,0x20,0x00,0x1E,0x03,0x1F,0x07,0x85,0x5B,0x04,0x81,0xCD,0x9A,0x67,0x81,0xCD,0x9A,
0x80,0x9A,0x11,0xCD,0x9A,0x67,0x81,0xCD,0x9A,0x0A,0x81,0x45,0x08,0x04,0x45,0x09,0x05,0x45,0x0A,0x06,0x45,0x0B,0x07,0x81,0xCD,0x9A,0x2A,0xB7,0x0A,0x45,0x00,0x0B,0xBF,0x08,
0xA0,0x9A,0xCD,0x9F,0xC1,0x72,0x03,0x52,0x19,0x0B,0x72,0x12,0x52,0x11,0x72,0x02,0x52,0x11,0xFB,0x20,0xF0,0x72,0x10,0x52,0x11,0x72,0x01,0x52,0x17,0xFB,0x35,0x58,0x52,0x16,
0xC0,0x9A,0xCD,0x9F,0xC1,0x72,0x03,0x52,0x17,0xFB,0xC6,0x52,0x19,0x72,0x0F,0x52,0x17,0xFB,0xB6,0x0A,0xC7,0x52,0x16,0x3D,0x0B,0x26,0x18,0x20,0x22,0x72,0x0F,0x52,0x17,0xFB,
0xE0,0x9A,0x9D,0x92,0xC6,0x08,0xC7,0x52,0x16,0x9D,0x3D,0x0B,0x27,0x05,0xBE,0x08,0x5C,0xBF,0x08,0x45,0x0B,0x00,0xB6,0x00,0x4A,0xB7,0x0B,0x3D,0x00,0x26,0xDE,0xC6,0x52,0x17,
0x00,0x9B,0xA4,0x84,0xA1,0x84,0x26,0xF7,0x72,0x12,0x52,0x11,0x72,0x02,0x52,0x11,0xFB,0xCD,0x9F,0xC1,0xCC,0x9A,0x7A,0x52,0x10,0x90,0xAE,0x9F,0xA4,0x96,0x5C,0x89,0xA6,0x08,
0x20,0x9B,0xCD,0x9F,0x5F,0x85,0x90,0xAE,0x9F,0xAC,0x96,0x1C,0x00,0x09,0x89,0xA6,0x08,0xCD,0x9F,0x5F,0x85,0x96,0x5C,0xCD,0x9D,0x2F,0x96,0x1C,0x00,0x09,0xCD,0x9B,0x80,0x7B,
0x40,0x9B,0x01,0xA1,0x09,0x26,0x34,0x35,0x01,0x00,0x02,0x20,0x24,0x90,0x5F,0x61,0x93,0x50,0xBF,0x00,0x96,0x1C,0x00,0x09,0x72,0xBB,0x00,0x00,0x1C,0x00,0x08,0xF6,0x96,0x5C,
0x60,0x9B,0x90,0xBF,0x00,0x72,0xBB,0x00,0x00,0xF1,0x26,0x0F,0xB6,0x02,0x4C,0xB7,0x02,0xB6,0x02,0xA1,0x08,0x25,0xD6,0xA6,0x01,0x20,0x04,0xCD,0x9C,0x17,0x4F,0x5B,0x10,0x81,
0x80,0x9B,0xCD,0x9A,0x2A,0x3B,0x00,0x0C,0xBF,0x08,0xCD,0x9B,0xD5,0x9D,0x9D,0xCD,0x9D,0x67,0xA6,0xCC,0xCD,0x9D,0x9E,0xA6,0x21,0xCD,0x9F,0xB4,0xA6,0xF0,0xCD,0x9D,0x9E,0xA6,
0xA0,0x9B,0x21,0xCD,0x9F,0xB4,0xA6,0x20,0xCD,0x9D,0x9E,0xA6,0x21,0xCD,0x9F,0xB4,0x4F,0xCD,0x9D,0x9E,0x3F,0x0C,0x20,0x13,0x5F,0x41,0x72,0xBB,0x00,0x08,0xBF,0x0A,0xCD,0x9D,
0xC0,0x9B,0xFE,0x92,0xC7,0x0A,0xB6,0x0C,0x4C,0xB7,0x0C,0xB6,0x0C,0xA1,0x08,0x25,0xE7,0x32,0x00,0x0C,0xCC,0x9A,0x7A,0xCD,0x9C,0x06,0xA6,0x01,0xCD,0x9B,0xF9,0xCD,0x9F,0x6C,
0xE0,0x9B,0x4F,0xCD,0x9B,0xF9,0xCD,0x9F,0x6C,0xA6,0x4B,0xCD,0x9F,0xB4,0xCC,0x9C,0x17,0x72,0x05,0x50,0x01,0x03,0xA6,0x01,0x81,0x4F,0x81,0x4D,0x27,0x05,0x72,0x14,0x50,0x00,
0x00,0x9C,0x81,0x72,0x15,0x50,0x00,0x81,0x72,0x14,0x50,0x02,0x72,0x14,0x50,0x03,0x72,0x15,0x50,0x04,0x72,0x15,0x50,0x00,0x81,0x72,0x15,0x50,0x02,0x72,0x15,0x50,0x03,0x72,
0x20,0x9C,0x15,0x50,0x04,0x81,0xC6,0x50,0x05,0xAA,0x30,0xC7,0x50,0x05,0xC6,0x50,0x07,0xAA,0x30,0xC7,0x50,0x07,0xC6,0x50,0x08,0xA4,0xCF,0xC7,0x50,0x08,0xC6,0x50,0x09,0xAA,
0x40,0x9C,0x30,0xC7,0x50,0x09,0x35,0x08,0x52,0x12,0x35,0x28,0x52,0x1B,0x72,0x5F,0x52,0x1C,0x35,0x09,0x52,0x1D,0x35,0xA2,0x52,0x13,0x72,0x1C,0x52,0x14,0x35,0x01,0x52,0x1A,
0x60,0x9C,0x72,0x14,0x52,0x11,0x72,0x10,0x52,0x10,0x81,0x88,0x89,0x5E,0xB6,0x01,0x42,0x89,0x1E,0x03,0xB6,0x00,0x42,0x72,0xFB,0x01,0x4F,0x02,0x89,0x1E,0x05,0xB6,0x01,0x42,
0x80,0x9C,0x72,0xFB,0x01,0x5B,0x06,0x84,0x81,0x5D,0x2B,0x06,0x90,0x5D,0x2B,0x0A,0x65,0x81,0x50,0x90,0x5D,0x2B,0x07,0x65,0x50,0x81,0x90,0x50,0x20,0xF9,0x90,0x50,0x20,0xEE,
0xA0,0x9C,0x4D,0x27,0x04,0x58,0x4A,0x26,0xFC,0x81,0x58,0x58,0x58,0x58,0x58,0x81,0x3B,0x00,0x08,0xB7,0x08,0xCD,0x9E,0x85,0xB6,0x08,0xCA,0x54,0x00,0xC7,0x54,0x00,0xA6,0x32,
0xC0,0x9C,0xB7,0x00,0x4A,0x3D,0x00,0x26,0xF9,0x72,0x10,0x54,0x01,0x72,0x0F,0x54,0x00,0xFB,0x72,0x1F,0x54,0x00,0xC6,0x54,0x05,0xB7,0x00,0xC6,0x54,0x04,0x5F,0x97,0x4F,0x02,
0xE0,0x9C,0x90,0x5F,0xB6,0x00,0x61,0xBF,0x00,0x93,0x02,0xBA,0x00,0x01,0x32,0x00,0x08,0x81,0x3B,0x00,0x08,0xB7,0x08,0xCD,0x9C,0x06,0xA6,0x01,0xCD,0x9B,0xF9,0x9D,0x4F,0xCD,
0x00,0x9D,0x9B,0xF9,0x3D,0x08,0x27,0x11,0xA6,0x03,0xCD,0x9F,0xB4,0xA6,0x01,0xCD,0x9B,0xF9,0xA6,0x21,0xCD,0x9F,0xB4,0x20,0x0F,0xA6,0x21,0xCD,0x9F,0xB4,0xA6,0x01,0xCD,0x9B,
0x20,0x9D,0xF9,0xA6,0x03,0xCD,0x9F,0xB4,0xA6,0x03,0xCD,0x9F,0xB4,0x32,0x00,0x08,0x81,0xCD,0x9A,0x2A,0x3B,0x00,0x0C,0xBF,0x08,0xCD,0x9B,0xD5,0xCD,0x9D,0x67,0x9D,0x9D,0xA6,
0x40,0x9D,0x33,0xCD,0x9D,0x9E,0x3F,0x0C,0x20,0x13,0x5F,0x41,0x72,0xBB,0x00,0x08,0xBF,0x0A,0xCD,0x9D,0xFE,0x92,0xC7,0x0A,0xB6,0x0C,0x4C,0xB7,0x0C,0xB6,0x0C,0xA1,0x08,0x25,
0x60,0x9D,0xE7,0x32,0x00,0x0C,0xCC,0x9A,0x7A,0xCD,0x99,0xED,0x3B,0x00,0x0A,0xAE,0x01,0x2C,0xBF,0x08,0x3F,0x0A,0x20,0x04,0x35,0x01,0x00,0x0A,0xBE,0x08,0xA3,0x00,0x01,0x2F,
0x80,0x9D,0x12,0x3D,0x0A,0x26,0x0E,0xCD,0x9B,0xEF,0xA1,0x00,0x27,0xEA,0xBE,0x08,0x5A,0xBF,0x08,0x20,0xE7,0xCD,0x9F,0x6C,0xB6,0x0A,0x32,0x00,0x0A,0xCC,0x9A,0x85,0xCD,0x99,
0xA0,0x9D,0xED,0x3B,0x00,0x0A,0xB7,0x0A,0x35,0x01,0x00,0x09,0x3F,0x08,0x20,0x11,0xB6,0x09,0xB4,0x0A,0xCD,0x9C,0xF0,0xB6,0x09,0x48,0xB7,0x09,0xB6,0x08,0x4C,0xB7,0x08,0xB6,
0xC0,0x9D,0x08,0xA1,0x08,0x25,0xE9,0xA6,0x37,0xCD,0x9F,0xB4,0x32,0x00,0x0A,0xCC,0x9A,0x85,0x3B,0x00,0x08,0xCD,0x9C,0x17,0x9D,0x9D,0x9D,0xCD,0x9C,0x06,0x4F,0xCD,0x9B,0xF9,
0xE0,0x9D,0x9D,0xCD,0x9C,0x17,0xA6,0x03,0xCD,0x9F,0xB4,0x9D,0x9D,0xCD,0x9B,0xEF,0xB7,0x08,0xA6,0x21,0xCD,0x9F,0xB4,0xCD,0x9C,0x17,0xB6,0x08,0x32,0x00,0x08,0x81,0xCD,0x99,
0x00,0x9E,0xED,0x3F,0x09,0x3F,0x08,0x20,0x14,0xCD,0x9D,0xD0,0x5F,0x97,0xB6,0x08,0xCD,0x9C,0xA0,0x9F,0xBA,0x09,0xB7,0x09,0xB6,0x08,0x4C,0xB7,0x08,0xB6,0x08,0xA1,0x08,0x25,
0x20,0x9E,0xE6,0xB6,0x09,0xCC,0x9A,0x85,0x89,0xFE,0x90,0x93,0x85,0x5C,0x5C,0x90,0x5D,0x27,0x1C,0x89,0xFE,0xBF,0x00,0x85,0x5C,0x5C,0x89,0xFE,0xBF,0x02,0x85,0x5C,0x5C,0x51,
0x40,0x9E,0x5A,0x92,0xD6,0x00,0x92,0xD7,0x02,0x5A,0x2A,0xF7,0x51,0x20,0xD9,0x81,0x72,0x15,0x50,0x11,0x72,0x15,0x50,0x12,0x72,0x15,0x50,0x13,0x72,0x17,0x50,0x11,0x72,0x17,
0x60,0x9E,0x50,0x12,0x72,0x17,0x50,0x13,0x72,0x19,0x50,0x0C,0x72,0x19,0x50,0x0D,0x72,0x19,0x50,0x0E,0x81,0x9E,0xC2,0x00,0x21,0x00,0x12,0x00,0x00,0x9E,0x26,0x00,0x02,0x9F,
0x80,0x9E,0xDC,0x00,0x10,0x00,0x00,0x72,0x5F,0x54,0x00,0xC6,0x54,0x01,0xA4,0x8F,0xC7,0x54,0x01,0xC6,0x54,0x01,0xC7,0x54,0x01,0x72,0x13,0x54,0x01,0x72,0x16,0x54,0x02,0x72,
0xA0,0x9E,0x10,0x54,0x01,0x81,0xCD,0x99,0xED,0xB7,0x09,0x3F,0x08,0x4F,0xB7,0x08,0xB6,0x08,0xB1,0x09,0x24,0x0B,0xCD,0x9F,0x78,0xB6,0x08,0xAB,0x01,0xB7,0x08,0x20,0xEF,0xCC,
0xC0,0x9E,0x9A,0x85,0x89,0xFE,0x90,0x93,0x85,0x5C,0x5C,0x90,0x5D,0x27,0x12,0x89,0xFE,0xBF,0x00,0x85,0x5C,0x5C,0x51,0x5A,0x92,0x6F,0x00,0x5A,0x2A,0xFA,0x51,0x20,0xE3,0x81,
0xE0,0x9E,0x90,0xAE,0x9E,0x73,0x20,0x0A,0x93,0x1C,0x00,0x02,0x90,0xFE,0x90,0xFD,0x90,0x93,0x90,0xA3,0x9E,0x85,0x26,0xF0,0x81,0x35,0xCC,0x50,0xE0,0x35,0x55,0x50,0xE0,0x35,
0x00,0x9F,0x06,0x50,0xE1,0x35,0xFF,0x50,0xE2,0x35,0xAA,0x50,0xE0,0x81,0xCD,0x99,0xED,0x52,0x02,0xBF,0x08,0xBE,0x08,0x1F,0x01,0x96,0x5C,0xA6,0x01,0xCD,0x9F,0xDB,0x20,0xF3,
0x20,0x9F,0xAE,0x03,0xFF,0x94,0xCD,0x9F,0xD2,0x5D,0x27,0x03,0xCD,0x9E,0xE0,0xCD,0x97,0x07,0xCC,0x9F,0xD5,0xCD,0x9F,0xBC,0xCD,0x8E,0xFD,0xCD,0x93,0x7D,0xCD,0x9E,0x4E,0xCD,
0x40,0x9F,0x9C,0x24,0xCC,0x9E,0xF7,0xA6,0x07,0xB7,0x00,0xB6,0x00,0xAB,0xFF,0x3D,0x00,0x26,0xF6,0x81,0xA6,0x1A,0xB7,0x00,0xB6,0x00,0xAB,0xFF,0x3D,0x00,0x26,0xF6,0x81,0x88,
0x60,0x9F,0x90,0xF6,0xF7,0x5C,0x90,0x5C,0x0A,0x01,0x26,0xF6,0x84,0x81,0xAE,0x00,0xFA,0x90,0x93,0x93,0x5A,0x90,0x5D,0x26,0xF8,0x81,0xAE,0x01,0xF4,0x90,0x93,0x93,0x5A,0x90,
0x80,0x9F,0x5D,0x26,0xF8,0x81,0xCD,0x9B,0x15,0xA1,0x01,0x26,0x03,0xA6,0x01,0x81,0x4F,0x81,0x1E,0x03,0x1C,0x00,0x04,0x1F,0x03,0x1D,0x00,0x04,0x81,0x35,0x56,0x50,0x62,0x35,
0xA0,0x9F,0xAE,0x50,0x62,0x81,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0x00,0x4A,0x3D,0x00,0x26,0xF9,0x81,0x35,0x02,0x50,0xC6,
0xC0,0x9F,0x81,0x35,0xAA,0x50,0xE0,0x81,0x89,0x85,0xCD,0x9F,0x0C,0x00,0x00,0x00,0x00,0xCC,0x9F,0xD8,0x5F,0x5C,0x81,0xCC,0x9F,0xC6,0x9D,0x20,0xFD,0x81,0x02,0x01,0x00,0x00,
0xE0,0x9F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0B,0x34,0x55,0x34,

};

#endif

