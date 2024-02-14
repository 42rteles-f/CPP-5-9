/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:30:13 by rteles-f          #+#    #+#             */
/*   Updated: 2024/02/05 17:47:00 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():
AForm("Shrubbery", 145, 137), _target("None")
{ 
	std::cout << " < Shrubbery Default Constructor called. >" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << " < Shrubbery Default Constructor called. >" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& tocopy)
{
	std::cout << " < Shrubbery Copy Constructor called. >" << std::endl;
	*this = tocopy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{ std::cout << " < Shrubbery Destructor called. >" << std::endl; }

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& tocopy) {
	if (this == &tocopy)
		return (*this);
	this->_target = tocopy._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	std::ofstream outfile;

	if (!this->isSigned())
		throw FormNotSigned();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();

	outfile.open((_target + "_shruberry").c_str(), std::ofstream::trunc);
	if (!outfile) {
		outfile.close();
		throw std::runtime_error("Failed to open file");
		return ;
	}
	outfile.write(_tree.c_str(), _tree.size());
}

const std::string	ShrubberyCreationForm::_tree =
"                                                        .\n"
"                                              .         ;  \n"
"                 .              .              ;%     ;;   \n"
"                   ,           ,                :;%  %;   \n"
"                    :         ;                   :;%;'     .,   \n"
"           ,.        %;     %;            ;        %;'    ,;\n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'   \n"
"                        `@%.  `;@%.      ;@@%;         \n"
"                          `@%%. `@%%    ;@@%;        \n"
"                            ;@%. :@%%  %@@%;       \n"
"                              %@bd%%%bd%%:;     \n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '         \n"
"                                %@@@o%;:(.,'         \n"
"                            `.. %@@@o%::;         \n"
"                               `)@@@o%::;         \n"
"                                %@@(o)::;        \n"
"                               .%@@@@%::;         \n"
"                               ;%@@@@%::;.          \n"
"                              ;%@@@@%%:;;;. \n"
"                          ...;%@@@@@%%:;;;;,..";
