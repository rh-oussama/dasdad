/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  split_or_and_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  By: oussama<oussama@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*  Created: 2024/03/02 11:47:20 by oussama           #+#    #+#             */
/*  Updated: 2024/03/02 14:08:18 by oussama          ###   ########.fr       */
/*                                                                            */
/* ***************************************************************************/


#include "hello.h"

int is_operator(char *data, int index)
{
	int i;
	int dq = 0;
	int sq = 0;
	int pr = 0;

	i = -1;
	while (data[++i] && i < index)
	{
		if (data[i] == '"' && dq == 0)
			dq++;
		else if (data[i] == '"' && dq)
			dq--;
		if (data[i] == '\'' && sq == 0)
			sq++;
		else if (data[i] == '\'' && sq)
			sq--;
		if (data[i] == '(')
			pr++;
		else if (data[i] == ')')
			pr--;
	}

	if (sq == 0 && dq == 0 && pr == 0)
		return (1);
	return (0);
}

char *get_split_line(char *row_data, int *index)
{
	int i;
	int j = 0;
	char *split;

	split = malloc(sizeof(char) *split_line_len(row_data));
	(*index) --;
	i = -1;
	while (row_data[++i])
	{
		if ((strncmp(&row_data[i], "&&", 2) == 0 || strncmp(&row_data[i], "||", 2) == 0) && is_operator(row_data, i))
			break;
		else
			split[j++] = row_data[i];
		(*index) ++;
	}

	split[j] = 0;
	return (split);
}

int split_line_len(char *row_data)
{
	int i;

	i = -1;
	while (row_data[++i])
		if ((strncmp(&row_data[i], "&&", 2) == 0 || strncmp(&row_data[i], "||", 2) == 0) && is_operator(row_data, i))
			break;
	return (i + 1);
}

int split_and_or_len(char *row_data)
{
	int i;
	int len;

	len = 1;
	i = -1;
	while (row_data[++i])
	{
		if ((strncmp(&row_data[i], "&&", 2) == 0 || strncmp(&row_data[i], "||", 2) == 0) && is_operator(row_data, i))
		{
			len += 2;
			i++;
		}
	}

	return (len + 1);
}

char **split_and_or(char *row_data)
{
	char **data = malloc(sizeof(char*) *split_and_or_len(row_data));

	int i;
	int u = 0;

	i = -1;
	while (row_data[++i])
	{
		if (strncmp("&&", &row_data[i], 2) == 0 && is_operator(row_data, i))
		{
			data[u++] = strdup("&&");
			i++;
		}
		else if (strncmp("||", &row_data[i], 2) == 0 && is_operator(row_data, i))
		{
			data[u++] = strdup("||");
			i++;
		}
		else
			data[u++] = get_split_line(&row_data[i], &i);
	}

	data[u] = NULL;

	return data;
}
