/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:31:06 by tmurua            #+#    #+#             */
/*   Updated: 2026/04/29 15:35:24 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

// • constant name. 
// • boolean indicating whether it is signed (at construction, it is not). 
// • constant grade required to sign it. 
// • constant grade required to execute it.

#include "Bureaucrat.hpp"

class Form{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

public:
	Form();
	Form(const std::string &name, int signGrade, int execGrade);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();

	const std::string	&getName() const;
	bool				getBoolSign() const;
	const int			&getSignGrade() const;
	const int			&getExecGrade() const;
	
	class GradeTooHighException : public std::exception{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception{
	public:
		const char* what() const throw();
	};

	void beSigned(const Bureaucrat &b);
};

	std::ostream	&operator<<(std::ostream &o, const Form &other);

#endif
