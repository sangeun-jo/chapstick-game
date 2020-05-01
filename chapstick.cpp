#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

void init();
void titleDraw();
int menuDraw();
void infoDraw();
void gotoxy(int, int);
void drawBone(string n1, string n2);
void drawLeftConsole(int r, int l);
void drawRightConsole(int r, int l);
void removeConsole();
void drawConsole(int l, int r, char hand);

class Hand {
protected:
	int finger;
public:
	Hand() {
		finger = 1;
	}
	int getFinger() {
		return finger;
	}
	void setFinger(int k) {
		finger = k;
	}
};

class Player : public Hand {
public:
	string name;
	Hand lHand;
	Hand rHand;

	Player(string n = "") {
		name = n;
	}

	void setName(string n = "") {
		name = n;
	}

	string getName() {
		return name;
	}
	int bothFighers() {
		return lHand.getFinger() + rHand.getFinger();
	}

	void reconstruct() {
		int k;
		int both = lHand.getFinger() + rHand.getFinger();
		cout << "바꿀 조합 선택" << endl;
		//손가락 합 2개  
		if (both == 2) {
			if (lHand.getFinger() == 1 && rHand.getFinger() == 1) {  // 1, 1 조합  
				cout << "1 : [0, 2]" << endl;
				cout << "2 : [2, 0]" << endl;
				cin >> k;
				if (k == 1) {
					lHand.setFinger(0);
					rHand.setFinger(2);
				}
				else if (k == 2) {
					lHand.setFinger(2);
					rHand.setFinger(0);
				}
			}
			else {  // 0, 2 또는 2, 0 조합  
				cout << "1 : [1, 1]" << endl;
				getchar();
				lHand.setFinger(1);
				rHand.setFinger(1);
			}
		}
		//손가락 합 3개  
		else if (both == 3) {
			if (lHand.getFinger() == 2 || rHand.getFinger() == 2) { // 1, 2 또는 2, 1 조합  
				cout << "1 : [0, 3]" << endl;
				cout << "2 : [3, 0]" << endl;
				cin >> k;
				if (k == 1) {
					lHand.setFinger(0);
					rHand.setFinger(3);
				}
				else if (k == 2) {
					lHand.setFinger(3);
					rHand.setFinger(0);
				}
			}
			else {  // 0, 3 또는 0, 3 조합  
				cout << "1 : [1, 2]" << endl;
				cout << "2 : [2, 1]" << endl;
				cin >> k;
				if (k == 1) {
					lHand.setFinger(1);
					rHand.setFinger(2);
				}
				else if (k == 2) {
					lHand.setFinger(2);
					rHand.setFinger(1);
				}
			}
		}
		//손가락 합 4개  
		else if (both == 4) {
			if (lHand.getFinger() == 0 || rHand.getFinger() == 0) { // 0, 4 또는 4, 0 조합  
				cout << "1 : [1, 3]" << endl;
				cout << "2 : [2, 2]" << endl;
				cout << "3 : [3, 1]" << endl;
				cin >> k;
				if (k == 1) {
					lHand.setFinger(3);
					rHand.setFinger(3);
				}
				else if (k == 2) {
					lHand.setFinger(2);
					rHand.setFinger(2);
				}
				else if (k == 3) {
					lHand.setFinger(3);
					rHand.setFinger(1);
				}
			}
			else if (lHand.getFinger() == 1 || rHand.getFinger() == 1) { // 1, 3 또는 3, 1 조합  
				cout << "1 : [0, 4]" << endl;
				cout << "2 : [2, 2]" << endl;
				cout << "3 : [4, 0]" << endl;
				cin >> k;
				if (k == 1) {
					lHand.setFinger(0);
					rHand.setFinger(4);
				}
				else if (k == 2) {
					lHand.setFinger(2);
					rHand.setFinger(2);
				}
				else if (k == 3) {
					lHand.setFinger(4);
					rHand.setFinger(0);
				}
			}
			else { // 2, 2 조합  
				cout << "1 : [0, 4]" << endl;
				cout << "2 : [1, 3]" << endl;
				cout << "3 : [3, 1]" << endl;
				cout << "4 : [4, 0]" << endl;
				cin >> k;
				if (k == 1) {
					lHand.setFinger(0);
					rHand.setFinger(4);
				}
				else if (k == 2) {
					lHand.setFinger(1);
					rHand.setFinger(3);
				}
				else if (k == 3) {
					lHand.setFinger(3);
					rHand.setFinger(1);
				}
				else if (k == 4) {
					lHand.setFinger(4);
					rHand.setFinger(0);
				}
			}
		}
		//손가락 합 5개 
		else if (both == 5) {
			if (lHand.getFinger() == 1 || rHand.getFinger() == 1) {  // 1, 4 또는 4, 1 조합  
				cout << "1 : [2, 3]" << endl;
				cout << "2 : [3, 2]" << endl;
				cin >> k;
				if (k == 1) {
					lHand.setFinger(2);
					rHand.setFinger(3);
				}
				else if (k == 2) {
					lHand.setFinger(3);
					rHand.setFinger(2);
				}
			}
			else { // 2, 3 또는 3, 2 조합  
				cout << "1 : [1, 4]" << endl;
				cout << "2 : [4, 1]" << endl;
				cin >> k;
				if (k == 1) {
					lHand.setFinger(1);
					rHand.setFinger(4);
				}
				else if (k == 2) {
					lHand.setFinger(4);
					rHand.setFinger(1);
				}
			}
		}

		//손가락 합 6개 
		else if (both == 6) {
			if (lHand.getFinger() == 3) { // 3, 3 조합
				cout << "1 : [2, 4]" << endl;
				cout << "2 : [4, 2]" << endl;
				if (k == 1) {
					lHand.setFinger(2);
					rHand.setFinger(4);
				}
				else if (k == 2) {
					lHand.setFinger(4);
					rHand.setFinger(2);
				}
			}
			else { // 2, 4 또는 4, 2 조합  
				cout << "1 : [3, 3]" << endl;
				getchar();
				lHand.setFinger(3);
				rHand.setFinger(3);
			}
		}

		//손가락 합 7개  
		else if (both == 7) {
			if (lHand.getFinger() == 3) { // 3, 4 조합  
				cout << "1 : [2, 0]" << endl;
				getchar();
				lHand.setFinger(2);
				rHand.setFinger(0);
			}
			else { // 4, 3 조합  
				cout << "1 : [0, 2]" << endl;
				getchar();
				lHand.setFinger(0);
				rHand.setFinger(2);
			}
		}
	}
	void showFingers() {
		cout << "왼손: " << lHand.getFinger();
		cout << " 오른손: " << rHand.getFinger() << endl;
	}
};

