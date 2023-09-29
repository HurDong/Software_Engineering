#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class ApplyImmediately;

/*
클래스 이름 : ApplyImmediatelyUI
기능 : 채용 지원 Boundary
*/
class ApplyImmediatelyUI
{
private:
	ApplyImmediately* control;
	ofstream* fout;
public:
	ApplyImmediatelyUI(ApplyImmediately* inputControl); // 생성자
	void init(ofstream* inputFout); // 파일 입출력을 위한 함수

	void startInterface(); // 인터페이스 시작
	void showApplyImmediately(string inputEvent, string currentLoginId); // 채용 지원을 완료하는 함수
};
