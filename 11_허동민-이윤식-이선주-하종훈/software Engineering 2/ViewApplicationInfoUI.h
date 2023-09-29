#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ViewApplicationInfo;

/*
클래스 이름 : AddRecruitInfoUI
기능 : 지원 정보 조회 Boundary
*/
class ViewApplicationInfoUI {
private:
	ViewApplicationInfo* control;
	ofstream* fout;
public:
	ViewApplicationInfoUI(ViewApplicationInfo* inputControl);		// 생성자
	void init(ofstream* inputFout);									// 파일 입출력을 위한 함수

	void startInterface();		// 인터페이스 시작
	void showApplicationInfo(string currentLoginId);		// 조회를 진행하고, 조회 완료된 애들을 파일에 기록
};