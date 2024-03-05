/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:16:18 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/05 17:16:18 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"

int	main(void)
{
	Data		structure;
	uintptr_t	ptr;

	ptr = Serializer::serialize(&structure);
	std::cout << ((Serializer::deserialize(ptr) == &structure) ?
					"Equal Pointers" : "Different Pointers") << std::endl;
}