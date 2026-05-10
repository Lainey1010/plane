#include "attitude_ctrl.h"
#include "task_control.h"
#include "mahony.h"

// 你自己的串口打印函数
// printf 已经重定向的话可以直接用 printf
#include <stdio.h>

int main(void)
{
    // 这里写你的系统初始化
    // SystemInit();
    // USART1_Init(115200);
    // SysTick_Init();

    Task_Attitude_Init();
    Task_Control_Init();

    while (1)
    {
        Attitude_t *att;

        Task_Attitude_Run();
        Task_Control_Run();

        att = Mahony_GetAttitude();

        printf("Roll: %.2f, Pitch: %.2f, Yaw: %.2f\r\n", att->roll, att->pitch, att->yaw);
        printf("PID Roll: %.2f, Pitch: %.2f, Yaw: %.2f, Height: %.2f\r\n",
               roll_output, pitch_output, yaw_output, height_output);

        // 这里先粗略延时
        // Delay_ms(100);
    }
}