void attack(Hand& hand1, Hand& hand2) {
	removeConsole();
	int attacked = hand1.getFinger() + hand2.getFinger();
	if (attacked >= 5) {
		attacked = 0;
		cout << "상대방의 손이 격파되었습니다." << endl;
	}
	else {
		cout << "공격 받은 손의 손가락 수는 " << attacked << "개 입니다." << endl;
	}
	hand2.setFinger(attacked);
}

void attackPlayer(Player& user, Player& other) {
	removeConsole();
	int k, c;
	do {
		cout << "내 손 선택" << endl;;
		if (user.lHand.getFinger() > 0) {
			cout << "1. 왼손";
		}
		if (user.rHand.getFinger() > 0) {
			cout << " 2. 오른손";
		}

		cin >> c;
		if (c != 1 && c != 2) cout << "잘못된 입력입니다.다시 선택해 주세요" << endl;
	} while (c != 1 && c != 2);
	do {
		gotoxy(0, 23);
		cout << "상대 손 선택" << endl;
		if (other.lHand.getFinger() > 0) {
			cout << "1. 왼손";
		}
		if (other.rHand.getFinger() > 0) {
			cout << " 2. 오른손";
		}
		cin >> k;
		if (k != 1 && k != 2) cout << "잘못된 입력입니다.다시 선택해 주세요" << endl;
	} while (k != 1 && k != 2);

	if (c == 1) {
		if (k == 1)
			attack(user.lHand, other.lHand);
		else
			attack(user.lHand, other.rHand);
	}
	else if (c == 2) {
		if (k == 1)
			attack(user.rHand, other.lHand);
		else
			attack(user.rHand, other.rHand);
	}
}

