#include "CancelApplicationUI.h"
#include "CancelApplication.h"

/*
	함수 이름 : CancelApplicationUI
	기능: 생성자
	매개변수: CancelApplication* inputControl -> 컨트롤 참조값
	반환값: X
*/
CancelApplicationUI::CancelApplicationUI(CancelApplication* inputControl) 
{
	control = inputControl;
}
/*
	함수 이름 : init
	기능: 파일 쓰기를 위한 ofstream 참조 전달
	매개변수: ofstream* inputFout -> ofstream 참조값
	반환값: X
*/
void CancelApplicationUI::init(ofstream* inputFout) 
{
	fout = inputFout;
}
/*
	함수 이름 : startInterface
	기능: 유저가 입력한 내용 화면에 띄우기
	매개변수: X
	반환값: X
*/
void CancelApplicationUI::startInterface() 
{
	*fout << "4.4. 지원 취소" << endl;
}

/*
	함수 이름 : showCancelApplication
	기능: 일반 회원이 지원취소를 하고 취소결과를 파일에 입력하기
	매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID, string inputEvent ->  입력한 한 줄의 문자열
	반환값: X
*/
void CancelApplicationUI::showCancelApplication(string currentLoginId, string inputEvent) 
{
	
	stringstream input(inputEvent);
	string num1, num2, businessNum;

	input >> num1 >> num2 >> businessNum;

	string returnString = control->viewCancelApplication(currentLoginId, businessNum);

	*fout << returnString << endl;

}

