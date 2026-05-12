/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 17:38:02 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/07 18:39:19 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),
												_target("defaultTarget"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : 
	AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other), _target(other._target){}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void	RobotomyRequestForm::executeAction() const{
	static bool	seeded = false;

	if (seeded == false){
		std::srand(std::time(NULL));
		seeded = true;
	}
	std::cout << "* drilling noise *" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "robotomy failed on " << _target << "." << std::endl;
}
