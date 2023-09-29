#include <string>
#include "AddRecruitInfoUI.h"
#include "AddRecruitInfo.h"
using namespace std;


/*
	함수 이름 : AddRecruitInfoUI
	기능: 생성자
	매개변수: AddRecruitInfo* inputControl -> Control 참조값
	반환값: X
*/
AddRecruitInfoUI::AddRecruitInfoUI(AddRecruitInfo* inputControl) 
{
	control = inputControl;
}

/*
	함수 이름 : init
	기능: 파일 쓰기를 위한 ofstream 참조 전달
	매개변수: ofstream* inputFout -> ofstream 참조값
	반환값: X
*/
void AddRecruitInfoUI::init(ofstream* inputFout) 
{
	fout = inputFout;
}


/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void AddRecruitInfoUI::startInterface() 
{
    *fout << "3.1. 채용 정보 등록" << endl;     // 유저가 입력한 내용 화면에 띄우기
}


/*
    함수 이름 : requestRecruitInfo
    기능: 유저가 채용정보 등록 요청하기
    매개변수: string inputEvent -> 입력한 한 줄의 문자열, string currentLoginId -> 현재 로그인 한 사람의 ID를 매개변수로 보냄
    반환값: X
*/
void AddRecruitInfoUI::requestAddRecruitInfo(string inputEvent, string currentLoginId) 
{
    // 다음에 사용될 함수의 매개변수에 char* type을 넣기 위해 string 자르기
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, work, targetNum, deadline;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // 공백을 기준으로 각각의 string을 변수에 담기

    control->addRecruitInfo(work, targetNum, deadline, currentLoginId);     // Control의 함수인 addRecruitInfo 호출

    _showAddedRecruitInfo(inputEvent);
}


/*
    함수 이름 : showAddedRecruitInfo
    기능: 등록된 채용정보 보여주기
    매개변수: string inputEvent -> 입력한 한 줄의 문자열
    반환값: X
*/
void AddRecruitInfoUI::_showAddedRecruitInfo(string inputEvent) 
{
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, work, targetNum, deadline;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> work >> targetNum >> deadline;     // 공백을 기준으로 각각의 string을 변수에 담기

    *fout << "> " << work << " " << targetNum << " " << deadline << endl << endl;       // 채용 정보 등록 성공 시, 파일에 저장
}
