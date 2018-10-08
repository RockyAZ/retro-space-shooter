#ifndef BULLET_HPP
# define BULLET_HPP

#include "Entry.hpp"

class	Bullet : public Entry
{
	public:
		Bullet(void);
		Bullet(int posX, int posY);
		Bullet(Bullet const& obj);
		~Bullet(void);

		Bullet&	operator=(Bullet const& obj);

		void	display(void) const;
		void	move(void);
		void	update(void);
};

#endif