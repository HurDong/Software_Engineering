#pragma once
#include <string>
#include <fstream>
using namespace std;

class Withdraw;


/*
클래스 이름 : WithdrawUI
기능 : 회원탈퇴 Boundary
*/
class WithdrawUI 
{
private:
	Withdraw* control;
	ofstream* fout;

	void _showWithdrawId(string withdrawId); // 회원 탈퇴한 ID 기록
public:
	WithdrawUI(Withdraw* inputControl);	// 생성자
	void init(ofstream* inputFout);		// 파일 입출력을 위한 함수

	void startInterface(); // 인터페이스 시작
	void requestWithdraw(string& loginId, string tempId, int& memberType); // 회원 삭제 요청
};