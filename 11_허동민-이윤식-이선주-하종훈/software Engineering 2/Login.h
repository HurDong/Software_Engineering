#pragma once
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include <iostream>
#include <string>

using namespace std;

class LoginUI;

/*
클래스 이름 : Login
기능 : 로그인 Control
*/
class Login 
{
private:
	LoginUI* boundary;
	MemberCollection* memberCollection;
public:
	Login(MemberCollection* memberCollection);	// 생성자
	LoginUI* getLoginUI();	// Boundary 호출
	bool isLoginVerified(string id, string pwd, string& loginId, int& memberType);	// 로그인 할 수 있는 자격을 갖추었는지 확인하는 함수
};