void doTurn(Player& player1, Player& player2) {
	int choice, both;
	removeConsole();
	gotoxy(0, 18);
	cout << endl << "[ " << player1.name << "(이)의 차례 ]" << endl;
	while (1) {
		both = player1.bothFighers();
		if (2 > both || 6 < both) {
			attackPlayer(player1, player2);
			break;
		}
		cout << "1.공격 \t2.바꾸기";
		cin >> choice;
		if (choice == 1) {
			attackPlayer(player1, player2);
			break;
		}
		else if (choice == 2) {
			removeConsole();
			player1.reconstruct();
			cout << endl;
			break;
		}
		if (choice != 1 && choice != 2) cout << "잘못된 입력입니다.다시 선택해 주세요" << endl; //이부분 문제 있음  
	}
}

bool showPlayerFingers(Player& user, Player& other) {
	gotoxy(0, 23);
	if (user.lHand.getFinger() == 0 && user.rHand.getFinger() == 0) {
		cout << user.getName() << " 탈락!" << endl;
		return false;
	}
	else if (other.lHand.getFinger() == 0 && other.rHand.getFinger() == 0) {
		cout << other.getName() << " 탈락!" << endl;
		return false;
	}
	gotoxy(0, 22);
	cout << endl << user.getName() << "의 손가락 현황" << endl;
	user.showFingers();

	cout << endl << other.getName() << "의 손가락 현황" << endl;
	other.showFingers();
	cout << endl;
	system("pause");
	return true;
}

void GameStart() {
	string player1, player2, turn;
	int order = 0, count = 0;
	cout << "player1 닉네임을 입력하세요:";
	cin >> player1;
	cout << "player2 닉네임을 입력하세요:";
	cin >> player2;
	cout << endl;

	Player user1(player1);
	Player user2(player2);
	srand((unsigned int)time(0));
	order = rand();
	if (order % 2 == 0) {
		cout << player1 << "(이)가 선입니다.\n" << endl;
		turn = player1;
	}
	else {
		cout << player2 << "(이)가 선입니다. \n" << endl;
		turn = player2;
	}
	system("pause");
	system("cls");
	drawBone(player1, player2);

	gotoxy(21, 8);
	cout << "#######";

	gotoxy(21, 13);
	cout << "#######";


	gotoxy(50, 8);
	cout << "#######";

	gotoxy(50, 13);
	cout << "#######";


	while (1) {
		if (turn == player1) {
			drawLeftConsole(user1.lHand.getFinger(), user1.rHand.getFinger());
			drawRightConsole(user2.lHand.getFinger(), user2.rHand.getFinger());
			doTurn(user1, user2);
			drawLeftConsole(user1.lHand.getFinger(), user1.rHand.getFinger());
			drawRightConsole(user2.lHand.getFinger(), user2.rHand.getFinger());
			turn = player2;

		}
		else {
			drawLeftConsole(user1.lHand.getFinger(), user1.rHand.getFinger());
			drawRightConsole(user2.lHand.getFinger(), user2.rHand.getFinger());
			doTurn(user2, user1);
			drawLeftConsole(user1.lHand.getFinger(), user1.rHand.getFinger());
			drawRightConsole(user2.lHand.getFinger(), user2.rHand.getFinger());
			turn = player1;
		}
		count += 1;
		if (showPlayerFingers(user1, user2) == false)
			break;
	}

	cout << count << "턴 만에 끝났습니다." << endl;
	system("pause");
}


int main()
{
	char awnser;
	init();
	while (1) {
		titleDraw();
		int menuCode = menuDraw();
		if (menuCode == 0) {
			//게임 시작  
			system("cls");
			GameStart();
			//system("cls");
			while (1) {
				int key = _getch();
				if (key == 13) { //엔터  
					break;
				}
			}
			//서브메뉴  
		}
		else if (menuCode == 1) {
			infoDraw();
		}
		else if (menuCode == 2) {
			return 0; //종료  
		}
		system("cls");
	}
}

