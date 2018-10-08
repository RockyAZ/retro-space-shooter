#include "Enemy.hpp"

Enemy::Enemy()
{
	this->_posX = -1;
}

Enemy::Enemy(Enemy const &obj)
{
	*this = obj;
}

Enemy::~Enemy()
{

}

Enemy&	Enemy::operator=(Enemy const& obj)
{
	_hp = obj._hp;
	_speedX = obj._speedX, 
	_speedY = obj._speedY;
	_posX = obj._posX;
	_posY = obj._posY;
	return *this;
}

void	Enemy::display(void) const
{
	start_color();
	init_pair(1, COLOR_BLUE, COLOR_WHITE);
	attron(COLOR_PAIR(1));
	mvaddch(_posY,_posX, 'O');
	mvaddch(_posY - 1,_posX, '|');
	mvaddch(_posY + 1,_posX, '|');
	attroff(COLOR_PAIR(1));
}

void	Enemy::move(void)
{
	setX(-1);
	return ;
}

void	Enemy::update(void)
{
	move();
	display();
}

int Enemy::_all = 0;