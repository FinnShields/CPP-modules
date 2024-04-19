/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fshields <fshields@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:40:24 by fshields          #+#    #+#             */
/*   Updated: 2024/04/17 09:52:12 by fshields         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main() {
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
    AMateria* tmp1;
    tmp1 = src->createMateria("ice");
    me->equip(tmp1);
	AMateria* tmp2;
    tmp2 = src->createMateria("cure");
    me->equip(tmp2);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
    me->use(1, *bob);
	bob->equip(tmp1);
	bob->use(0, *me);
	bob->unequip(0);
	me->unequip(0);
	me->unequip(1);
	delete(tmp1);
	delete(tmp2);
	delete bob;
	delete me;
	delete src;
	return 0;
}