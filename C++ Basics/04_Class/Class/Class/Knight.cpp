#include "pch.h"
#include "Player.h"
#include "Knight.h"

Knight::Knight()
// 빠른 초기화 영역
: Player()
{
	// 늦은 초기화 영역
	cout << "Knight의 기본생성자" << endl;

	_stamina = 0;
}

Knight::Knight(int hp, int mp, int attack, int stamina)
: Player(hp, mp, attack)
{
	cout << "Knight의 타입변환 생성자" << endl;
	_stamina = stamina;
}

Knight::~Knight()
{
	cout << "Knight의 소멸자" << endl;
}

// 함수 오버라이딩
void Knight::Attack(Player* p)
{
	if (IsDead() || p->IsDead()) return;

	cout << "Knight의 Attack!!!" << endl;
	p->TakeDamage(_attack);
}
