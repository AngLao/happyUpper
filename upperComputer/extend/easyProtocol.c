#include "easyProtocol.h"


frame_t send_frame ;

//Ӳ����ʵ��
void hardwork_send(frame_t *p_Frame, uint8_t length)
{
    uint8_t* p_data =  (uint8_t*)p_Frame ;
#if (user_en == 1)
    //����֡����
    for (int i = 0; ; i++) {
        USART1->DR=*(p_data+i);
        while((USART1->SR&0X40)==0);//�ȴ����ͽ���

        if(i == length + 3)
        {
            uint8_t check_hight = p_Frame->check >>8;
            uint8_t check_low = p_Frame->check ;
                //����֡У��
            USART1->DR=check_hight;;
            while((USART1->SR&0X40)==0);//�ȴ����ͽ���
            USART1->DR=check_low;;
            while((USART1->SR&0X40)==0);//�ȴ����ͽ���
            //һ֡���ݷ������
            break;
        }
    }
#endif
}

//���󷽷�
/**
 * @brief ��������ֽڵ�����
 * @param addr �豸��ַ
 * @param id ������
 * @param data ����
 * @param data_length ���ݳ���
 * @return ���ش��������ݽṹ��ַ
 */
frame_t* easy_pack_data(const uint8_t addr, const uint8_t id, const uint32_t data , const uint8_t data_length)
{
    send_frame.header 						= FRAME_HEADER;
    send_frame.address 						= addr;
    send_frame.id                           = id;
    send_frame.data_length                  = data_length;

#if(transfer_model == low_first_out)
    for (char i = 0; i < data_length; i++) {
        send_frame.data[i]                  = data>>8*i ;
    }
#elif(transfer_model == high_first_out)
    for(char i = 0 ; i < data_length ; i++){
        send_frame.data[i]                  = data>>8*(data_length-i-1);
    }
#endif

    send_frame.check                        = calculate_check(&send_frame, send_frame.data_length);

    return &send_frame;
}

/**
 * @brief ��������ֽڵ�����
 * @param addr �豸��ַ
 * @param id ������
 * @param data ����
 * @param data_length ���ݳ���
 * @return ���ش��������ݽṹ��ַ
 */
frame_t* easy_pack_data_byName(const uint16_t name, const uint32_t data , const uint8_t data_length)
{
    send_frame.header 						= FRAME_HEADER;
    send_frame.address 						= name>>8;
    send_frame.id                           = name;
    send_frame.data_length                  = data_length;

#if(transfer_model == low_first_out)
    for (char i = 0; i < data_length; i++) {
        send_frame.data[i]                  = data>>8*i ;
    }
#elif(transfer_model == high_first_out)
    for(char i = 0 ; i < data_length ; i++){
        send_frame.data[i]                  = data>>8*(data_length-i-1);
    }
#endif

    send_frame.check 							= calculate_check(&send_frame, send_frame.data_length);

    return &send_frame;
}
/**
 * @brief ����ָ�������ֽڵ�����
 * @param addr �豸��ַ
 * @param id ������
 * @param data ����
 * @param data_length ���ݳ���
 */
void easy_send_data(const uint8_t addr, const uint8_t id, const uint32_t data , const uint8_t data_length)
{
    send_frame.header 						= FRAME_HEADER;
    send_frame.address 						= addr;
    send_frame.id 								= id;
    send_frame.data_length 				= data_length;

#if(transfer_model == low_first_out)
    for (char i = 0; i < data_length; i++) {
        send_frame.data[i] 				= data>>8*i ;
    }
#elif(transfer_model == high_first_out)
    for(char i = 0 ; i < data_length ; i++){
        send_frame.data[i] 				= data>>8*(data_length-i-1);
    }
#endif

    send_frame.check 							= calculate_check(&send_frame, send_frame.data_length);

    hardwork_send(&send_frame, send_frame.data_length);
}

