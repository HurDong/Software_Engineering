#include "ApplyImmediatelyUI.h"
#include "ApplyImmediately.h"

/*
	함수 이름 : ApplyImmediately
	기능: 생성자
	매개변수: ApplyImmediately* inputControl
			 RecruitInfoCollection* inputRecruitInfoCollection 
			 MemberCollection* inputMemberCollection 
	반환값: X
*/
ApplyImmediately::ApplyImmediately(ApplicationInfoCollection* inputApplicationInfoCollection,
								   RecruitInfoCollection* inputRecruitInfoCollection,MemberCollection* inputMemberCollection)
{
	applicationInfoCollection = inputApplicationInfoCollection;
	recruitInfoCollection = inputRecruitInfoCollection;
	memberCollection = inputMemberCollection;
	ApplyImmediatelyUI* boundary = new ApplyImmediatelyUI(this);
	this->boundary = boundary;
}

/*
    함수 이름 : getApplyImmediatelyUI
    기능: Boundary를 호출하기 위한 함수
    매개변수: X
    반환값: ApplyImmediately* 타입의 Boundary
*/
ApplyImmediatelyUI* ApplyImmediately::getApplyImmediatelyUI()
{
	return boundary;
}

/*
    함수 이름 : applyImmediately
    기능: 채용 지원을 위한 함수
    매개변수: string businessNum -> 사업자 번호, string currentLoginId -> 현재 로그인한 ID를 매개변수로 보냄
    반환값: 채용 지원을 완료한 채용 정보를 returnSTring에 저장
*/
string ApplyImmediately::applyImmediately(string businessNum, string currentLoginId)
{
	string companyId = memberCollection->findIdByBusinessNum(businessNum);
	string companyName = memberCollection->findNameById(companyId);
	RecruitInfo* companyRecruitInfo = recruitInfoCollection->findByCompanyId(companyId);

	applicationInfoCollection->addApplicationInfo(companyRecruitInfo,currentLoginId);
	string companyWork = recruitInfoCollection->findWorkById(companyId);
	string returnString= "> " + companyName + " " + businessNum + " " + companyWork;
	
	return returnString;
}