#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "RecruitInfoCollection.h"
#include "MemberCollection.h"

using namespace std;

class SearchRecruitInfoUI;

/*
클래스 이름 : SearchRecruitInfo
기능 : 채용 정보 검색 Control
*/
class SearchRecruitInfo {
private:
	SearchRecruitInfoUI* boundary;
	RecruitInfoCollection* recruitInfoCollection;
	MemberCollection* memberCollection;
public:
	SearchRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection, MemberCollection* inputMemberCollection); // 생성자
	SearchRecruitInfoUI* getSearchRecruitInfoUI(); // Boundary를 호출하기 위한 함수

	string searchRecruitInfo(string name); // 채용 정보 검색을 위한 함수
	
};