#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h" // 필요한지
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Login;

/*
클래스 이름 : LoginUI
기능 : 로그인 Boundary
*/
class LoginUI 
{
private:
	Login* control;
	ofstream* fout;

	void _showLoginSuccessInterface(string inputEvent);	// 로그인 성공 화면 파일에 저장
	void _showLoginFailInterface();		// 로그인 실패 화면 파일에 저장
public:
	LoginUI(Login* inputControl);	// 생성자
	void init(ofstream* inputFout);	// 파일 입출력을 위한 함수

	void startInterface();		// 인터페이스 시작
	void verifyLogin(string inputEvent, string& currentLoginId, int& currentMemberType);	// 로그인 요청
	
};