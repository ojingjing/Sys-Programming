## REPORT
### 16비트 데이터를 2진수로 출력하는 프로그램 만들기
![image](https://user-images.githubusercontent.com/48702158/230850375-222ec65b-eea7-47e5-aefb-ec3143d4a7f3.png)
---
**코드설명**   
date 와 bit 배열을 정의 한후 data에는 16진수로 입력된 데이터를 저장 
bit에는 입력된 비트수를 저장
for 문을 이용하여 데이터 개수만큼 반복 하며 내부 for문은 데이터를 비트 단위로 출력한다.
data 배열에서 데이터를 읽어온후 >>(비트 이동 연산자) 를 이용하여 오른쪽으로 이동시키고 &(and) 연산자를 이용해
해당 비트가 1인지 0인지 확인한다.

---
![image](https://user-images.githubusercontent.com/48702158/230850242-07d37f6e-fa06-4592-8ce5-147680486b7c.png)  

그후 
**gcc** **-o** **report0410** **report0410.c**를 이용하여  **컴파일** 한다. 
**./report0410** 으로 결과값을 

