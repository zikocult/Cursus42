/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:07:06 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/07/15 19:10:02 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct  s_point
{
    int           x;
    int           y;
}               t_point;

void  flood_fill(char **tab, t_point size, t_point begin)
{
    char target;

    if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
        return;

    target = tab[begin.y][begin.x];

    tab[begin.y][begin.x] = 'F';

    t_point up = {begin.x, begin.y - 1};
    if (up.y >= 0 && tab[up.y][up.x] == target)
        flood_fill(tab, size, up);
    t_point down = {begin.x, begin.y + 1};
    if (down.y < size.y && tab[down.y][down.x] == target)
        flood_fill(tab, size, down);
    t_point left = {begin.x - 1, begin.y};
    if (left.x >= 0 && tab[left.y][left.x] == target)
        flood_fill(tab, size, left);
    t_point right = {begin.x + 1, begin.y};
    if (right.x < size.x && tab[right.y][right.x] == target)
        flood_fill(tab, size, right);
}
