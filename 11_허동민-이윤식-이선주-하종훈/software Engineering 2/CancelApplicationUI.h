#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CancelApplication;

/*
클래스 이름 : CancelApplicationUI
기능 : 지원 취소 Boundary
*/
class CancelApplicationUI {
private:
	CancelApplication* control;
	ofstream* fout;

public:
	CancelApplicationUI(CancelApplication* inputControl);		// 생성자
	void init(ofstream* inputFout);									// 파일 입출력을 위한 함수

	void startInterface();		// 인터페이스 시작	
	void showCancelApplication(string currentLoginId, string inputEvent);	
};