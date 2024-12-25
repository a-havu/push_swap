/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 10:00:27 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/25 12:19:35 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  compare(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i] != 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

static int     incl_dup(int argc, char **argv)
{
    int i;
    int k;

    i = 1;
    k = 2;
    while (i < argc)
    {
        while (argv[k])
        {
            if (compare(argv[i], argv[k]))
                return (1);
            else
                k++;
        }
        i++;
    }
    return (0);
}

static int  incl_chars(char *arg)
{
    int i;

    i = 0;
    while (i < ft_strlen(arg))
    {
        if (ft_isdigit(arg[i]) || (arg[i] == '-' && ft_isdigit(arg[i + 1]))
        || (arg[i] == '+' && ft_isdigit(arg[i + 1])))
            i++;
        else
            return (1);
    }
    return (0);
}

char     **check_args(int argc, char **argv)
{
    int     i;
    int     k;
    
    i = 1;
    k = 0;
    if (argc == 2)
    {
        ft_strtrim(argv[1], "\"");
        argv = ft_split(argv[1], ' ');
    }
    while (argv[i])
    {
        if (incl_chars(argv[i]))
            return (NULL);
        if (incl_dup(argc, argv))
            return (NULL);
    }
        i++;
    return (argv);
}
