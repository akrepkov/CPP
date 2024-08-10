/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akrepkov <akrepkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:07:04 by akrepkov          #+#    #+#             */
/*   Updated: 2024/05/14 16:30:57 by akrepkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Base_HPP
#define Base_HPP

class Base{
	public:
		virtual ~Base();

};
	Base* generate(void);
	void identify(Base* p);
	void identify(Base& p);
#endif
