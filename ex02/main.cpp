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
#include "AForm.hpp"

int main()
{
	std::cout << "----- A: valid AForm construction -----" << std::endl;
	try{
		AForm a("AForm A", 50, 25);
		std::cout << a << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- B: invalid AForm construction (grade too high) -----" << std::endl;
	try{
		AForm b("AForm B", 0, 25);
		std::cout << b << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- C: invalid AForm construction (grade too low) -----" << std::endl;
	try{
		AForm c("AForm C", 50, 151);
		std::cout << c << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- D: successful signing -----" << std::endl;
	try{
		Bureaucrat dB("Mr. D", 40);
		AForm dF("AForm D", 50, 25);

		std::cout << dB << std::endl;
		std::cout << dF << std::endl;

		dB.signAForm(dF);

		std::cout << dF << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- E: failed signing (grade too low) -----" << std::endl;
	try{
		Bureaucrat eB("Mr. E", 100);
		AForm eF("AForm E", 50, 25);

		std::cout << eB << std::endl;
		std::cout << eF << std::endl;

		eB.signAForm(eF);

		std::cout << eF << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- F: signed status changes only when allowed -----" << std::endl;
	try{
		Bureaucrat good("Mr. Good F", 10);
		Bureaucrat bad("Mr. Bad F", 120);
		AForm f("AForm F", 50, 25);

		std::cout << f << std::endl;

		bad.signAForm(f);
		std::cout << "After bad attempt: " << f << std::endl;

		good.signAForm(f);
		std::cout << "After good attempt: " << f << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- G: copy constructor -----" << std::endl;
	try{
		AForm original("AForm G", 70, 30);
		std::cout << original << std::endl;

		AForm copy(original);
		std::cout << copy << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- H: assignment operator -----" << std::endl;
	try{
		AForm original("Original AForm H", 60, 20);
		AForm assigned("Assigned AForm H", 120, 130);
		Bureaucrat h("Mr. H", 60);

		h.signAForm(original);

		std::cout << original << std::endl;
		std::cout << assigned << std::endl;

		assigned = original;

		std::cout << assigned << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}
