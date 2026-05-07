/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:53:04 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/07 18:40:55 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "----- A: cannot execute unsigned form -----" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm formA("home");
		std::cout << formA << std::endl;
		boss.executeForm(formA);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- B: signed but grade too low to execute -----" << std::endl;
	try {
		Bureaucrat signer("Signer", 1);
		Bureaucrat weak("Weak", 150);
		RobotomyRequestForm formB("Bender");
		signer.signForm(formB);
		weak.executeForm(formB);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- C: successful shrubbery execution -----" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm formC("garden");
		boss.signForm(formC);
		boss.executeForm(formC);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- D: successful robotomy execution -----" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm formD("Marvin");
		boss.signForm(formD);
		boss.executeForm(formD);
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// std::cout << "\n----- E: successful presidential pardon -----" << std::endl;
	// try
	// {
	// 	Bureaucrat boss("Boss", 1);
	// 	PresidentialPardonForm formE("Arthur Dent");
	// 	boss.signForm(formE);
	// 	boss.executeForm(formE);
	// }
	// catch (const std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	//
	// std::cout << "\n----- F: delete through AForm* -----" << std::endl;
	// AForm *forms[3];
	// forms[0] = new ShrubberyCreationForm("park");
	// forms[1] = new RobotomyRequestForm("HAL");
	// forms[2] = new PresidentialPardonForm("Ford Prefect");
	//
	// for (int i = 0; i < 3; i++)
	// 	delete forms[i];
}
