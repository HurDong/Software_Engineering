#include "LoginUI.h"
#include "Login.h"
#include <string>
using namespace std;

/*
	함수 이름 : LoginUI
	기능: 생성자
	매개변수: Login* inputControl -> Control 참조값
	반환값: X
*/
LoginUI::LoginUI(Login* inputControl)
{
    control = inputControl;
}

/*
	함수 이름 : init
	기능: 파일 쓰기를 위한 ofstream 참조 전달
	매개변수: ofstream* inputFout -> ofstream 참조값
	반환값: X
*/
void LoginUI::init(ofstream* inputFout)
{
    fout = inputFout;
}


/*
    함수 이름 : startInterface
    기능: 유저가 입력한 내용 화면에 띄우기
    매개변수: X
    반환값: X
*/
void LoginUI::startInterface() {
    *fout << "2.1. 로그인" << endl;  // 유저가 입력한 내용 화면에 띄우기
}

/*
    함수 이름 : isLoginValid
    기능: 로그인 Boundary의 함수로써, 로그인의 Control에 로그인을 요청하는 역할
    매개변수: MemberCollection& memberCollection -> memberCollection에 저장되어있는 애인지 확인하기 위해 보내는 argument
              const char* name -> 이름
              const char* num -> 주민등록번호
              const char* id -> ID
              const char* pwd -> Password
              string& loginId -> 현재 login한 ID를 저장해 오기 위한 변수
              int memberType -> 회사 회원, 일반 회원에 따라 memberType값을 저장해 오기 위한 변수
    반환값: X
*/
void LoginUI::verifyLogin(string inputEvent, string& currentLoginId, int& currentMemberType) 
{
    // 다음에 호출할 함수의 매개변수에 const char* type을 넣기 위한 작업
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, id, pwd;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> id >> pwd;     // 공백을 기준으로 각각의 string을 변수에 담기

    if (control->isLoginVerified(id, pwd, currentLoginId, currentMemberType)){
        _showLoginSuccessInterface(inputEvent); 
    }
    else{
        _showLoginFailInterface(); 
    }
    return;
}

/*
    함수 이름 : showLoginSuccessInterface
    기능: 로그인 성공 시 파일에 내용 저장 역할
    매개변수: string inputEvent -> 파일에 저장할 id와 pwd를 파싱하기 위한 매개변수
    반환값: X
*/

void LoginUI::_showLoginSuccessInterface(string inputEvent) 
{
    stringstream input(inputEvent);      // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
    string num1, num2, id, pwd;     // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

    input >> num1 >> num2 >> id >> pwd;     // 공백을 기준으로 각각의 string을 변수에 담기


    *fout << "> " << id << " " << pwd << endl << endl;       // 로그인 성공 시, 나머지 내용 (id, pwd)을 파일에 저장
}


/*
    함수 이름 : showLoginFailInterface
    기능: 로그인 실패 시 파일에 내용 저장 역할
    매개변수: X
    반환값: X
*/
void LoginUI::_showLoginFailInterface() 
{
    *fout << endl;        // 로그인 실패 시, 개행만 두 번 실행한 결과를 파일에 저장
}