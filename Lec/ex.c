#include <stdio.h>

/* func3: signed int을 받아서 float로 변환/가공 */
float func3(signed int x)
{
    return (float)x / 2.0f;
}

/* func2: int를 받아 int를 리턴하는 재귀 함수 (팩토리얼) */
int func2(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * func2(n - 1);   /* 자기 자신을 재귀 호출 */
}

/* func1: void 리턴, func2 결과를 func3에게 넘김 */
void func1(int n)
{
    int result = func2(n);      /* func2 호출 (내부에서 재귀) */
    float value = func3(result); /* func3에게 넘김 */
    printf("value = %f\n", value);
}

int main(void)
{
    func1(5);
    return 0;
}
