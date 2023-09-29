#include <string>
#include "ViewAddedRecruitList.h"
#include "ViewAddedRecruitListUI.h"
using namespace std;


/*
    함수 이름 : ViewAddedRecruitListUI
    기능: 생성자
    매개변수: AddRecruitInfo* inputControl -> 컨트롤 참조값
    반환값: X
*/
ViewAddedRecruitListUI::ViewAddedRecruitListUI(ViewAddedRecruitList* inputControl) 
{
    control = inputControl;
}


/*
    함수 이름 : init
    기능: 파일 쓰기를 위한 ofstream 참조 전달
    매개변수: ofstream* inputFout -> ofstream 참조값
    반환값: X
*/
void ViewAddedRecruitListUI::init(ofstream* inputFout) 
{
    fout = inputFout;
}


/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void ViewAddedRecruitListUI::startInterface() 
{
    *fout << "3.2. 등록된 채용 정보 조회" << endl;     // 유저가 입력한 내용 화면에 띄우기
}



/*
    함수 이름 : showRecruitInfo
    기능: 회사 회원이 등록한 채용 정보를 모두 화면에 띄우기
    매개변수: string currentLoginId -> 현재 로그인 한 사람의 ID
    반환값: X
*/
void ViewAddedRecruitListUI::showRecruitInfo(string currentLoginId) 
{
    string returnString = control->viewAddedRecruitList(currentLoginId);       // recruitInfo의 모든 정보는 returnString에 담겨 있음

    *fout << returnString << endl;       // 채용 정보 등록 성공 시, 파일에 저장
}

