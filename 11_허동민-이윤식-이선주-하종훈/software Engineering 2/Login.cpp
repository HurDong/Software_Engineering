#include "Login.h"
#include "LoginUI.h"

/*
	함수 이름 : Login
	기능: 생성자
	매개변수: MemberCollection* inputMemberCollection -> MemberCollection 포인터 배열
	반환값: X
*/
Login::Login(MemberCollection* inputMemberCollection)
{
    LoginUI* boundary = new LoginUI(this);
    this->boundary = boundary;
    memberCollection = inputMemberCollection;

}


/*
	함수 이름 : getLoginUI
	기능: boundary 반환
	매개변수: X
	반환값: LoginUI* 타입의 Boundary
*/
LoginUI* Login::getLoginUI(){
    return boundary;
}

/*
    함수 이름 : isLoginVerified
    기능: 로그인 할 수 있는 자격을 갖추었는지 확인하는 함수
    매개변수: MemberCollection& memberCollection -> memberCollection에 저장되어있는 애인지 확인하기 위해 보내는 argument
              string name -> 이름
              string num -> 주민등록번호
              string* id -> ID
              string pwd -> Password
              string& loginId -> 현재 login한 ID를 저장해 오기 위한 변수
              int memberType -> 회사 회원, 일반 회원에 따라 memberType값을 저장해 오기 위한 변수
    반환값: bool 타입의 true 또는 false
*/
bool Login::isLoginVerified(string id, string pwd, string& currentLoginId, int& currentMemberType) 
{
    // 회원이 맞는 경우
    if (memberCollection->isMember(id, pwd)) {
		currentLoginId = id;           // loginId에 방금 로그인을 시도했던 id를 저장
		currentMemberType = memberCollection->getMemberType(id, pwd);       // memberType에 현재 로그인 한 member의 type을 저장
        return true;
    }
    // 회원이 아닌 경우
    else
        return false;
}