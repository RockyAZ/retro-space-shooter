#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entry.hpp"

class Enemy : public Entry
{
public:
	Enemy(void);
	Enemy(Enemy const &obj);
	~Enemy(void);

	Enemy&	operator=(Enemy const& obj);

	void	display(void) const;
	void	move(void);
	void	update(void);
private:
	static int _all;
};
#endif
