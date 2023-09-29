#include "AddRecruitInfo.h"
#include "AddRecruitInfoUI.h"


/*
    함수 이름 : AddRecruitInfo
    기능: 생성자
    매개변수: RecruitInfoCollection* inputRecruitInfoCollection
    반환값: X
*/
AddRecruitInfo::AddRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection) 
{
    recruitInfoCollection = inputRecruitInfoCollection;

    // Boundary 생성
    AddRecruitInfoUI* boundary = new AddRecruitInfoUI(this);
    this->boundary = boundary;
}


/*
    함수 이름 : getAddRecruitInfoUI
    기능: Boundary를 호출하기 위한 함수
    매개변수: X
    반환값: AddRecruitInfoUI* 타입의 Boundary
*/
AddRecruitInfoUI* AddRecruitInfo::getAddRecruitInfoUI()
{
    return boundary;
}


/*
    함수 이름 : addRecruitInfo
    기능: 채용 정보 등록을 위한 함수
    매개변수: string work -> 업무, string targetNum -> 인원 수, string deadline -> 신청 마감일, string currentLoginId -> 현재 로그인 한 사람의 ID를 매개변수로 보냄
    반환값: X
*/
void AddRecruitInfo::addRecruitInfo(string work, string targetNum, string deadline, string currentLoginId) 
{
    recruitInfoCollection->addRecruitInfo(work, targetNum, deadline, currentLoginId);  // recruitInfoCollection class가 갖고 있는 addRecruitInfo함수 호출하여 RecruitInfo 추가
}