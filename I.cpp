#include "I.hpp"

I::I(void) : Entry()
{
	_hp = 5;
	return ;
}

I::I(int posX, int posY) : Entry(posX, posY)
{
	return ;
}

I::I(I const& obj)
{
	*this = obj;
	return ;
}

I::~I(void)
{
	return ;
}

I&	I::operator=(I const& obj)
{
	_hp = obj._hp;
	_speedX = obj._speedX, 
	_speedY = obj._speedY;
	_posX = obj._posX; 
	_posY = obj._posY;
	return *this;
}
		
void	I::display(void) const
{
	mvaddch(this->_posY, this->_posX, ACS_DIAMOND);
	mvaddch(this->_posY - 1, this->_posX, '|');
	mvaddch(this->_posY + 1, this->_posX, '|');
	mvaddch(this->_posY, this->_posX - 1, '>');
	mvaddch(this->_posY, this->_posX + 1, '}');
}

void	I::move(void)
{
	return ;
}
