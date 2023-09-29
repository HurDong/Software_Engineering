#include <string>
#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

using namespace std;

/*
	함수 이름 : ApplyImmediatelyUI
	기능: 생성자
	매개변수: ApplyImmediately* inputControl -> Control 참조값
	반환값: X
*/
ApplyImmediatelyUI::ApplyImmediatelyUI(ApplyImmediately* inputControl)
{
	control = inputControl;
}

/*
	함수 이름 : init
	기능: 파일 쓰기를 위한 ofstream 참조 전달
	매개변수: ofstream* inputFout -> ofstream 참조값
	반환값: X
*/
void ApplyImmediatelyUI::init(ofstream* inputFout)
{
	fout = inputFout;
}

/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void ApplyImmediatelyUI::startInterface()
{
	*fout << "4.2. 채용 지원" << endl;
}

/*
    함수 이름 : showApplyImmediately
    기능: 채용 지원 완료 보여주기
    매개변수: string inputEvent -> 입력한 한 줄의 문자열, string currentLoginId -> 현재 로그인한 ID
    반환값: X
*/
void ApplyImmediatelyUI::showApplyImmediately(string inputEvent,string currentLoginId)
{
	stringstream input(inputEvent); // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
	string num1, num2, businessNum; // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

	input >> num1 >> num2 >> businessNum; // 공백을 기준으로 각각의 string을 변수에 담기

	string returnString = control->applyImmediately(businessNum, currentLoginId); // Control의 함수인 applyImmediately 호출 

	*fout <<  returnString << endl << endl; // 채용 지원 성공 시, 파일에 저장
}

