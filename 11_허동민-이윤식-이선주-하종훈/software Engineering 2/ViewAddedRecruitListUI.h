#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class ViewAddedRecruitList;


/*
클래스 이름 : ViewAddedRecruitListUI
기능 : 등록한 채용 정보 조회 Boundary
*/
class ViewAddedRecruitListUI {
private:
	ViewAddedRecruitList* control;
	ofstream* fout;
public:
	ViewAddedRecruitListUI(ViewAddedRecruitList* inputControl);		// 생성자
	void init(ofstream* inputFout);									// 파일 입출력을 위한 함수

	void startInterface();		// 인터페이스 시작
	void showRecruitInfo(string currentLoginId);		// 조회를 진행하고, 조회 완료된 애들을 파일에 기록
};