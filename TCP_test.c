#include "wizchip_conf.h"
#include "socket.h"
#include "main.h"

#define TCP_SERVER_PORT 1000 //Change it to your PORT adress 1000 for example
#define BUF_SIZE 1024


uint8_t buf[BUF_SIZE];
int32_t ret;
uint8_t socket_num = 0;

void TCP_Server_Process(void)
{
    switch(getSn_SR(socket_num))
    {
        case SOCK_INIT:
            listen(socket_num);
            break;

        case SOCK_ESTABLISHED:
            if(getSn_RX_RSR(socket_num) > 0) {
                ret = recv(socket_num, buf, BUF_SIZE);
                if(ret > 0)
                {
                    buf[ret] = 0;

                    if(buf[0] == '1') {  //'1' OR Any Data which you have send on powershell
                        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET);
                        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_RESET);
                    } else {
                        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
                        HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET);
                    }
                }
            }
            break;

        case SOCK_CLOSE_WAIT:
            disconnect(socket_num);
            break;

        case SOCK_CLOSED:
            socket(socket_num, Sn_MR_TCP, TCP_SERVER_PORT, 0);
            break;

        default:
            break;
    }
}
