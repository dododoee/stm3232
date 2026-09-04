# 3강 심화 개념 학습
오늘 배우는 이 공식은 지난 [[Lec1_개요]]에서 배웠던 기본 법칙을 바탕으로 합니다. 
더 자세한 실습 코드는 [[Lec2_실습]]을 참고하세요.

# ARM 마이크로 프로세서 개요
MCU는 CPU의 디지털신호/PWM/통신과 같이 임베디드에서 사용되는 주변장치(PHERIPHERAL)을 연결해 하나의 칩으로 제작된 형태
CPU는 주변장치와 데이터를 주고 받으며 이를 버스라고 부름 (GPIO RAN TIMERCOUNTER UART JTAG NVIC ADC CLOCK ADC I2C)
ARM회사는 MCU코어만 만들고 ST회사에서는 주변장치를 모두 포함한 MCU장치를 판매

# CORTEX종류와 용도
CORTEX-R:실시간 프로세싱을 위한 고성능 임베디드 프로세서(MULTI MCU처리)
CORTEX-M:MCU기반 임베디드
선택한 모델: CORETEX-M4모델
어떤 모델을 선택하면 DATASHEET와 REFERENCE MANUAL을 읽을 줄 알아야함.


#BLOCK DIAGRAM
![alt text](image.png)
ARM CORTEX에는 AHB/ASB라고 불리우슨 버스제어기(CLOCK동기화)로 내부 SRAM메모리 제어기 GPIO등등이 APB브리지에 연결되어 타이머/UART/ADC가 들어가있음

#F446RE의 칩페키지 사양 /포트 사양/ 레지스터 설정
1. 레지스터: CONTROL REGISTER(속도, 인터럽트 설정)/ STATUS REGISTER(통신 완료 , 클럭 설정 완료, 인터럽트 발생)/ DATA REGISTER(ADC변환 데이터, 통신 데이터)
2. 포트 사양

꽃