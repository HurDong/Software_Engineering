#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Register;

/*
클래스 이름 : RegisterUI
기능 : 회원가입 Boundary
*/
class RegisterUI 
{
private:
	Register* control;
	ofstream* fout;

	void _showRegisterSuccessInterface(string inputEvent, int memberType);		// 회원 가입 성공 화면 파일에 저장
public:
	RegisterUI(Register* inputControl);		// 생성자
	void init(ofstream* inputFout); 		// 파일 입출력을 위한 함수

	void startInterface();		// 인터페이스 시작
	int selectMemberType(string inputEvent);		// 회사 회원인지, 일반 회원인지 member type 고르기
	void requestRegister(string inputEvent, int memberType);		// 회원 가입 요청
};