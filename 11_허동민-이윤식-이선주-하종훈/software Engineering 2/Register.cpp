#include "Register.h"
#include "RegisterUI.h"

/*
	함수 이름 : Register
	기능: 생성자
	매개변수: MemberCollection* inputMemberCollection -> MemberCollection 포인터 배열
	반환값: X
*/
Register::Register(MemberCollection* inputMemberCollection) 
{
    memberCollection = inputMemberCollection;

    RegisterUI* boundary = new RegisterUI(this);
    this->boundary = boundary;
}


/*
	함수 이름 : getRegisterUI
	기능: 바운더리 반환
	매개변수: X
	반환값: RegisterUI* 타입의 바운더리
*/
RegisterUI* Register::getRegisterUI()
{
    return boundary;
}

/*
    함수 이름 : registerCompanyMember
    기능: 회사 회원을 새로 등록함
    매개변수: MemberCollection& memberCollection -> 회원 가입 완료 시, memberCollection에 저장
              const char* name -> 이름
              const char* num -> 사업자 번호
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 1 (회사 회원)
    반환값: X
*/
void Register::registerCompanyMember(
    string name, string num, string id, string pwd, int memberType)
{
    memberCollection->addMember(name, num, id, pwd, memberType);  // memberCollection class가 갖고 있는 addMember함수 호출하여 Member 추가
}

/*
    함수 이름 : registerGeneralMember
    기능: 일반 회원을 새로 등록함
    매개변수: MemberCollection& memberCollection -> 회원 가입 완료 시, memberCollection에 저장
              const char* name -> 이름
              const char* num -> 주민등록번호
              const char* id -> ID
              const char* pwd -> Password
              int memberType -> 2 (일반 회원)
    반환값: X
*/
void Register::registerGeneralMember(
   string name, string num, string id, string pwd, int memberType)
{
     // 그 객체에 GeneralMember 생성자 만들어 넣기
    memberCollection->addMember(name, num, id, pwd, memberType);  // memberCollection class가 갖고 있는 addMember함수 호출하여 Member 추가
}