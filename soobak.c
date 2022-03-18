#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d", &n);
    char* solution(n);
    return 0;
}


char* solution(int n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    char* answer = (char*)malloc(sizeof(char) * (n * 3) + 1);
    //malloc은 초기화하지 않을 때까지 쓰레기값이 들어감 -> NULL로 초기화
    strcpy(answer, "\0");
    for (int i = 0; i < n; i++) {
        if ((i % 2) == 0) {
            answer[i] = "수";
        }
        else
            answer[i] = "박";
    }
    return answer;
}
