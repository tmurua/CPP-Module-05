/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:53:04 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/12 23:41:55 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testForm(Intern &intern, std::string name, std::string target){
	AForm *form = intern.makeForm(name, target);
	
	if (form)
		delete (form);
}

int main(){
	Intern someRandomIntern;

	AForm* rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
		delete (rrf);

	testForm(someRandomIntern, "shrubbery creation", "home");
	testForm(someRandomIntern, "robotomy request", "Bender");
	testForm(someRandomIntern, "presidential pardon", "Arthur Dent");
	testForm(someRandomIntern, "nonexistent form", "nowhere");

	Bureaucrat boss("Boss", 1);
	AForm *pardon = someRandomIntern.makeForm("presidential pardon", "Richard Nixon");
	boss.signForm(*pardon);
	boss.executeForm(*pardon);
	if (pardon)
		delete (pardon);
}
