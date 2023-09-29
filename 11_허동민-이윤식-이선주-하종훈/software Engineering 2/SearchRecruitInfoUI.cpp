#include <string>
#include "SearchRecruitInfo.h"
#include "SearchRecruitInfoUI.h"

using namespace std;

/*
	함수 이름 : SeacrhRecruitInfoUI
	기능: 생성자
	매개변수: SearchRecruitInfo* inputControl -> 컨트롤 참조값
	반환값: X
*/
SearchRecruitInfoUI::SearchRecruitInfoUI(SearchRecruitInfo* inputControl) 
{
	control = inputControl;
}

/*
	함수 이름 : init
	기능: 파일 쓰기를 위한 ofstream 참조 전달
	매개변수: ofstream* inputFout -> ofstream 참조값
	반환값: X
*/
void SearchRecruitInfoUI::init(ofstream* inputFout) 
{
	fout = inputFout;
}

/*
	함수 이름 : startInterface
	기능: 유저가 입력한 내용 화면에 띄우기
	매개변수: X
	반환값: X
*/
void SearchRecruitInfoUI::startInterface() 
{
	*fout << "4.1. 채용 정보 검색" << endl;     // 유저가 입력한 내용 화면에 띄우기
}

/*
	함수 이름 : showSearchRecruitInfo
	기능: 일반 회원이 채용 정보 검색을 요청
	매개변수: string inputEvent -> 입력한 한 줄의 문자열, string currentLoginId -> 현재 로그인 한 사람의 ID를 매개변수로 보냄
	반환값: X
*/
void SearchRecruitInfoUI::showSearchRecruitInfo(string inputEvent) 
{
	stringstream input(inputEvent); // 공백 (" ")을 포함한 문자열을 각 문자로 자르기 위해 stringstream 사용
	string num1, num2, name; // 공백을 기준으로 각각의 string을 담아줄 변수를 설정

	input >> num1 >> num2 >> name; // 공백을 기준으로 각각의 string을 변수에 담기

	
	string returnString = control->searchRecruitInfo(name); // Control의 함수인 searchRecruitInfo 호출 

	*fout << returnString << endl; // 채용 정보 검색 완료 후, 파일에 저장
}

