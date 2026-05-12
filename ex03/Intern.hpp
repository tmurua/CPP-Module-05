/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmurua <tmurua@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:06:03 by tmurua            #+#    #+#             */
/*   Updated: 2026/05/12 19:26:21 by tmurua           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern{
public:
Intern();
Intern(const Intern &other);
Intern &operator=(const Intern &other);
~Intern();

AForm *makeForm(std::string nameForm, std::string targetForm);
};

#endif
