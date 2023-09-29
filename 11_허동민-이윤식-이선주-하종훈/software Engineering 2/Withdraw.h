#pragma once
#include <iostream>
#include <string>
#include "MemberCollection.h"
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"

using namespace std;

class WithdrawUI;


/*
클래스 이름 : Withdraw
기능 : 회원탈퇴 Control
*/
class Withdraw 
{
private:
	WithdrawUI* boundary;
	MemberCollection* memberCollection;
	ApplicationInfoCollection* applicationInfoCollection;
	RecruitInfoCollection* recruitInfoCollection;

public:
	Withdraw(MemberCollection* inputMemberCollection, RecruitInfoCollection* inputRecruitInfoCollection,
			 ApplicationInfoCollection* inputApplicationInfoCollection);	// 생성자
	WithdrawUI* getWithdrawUI();	// 바운더리 호출
	void withdrawMember(string& loginId, int& memberType);// 회원 삭제
};