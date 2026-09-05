/**
 * 파일 이름: startup.c
 * 설명: MCU 부팅 시 main 함수로 진입하기 위한 최소 벡터 테이블 및 리셋 핸들러
 */

extern int main(void);

void Reset_Handler(void) {
    // 전역 변수 초기화 등이 필요하다면 이 곳에 추가
    main();
}

// ARM Cortex-M4 벡터 테이블 정의
__attribute__((section(".isr_vector")))
unsigned int *vector_table[] = {
    (unsigned int *)0x20020000,     // 초기 스택 포인터 (SRAM 끝단 주소 기준)
    (unsigned int *)Reset_Handler   // 리셋 발생 시 실행할 함수
};