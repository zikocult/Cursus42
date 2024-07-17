/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:56:54 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/16 12:20:14 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 typedef struct  s_point
 {
	int x;
	int y;
 }		t_point;

void flood_fill(char **tab, t_point size, t_point begin)
{
	char target;
	t_point up, down, left, right;

	if (begin.y < 0 || begin.x < 0 || begin.y >= size.y || begin.x >= size.x)
		return ;

	target = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';

	up.x = begin.x; 
	up.y = begin.y - 1;
	if (up.y >= 0 && tab[up.y][up.x] == target)
		flood_fill(tab, size, up);

	down.x = begin.x;
	down.y = begin.y + 1;
	if (down.y < size.y && tab[down.y][down.x] == target)
		flood_fill(tab, size, down);

	left.x = begin.x - 1;
	left.y = begin.y;
	if (left.x >= 0 && tab[left.y][left.x] == target)
		flood_fill(tab, size, left);

	right.x = begin.x + 1;
	right.y = begin.y;
	if (right.x < size.x && tab[right.y][right.x] == target)
		flood_fill(tab, size, right);
}
