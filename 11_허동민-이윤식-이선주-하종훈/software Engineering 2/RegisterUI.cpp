#include "RegisterUI.h"
#include "Register.h"
#include <string>
using namespace std;

/*
	함수 이름 : RegisterUI
	기능: 생성자
	매개변수: Register* inputControl -> 컨트롤 참조값
	반환값: X
*/
RegisterUI::RegisterUI(Register* inputControl)
{
    control = inputControl;
}

/*
	함수 이름 : init
	기능: 파일 쓰기를 위한 ofstream 참조 전달
	매개변수: ofstream* inputFout -> ofstream 참조값
	반환값: X
*/
void RegisterUI::init(ofstream* inputFout)
{
    fout = inputFout;
}

/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void RegisterUI::startInterface() 
{
    *fout << "1.1. 회원가입" << endl;  // 유저가 입력한 내용 화면에 띄우기. 이에 대한 응답은 boundary에서 실현
}

/*
    함수 이름 : selectMemberType
    기능: 파일의 한 줄을 읽고, 회원의 Type에 맞게 값을 반환
    매개변수: string inputEvent -> 파일에서 방금 읽어들인 한 줄의 내용
    반환값: 회사 회원이면 1, 일반 회원이면 2를 반환
*/
int RegisterUI::selectMemberType(string inputEvent) 
{
    return inputEvent[4] - '0';
}

/*
    함수 이름 : requestRegister
    기능: 회원가입 Boundary의 함수로써, 회원 가입 Control에게 회원 가입을 요청하는 역할
    매개변수: MemberCollection& memberCollection -> 회원 가입 완료 시, memberCollection에 저장
              string inputEvent -> 파일에서 방금 읽어들인 한 줄의 내용
              int memberType -> 1: 회사 회원, 2: 일반 회원
    반환값: X
*/
void RegisterUI::requestRegister(string inputEvent, int memberType) 
{
    // 다음에 사용될 함수의 매개변수에 char* type을 넣기 위해 string 자르기
    stringstream input(inputEvent);     // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, num3, name, num, id, pwd;    // 공백을 기준으로 잘라진 애들을 넣을 string 변수 생성

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // 공백을 기준으로 각 변수에 string이 넣어짐

    // 1.1.1인지 1.1.2인지는 이 switch case문에서 결정
    switch (memberType) {
    case 1:             // 회사 회원인 경우
        control->registerCompanyMember(name, num, id, pwd, 1);     // Control의 함수인 registerCompanyMember 호출
        _showRegisterSuccessInterface(inputEvent, 1);
        break;
    case 2:             // 일반 회원인 경우
        control->registerGeneralMember(name, num, id, pwd, 2);     // Control의 함수인 registerGeneralMember 호출
        _showRegisterSuccessInterface(inputEvent, 2);
        break;
    }
}

/*
    함수 이름 : showRegisterSuccessInterface
    기능: 회원 가입 완료 시 파일에 내용 저장 역할
    매개변수: string inputEvent -> 파일에 저장할 name, num, id, pwd를 파싱하기 위한 매개변수
              memberType -> 회사 회원, 일반 회원에 맞는 번호를 파일에 저장하기 위한 매개변수
    반환값: X
*/
void RegisterUI::_showRegisterSuccessInterface(string inputEvent, int memberType) 
{
    // 파일에 내용을 기입하기 위해 string 자르기
    stringstream input(inputEvent);     // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, num3, name, num, id, pwd;    // 공백을 기준으로 잘라진 애들을 넣을 string 변수 생성

    input >> num1 >> num2 >> num3 >> name >> num >> id >> pwd;      // 공백을 기준으로 각 변수에 string이 넣어짐

    *fout << "> " << memberType << " " << name << " " << num << " " << id << " " << pwd << endl << endl;    // 파일에 회원 가입 정보 기입
}
