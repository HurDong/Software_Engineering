#include "ViewRecruitInfoStats.h"
#include "ViewRecruitInfoStatsUI.h"

/*
	함수 이름 : ViewRecruitInfoStats
	기능: 생성자
	매개변수: RecruitInfoCollection* inputRecruitInfoCollection -> 채용 정보 Collection 클래스 참조 값
            ApplicationInfoCollection* inputApplicationInfoCollection -> 지원 정보 Collection 클래스 참조 값
	반환값: X
*/
ViewRecruitInfoStats::ViewRecruitInfoStats(RecruitInfoCollection* inputRecruitInfoCollection, ApplicationInfoCollection* inputApplicationInfoCollection)
{
    ViewRecruitInfoStatsUI* boundary = new ViewRecruitInfoStatsUI(this); //Boundary 클래스 생성
    this->boundary = boundary; //Boundary 클래스 참조 값 저장

    recruitInfoCollection = inputRecruitInfoCollection;
    applicationInfoCollection = inputApplicationInfoCollection;
}

/*
	함수 이름 : getViewRecruitInfoStatsUI
	기능: 채용 정보 통계 Boundary 클래스 반환
	매개변수: X
	반환값: ViewRecruitInfoStatsUI* -> 채용 정보 통계 Boundary 클래스 참조 값
*/
ViewRecruitInfoStatsUI* ViewRecruitInfoStats::getViewRecruitInfoStatsUI() 
{
    return boundary;
}

/*
	함수 이름 : getAddedRecruitInfoStats
	기능: 회사 회원이 등록한 채용 정보 통계 반환
	매개변수: string currentLoginId -> 현재 로그인한 회사 회원 아이디
	반환값: string -> 채용 정보 통계 저장
*/
string ViewRecruitInfoStats::getAddedRecruitInfoStats(string currentLoginId)
{
    return recruitInfoCollection-> calcAddedRecruitInfoStats(currentLoginId);
}

/*
	함수 이름 : getAppliedRecruitInfoStats
	기능: 회사회원이 등록한 채용 정보 통계 반환
	매개변수: string currentLoginId -> 현재 로그인한 일반 회원 아이디
	반환값:string -> 채용 정보 통계 저장
*/
string ViewRecruitInfoStats::getAppliedRecruitInfoStats(string currentLoginId)
{
    return applicationInfoCollection->calcAppliedRecruitInfoStats(currentLoginId);
}


