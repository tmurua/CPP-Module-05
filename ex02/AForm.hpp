/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:31:06 by tmurua            #+#    #+#             */
/*   Updated: 2026/04/29 15:35:24 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

protected:
	virtual void	executeAction() const = 0;

public:
	AForm();
	AForm(const std::string &name, int signGrade, int execGrade);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();

	const std::string	&getName() const;
	bool				getBoolSign() const;
	int			getSignGrade() const;
	int			getExecGrade() const;
	
	class GradeTooHighException : public std::exception{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		const char* what() const throw();
	};

	void beSigned(const Bureaucrat &b);
	//TODO
	void execute(Bureaucrat const & executor) const;

	class FormNotSignedException : public std::exception{
	public:
		const char* what() const throw();
	};
};

	std::ostream	&operator<<(std::ostream &o, const AForm &other);

#endif