/**
 * @brief ����ָ�������ֽ����ݵ�ָ�����ֵ��豸
 * @param name �豸����
 * @param data ���͵�����
 * @param data_length ���ݳ���
*/
void easy_send_data_byName(const uint16_t name, const uint32_t data , const uint8_t data_length)
{
    send_frame.header 						= FRAME_HEADER;
    send_frame.address 						= name>>8;
    send_frame.id 								= name;
    send_frame.data_length 				= data_length;

#if(transfer_model == low_first_out)
    for (char i = 0; i < data_length; i++) {
        send_frame.data[i] 				= data>>8*i ;
    }
#elif(transfer_model == high_first_out)
    for(char i = 0 ; i < data_length ; i++){
        send_frame.data[i] 				= data>>8*(data_length-i-1);
    }
#endif

    send_frame.check 							= calculate_check(&send_frame, send_frame.data_length);

    hardwork_send(&send_frame, send_frame.data_length);
}

/**
 * @brief ����һ���ֽڵ�����
 * @param addr �豸��ַ
 * @param id ������
 * @param data ����
 */
void easy_send_uchar(uint8_t addr, uint8_t id, uint8_t data)
{
    easy_send_data(addr, id, data , 1);
}

/**
 * @brief ����һ��2�ֽ�����
 * @param addr �豸��ַ
 * @param id ������
 * @param data ����
 */
void easy_send_ushort(uint8_t addr, uint8_t id, uint16_t data)
{
    easy_send_data(addr, id, data , 2);
}
/**
 * @brief ����һ��4�ֽڵ�����֡
 * @param addr Ŀ���ַ
 * @param id ����֡��id
 * @param data �����͵�����
*/
void easy_send_uint(uint8_t addr, uint8_t id, uint32_t data)
{
    easy_send_data(addr, id, data , 4);
}

/**
 * @brief ����һ���ֽ����ݵ�ָ�����ֵ��豸
 * @param name �豸����
 * @param data ���͵�����
*/
void easy_send_uchar_byName(uint16_t name, uint8_t data)
{
    easy_send_data_byName(name, data , 1);
}

/**
 * @brief ���������ֽ����ݵ�ָ�����ֵ��豸
 * @param name �豸����
 * @param data ���͵�����
*/
void easy_send_ushort_byName(uint16_t name, uint16_t data)
{
    easy_send_data_byName(name, data , 2);
}
/**
 * @brief �����ĸ��ֽ����ݵ�ָ�����ֵ��豸
 * @param name �豸����
 * @param data ���͵�����
*/
void easy_send_uint_byName(uint16_t name, uint32_t data)
{
    easy_send_data_byName(name, data , 4);
}


/**
 * @brief ����check_modelѡ����Ӧ��У���㷨����У��
 * @param p_Frame ��У�������ָ֡��
 * @param length ��У������ݳ���
 * @return У����������check_model��ͬ����ΪУ��ͻ�CRCУ����
*/
uint16_t calculate_check(frame_t *p_Frame, uint8_t length)
{
#if(check_model == sum_model) // ���ʹ��У���ģʽ
    return calculate_sum(p_Frame,length); // ���ü���У��͵ĺ���
#elif(check_model == crc16_model) // ���ʹ��CRC16ģʽ
    return calculate_crc(p_Frame,length); // ���ü���CRCУ����ĺ���

#endif
}

/**
 * @brief ��������֡��У���
 * @param p_Frame ��У�������ָ֡��
 * @param length ��У������ݳ���
 * @return У���
*/
uint8_t calculate_sum(frame_t *p_Frame, uint8_t length)
{
    uint8_t sum = 0;
    //i = 1,��������header
    for (int i = 1; i < length + 4; i++) { // ����У��ͣ��ӵڶ����ֽڣ�����header����ʼ
        sum += *((uint8_t*)p_Frame+i);
    }
    return sum;
}

/**
 * @brief ����֡��CRCУ����
 * @param p_Frame ָ��֡�ṹ���ָ��
 * @param length ֡���ȣ�������У���룩
 * @return uint16_t CRCУ����
 */
