#ifndef __EASYPROTOCOL_H
#define __EASYPROTOCOL_H


#ifdef __cplusplus
extern "C" {

#endif

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;

#define MAX_DATA_LENGTH             32
#define FRAME_HEADER 				0xAA

//У�鷽��ѡ��
#define sum_model 					0
#define crc16_model                 1
#define check_model                 sum_model

//���ݴ���ģʽѡ��   ��λ�ȳ�? ��λ�ȳ�?
#define transfer_model              high_first_out

#define low_first_out               1
#define high_first_out              2
//----------�û�����----------

#define user_en                     0
#if (user_en == 1)
#include "usart.h"
#endif

//----------���ͷ���������----------

//----------��С֡�ṹ����----------
typedef struct {
    uint8_t header;         // ֡ͷ
    uint8_t address;        // ��ַ
    uint8_t id;             // ID
    uint8_t data_length;    // ���ݳ���
    uint8_t data[MAX_DATA_LENGTH];  // ����
    uint16_t check;           // ֡У��
} frame_t;


//Ӳ���㷽��
void hardwork_send(frame_t *p_Frame, uint8_t length);

//����㷽��
frame_t* easy_pack_data(const uint8_t addr, const uint8_t id, const uint32_t data , const uint8_t data_length);
frame_t* easy_pack_data_byName(const uint16_t name, const uint32_t data , const uint8_t data_length);
void easy_send_data(uint8_t addr, uint8_t id, uint32_t data , uint8_t data_length);
void easy_send_uchar(uint8_t addr, uint8_t id, uint8_t data);
void easy_send_ushort(uint8_t addr, uint8_t id, uint16_t data);
void easy_send_uint(uint8_t addr, uint8_t id, uint32_t data);


void easy_send_data_byName(uint16_t name, uint32_t data , uint8_t data_length);
void easy_send_uchar_byName(uint16_t addr, uint8_t data);
void easy_send_ushort_byName(uint16_t name, uint16_t data);
void easy_send_uint_byName(uint16_t name, uint32_t data);

//----------У�鷽������----------
uint16_t calculate_check(frame_t *p_Frame, uint8_t length);
uint8_t calculate_sum(frame_t *p_Frame, uint8_t length) ;
uint16_t calculate_crc(frame_t *p_Frame, uint8_t length);


//----------���շ���������----------
typedef enum {
    PARSE_STATE_WAIT_HEADER,
    PARSE_STATE_WAIT_ADDRESS,
    PARSE_STATE_WAIT_ID,
    PARSE_STATE_WAIT_DATA_LENGTH,
    PARSE_STATE_WAIT_DATA,
    PARSE_STATE_WAIT_CRC_HIGH,
    PARSE_STATE_WAIT_CRC_LOW
} parse_state_t;

uint8_t easy_parse_data(const uint8_t new_data, frame_t* frame);
uint16_t easy_read_frame_name(frame_t* frame);


#ifdef __cplusplus
}
#endif

#endif
