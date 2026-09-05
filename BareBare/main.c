/**
 * 파일 이름: main.c
 * 설명: Visual Studio 베어메탈 환경용 STM32F446RE PA6 LED 제어 코드
 */

#define RCC_BASE        0x40023800UL
#define GPIOA_BASE      0x40020000UL

// 레지스터 포인터 정의 (volatile을 붙여서 컴파일러 최적화 방지)
#define RCC_AHB1ENR     (*(volatile unsigned int*)(RCC_BASE + 0x30))
#define GPIOA_MODER     (*(volatile unsigned int*)(GPIOA_BASE + 0x00))
#define GPIOA_ODR       (*(volatile unsigned int*)(GPIOA_BASE + 0x14))

void delay(volatile unsigned int count) {
    while (count--);
}

int main(void)
{
    // 1단계: GPIOA 클록 활성화 (RCC_AHB1ENR의 0번 비트를 1로 설정)
    RCC_AHB1ENR |= (1 << 0);

    // 2단계: PA6 모드를 일반 출력(General purpose output mode)으로 설정 (01)
    // MODER6 비트(12~13번 비트)를 초기화 후 '01' 대입
    GPIOA_MODER &= ~(3 << (6 * 2)); // 12, 13번 비트 0으로 클리어
    GPIOA_MODER |=  (1 << (6 * 2)); // 12번 비트에 1 대입 (출력 모드 지정)

    while (1)
    {
        // 3단계: PA6 핀 출력 High (LED 켜기)
        GPIOA_ODR |= (1 << 6);
        delay(500000);

        // 4단계: PA6 핀 출력 Low (LED 끄기)
        GPIOA_ODR &= ~(1 << 6);
        delay(500000);
    }

    return 0;
}