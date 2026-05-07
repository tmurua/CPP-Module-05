/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:20:27 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/07 17:26:03 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 
											145, 137), _target("defaultTarget"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
						AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
											AForm(other), _target(other._target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm 
														&other){
	if (this != &other){
		AForm::operator=(other);
		_target = other._target;
	}
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void	ShrubberyCreationForm::executeAction() const{
	std::ofstream outfilestream((_target + "_shrubbery").c_str());

	if (!outfilestream)
		return ;

	outfilestream << "  /\\    /\\    /\\" << std::endl;
	outfilestream << " /__\\  /__\\  /__\\" << std::endl;
	outfilestream << "  ||    ||    ||" << std::endl;
}
