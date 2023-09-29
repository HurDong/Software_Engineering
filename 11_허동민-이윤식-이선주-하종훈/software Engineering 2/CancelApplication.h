#pragma once
#include <iostream>
#include <string>
#include "ApplicationInfoCollection.h"

using namespace std;

class CancelApplicationUI;

/*
클래스 이름 : CancelApplication
기능 : 지원 취소 Control
*/
class CancelApplication {
private:
	CancelApplicationUI* boundary;
	ApplicationInfoCollection* applicationInfoCollection;
public:
	CancelApplication(ApplicationInfoCollection* inputApplicationInfoCollection);	// 생성자
	CancelApplicationUI* getCancelApplicationUI();	// Boundary를 호출하기 위한 함수

	string viewCancelApplication(string currentLoginId, string inputBusinessNum);		
};