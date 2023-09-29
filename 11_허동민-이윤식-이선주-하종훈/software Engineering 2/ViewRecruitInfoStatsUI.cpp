#include "ViewRecruitInfoStatsUI.h"
#include "ViewRecruitInfoStats.h"

/*
	함수 이름 : ViewRecruitInfoStatsUI
	기능: 생성자
	매개변수: ViewRecruitInfoStats* inputControl -> 채용 정보 통계 Control 클래스 참조 값
	반환값: X
*/
ViewRecruitInfoStatsUI::ViewRecruitInfoStatsUI(ViewRecruitInfoStats* inputControl)
{
    control = inputControl;
}

/*
	함수 이름 : init
	기능: 파일 쓰기용 ofstream 참조 값 지정
	매개변수: ofstream* inputFout -> ofstream 참조 값
	반환값: X
*/
void ViewRecruitInfoStatsUI::init(ofstream* inputFout) {
    fout = inputFout;
}

/*
	함수 이름 : startInterface
	기능: 사용자가 선택한 메뉴 output.txt에 출력
	매개변수: X
	반환값: X
*/
void ViewRecruitInfoStatsUI::startInterface() {
    *fout << "5.1 지원 정보 통계" << endl;
}

/*
	함수 이름 : requestAddedRecruitInfoStats
	기능: 회사 회원이 등록한 채용 정보 통계 Control 클래스에게 요청
	매개변수: string currentLoginId -> 현재 로그인한 회사 회원 아이디 
	반환값: X
*/
void ViewRecruitInfoStatsUI::requestAddedRecruitInfoStats(string currentLoginId)
{   
    string recruitInfoStats = control->getAddedRecruitInfoStats(currentLoginId);
    _showRecruitInfoStatsInterface(recruitInfoStats);
}

/*
	함수 이름 : requestAppliedRecruitInfoStats
	기능: 일반 회원이 지원한 채용 정보 통계 Control 클래스에게 요청
	매개변수: string currentLoginId -> 현재 로그인한 일반 회원 아이디 
	반환값: X
*/
void ViewRecruitInfoStatsUI::requestAppliedRecruitInfoStats(string currentLoginId) {
    string recruitInfoStats = control->getAppliedRecruitInfoStats(currentLoginId);
    _showRecruitInfoStatsInterface(recruitInfoStats);
}

/*
	함수 이름 : requestAppliedRecruitInfoStats
	기능: Control 클래스에서 받아온 채용 정보 통계 output.txt에 출력
	매개변수: string recruitInfoStats -> 채용 정보 통계 저장
	반환값: X
*/
void ViewRecruitInfoStatsUI::_showRecruitInfoStatsInterface(string recruitInfoStats)
{   
        *fout << recruitInfoStats << endl;
}
