/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:24:18 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/08 12:16:24 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

char **args_split(char *arg)
{
    char    **ret;
    
    if (ft_strchr(arg, '\"'))
    {
        arg = ft_strtrim(arg, "\"");
        ret = ft_split(arg, ' ');
		if (!ret)
		{
			free (ret);
			return (NULL);
		}
    }
	else
	{
		ft_printf("%s\n", "Error");
        return (NULL);
	}
    return (ret);
}