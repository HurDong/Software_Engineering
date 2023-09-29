#pragma once
#include <iostream>
#include <string>
#include "RecruitInfoCollection.h"

using namespace std;

class ViewAddedRecruitListUI;

/*
클래스 이름 : ViewAddedRecruitList
기능 : 등록한 채용 정보 조회 Control
*/
class ViewAddedRecruitList {
private:
	ViewAddedRecruitListUI* boundary;
	RecruitInfoCollection* recruitInfoCollection;
public:
	ViewAddedRecruitList(RecruitInfoCollection* inputRecruitInfoCollection);	// 생성자
	ViewAddedRecruitListUI* getViewAddedRecruitListUI();	// Boundary를 호출하기 위한 함수

	string viewAddedRecruitList(string currentLoginId);		// 등록된 채용 정보를 모두 확인하는 함수
};