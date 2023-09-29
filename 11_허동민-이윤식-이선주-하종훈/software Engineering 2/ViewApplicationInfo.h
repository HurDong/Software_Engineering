#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"

using namespace std;

class ViewApplicationInfoUI;

/*
클래스 이름 : AddRecruitInfo
기능 : 지원 정보 조회 Control
*/
class ViewApplicationInfo {
private:
	ViewApplicationInfoUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
public:
	ViewApplicationInfo(ApplicationInfoCollection* inputApplicationInfoCollection);	// 생성자
	ViewApplicationInfoUI* getViewApplicationInfoUI();	// Boundary를 호출하기 위한 함수

	string viewApplicationList(string currentLoginId);		// Application List를 조회하기 위한 함수
};