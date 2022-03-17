/******************************************************************************************************/
/*                                HW#1 : C++ 시작하기                                                 */
/*  작성자 : 홍은성                                                 날짜 : 2022년 3월 16일            */
/*                                                                                                    */
/* 문제 정의 :  성적처리프로그램#1                                                                    */
/*              cin과 cout을 이용하여 다양한 데이터 형의 사용자 입력을 처리하고, 처리 결과를 출력한다.*/
/******************************************************************************************************/


#include <string>
#include <iostream>
using namespace std;

struct Subject {
	char SubName[30]; //과목 이름
	int Hakjum; //과목 학점
	char Grade[10]; //과목 등급
	float GPA; //과목 평점
};



struct Student {
	char StdName[30]; //학생 이름
	int Hakbun; //학번
	Subject Sub[3]; //과목
	float AveGPA; //교과목 평균 평점
};
typedef struct Student st;



void display_menu(); // 메뉴 옵션 1, 2, 3번을 보여주는 함수입니다. 
void std_input(st* s); //학생의 정보를 입력받는 함수입니다. 
void cal_avg(st* s); //학생의 교과목 평균 평점을 계산하는 함수입니다. 
void std_out(st* s); //학생의 신상 및 성적 정보를 출력하는 함수입니다. 



/* 메인함수에서는 while문을 통해 '메뉴출력-기능실행'이 반복됩니다. 
메뉴 옵션 선택 단계에서 입력 오류가 발생하는 것을 처리하기 위해 else문과 cin.clear과 cin.ignore 함수를 사용했습니다.*/
void main() 
{
	st std[2]; //함수 처리를 쉽게 하기 위해 하나의 구조체 배열로 선언했습니다.


	int option; //메뉴의 세 가지 옵션 중 무엇을 선택할지에 대한 변수입니다. 
	int loop = 1; //메뉴의 3번인 종료 옵션을 선택하기 전까지 프로그램이 반복되도록 하기 위해 이용하는 루프 인덱스입니다. 


	while (loop == 1) {   

		display_menu();//루프가 실행될 때마다 메뉴를 다시 보여줍니다.
		cout << "\n원하는 기능을 입력하세요 : ";
		cin >> option; //옵션 선택지 번호를 저장합니다.


		if (option == 1)
			std_input(&std[0]); // 1번을 선택하면 학생 정보 입력 함수를 실행합니다.
		else if (option == 2)
			std_out(std); //2번을 선택하면 학생 정보 출력 함수를 실행합니다.
		else if (option == 3)
			loop = 0; // 3번 메뉴를 선택하면 반복문을 탈출합니다.  

		else //다른 숫자를 입력한 경우, 혹은 숫자가 아닌 문자열 등을 입력한 경우를 전부 묶어서 else로 처리합니다.
		{
			cout << "\n잘못된 입력입니다.\n\n";
			cin.clear();  // 숫자가 아닌 문자를 입력했을 경우 에러가 발생하므로 cin.clear 함수를 사용해 에러 비트를 초기화합니다.
			cin.ignore(1000, '\n'); //최대 1000자까지 읽어들일 수 있는 cin.ignore로 입력버퍼에 남아있는 문자열까지 모두 제거해줍니다.
		}

	}

	cout << "\n프로그램을 종료합니다.";

}




void display_menu() { //cout을 이용해 메뉴를 출력하도록 설정했습니다.
	cout << "\n========= 메뉴 =========\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 프로그램 종료\n";
}



