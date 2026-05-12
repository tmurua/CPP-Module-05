/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:06:23 by tmurua            #+#    #+#             */
/*   Updated: 2026/04/29 15:35:39 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Standard AForm"), _isSigned(false), _signGrade(150),
				_execGrade(150){}

AForm::AForm(const std::string &name, int signGrade, int execGrade) : 
			_name(name), _isSigned(false), _signGrade(signGrade), 
				_execGrade(execGrade){
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned),
				_signGrade(other._signGrade), _execGrade(other._execGrade){}

// assignment operator only copies bool flag, everything else is const
AForm	&AForm::operator=(const AForm &other){
	if (this != &other){
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm(){}


const std::string	&AForm::getName() const{
	return (_name);
}

bool				AForm::getBoolSign() const{
	return (_isSigned);
}

int			AForm::getSignGrade() const{
	return (_signGrade);
}

int			AForm::getExecGrade() const{
	return (_execGrade);
}


const char* AForm::GradeTooHighException::what() const throw(){
	return ("grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("grade is too low!");
}


void AForm::beSigned(const Bureaucrat &b){
	if (b.getGrade() <= _signGrade)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const{
	if (_isSigned == false)
		throw FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	executeAction();
}

const char * AForm::FormNotSignedException::what() const throw(){
	return ("form is not signed!");
}


std::ostream	&operator<<(std::ostream &o, const AForm &other)
{
	o << other.getName() << " | Signed status: " << 
		other.getBoolSign() << " | Grade required to sign it: " << 
		other.getSignGrade() << " | Grade required to execute it: " << 
		other.getExecGrade() << ".";
	return (o);
}
