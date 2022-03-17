#include <iostream>
#include <cstdlib>

using namespace std;

struct Subject{//과목 정보
	char SubName[30];  //과목이름
	int Hakjum;  //과목학점
	char Grade[10];  //과목등급
	float GPA;	//과목 평점
};
struct Student{//학생정보
	char StdName[30];	//학생이름
	int Hakbun;	//학번
	Subject Sub[3];	//과목
	float AveGPA;	//교과목 평균 평점
};

void selected_menu(int choice);	//기능 불러오는 함수
float get_gradenum(char grade[]);	//입력 받은 학점을 평점으로 바꿔주는 함수

int load_menu();	//메뉴 출력

struct Student stu_list[2]; //학생 수: 2명

int main()
{
	while(1)
	{
		int choice = load_menu();	//메뉴를 불러와 선택 저장
		selected_menu(choice);		//기능 불러오기
	}
	return EXIT_SUCCESS;	//정상종료
}
int load_menu()	//메뉴 불러오기
{
	int choice;
	cout << "----- 메뉴 -----" << endl;
	cout << "1. 학생 성적 입력" << endl;
	cout << "2. 전체 학생 성적 보기" << endl;
	cout << "3. 프로그램 종료\n" << endl;
	cout << "원하는 기능을 입력하세요: ";
	cin >> choice;
	if (choice == 3)	//3입력시 종료
	{
		cout << "\n프로그램을 종료합니다.";
		exit(0);
	}
	if (1 > choice || choice > 3) 
	{
		cout << "잘못입력하셨습니다. \n" << endl;
		load_menu();
	}
	return choice;
}
void selected_menu(int choice)		//기능 불러오기
{
	switch (choice)
	{
		case 1:	//학생의 정보입력
			for (int k = 0; k < 2; k++)
			{
				cout << "* " << k+1 << " 번째 학생 이름과 학번을 입력하세요." << endl;
				cout << "이름 : ";
				cin >> stu_list[k].StdName;
				cout << "학번 : ";
				cin >> stu_list[k].Hakbun;
				cout << "\n\n\n" << endl;

				cout << "* 수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n" << endl;
				
				float add_GPA = 0;

				for (int i = 0; i < 3; i++)
				{
					cout << "교과목명 : ";
					cin >> stu_list[k].Sub[i].SubName;
					cout << "과목학점수 : ";
					cin >> stu_list[k].Sub[i].Hakjum;
					cout << "과목등급(A+~F) : ";
					cin >> stu_list[k].Sub[i].Grade;
					stu_list[k].Sub[i].GPA = stu_list[k].Sub[i].Hakjum * get_gradenum(stu_list[k].Sub[i].Grade); // 교과목 평점 계산
					
					add_GPA += stu_list[k].Sub[i].GPA;	// 과목평점 더하기
					stu_list[k].AveGPA = add_GPA / 3;	//개인 학생의 교과목 평균 평점 계산
					cout << "\n";
				}
			}
			cout << "\n\n\n" << endl;
			break;
		case 2: //전체 학생의 신상/성적 정보 출력
			cout << "\n		전체학생 성적보기" << endl;
			cout << "=======================================================" << endl;
			for (int i = 0; i < 2; i++)
			{
				cout.width(10);
				cout << "이름: " << stu_list[i].StdName;
				cout.width(10);
				cout<< "학번: " << stu_list[i].Hakbun << endl;
				cout << "=======================================================" << endl;
				cout.width(10);
				cout << "과목명 ";
				cout.width(10);
				cout << "과목학점 ";
				cout.width(10);
				cout << "과목등급 ";
				cout.width(10);
				cout << "과목평점 " << endl;
				cout << "=======================================================" << endl;
				for (int k = 0; k < 3; k++)
				{
					cout.width(10);
					cout << stu_list[i].Sub[k].SubName;
					cout.width(10);
					cout << stu_list[i].Sub[k].Hakjum;
					cout.width(10);
					cout << stu_list[i].Sub[k].Grade;
					cout.width(10);
					cout << fixed;
					cout.precision(2);
					cout << stu_list[i].Sub[k].GPA << endl;
				}
				cout << "=======================================================" << endl;
				cout << "\t\t\t\t\t\t평균 평점: " << "\t";
				cout << fixed;
				cout.precision(2);
				cout << stu_list[i].AveGPA << endl;
			}
			break;
	}
}
float get_gradenum(char grade[]) //입력 받은 문자를 평점으로 변환
{
	float gradenum;
	switch (grade[0])
	{
	case 'A':
		gradenum = (grade[1] == '+') ? 4.5 : 4.0;
		break;
	case 'B':
		gradenum = (grade[1] == '+') ? 3.5 : 3.0;
		break;
	case 'C':
		gradenum = (grade[1] == '+') ? 2.5 : 2.0;
		break;
	case 'D':
		gradenum = (grade[1] == '+') ? 1.5 : 1.0;
		break;
	default:
		if (grade[0] == 'F')
			gradenum = 0;
		else
		{
			cout << "잘못입력하셨습니다.\n" << endl;
			cout << "과목등급(A+~F) : ";
			cin >> grade;
			gradenum = get_gradenum(grade);	//***잘못 입력된 경우 다시 입력 받고 변환
		}
		break;
	}
	return gradenum;
}