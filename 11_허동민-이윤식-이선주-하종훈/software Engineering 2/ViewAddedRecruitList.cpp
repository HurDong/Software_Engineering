#include "ViewAddedRecruitList.h"
#include "ViewAddedRecruitListUI.h"


/*
    함수 이름 : ViewAddedRecruitList
    기능: 생성자
    매개변수: RecruitInfoCollection* inputRecruitInfoCollection
    반환값: X
*/
ViewAddedRecruitList::ViewAddedRecruitList(RecruitInfoCollection* inputRecruitInfoCollection) 
{
    recruitInfoCollection = inputRecruitInfoCollection;

    ViewAddedRecruitListUI* boundary = new ViewAddedRecruitListUI(this);
    this->boundary = boundary;
}


/*
    함수 이름 : getViewAddedRecruitListUI
    기능: Boundary를 호출하기 위한 함수
    매개변수: X
    반환값: ViewAddedRecruitListUI* 타입의 바운더리
*/
ViewAddedRecruitListUI* ViewAddedRecruitList::getViewAddedRecruitListUI() 
{
    return boundary;
}



/*
    함수 이름 : viewAddedRecruitList
    기능: currentLoginId를 통해 RecruitInfo를 반환하기 위한 함수
    매개변수: string currentLoginId
    반환값: string 타입의 returnString
*/
string ViewAddedRecruitList::viewAddedRecruitList(string currentLoginId) 
{
    string returnString = recruitInfoCollection->getRecruitInfo(currentLoginId);  // recruitInfoCollection에서 해당하는 정보 모두 반환
    return returnString;
}