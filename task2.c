#include <stdio.h>

int main(void)
{
    const float temp_f = 90.2;
    float temp_c;
    temp_c = (temp_f - 32)/1.8;
    printf("%f Fahrenheit = %f Celsius\n",temp_f, temp_c);

    return 0;
}