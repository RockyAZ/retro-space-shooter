#include "Entry.hpp"

Entry::Entry(void)
{
	return ;
}

Entry::Entry(int posX, int posY) : _posX(posX), _posY(posY)
{
	return ;
}

Entry::Entry(Entry const& obj)
{
	*this = obj;
	return ;
}

Entry::~Entry(void)
{
	return ;
}

void		Entry::decrHp(int hp)
{
	if (_hp - hp < 0)
		_hp = 0;
	else
		_hp -= hp;
}

void		Entry::setX(int x)
{
	mvaddch(_posY,_posX, ' ');
	_posX += x;
}

void		Entry::setY(int y)
{
	mvaddch(_posY,_posX, ' ');
	_posY += y;
}

int			Entry::getX(void) const
{
	return this->_posX;
}

int			Entry::getY(void) const
{
	return this->_posY;
}

int			Entry::getHp(void) const
{
	return this->_hp;
}

Entry&		Entry::operator=(Entry const& obj)
{
		_hp = obj._hp;
		_speedX = obj._speedX, 
		_speedY = obj._speedY;
		_posX = obj._posX; 
		_posY = obj._posY;
		return *this;
}
