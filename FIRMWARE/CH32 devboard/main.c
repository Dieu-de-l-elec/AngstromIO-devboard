/*
 *   CH32 devboard demo code | Clem, #Dieu-de-l'elec | https://github.com/Dieu-de-l-elec/AngstromIO-devboard/tree/main
 *   Charlieplexed 5x4 LED matrix
 *   1 button & 1 LED
 *   
 *   After creating a new Mounriver Studio project and selecting the chip 'CH32V003F4U', the following main.c file can be replaced with the following code (in User>main.c)  
 *   as the devboard doesn't comes with an external oscillator, the file 'system_ch32v00x.c has to be modified, changing the code as below:
 *            //#define SYSCLK_FREQ_8MHz_HSI    8000000
 *            //#define SYSCLK_FREQ_24MHZ_HSI   HSI_VALUE
 *            #define SYSCLK_FREQ_48MHZ_HSI   48000000               // This line has to be uncommented
 *            //#define SYSCLK_FREQ_8MHz_HSE    8000000
 *            //#define SYSCLK_FREQ_24MHz_HSE   HSE_VALUE
 *            //#define SYSCLK_FREQ_48MHz_HSE   48000000              Default line that should be commented
 */

#include "debug.h"

#define BUTTON_PIN 13
#define LED_PIN 7

uint32_t DELAY_FRAME = 2;  // 2 ms
uint8_t stateLED = 0;

typedef struct {
    GPIO_TypeDef *PORT;
    uint16_t PIN;
} PinSetup;

PinSetup pinMap[] = {

    {GPIOD, GPIO_Pin_6}, //  0  L1
    {GPIOD, GPIO_Pin_5}, //  1  L2
    {GPIOD, GPIO_Pin_4}, //  2  L3
    {GPIOD, GPIO_Pin_3}, //  3  L4
    {GPIOD, GPIO_Pin_2}, //  4   L5

    {GPIOA, GPIO_Pin_1}, //  5  T1CH2
    {GPIOA, GPIO_Pin_2}, //  6
    {GPIOC, GPIO_Pin_0}, //  7  T2CH3
    {GPIOC, GPIO_Pin_3}, //  8  T1CH3
    {GPIOC, GPIO_Pin_4}, //  9  T1CH4
    {GPIOC, GPIO_Pin_5}, //  10
    {GPIOC, GPIO_Pin_6}, //  11
    {GPIOC, GPIO_Pin_7}, //  12
    {GPIOD, GPIO_Pin_0}, //  13            Button here
    {GPIOC, GPIO_Pin_1}, //  14  SDA
    {GPIOC, GPIO_Pin_2}  //  15  SCL
};

static const uint8_t Off_LED_Matrix[5][4] = {
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0},
    {0, 0, 0, 0}
};

static const uint8_t On_LED_Matrix[5][4] = {
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {1, 1, 1, 1}
};

static const uint8_t Digits_Matrix[10][5][4] = {     // creating all the digits from 0 to 9
    {{0, 1, 1, 0},
     {1, 0, 0, 1},
     {1, 0, 0, 1},
     {1, 0, 0, 1},
     {0, 1, 1, 0}},

    {{0, 0, 1, 0},
     {0, 1, 1, 0},
     {1, 0, 1, 0},
     {0, 0, 1, 0},
     {0, 0, 1, 0}},

    {{1, 1, 1, 0},
     {0, 0, 0, 1},
     {0, 1, 1, 1},
     {1, 0, 0, 0},
     {1, 1, 1, 1}},

    {{1, 1, 1, 0},
     {0, 0, 0, 1},
     {0, 1, 1, 0},
     {0, 0, 0, 1},
     {1, 1, 1, 0}},

    {{1, 0, 0, 1},
     {1, 0, 0, 1},
     {0, 1, 1, 1},
     {0, 0, 0, 1},
     {0, 0, 0, 1}},

    {{1, 1, 1, 1},
     {1, 0, 0, 0},
     {1, 1, 1, 0},
     {0, 0, 0, 1},
     {1, 1, 1, 0}},

    {{0, 1, 1, 1},
     {1, 0, 0, 0},
     {1, 1, 1, 1},
     {1, 0, 0, 1},
     {0, 1, 1, 0}},

    {{1, 1, 1, 1},
     {0, 0, 0, 1},
     {0, 0, 1, 0},
     {0, 1, 0, 0},
     {0, 1, 0, 0}},

    {{0, 1, 1, 0},
     {1, 0, 0, 1},
     {0, 1, 1, 0},
     {1, 0, 0, 1},
     {0, 1, 1, 0}},

    {{0, 1, 1, 0},
     {1, 0, 0, 1},
     {1, 1, 1, 1},
     {0, 0, 0, 1},
     {1, 1, 1, 0}}
};

