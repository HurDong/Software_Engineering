#pragma once
#include <iostream>
#include <string>
#include "RecruitInfoCollection.h"

using namespace std;

class AddRecruitInfoUI;

/*
클래스 이름 : AddRecruitInfo
기능 : 채용 정보 추가 Control
*/
class AddRecruitInfo {
private:
	AddRecruitInfoUI* boundary;
	RecruitInfoCollection* recruitInfoCollection;

public:
	AddRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection);	// 생성자
	AddRecruitInfoUI* getAddRecruitInfoUI();	// Boundary를 호출하기 위한 함수

	void addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId);		// 채용 정보 등록을 위한 함수
};