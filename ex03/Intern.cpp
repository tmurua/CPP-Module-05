/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:06:34 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/12 23:46:52 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

Intern::Intern(){}
Intern::Intern(const Intern &other){
	(void)other;
}

Intern	&Intern::operator=(const Intern &other){
	(void)other;
	return (*this);
}

Intern::~Intern(){}

AForm	*Intern::makeForm(std::string nameForm, std::string targetForm){
	std::string	successMessage = "Intern creates ";

	if (nameForm == "shrubbery creation"){
		std::cout << successMessage << nameForm << std::endl;
		return new ShrubberyCreationForm(targetForm);
	}
	if (nameForm == "robotomy request"){
		std::cout << successMessage << nameForm << std::endl;
		return new RobotomyRequestForm(targetForm);
	}
	if (nameForm == "presidential pardon"){
		std::cout << successMessage << nameForm << std::endl;
		return new PresidentialPardonForm(targetForm);
	}
	std::cout << "Error: unknown form name." << std::endl;
	return (0);
}
