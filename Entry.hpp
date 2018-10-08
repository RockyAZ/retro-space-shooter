#ifndef ENTRY_HPP
# define ENTRY_HPP

#include <ncurses.h>

class	Entry
{
	protected:
		int		_hp;
		int		_speedX, _speedY;
		int		_posX, _posY;

	public:
		Entry(void);
		Entry(int posX, int posY);
		Entry(Entry const& obj);
		virtual ~Entry(void);
		void	decrHp(int hp);
		void	setX(int x);
		void	setY(int y);
		int		getX(void) const;
		int		getY(void) const;
		int		getHp(void) const;
		Entry&	operator=(Entry const& obj);
		
		virtual void	display(void) const = 0;
		virtual void	move(void) = 0;
};
#endif