void pinMode (uint8_t pin_number, GPIOMode_TypeDef mode) {
    if (pin_number > 15)
        return;

    GPIO_InitTypeDef GPIO_InitStructure = {0};

    RCC_APB2PeriphClockCmd (RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOC | RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = pinMap[pin_number].PIN;
    GPIO_InitStructure.GPIO_Mode = mode;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_30MHz;

    GPIO_Init (pinMap[pin_number].PORT, &GPIO_InitStructure);
}

void digitalWrite (uint8_t pin_number, uint8_t bit_state) {
    if (pin_number > 15)
        return;
    if (bit_state == 1) {
        GPIO_SetBits (pinMap[pin_number].PORT, pinMap[pin_number].PIN);
    } else {
        GPIO_ResetBits (pinMap[pin_number].PORT, pinMap[pin_number].PIN);
    }
}

uint8_t digitalRead (uint8_t pin_number) {
    if (pin_number > 15)
        return 0;
    return GPIO_ReadInputDataBit (pinMap[pin_number].PORT, pinMap[pin_number].PIN);
}

void updateDisplay (const uint8_t LED_Matrix[5][4], uint32_t duration) {        // runs the display for 'duration' milliseconds
    for (uint32_t it = 0; it < (duration / (DELAY_FRAME * 5)); it++) {
        for (uint8_t c = 0; c < 5; c++) {
            pinMode (c, GPIO_Mode_Out_PP);
            digitalWrite (c, 0);
            for (uint8_t l = 0; l < 5; l++) {
                if (l < c) {
                    if (LED_Matrix[l][c - 1] == 1) {
                        pinMode (l, GPIO_Mode_Out_PP);
                        digitalWrite (l, 1);
                    }
                }
                if (l > c) {
                    if (LED_Matrix[l][c] == 1) {
                        pinMode (l, GPIO_Mode_Out_PP);
                        digitalWrite (l, 1);
                    }
                }
            }
            Delay_Ms (DELAY_FRAME);
            for (uint8_t pin = 0; pin < 5; pin++) {
                pinMode (pin, GPIO_Mode_IN_FLOATING);
            }
        }
    }
}

int main (void) {
    SystemCoreClockUpdate();
    Delay_Init();
    //USART_Printf_Init (115200); // actually the TX pin isn't broken out...
    pinMode(0, GPIO_Mode_IN_FLOATING);
    pinMode(1, GPIO_Mode_IN_FLOATING);
    pinMode(2, GPIO_Mode_IN_FLOATING);
    pinMode(3, GPIO_Mode_IN_FLOATING);
    pinMode(4, GPIO_Mode_IN_FLOATING);
    pinMode (7, GPIO_Mode_Out_PP);
    Delay_Ms (5000);
    //printf ("CH32 devboard ready\r\n"); // actually the TX pin isn't broken out...
    pinMode (BUTTON_PIN, GPIO_Mode_IN_FLOATING);  // Already have external 20k pull up

    while (1) {
        while (digitalRead (BUTTON_PIN) == 1) {
            digitalWrite (LED_PIN, stateLED);
            stateLED = !stateLED;
            Delay_Ms (100);
        }
        for (uint8_t counter = 9; counter > 0; counter--) {  // count down to 0
            updateDisplay (Digits_Matrix[counter], 1000);
        }
        updateDisplay (Off_LED_Matrix, 300);    //
        updateDisplay (Digits_Matrix[0], 300);  // fun blinking animation :D
        updateDisplay (Off_LED_Matrix, 300);    //
        updateDisplay (Digits_Matrix[0], 300);  //
        updateDisplay (Off_LED_Matrix, 300);    //
        digitalWrite (LED_PIN, 1);                  //
        updateDisplay (On_LED_Matrix, 6000);        // lit all LEDs for 6 seconds
        updateDisplay (Off_LED_Matrix, 10);     
    }
}
