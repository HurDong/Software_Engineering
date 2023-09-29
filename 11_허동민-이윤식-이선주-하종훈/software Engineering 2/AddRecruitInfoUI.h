#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class AddRecruitInfo;


/*
클래스 이름 : AddRecruitInfoUI
기능 : 채용 정보 추가 Boundary
*/
class AddRecruitInfoUI {
private:
	AddRecruitInfo* control;
	ofstream* fout;

	void _showAddedRecruitInfo(string inputEvent);		// 추가가 완료되면 파일에 기록
public:
	AddRecruitInfoUI(AddRecruitInfo* inputControl);		// 생성자
	void init(ofstream* inputFout);						// 파일 입출력을 위한 함수

	void startInterface();		// 인터페이스 시작
	void requestAddRecruitInfo(string inputEvent, string currentLoginId);		// recruitInfoCollection에 recruitInfo를 추가하는 함수 호출
};