void init() {
	system("mode con cols=79 lines=33 | title = chopstick");

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void titleDraw() {
	cout << "\n\n\n\n";
	cout << "         ###   #       ###    ####     ###   #####   #     ###   #  # " << endl;
	cout << "        #      #      #   #   #   #   #        #     #    #      # #  " << endl;
	cout << "        #      ###    #   #   ####    ####     #     #    #      ##   " << endl;
	cout << "        #      #  #   #   #   #           #    #     #    #      # #  " << endl;
	cout << "         ###   #  #    ###    #       ####     #     #     ###   #  # " << endl;
}


int menuDraw() {
	int x = 30;
	int y = 12;
	gotoxy(x - 2, y);
	cout << "> 게 임 시 작" << endl;
	gotoxy(x, y + 1);
	cout << "게 임 정 보" << endl;
	gotoxy(x, y + 2);
	cout << "게 임 종 료" << endl;
	while (1) {
		int key = _getch();
		if (key == 224) {
			key = _getch();
			switch (key) {
			case 72: //윗 방향키  
				if (y > 12) { // y는 12~14까지만 이동  
					gotoxy(x - 2, y);
					cout << " "; //원래위치를 지우고  
					gotoxy(x - 2, --y);
					cout << ">";
				}
				break;
			case 80: //아래 방향키  
				if (y < 14) {
					gotoxy(x - 2, y);
					cout << " ";
					gotoxy(x - 2, ++y);
					cout << ">";
				}
				break;
			default:
				break;
			}
		}
		else if (key == 13) {
			return y - 12;
		}
	}
}

//커서 위치 이동함수 
void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void infoDraw() {
	system("cls");
	cout << "\n\n";
	cout << "                          [ 게 임 규 칙 ]\n\n";
	cout << "자신의 차례가 돌아오면 아래 중 하나의 행동을 반드시 해야 합니다.\n";
	cout << " (단 펼쳐저 있는 손가락이 있는 손만 사용) \n\n";
	cout << " 1. 공격\n";
	cout << "   이 경우 자신이 공격한 상대방의 손은\n";
	cout << "   (공격한 손의 펼쳐진 손가락 수) + (공격 받은 손의 펼쳐진 손가락 수) 가 됩니다.\n";
	cout << "   이 때 공격 받은 손가락의 수가 5개 이상이면 공격 받은 손이 격파 됩니다.\n\n";
	cout << " 2. 바꾸기\n";
	cout << "  양 손가락 합이 같도록 나눌 수 있습니다.\n";
	cout << "  양손의 순서만 바꾸는 것은 불가능 합니다.\n\n";
	cout << "양 손이 모두 격파되면 패배합니다. \n\n";
	cout << "                  엔터를 누르면 메인으로 이동합니다.";

	while (1) {
		int key = _getch();
		if (key == 13) { //엔터  
			break;
		}
	}
}

void drawBone(string n1, string n2) {
	gotoxy(0, 0);
	cout << n1 << "(이)의 손\n";
	gotoxy(39, 0);
	cout << n2 << "(이)의 손\n";
	gotoxy(0, 0);
	for (int i = 0; i < 20; i++) {
		gotoxy(38, i);
		cout << "|";
	}
	int x = 10;

	//사용자 1의 왼손  
	for (int i = 5; i <= 8; i++) {
		gotoxy(x, i);
		cout << "######### ";
	}


	//사용자 1의 오른손  
	for (int i = 13; i <= 16; i++) {
		gotoxy(x, i);
		cout << "######### ";
	}

	int y = 57;

	//사용자 2의 왼손  
	for (int i = 5; i <= 8; i++) {
		gotoxy(y, i);
		cout << " #########";
	}

	//사용자 2의 오른손  
	for (int i = 13; i <= 16; i++) {
		gotoxy(y, i);
		cout << " #########";
	}
}

void removeConsole() { //현황판 시작점  
	for (int y = 20; y <= 32; y++)
		for (int x = 0; x <= 78; x++) {
			gotoxy(x, y);
			cout << " ";
		}
	gotoxy(0, 20);
}

//왼편 화면 그림 그려주는 툴 

void drawLeftConsole(int l, int r) {
	gotoxy(21, 5);
	cout << "       ";
	gotoxy(21, 6);
	cout << "       ";
	gotoxy(21, 8);
	cout << "       ";
	gotoxy(21, 7);
	cout << "       ";

	gotoxy(21, 13);
	cout << "       ";
	gotoxy(21, 14);
	cout << "       ";
	gotoxy(21, 15);
	cout << "       ";
	gotoxy(21, 16);
	cout << "       ";
	switch (l) {
	case 0:
		break;
	case 1:
		gotoxy(21, 8);
		cout << "#######";
		break;
	case 2:
		gotoxy(21, 8);
		cout << "#######";
		gotoxy(21, 7);
		cout << "#######";
		break;
	case 3:
		gotoxy(21, 6);
		cout << "#######";
		gotoxy(21, 8);
		cout << "#######";
		gotoxy(21, 7);
		cout << "#######";
		break;
	case 4:
		gotoxy(21, 5);
		cout << "#######";
		gotoxy(21, 6);
		cout << "#######";
		gotoxy(21, 8);
		cout << "#######";
		gotoxy(21, 7);
		cout << "#######";
		break;
	}
	switch (r) {
	case 0:
		break;
	case 1:
		gotoxy(21, 13);
		cout << "#######";
		break;
	case 2:
		gotoxy(21, 13);
		cout << "#######";
		gotoxy(21, 14);
		cout << "#######";
		break;
	case 3:
		gotoxy(21, 13);
		cout << "#######";
		gotoxy(21, 14);
		cout << "#######";
		gotoxy(21, 15);
		cout << "#######";
		break;
	case 4:
		gotoxy(21, 16);
		cout << "#######";
		gotoxy(21, 15);
		cout << "#######";
		gotoxy(21, 14);
		cout << "#######";
		gotoxy(21, 13);
		cout << "#######";
		break;
	}
}

//오른편 화면에  그림 그려주는 툴  
void drawRightConsole(int l, int r) {
	//반복문 쓰자  
	gotoxy(50, 5);
	cout << "       ";
	gotoxy(50, 6);
	cout << "       ";
	gotoxy(50, 8);
	cout << "       ";
	gotoxy(50, 7);
	cout << "       ";

	gotoxy(50, 13);
	cout << "       ";
	gotoxy(50, 14);
	cout << "       ";
	gotoxy(50, 15);
	cout << "       ";
	gotoxy(50, 16);
	cout << "       ";
	switch (l) {
	case 0:
		break;
	case 1:
		gotoxy(50, 8);
		cout << "#######";
		break;
	case 2:
		gotoxy(50, 8);
		cout << "#######";
		gotoxy(50, 7);
		cout << "#######";
		break;
	case 3:
		gotoxy(50, 6);
		cout << "#######";
		gotoxy(50, 8);
		cout << "#######";
		gotoxy(50, 7);
		cout << "#######";
		break;
	case 4:
		gotoxy(50, 5);
		cout << "#######";
		gotoxy(50, 6);
		cout << "#######";
		gotoxy(50, 8);
		cout << "#######";
		gotoxy(50, 7);
		cout << "#######";
		break;
	}
	switch (r) {
	case 0:
		break;
	case 1:
		gotoxy(50, 13);
		cout << "#######";
		break;
	case 2:
		gotoxy(50, 13);
		cout << "#######";
		gotoxy(50, 14);
		cout << "#######";
		break;
	case 3:
		gotoxy(50, 13);
		cout << "#######";
		gotoxy(50, 14);
		cout << "#######";
		gotoxy(50, 15);
		cout << "#######";
		break;
	case 4:
		gotoxy(50, 16);
		cout << "#######";
		gotoxy(50, 15);
		cout << "#######";
		gotoxy(50, 14);
		cout << "#######";
		gotoxy(50, 13);
		cout << "#######";
		break;
	}
}
