/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-09 06:36:29 by welow             #+#    #+#             */
/*   Updated: 2025-02-09 06:36:29 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#ifndef CALL
#define CALL 0
#endif

#include <iostream>
#include <string>

class Brain
{
    private:
        std::string _idea[100];
    public:
        Brain(void);
        Brain(std::string idea);
        Brain(const Brain &src);
        Brain &operator=(const Brain &src);
        ~Brain(void);
        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
};

#endif