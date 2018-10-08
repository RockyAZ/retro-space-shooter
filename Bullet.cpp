#include "Bullet.hpp"

Bullet::Bullet(void) : Entry()
{
	return ;
}

Bullet::Bullet(int posX, int posY) : Entry(posX, posY)
{
	return ;
}

Bullet::Bullet(Bullet const& obj)
{
	*this = obj;
	return ;
}

Bullet::~Bullet(void)
{
	return ;
}

Bullet&	Bullet::operator=(Bullet const& obj)
{
	_hp = obj._hp;
	_speedX = obj._speedX, 
	_speedY = obj._speedY;
	_posX = obj._posX; 
	_posY = obj._posY;
	return *this;
}
		
void	Bullet::display(void) const
{
	start_color();
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	mvaddch(_posY,_posX, '-');
	attroff(COLOR_PAIR(2));
}

void	Bullet::move(void)
{
	setX(1);
	return ;
}

void	Bullet::update(void)
{
	move();
	display();
}