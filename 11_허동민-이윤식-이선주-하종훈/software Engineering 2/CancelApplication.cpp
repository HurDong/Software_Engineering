#include "CancelApplication.h"
#include "CancelApplicationUI.h"

/*
	함수 이름 : CancelApplication
	기능: 생성자
	매개변수: ApplicationInfoCollection* inputApplicationInfoCollection
	반환값: X
*/
CancelApplication::CancelApplication(ApplicationInfoCollection* inputApplicationInfoCollection) 
{

	applicationInfoCollection = inputApplicationInfoCollection;

	CancelApplicationUI* boundary = new CancelApplicationUI(this);
	this->boundary = boundary;

}
/*
	함수 이름 : getCancelApplicationUI
	기능: Boundary를 호출하기 위한 함수
	매개변수: X
	반환값: CancelApplication* 타입의 Boundary
*/
CancelApplicationUI* CancelApplication::getCancelApplicationUI() 
{
	return boundary;
}

/*
	함수 이름 : viewCancelApplication
	기능: currentLoginId와 inputBusinessNum을 지원을 취소하고 취소정보를 반환하기 위한 함수
	매개변수: string currentLoginId, string inputBusinessNum
	반환값: 지원 취소를 완료한 지원 정보를 returnString에 저장
*/
string CancelApplication::viewCancelApplication(string currentLoginId, string inputBusinessNum) 
{
	string returnString;

	returnString = applicationInfoCollection->removeApplicationInfo(currentLoginId, inputBusinessNum);

	return returnString;
}