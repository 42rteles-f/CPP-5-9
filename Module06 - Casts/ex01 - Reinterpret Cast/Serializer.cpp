/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rteles-f <rteles-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:47:32 by rteles-f          #+#    #+#             */
/*   Updated: 2024/03/04 17:26:18 by rteles-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer& tocopy)
{
	std::cout << "Serializer Copy Constructor called." << std::endl;
	*this = tocopy;
}

Serializer::~Serializer()
{}

Serializer& Serializer::operator=(const Serializer& tocopy) {
	(void)tocopy;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}