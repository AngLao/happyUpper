#include "easyProtocol.h"


frame_t send_frame ;

//硬件层实现
void hardwork_send(frame_t *p_Frame, uint8_t length)
{
    uint8_t* p_data =  (uint8_t*)p_Frame ;
#if (user_en == 1)
    //发送帧数据
    for (int i = 0; ; i++) {
        USART1->DR=*(p_data+i);
        while((USART1->SR&0X40)==0);//等待发送结束

        if(i == length + 3)
        {
            uint8_t check_hight = p_Frame->check >>8;
            uint8_t check_low = p_Frame->check ;
                //发送帧校验
            USART1->DR=check_hight;;
            while((USART1->SR&0X40)==0);//等待发送结束
            USART1->DR=check_low;;
            while((USART1->SR&0X40)==0);//等待发送结束
            //一帧数据发送完成
            break;
        }
    }
#endif
}

//抽象方法
/**
 * @brief 打包长度字节的数据
 * @param addr 设备地址
 * @param id 功能码
 * @param data 数据
 * @param data_length 数据长度
 * @return 返回打包后的数据结构地址
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
 * @brief 打包长度字节的数据
 * @param addr 设备地址
 * @param id 功能码
 * @param data 数据
 * @param data_length 数据长度
 * @return 返回打包后的数据结构地址
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
 * @brief 发送指定长度字节的数据
 * @param addr 设备地址
 * @param id 功能码
 * @param data 数据
 * @param data_length 数据长度
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
 * @brief 发送指定长度字节数据到指定名字的设备
 * @param name 设备名字
 * @param data 发送的数据
 * @param data_length 数据长度
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
 * @brief 发送一个字节的数据
 * @param addr 设备地址
 * @param id 功能码
 * @param data 数据
 */
void easy_send_uchar(uint8_t addr, uint8_t id, uint8_t data)
{
    easy_send_data(addr, id, data , 1);
}

/**
 * @brief 发送一个2字节数据
 * @param addr 设备地址
 * @param id 功能码
 * @param data 数据
 */
void easy_send_ushort(uint8_t addr, uint8_t id, uint16_t data)
{
    easy_send_data(addr, id, data , 2);
}
/**
 * @brief 发送一个4字节的数据帧
 * @param addr 目标地址
 * @param id 数据帧的id
 * @param data 待发送的数据
*/
void easy_send_uint(uint8_t addr, uint8_t id, uint32_t data)
{
    easy_send_data(addr, id, data , 4);
}

/**
 * @brief 发送一个字节数据到指定名字的设备
 * @param name 设备名字
 * @param data 发送的数据
*/
void easy_send_uchar_byName(uint16_t name, uint8_t data)
{
    easy_send_data_byName(name, data , 1);
}

/**
 * @brief 发送两个字节数据到指定名字的设备
 * @param name 设备名字
 * @param data 发送的数据
*/
void easy_send_ushort_byName(uint16_t name, uint16_t data)
{
    easy_send_data_byName(name, data , 2);
}
/**
 * @brief 发送四个字节数据到指定名字的设备
 * @param name 设备名字
 * @param data 发送的数据
*/
void easy_send_uint_byName(uint16_t name, uint32_t data)
{
    easy_send_data_byName(name, data , 4);
}


/**
 * @brief 根据check_model选择相应的校验算法进行校验
 * @param p_Frame 待校验的数据帧指针
 * @param length 待校验的数据长度
 * @return 校验结果，根据check_model不同可能为校验和或CRC校验码
*/
uint16_t calculate_check(frame_t *p_Frame, uint8_t length)
{
#if(check_model == sum_model) // 如果使用校验和模式
    return calculate_sum(p_Frame,length); // 调用计算校验和的函数
#elif(check_model == crc16_model) // 如果使用CRC16模式
    return calculate_crc(p_Frame,length); // 调用计算CRC校验码的函数

#endif
}

