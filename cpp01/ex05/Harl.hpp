/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:39:06 by akrepkov          #+#    #+#             */
/*   Updated: 2024/03/26 13:41:01 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 //READ   https://isocpp.org/wiki/faq/pointers-to-members 
/*    void: This specifies the return type of the functions
    (Harl::*fptr[4])(): This declares an array of function pointers named fptr. 
	Each function pointer in this array can point to a member function of the Harl class.
    Harl::*: This specifies that the function pointers in the array are member function pointers of the Harl class.
    fptr[4]: This indicates that fptr is an array of 4 function pointers.
    = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error}: 
	&_debug, &_info, &_warning, and &_error are the addresses of member functions _debug, _info, _warning, and _error of the Harl class, respectively.*/

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

class Harl{
	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);

	public:
		void complain( std::string level);

};

#endif

