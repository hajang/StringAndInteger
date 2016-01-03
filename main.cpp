//
// Created by Ha on 16. 1. 3..
//

/*
 * page 190
 * 두 개의 변환 루틴을 작성하라. 첫 번째 루틴은 문자열을 부호가 있는 정수로 변환하는 루틴이다.
 * 문자열에는 숫자와 마이너스 문자(-)만 들어있으며 제대로 된 정수이며, int 유형 범위 안에 들어간
 * 정수라고 가정해도 좋다. 두 번째 루틴은 int 유형으로 저장된 부호가 이쓴 정수를 다시 문자열로 변환하는 루틴이다.
 */

#include <stdio.h>
#include <math.h>
#include <string.h>


// 문자열을 입력받아 int형으로 변환하는 함수
int toInt(char *str){
    int len = strlen(str), i = 0, num = 0;
    bool neg = false;

    // - 가 문자열 시작에 포함되었다면 음수이므로 neg flag set
    // 그리고 숫자계산시 시작할 index는 0이 아닌 1
    if(str[0] == '-'){
        neg = true;
        i = 1;
    }

    // ascii 코드 값으로 숫자 값을 구하고 각 차수에 맞게 10에 지수승을 곱하여 결과에 합산
    for(; i < len; i++)
        num = num + (str[i] - '0') * (int)pow(10.0, len - i - 1);

    if(neg)
        num = num * -1;

    return num;
}

// int형 데이터를 입력받아 문자열로 변화하는 함수
void toString(int num, char *str){
    int dst = 0, count = 0;
    char buf[11]; // int로 표현할 수 있는 최대 길이 = 10(부호 +1) = 11

    // 만약 음수라면 부호를 삽입 후 양수화
    if(num < 0){
        str[dst++] = '-';
        num = num * -1;
    }

    // 각 자리를 종주하며 각 숫자의 ascii값을 대입
    while(num != 0){
        buf[count++] = num % 10 + '0';
        num = num / 10;
    }

    // 버퍼 내용을 거꾸로 str에 씀
    while(count != 0)
        str[dst++] = buf[--count];

    // 문자열 마지막은 nullstr
    str[dst] = '\0';
}

int main(){
    printf("%d\n", toInt("-1234567891\0"));

    char *s;
    toString(123, s);
    printf("s : %s", s);

    return 0;
}