#pragma once
#include <fstream>
#include <string>
using namespace std;

class ViewRecruitInfoStats;

/*
클래스 이름: ViewRecruitInfoStatsUI
기능: 채용 정보 통계 Boundary
*/
class ViewRecruitInfoStatsUI
{
private:
	ViewRecruitInfoStats* control; //채용 정보 통계 Control 클래스 참조 값
	ofstream* fout; //파일 쓰기용 ofstream 참조 값

	void _showRecruitInfoStatsInterface(string recruitInfoStats); //채용 정보 통계 output.txt 파일에 출력 

public:
	ViewRecruitInfoStatsUI(ViewRecruitInfoStats* inputControl); //생성자
	void init(ofstream* inputFout); //파일 쓰기용 ofstream 참조 값 지정

	//control -> 1 -> boundary
	void startInterface(); //인터페이스 시작
	
	//actor -> 2 [currentMemberType == 1] -> boundary
	void requestAddedRecruitInfoStats(string currentLoginId); //회사회원의 등록한 채용 정보 통계 요청 
	//actor -> 3 [currentMemberType == 2] -> boundary
	void requestAppliedRecruitInfoStats(string currentLoginId); //일반회원의 지원한 채용 정보 통계 요청
};

