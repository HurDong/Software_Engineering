#pragma once
#include <string>
using namespace std;

class LogoutUI;

/*
클래스 이름 : LoginUI
기능 : 로그아웃 Control
*/
class Logout 
{
private:
	LogoutUI* boundary;
	
public:
	Logout();	// 생성자
	LogoutUI* getLogoutUI();	// Boundary 호출
	void logoutMember(string& loginId, int& memberType);  	// 로그아웃 진행, loginId를 ""로 비워놓고, memberType은 0으로 돌려놓음
};