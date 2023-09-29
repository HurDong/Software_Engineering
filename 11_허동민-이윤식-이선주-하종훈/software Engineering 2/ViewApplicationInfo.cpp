#include "ViewApplicationInfo.h"
#include "ViewApplicationInfoUI.h"


/*
	함수 이름 : ViewApplicationInfo
	기능: 생성자
	매개변수: ApplicationInfoCollection* inputApplicationInfoCollection
	반환값: X
*/
ViewApplicationInfo::ViewApplicationInfo(ApplicationInfoCollection* inputApplicationInfoCollection) 
{

	applicationInfoCollection = inputApplicationInfoCollection;

	ViewApplicationInfoUI* boundary = new ViewApplicationInfoUI(this);
	this->boundary = boundary;
}

/*
	함수 이름 : getViewApplicationInfoUI
	기능: Boundary를 호출하기 위한 함수
	매개변수: X
	반환값: ViewApplicationInfoUI* 타입의 바운더리
*/
ViewApplicationInfoUI* ViewApplicationInfo::getViewApplicationInfoUI() 
{
	return boundary;
}

/*
	함수 이름 : viewApplicationList
	기능: currentLoginId를 통해 ApplicationInfo를 반환하기 위한 함수
	매개변수: string currentLoginId
	반환값: string 타입의 returnString
*/
string ViewApplicationInfo::viewApplicationList(string currentLoginId) 
{
	string retrunString = applicationInfoCollection->getApplicationInfo(currentLoginId);
	return retrunString;
}