/*학생의 정보를 입력받는 함수입니다.
구조체 배열을 포인터 형식으로 전달받으므로 반복문을 통해 학생 두 명의 정보를 각각 입력받도록 했습니다
학번, 과목학점수, 과목 등급에 대해 입력오류 상황까지 처리해두었습니다.*/
void std_input(st* s) { 
	
	for (int a = 0; a < 2; a++) { //총 두 번 반복되며 학생 각각의 정보를 입력받습니다. 
		int loop = 1; // 입력 오류 처리를 위해 설정한 루프 인덱스입니다. 입력 오류가 발생할 수 있는 단계마다 사용됩니다. 
		cout << "\n" << a+1 << "번째 학생의 이름과 학번을 입력하세요.\n"; 
		cout << "이름 : ";
		cin >> (s+a)->StdName;
		while (loop == 1) { //학번이 정상 입력되면 루프 변수가 0이 되며 다음 단계로 넘어가고, 1로 유지되는 동안은 재입력 메시지가 출력됩니다. 
			cout << "학번 : ";
			cin >> (s + a)->Hakbun;
			if (!cin) { //입력 오류가 발생할 시 실행되도록 !cin을 사용했습니다.
				cout << "잘못된 입력입니다.\n";
				cin.clear();//메인함수에서처럼 에러비트와 입력버퍼를 초기화해줍니다.
				cin.ignore(1000, '\n');
			}
			else
				loop = 0;
		}
		cout << "\n수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";


		for (int i = 0; i < 3; i++)
		{
			float GradeNumber = 0;
			loop = 1;


			cout << "\n교과목명(" << i + 1 << ") : "; // "교과목명(1) : "과 같이 표시됩니다.
			cin >> (s+a)->Sub[i].SubName;


			while (loop == 1) { //입력 에러가 발생하지 않는 경우 루프 변수가 0이 되며 다음 단계로 넘어갑니다.
				cout << "과목학점수 : ";
				cin >> (s + a)->Sub[i].Hakjum;
				if (!cin)//동일한 방식으로 입력 오류를 처리했습니다.
				{
					cout << "잘못된 입력입니다.\n";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else
					loop = 0;

			}

			loop = 1;
			while (loop == 1) {
				//과목 등급이 올바르게 입력되면 전부 대문자로 변환해 Grade에 저장하고, 과목평점을 계산하기 위해 GradeNumber 변수에 해당하는 학점을 저장합니다.
				cout << "과목등급(A~F) : ";
				cin >> (s + a)->Sub[i].Grade;

				if ((strcmp((s + a)->Sub[i].Grade, "A+") == 0) || (strcmp((s + a)->Sub[i].Grade, "a+") == 0))//올바르게 성적이 입력되었는지는 strcmp 함수로 판별합니다.
				{
					GradeNumber = 4.5;
					loop = 0;//성적이 올바르게 입력되었다면 다음 단계로 넘어가기 위해 루프 변수를 수정해 while문을 탈출합니다.
					strcpy((s + a)->Sub[i].Grade, "A+");//소문자로 입력되었더라도, 학생 정보 출력 화면의 통일성을 위해 전부 대문자로 저장합니다.
				}
				else if (((strcmp((s + a)->Sub[i].Grade, "A") == 0) || (strcmp((s + a)->Sub[i].Grade, "A0")) == 0) || ((strcmp((s + a)->Sub[i].Grade, "a") == 0) || (strcmp((s + a)->Sub[i].Grade, "a0") == 0)))
				{
					GradeNumber = 4;
					loop = 0;
					strcpy((s + a)->Sub[i].Grade, "A0");
				}
				else if ((strcmp((s + a)->Sub[i].Grade, "B+") == 0) || (strcmp((s + a)->Sub[i].Grade, "b+") == 0))
				{
					GradeNumber = 3.5;
					loop = 0;
					strcpy((s + a)->Sub[i].Grade, "B+");
				}
				else if (((strcmp((s + a)->Sub[i].Grade, "B") == 0) || (strcmp((s + a)->Sub[i].Grade, "B0")) == 0) || ((strcmp((s + a)->Sub[i].Grade, "b") == 0) || (strcmp((s + a)->Sub[i].Grade, "b0") == 0)))
				{
					GradeNumber = 3;
					loop = 0;
					strcpy((s + a)->Sub[i].Grade, "B0");
				}
				else if ((strcmp((s + a)->Sub[i].Grade, "C+") == 0) || (strcmp((s + a)->Sub[i].Grade, "c+") == 0))
				{
					GradeNumber = 2.5;
					loop = 0;
					strcpy((s + a)->Sub[i].Grade, "C+");
				}
				else if (((strcmp((s + a)->Sub[i].Grade, "C") == 0) || (strcmp((s + a)->Sub[i].Grade, "C0")) == 0) || ((strcmp((s + a)->Sub[i].Grade, "c") == 0) || (strcmp((s + a)->Sub[i].Grade, "c0") == 0)))
				{
					GradeNumber = 2;
					loop = 0;
					strcpy((s + a)->Sub[i].Grade, "C0");
				}
				else if ((strcmp((s + a)->Sub[i].Grade, "D+") == 0) || (strcmp((s + a)->Sub[i].Grade, "d+") == 0))
				{
					GradeNumber = 1.5;
					loop = 0;
					strcpy((s + a)->Sub[i].Grade, "D+");
				}
				else if (((strcmp((s + a)->Sub[i].Grade, "D") == 0) || (strcmp((s + a)->Sub[i].Grade, "D0")) == 0) || ((strcmp((s + a)->Sub[i].Grade, "d") == 0) || (strcmp((s + a)->Sub[i].Grade, "d0") == 0)))
				{
					GradeNumber = 1;
					loop = 0;
					strcpy((s + a)->Sub[i].Grade, "D0");

				}
				else if ((strcmp((s + a)->Sub[i].Grade, "F") == 0) || (strcmp((s + a)->Sub[i].Grade, "f") == 0))
				{
					GradeNumber = 0;
					loop = 0;
					strcpy((s + a)->Sub[i].Grade, "F");
				}

				else
				{
					cout << "잘못된 입력입니다.\n";
					loop = 1; //성적 외 다른 문자열이 입력된 경우 while문이 다시 실행되고, 성적을 다시 입력받습니다.
				}
			}

			(s+a)->Sub[i].GPA = (s+a)->Sub[i].Hakjum * GradeNumber; //과목평점은 따로 함수로 처리하지 않고, 이처럼 학생정보입력 함수 내에서 간단하게 처리합니다.

		}

	}

	cal_avg(&s[0]); //학생 한 명의 성적 정보를 모두 입력받으면, 교과목 평균평점을 계산 함수를 실행합니다. 

}




//학생의 교과목 평균평점을 계산해주는 함수입니다. 과목별 평점을 모두 합산한 뒤, 이를 총 학점으로 나누어 평균평점을 도출합니다.
void cal_avg(st* s) {
	for (int i = 0; i < 2; i++)
	{
		double totalgpa = 0; // 학생의 총평점을 저장합니다.
		double totalHakjum = 0; //학생의 총 학점수를 저장합니다.
		for (int j = 0; j < 3; j++) { // 두 변수에 과목별 정보를 모두 저장하기 위해 세 번 반복됩니다.
			totalgpa += (s + i)->Sub[j].GPA;
			totalHakjum += (s + i)->Sub[j].Hakjum;
		}

		(s + i)->AveGPA = totalgpa / totalHakjum; //student.AveGPA에 평균평점을 저장합니다.
	}

}


/*학생 정보 출력 함수입니다. 출력 정보에 대한 정렬이 필요한 경우는 cout.width 함수를 사용했습니다.
학생의 정보가 구조체 배열에 저장되므로 모든 출력은 주소값을 통해 수행되도록 작성했습니다.*/
void std_out(st* s) {

	cout << "\n\n                   전체 학생 성적 보기\n";
	cout << "============================================================\n\n";
	
	for (int b = 0; b < 2; b++) { //이하의 화면이 학생별로 한 번씩, 총 두 번 출력됩니다.

		cout << "                           이름 : " << (s+b)->StdName << "  학번 : " << (s+b)->Hakbun; 
		cout << "\n============================================================\n";
		cout << "               과목명     과목학점     과목등급     과목평점\n";
		cout << "============================================================\n";

		for (int j = 0; j < 3; j++) { //과목별 과목명, 학점수, 등급, 평점이 하나의 행에 순차적으로 표시됩니다. 
			cout.width(20);
			cout << (s+b)->Sub[j].SubName;
			cout.width(13);
			cout << (s+b)->Sub[j].Hakjum;
			cout.width(13);
			cout << (s+b)->Sub[j].Grade;
			cout.width(13);
			cout << (s+b)->Sub[j].GPA;
			cout << "\n";
		}
		cout << "============================================================\n";
		cout.width(43);
		cout << "평균평점";
		cout.width(13);
		cout << (s + b)->AveGPA << "\n\n"; //cal_avg 함수를 통해 계산된 평균평점이 출력됩니다. 



	}

}