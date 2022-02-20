/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:06:47 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/20 16:32:11 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lab.hpp"

int	is_valid_product(std::string product)
{
	return (product == "A" || product == "B" || product == "C" || product == "D");
}

std::map<std::string, int> init_map()
{
	std::map<std::string, int> curr;

	curr["A"] = 0;
	curr["B"] = 0;
	curr["C"] = 0;
	curr["D"] = 0;

	return (curr);
}

static void	find_max_price()
{
	int N;
	int input_price;
	std::string input_data[3];
	std::map<std::string, int> max_prices = init_map();
	std::map<std::string, int> count_shops = init_map();


	std::cout << "Input N: ";
	std::cin >> N;

	std::cout << "Input data about shops and prices:\n";
	for (int i = 0; i < N; i++)
	{
		std::cin >> input_data[0] >> input_data[1] >> input_data[2] >> input_price;
		if (is_valid_product(input_data[2]))
		{
			if (max_prices[input_data[2]] < input_price)
			{
				max_prices[input_data[2]] = input_price;
				count_shops[input_data[2]] = 1;
			}
			else if (max_prices[input_data[2]] == input_price)
				count_shops[input_data[2]]++;
		} 
		else {
			std::cout << "Bad input product, please retry";
			exit(1);
		}
	}

	std::cout << "Result: " << count_shops["A"] << " " << count_shops["B"] << " " << count_shops["C"] << " " << count_shops["D"];
	
}	

int main ()
{
	find_max_price();
	return (0);
}