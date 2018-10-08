#ifndef I_HPP
# define I_HPP

#include "Entry.hpp"

class	I : public Entry
{
	public:
		I(void);
		I(int posX, int posY);
		I(I const& obj);
		~I(void);

		I&	operator=(I const& obj);

		void	display(void) const;
		void	move(void);
};

#endif