uint16_t calculate_crc(frame_t *p_Frame, uint8_t length) {
#define POLY 0x1021
    uint16_t crc = 0xFFFF;

    // ����֡�����ݲ��֣�����CRCУ����
    for (int i = 1; i < length + 3; i++) {
        crc ^= ((uint16_t)*((uint8_t*)p_Frame+i) << 8);
        for (int j = 0; j < 8; j++) {
            if (crc & 0x8000) {
                crc = (crc << 1) ^ POLY;
            } else {
                crc <<= 1;
            }
        }
    }

    return crc;
}


/**
 * @brief ����֡����
 * @param new_data �µ�����
 * @param frame �洢�������֡����
 * @return �����ɹ����� true�����򷵻� false
 */
uint8_t easy_parse_data(const uint8_t new_data, frame_t* frame)
{
    static parse_state_t	parse_state = PARSE_STATE_WAIT_HEADER;
    static uint8_t 			 	data_index  = 0;
    static frame_t 			 	current_frame ;  // ��̬�����洢��ǰ֡��״̬������

    uint8_t parse_fail  = 1;

    switch (parse_state) {
    case PARSE_STATE_WAIT_HEADER: {
        // �ȴ�֡ͷ�ĵ�һ���ֽ�
        if (new_data == FRAME_HEADER) {
            current_frame.header = new_data;
            parse_state = PARSE_STATE_WAIT_ADDRESS;
        }
        break;
    }
    case PARSE_STATE_WAIT_ADDRESS: {
        // �ȴ���ַ�ֽ�
        current_frame.address = new_data;
        parse_state = PARSE_STATE_WAIT_ID;
        break;
    }
    case PARSE_STATE_WAIT_ID: {
        // �ȴ� ID �ֽ�
        current_frame.id = new_data;
        parse_state = PARSE_STATE_WAIT_DATA_LENGTH;
        break;
    }
    case PARSE_STATE_WAIT_DATA_LENGTH: {
        // �ȴ����ݳ����ֽ�
        current_frame.data_length = new_data;
        if (current_frame.data_length > MAX_DATA_LENGTH) {
            //���ݳ��ȳ�����Χ�����ý���״̬
            parse_state = PARSE_STATE_WAIT_HEADER;
        } else {
            data_index = 0;
            parse_state = (current_frame.data_length > 0) ? PARSE_STATE_WAIT_DATA : PARSE_STATE_WAIT_CRC_HIGH;
        }
        break;
    }
    case PARSE_STATE_WAIT_DATA: {
        // �ȴ������ֽ�
        current_frame.data[data_index++] = new_data;
        if (data_index == current_frame.data_length) {
            // ���ݽ�����ϣ�������һ��״̬
            parse_state = PARSE_STATE_WAIT_CRC_HIGH;
        }
        break;
    }
    case PARSE_STATE_WAIT_CRC_HIGH: {
        // �ȴ�У�����λ�ֽ�
        current_frame.check = (uint16_t)new_data << 8;
        parse_state = PARSE_STATE_WAIT_CRC_LOW;
        break;
    }
    case PARSE_STATE_WAIT_CRC_LOW: {
        // �ȴ�У�����λ�ֽ�
        current_frame.check += new_data;
        const uint16_t checksum = calculate_check(&current_frame,current_frame.data_length);
        if (checksum == current_frame.check) {
            // У����ƥ�䣬�����ɹ�
            *frame =  current_frame;
            parse_fail = 0;
        }
        parse_state = PARSE_STATE_WAIT_HEADER;
        break;
    }
    }

    return parse_fail;
}

/**
 * @brief ��֡�н�����֡����
 * @param  frame ָ��֡�ṹ���ָ��
 * @return uint16_t ֡����
 */
uint16_t easy_read_frame_name(frame_t* frame)
{
    // ��֡�ж�ȡID�͵�ַ�����֡����
    uint16_t name =frame->address << 8  ;
    name |=frame->id  ;
    return name;
}

