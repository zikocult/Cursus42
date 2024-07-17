/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:46:40 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/16 22:51:13 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int ft_list_size(t_list *begin_list)
{
	int	count = 0;

	while (begin_list)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}
