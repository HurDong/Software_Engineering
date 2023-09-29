#include "ViewApplicationInfoUI.h"
#include "ViewApplicationInfo.h"

/*
	함수 이름 : ViewApplicationInfoUI
	기능: 생성자
	매개변수: ViewApplicationInfo* inputControl -> 컨트롤 참조값
	반환값: X
*/
ViewApplicationInfoUI::ViewApplicationInfoUI(ViewApplicationInfo* inputControl) 
{
	control = inputControl;
}
/*
	함수 이름 : init
	기능: 파일 쓰기를 위한 ofstream 참조 전달
	매개변수: ofstream* inputFout -> ofstream 참조값
	반환값: X
*/
void ViewApplicationInfoUI::init(ofstream* inputFout) 
{
	fout = inputFout;
}
/*
	함수 이름 : startInterface
	기능: 유저가 입력한 내용 화면에 띄우기
	매개변수: X
	반환값: X
*/
void ViewApplicationInfoUI::startInterface() 
{
	*fout << "4.3. 지원 정보 조회" << endl;
}

/*
	함수 이름 : showApplicationInfo
	기능: 일반 회원의 지원정보를 모두 화면에 띄우기
	매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
	반환값: X
*/
void ViewApplicationInfoUI::showApplicationInfo(string currentLoginId) 
{

	string returnString = control->viewApplicationList(currentLoginId);

	*fout << returnString << endl;

}