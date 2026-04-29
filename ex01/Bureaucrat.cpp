/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 09:56:11 by tmurua            #+#    #+#             */
/*   Updated: 2026/04/28 12:30:26 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Mr. Nobody"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &name,
					   int grade) : _name(name), _grade(grade){
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), 
						_grade(other._grade){}

// partial assignment, only assigns _grade, cuz _name is const
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
		_grade = other._grade; 
	return (*this);
}

Bureaucrat::~Bureaucrat(){}


const std::string	&Bureaucrat::getName() const{
	return (_name);
}

int					Bureaucrat::getGrade() const{
	return (_grade);
}


void	Bureaucrat::incrementGrade(){
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade(){
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return ("Trying to give a grade that is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return ("Trying to give a grade that is too low!");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &other){
		o << other.getName() << ", bureaucrat grade " << 
			other.getGrade() << ".";
	return (o);
}
