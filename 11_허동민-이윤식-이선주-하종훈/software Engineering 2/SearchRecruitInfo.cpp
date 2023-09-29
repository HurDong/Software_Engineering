#include "SearchRecruitInfoUI.h"
#include "SearchRecruitInfo.h"


/*
    함수 이름 : SearchRecruitInfo
    기능: 생성자
    매개변수: RecruitInfoCollection* inputRecruitInfoCollection, MemberCollection* inputMemberCollection
    반환값: X
*/
SearchRecruitInfo::SearchRecruitInfo(RecruitInfoCollection* inputRecruitInfoCollection,MemberCollection* inputMemberCollection) 
{
    recruitInfoCollection = inputRecruitInfoCollection;
    memberCollection = inputMemberCollection;

    SearchRecruitInfoUI* boundary = new SearchRecruitInfoUI(this);
    this->boundary = boundary;
}

/*
    함수 이름 : getSearchRecruitInfoUI
    기능: Boundary를 호출하기 위한 함수
    매개변수: X
    반환값: SearchRecruitInfoUI* 타입의 바운더리
*/
SearchRecruitInfoUI* SearchRecruitInfo:: getSearchRecruitInfoUI() 
{
    return boundary;
}



/*
    함수 이름 : searchRecruitInfo
    기능: 채용 정보 검색을 위한 함수, 단 프로그램 실행 날짜 기준으로 마감일이 지나지 않은 채용 정보만 호출한다.
    매개변수: string name -> 회사이름을 매개변수로 보냄
    반환값: 회사 이름을 기준으로 마감일이 지나지 않은 채용 정보를 str에 저장
*/
string SearchRecruitInfo::searchRecruitInfo(string name) 
{
    string targetId = memberCollection->findIdByName(name); // 회사 ID
    string businessNum = memberCollection->findBusinessNumByName(name); // 회사 사업자번호
    string returnString = recruitInfoCollection->getRecruitInfoWithoutSign(targetId);  // 회사 ID를 이용하여 returnString에 채용 정보를 저장 
    
    int lineNum = count(returnString.begin(), returnString.end(), '\n');
    
    string newString = "> " + name + " " + businessNum + " ";
    stringstream temp(returnString);
    string line;

    vector<string> lines;
    // 회사 ID 기준으로 등록한 채용 정보 중 마감일이 지나지 않은 채용 정보를 str에 저장
    while (getline(temp, line)) 
    {
        lines.push_back(newString + line);
    }
    stringstream result;
    for (size_t i = 0; i < lines.size(); ++i)
    {
        result << lines[i];
        if (i < lines.size())
        {
            result << "\n";
        }
    }
    return result.str();
}