#ifndef __EASYPROTOCOL_H
#define __EASYPROTOCOL_H


#ifdef __cplusplus
extern "C" {

#endif

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;

#define MAX_DATA_LENGTH             32

extern uint8_t REC_HEADER ;
extern uint8_t check_model ;
extern uint8_t transfer_model ;
//У�鷽��ѡ��
#define sum_model 					0
#define crc16_model                 1
#define niming_model                2

//���ݴ���ģʽѡ��   ��λ�ȳ�? ��λ�ȳ�?
#define low_first_out               1
#define high_first_out              2


//----------���ͷ���������----------
typedef struct {
    uint8_t header;         // ֡ͷ
    uint8_t address;        // ��ַ
    uint8_t id;             // ID
    uint8_t data_length;    // ���ݳ���
    uint16_t check;         // ֡У��

    uint8_t data[MAX_DATA_LENGTH];  // ����
} frame_t;


//����㷽��
void easy_wipe_data(frame_t *p_Frame);
void easy_set_id(frame_t *p_Frame, uint8_t id);
void easy_set_header(frame_t *p_Frame, uint8_t header);
void easy_set_address(frame_t *p_Frame, uint8_t address);
uint8_t easy_add_check(frame_t *p_Frame);
uint8_t easy_add_data(frame_t *p_Frame, uint32_t data, uint8_t length);

//----------У�鷽������----------
uint16_t calculate_check(frame_t *p_Frame, uint8_t length);
uint16_t calculate_sum(frame_t *p_Frame, uint8_t length) ;
uint16_t calculate_crc(frame_t *p_Frame, uint8_t length);


//----------���շ���������----------
typedef enum {
    HEADER = 0,
    ADDRESS,
    ID,
    DATA_LENGTH,
    DATA,
    CHECK_HIGH,
    CHECK_LOW
} parse_state_t;

uint8_t  easy_return_buflen(frame_t* p_Frame);
uint16_t easy_return_name(frame_t* p_Frame);
uint8_t  easy_parse_data(const uint8_t new_data, frame_t* frame);


#ifdef __cplusplus
}
#endif

#endif
