/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:06:23 by tmurua            #+#    #+#             */
/*   Updated: 2026/04/29 15:35:39 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Standard Form"), _isSigned(false), _signGrade(150),
				_execGrade(150){}

Form::Form(const std::string &name, int signGrade, int execGrade) : 
			_name(name), _isSigned(false), _signGrade(signGrade), 
				_execGrade(execGrade){
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned),
				_signGrade(other._signGrade), _execGrade(other._execGrade){}

// assignment operator only copies bool flag, everything else is const
Form	&Form::operator=(const Form &other){
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form(){}


const std::string	&Form::getName() const{
	return (_name);
}

bool				Form::getBoolSign() const{
	return (_isSigned);
}

int			Form::getSignGrade() const{
	return (_signGrade);
}

int			Form::getExecGrade() const{
	return (_execGrade);
}


const char* Form::GradeTooHighException::what() const throw(){
	return ("grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("grade is too low!");
}


void Form::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, const Form &other)
{
	o << other.getName() << " | Signed status: " << 
		other.getBoolSign() << " | Grade required to sign it: " << 
		other.getSignGrade() << " | Grade required to execute it: " << 
		other.getExecGrade() << ".";
	return (o);
}