/**
 * @brief 计算数据帧的校验和
 * @param p_Frame 待校验的数据帧指针
 * @param length 待校验的数据长度
 * @return 校验和
*/
uint8_t calculate_sum(frame_t *p_Frame, uint8_t length)
{
    uint8_t sum = 0;
    //i = 1,跳过检验header
    for (int i = 1; i < length + 4; i++) { // 计算校验和，从第二个字节（跳过header）开始
        sum += *((uint8_t*)p_Frame+i);
    }
    return sum;
}

/**
 * @brief 计算帧的CRC校验码
 * @param p_Frame 指向帧结构体的指针
 * @param length 帧长度（不包括校验码）
 * @return uint16_t CRC校验码
 */
uint16_t calculate_crc(frame_t *p_Frame, uint8_t length) {
#define POLY 0x1021
    uint16_t crc = 0xFFFF;

    // 遍历帧的数据部分，计算CRC校验码
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
 * @brief 解析帧数据
 * @param new_data 新的数据
 * @param frame 存储解析后的帧数据
 * @return 解析成功返回 true，否则返回 false
 */
uint8_t easy_parse_data(const uint8_t new_data, frame_t* frame)
{
    static parse_state_t	parse_state = PARSE_STATE_WAIT_HEADER;
    static uint8_t 			 	data_index  = 0;
    static frame_t 			 	current_frame ;  // 静态变量存储当前帧的状态和数据

    uint8_t parse_fail  = 1;

    switch (parse_state) {
    case PARSE_STATE_WAIT_HEADER: {
        // 等待帧头的第一个字节
        if (new_data == FRAME_HEADER) {
            current_frame.header = new_data;
            parse_state = PARSE_STATE_WAIT_ADDRESS;
        }
        break;
    }
    case PARSE_STATE_WAIT_ADDRESS: {
        // 等待地址字节
        current_frame.address = new_data;
        parse_state = PARSE_STATE_WAIT_ID;
        break;
    }
    case PARSE_STATE_WAIT_ID: {
        // 等待 ID 字节
        current_frame.id = new_data;
        parse_state = PARSE_STATE_WAIT_DATA_LENGTH;
        break;
    }
    case PARSE_STATE_WAIT_DATA_LENGTH: {
        // 等待数据长度字节
        current_frame.data_length = new_data;
        if (current_frame.data_length > MAX_DATA_LENGTH) {
            //数据长度超出范围，重置解析状态
            parse_state = PARSE_STATE_WAIT_HEADER;
        } else {
            data_index = 0;
            parse_state = (current_frame.data_length > 0) ? PARSE_STATE_WAIT_DATA : PARSE_STATE_WAIT_CRC_HIGH;
        }
        break;
    }
    case PARSE_STATE_WAIT_DATA: {
        // 等待数据字节
        current_frame.data[data_index++] = new_data;
        if (data_index == current_frame.data_length) {
            // 数据接收完毕，进入下一步状态
            parse_state = PARSE_STATE_WAIT_CRC_HIGH;
        }
        break;
    }
    case PARSE_STATE_WAIT_CRC_HIGH: {
        // 等待校验码高位字节
        current_frame.check = (uint16_t)new_data << 8;
        parse_state = PARSE_STATE_WAIT_CRC_LOW;
        break;
    }
    case PARSE_STATE_WAIT_CRC_LOW: {
        // 等待校验码低位字节
        current_frame.check += new_data;
        const uint16_t checksum = calculate_check(&current_frame,current_frame.data_length);
        if (checksum == current_frame.check) {
            // 校验码匹配，解析成功
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
 * @brief 从帧中解析出帧名称
 * @param  frame 指向帧结构体的指针
 * @return uint16_t 帧名称
 */
uint16_t easy_read_frame_name(frame_t* frame)
{
    // 从帧中读取ID和地址，组成帧名称
    uint16_t name =frame->address << 8  ;
    name |=frame->id  ;
    return name;
}

