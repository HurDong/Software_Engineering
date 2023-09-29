#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"
#include "RecruitInfoCollection.h"
#include "MemberCollection.h"

using namespace std;

class ApplyImmediatelyUI;

/*
클래스 이름 : ApplyImmediately
기능 : 채용 지원 Control
*/
class ApplyImmediately
{
private:
	ApplyImmediatelyUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
	RecruitInfoCollection* recruitInfoCollection;
	MemberCollection* memberCollection;
public:
	ApplyImmediately(ApplicationInfoCollection* inputApplicationInfoCollection,
					 RecruitInfoCollection* inputRecruitInfoCollection,MemberCollection* inputMemberCollection); // 생성자

	ApplyImmediatelyUI* getApplyImmediatelyUI(); // Boundary를 호출하기 위한 함수

	string applyImmediately(string businessNum, string currentLoginId); // 채용 지원을 완료하기 위한 함수
};

