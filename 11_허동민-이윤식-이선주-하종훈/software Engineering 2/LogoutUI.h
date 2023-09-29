#pragma once
#include <string>
#include <fstream>

using namespace std;


class Logout;

/*
클래스 이름 : LoginUI
기능 : 로그아웃 Boundary
*/
class LogoutUI
{
private:
	Logout* control;
	ofstream* fout;

	void _showLogoutId(string logoutId);		// 로그아웃 성공 화면 파일에 저장
public:
	LogoutUI(Logout* inputControl);		// 생성자
	void init(ofstream* inputFout);		// 파일 입출력을 위한 함수

	void startInterface();		// 인터페이스 시작
	void requestLogout(string& loginId, string tempId, int& memberType);	// 로그아웃 요청
};