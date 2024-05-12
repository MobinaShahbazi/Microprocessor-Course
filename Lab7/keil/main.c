#include <stdio.h>
#include "stm32f4xx.h"

int isPrime(int num);
int isPalindrome(int num);
void delay1();
void delay2();
void showNum(int num);


int main() {
	  //====================
	  RCC->AHB1ENR = ((1<<0) | (1<<2));
	  GPIOC->MODER &= ~(0x3 << 13);       // PC12-13: input   // CHECK
    //====================
    int num = 2, last = 0;
    int arr[1000];
    while(1){
        if((GPIOA->IDR & (1<<12)) == 0){                    // CHECK
            while(!isPrime(num) || !isPalindrome(num))
                num++;
            arr[last] = num;
            last++;
            showNum(num);
            num++;
        }
        else if((GPIOA->IDR & (1<<13)) == 0){               // CHECK
            int index = last - 2;
            num = arr[index] + 1;
            last--;
            showNum(arr[index]);
        }
    }
    return 0;
}

int isPrime(int num) {
    int i;
    if (num < 2)
        return 0;

    for (i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}
int isPalindrome(int num) {
    int reversedNum = 0;
    int originalNum = num;
    while (num > 0) {
        reversedNum = reversedNum * 10 + (num % 10);
        num /= 10;
    }
    if (originalNum == reversedNum)
        return 1;
    else
        return 0;
}
void delay1(){
	for (unsigned int d = 100000;d!=0;d--)
	{}
}
void delay2(void){
	for (unsigned int d = 400000;d!=0;d--)
	{}
}
void showNum(int num){
	  
	  
		GPIOA->MODER |= (1<<10);            // PA0-6: output    // CHECK
		

	
    int count = 0,copy = num;
    while (copy != 0) {
        copy /= 10;
        count++;
    }
    for(int i=0;i<count;i++){
        int digit = num%10;
        num/=10;
        
        switch (digit) {
            case 0:
                GPIOA->ODR = 0x3f;
                delay1();
                break;
            case 1:
                GPIOA->ODR = 0x06;
                delay1();
                break;
            case 2:
                GPIOA->ODR = 0x5b;
                delay1();
                break;
            case 3:
                GPIOA->ODR = 0x4f;
                delay1();
                break;
            case 4:
                GPIOA->ODR = 0x66;
                delay1();
                break;
            case 5:
                GPIOA->ODR = 0x6d;
                delay1();
                break;
            case 6:
                GPIOA->ODR = 0x7d;
                delay1();
                break;
            case 7:
                GPIOA->ODR = 0x07;
                delay1();
                break;
            case 8:
                GPIOA->ODR = 0x7f;
                delay1();
                break;
            case 9:
                GPIOA->ODR = 0x67;
                delay1();
                break;
        }    
    }
    GPIOA->ODR = 0x00;
    delay2();
}
