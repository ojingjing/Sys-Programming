#include <stdio.h> 
#include "student.h"
/* 텍스트 파일에서 학생 정보를 읽어 프린트한다. */
int main(int argc, char* argv[]) 
{ 
	struct student record;
	FILE *fp;
	if (argc != 2) {
		fprintf(stderr, "사용법: %s 파일이름\n", argv[0]);
		return 1; 
	}
	fp = fopen(argv[1], "r");
	printf("%-9s %-7s %-4s\n", "학번", "이름", "점수"); 
	while (fscanf(fp,"%d %s %d", &record.id, record.name, &record.score) == 3) 
		printf("%d %s %d\n", record.id, record.name, record.score);
	fclose(fp);
	return 0;
} 


위의 코드는 텍스트 파일에서 학생 정보를 읽어와서 출력하는 프로그램입니다. 코드의 동작을 살펴보면 다음과 같습니다:

student.h 헤더 파일을 포함시킵니다. 이 헤더 파일은 학생 정보를 담는 구조체(struct student)를 정의합니다.

main 함수에서는 프로그램 실행 시 전달된 인자의 개수를 확인합니다. 인자 개수가 2가 아니면 사용법을 출력하고 프로그램을 종료합니다.

전달된 인자로부터 파일 이름을 얻어와 해당 파일을 읽기 모드로 엽니다.

헤더에 정의된 형식에 맞게 학생 정보를 파일에서 읽어옵니다. fscanf 함수를 사용하여 파일에서 정수형 학번, 문자열 형태의 이름, 정수형 점수를 읽어옵니다.

읽어온 학생 정보를 형식에 맞춰 출력합니다. %d, %s와 같은 서식지정자를 사용하여 학번, 이름, 점수를 출력합니다.

파일을 닫고 프로그램을 종료합니다.

이 코드는 텍스트 파일에서 학생 정보를 읽어와 출력하는 간단한 예제입니다. 입력 파일은 학생의 학번, 이름, 점수로 구성되며, 각 열은 공백으로 구분되어야 합니다. 출력은 해당 파일의 내용을 학번, 이름, 점수의 형식으로 정렬된 형태로 보여줍니다.




