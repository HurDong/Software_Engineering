#pragma once
#include "RecruitInfoCollection.h"
#include "ApplicationInfoCollection.h"
#include <iostream>
#include <string>

using namespace std;

class ViewRecruitInfoStatsUI;

/*
클래스 이름: ViewRecruitInfoStats
기능: 채용 정보 통계 Control
*/
class ViewRecruitInfoStats{
private:
	ViewRecruitInfoStatsUI* boundary;  //채용 정보 통계 Boundary 클래스 참조 값
	
	RecruitInfoCollection* recruitInfoCollection; //채용 정보 Collection 클래스 참조 값
	ApplicationInfoCollection* applicationInfoCollection; //지원 정보 Collection 클래스 참조 값

public:
	ViewRecruitInfoStats(RecruitInfoCollection* recruitInfoCollection, ApplicationInfoCollection* applicationInfoCollection); //생성자

	ViewRecruitInfoStatsUI* getViewRecruitInfoStatsUI();  //채용 정보 통계 Boundary 클래스 반환

	//boundary -> 2.1 -> control
	string getAddedRecruitInfoStats(string currentLoginId); //회사회원이 등록한 채용 정보 통계 반환
	//boundary -> 3.1 -> control
	string getAppliedRecruitInfoStats(string currentLoginId); //일반회원이 지원한 채용 정보 통계 반환
};
