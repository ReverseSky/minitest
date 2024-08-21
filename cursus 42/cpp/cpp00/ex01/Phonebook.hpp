/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 17:07:54 by grobledo          #+#    #+#             */
/*   Updated: 2024/08/17 22:32:43 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "repertory.hpp"

class Phonebook
{
	public :

		Phonebook();
		~Phonebook();

		void	add_contact();
		void	search_contact();
	
	private :

		int	current_contact;
		int	nb_contact;
		Contact	array[8];

};
#endif