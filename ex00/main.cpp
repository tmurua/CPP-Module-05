/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:53:04 by tmurua            #+#    #+#             */
/*   Updated: 2026/04/28 13:18:33 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	std::cout << "----- X: Default constructor and " <<
					"parameterized constructor -----\n";
	try{
		Bureaucrat dX;
		std::cout << dX << std::endl;
		Bureaucrat pX("Mr. X", 1);
		std::cout << pX << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- A: Constructor attempt to instantiate" <<
					" Bureaucrats with grades out of range -----\n";
	try{
		Bureaucrat highA("Mr. High A", 0);
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	try{
		Bureaucrat lowA("Mr. Low A", 151);
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- B: attempt to increment grade out of range -----\n"; 
	try{
		Bureaucrat B("Mr. B", 2);
		std::cout << B << std::endl;
		B.incrementGrade();
		std::cout << B << std::endl;
		B.incrementGrade();
		std::cout << B << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- C: attempt to decrement grade out of range -----\n"; 
	try{
		Bureaucrat C("Mr. C", 149);
		std::cout << C << std::endl;
		C.decrementGrade();
		std::cout << C << std::endl;
		C.decrementGrade();
		std::cout << C << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n----- Y: Copy constructor -----\n";
	try{
		Bureaucrat ogY("Mr. Y", 50);
		std::cout << ogY << std::endl;
		Bureaucrat cpY(ogY);
		std::cout << cpY << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << "\n----- Z: Assignement operator copies grade -----\n";
	try{
		Bureaucrat ogZ("Mr. Original Z", 30);
		std::cout << ogZ << std::endl;
		Bureaucrat cpZ("Mr. Copy Z", 20);
		std::cout << cpZ << std::endl;
		cpZ = ogZ;
		std::cout << cpZ << std::endl;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}
