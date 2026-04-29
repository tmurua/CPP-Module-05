/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:53:04 by tmurua            #+#    #+#             */
/*   Updated: 2026/04/29 12:49:38 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "----- A: valid Form construction -----" << std::endl;
	try{
		Form a("Form A", 50, 25);
		std::cout << a << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- B: invalid Form construction (grade too high) -----" << std::endl;
	try{
		Form b("Form B", 0, 25);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- C: invalid Form construction (grade too low) -----" << std::endl;
	try{
		Form c("Form C", 50, 151);
		std::cout << c << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- D: successful signing -----" << std::endl;
	try{
		Bureaucrat dB("Mr. D", 40);
		Form dF("Form D", 50, 25);

		std::cout << dB << std::endl;
		std::cout << dF << std::endl;

		dB.signForm(dF);

		std::cout << dF << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- E: failed signing (grade too low) -----" << std::endl;
	try{
		Bureaucrat eB("Mr. E", 100);
		Form eF("Form E", 50, 25);

		std::cout << eB << std::endl;
		std::cout << eF << std::endl;

		eB.signForm(eF);

		std::cout << eF << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- F: signed status changes only when allowed -----" << std::endl;
	try{
		Bureaucrat good("Mr. Good F", 10);
		Bureaucrat bad("Mr. Bad F", 120);
		Form f("Form F", 50, 25);

		std::cout << f << std::endl;

		bad.signForm(f);
		std::cout << "After bad attempt: " << f << std::endl;

		good.signForm(f);
		std::cout << "After good attempt: " << f << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- G: copy constructor -----" << std::endl;
	try{
		Form original("Form G", 70, 30);
		std::cout << original << std::endl;

		Form copy(original);
		std::cout << copy << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- H: assignment operator -----" << std::endl;
	try{
		Form original("Original Form H", 60, 20);
		Form assigned("Assigned Form H", 120, 130);
		Bureaucrat h("Mr. H", 60);

		h.signForm(original);

		std::cout << original << std::endl;
		std::cout << assigned << std::endl;

		assigned = original;

		std::cout << assigned << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
