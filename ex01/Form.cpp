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
