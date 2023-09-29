#include "WithdrawUI.h"
#include "Withdraw.h"

/*
	함수 이름 : WithdrawUI
	기능: 생성자
	매개변수: Withdraw* inputControl -> 컨트롤 참조값
	반환값: X
*/
WithdrawUI::WithdrawUI(Withdraw* inputControl)
{
    control = inputControl;
}

/*
	함수 이름 : init
	기능: 파일 쓰기를 위한 ofstream 참조 전달
	매개변수: ofstream* inputFout -> ofstream 참조값
    반환값: X
*/
void WithdrawUI::init(ofstream* inputFout)
{
	fout = inputFout;
}

/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void WithdrawUI::startInterface() 
{
    *fout << "1.2. 회원탈퇴" << endl;     // 유저가 입력한 내용 화면에 띄우기
}

/*
    함수 이름 : requestWithdraw
    기능: 회원탈퇴 Boundary의 함수로써, 회원탈퇴의 Control에 회원탈퇴를 요청하는 역할
    매개변수: MemberCollection& memberCollection -> 회원 탈퇴를 요청한 회원을 찾고, 정보를 삭제하기 위해 매개변수로 전달
              string& loginId -> 현재 login한 ID를 ""로 돌려놓기 위한 매개변수
              int memberType -> memberType을 0으로 돌려놓기 위한 매개변수
    반환값: X
*/
void WithdrawUI::requestWithdraw(string& loginId, string tempId, int& memberType) 
{
    control->withdrawMember(loginId, memberType);     // 회원 탈퇴를 위한 함수 호출
    _showWithdrawId(tempId);
}

/*
    함수 이름 : showWithdrawId
    기능: 회원 탈퇴 성공 시 파일에 내용 저장 역할
    매개변수: string withdrawId -> 파일에 저장할 id를 위한 매개변수
    반환값: X
*/
void WithdrawUI::_showWithdrawId(string withdrawId) 
{
    *fout << "> " << withdrawId << endl << endl;        // 파일에 내용 기입
}
