/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:29:11 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/16 22:34:59 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
	int count = 0;

	while (str[count])
		count++;
	return (count);
}