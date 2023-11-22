/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:45:43 by gmorais-          #+#    #+#             */
/*   Updated: 2023/11/21 09:28:08 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*falta teste*/
#include "../inc/minishell.h"

static void add_var(char *var)
{
    int i = 0;
    
    while (data()->copy_env[i])
    {
        if (ft_strncmp(var, data()->copy_env[i], ft_strlen(var)) == 0) {
            // Atualiza uma variável de ambiente existente
            free(data()->copy_env[i]);
            data()->copy_env[i] = ft_strdup(var);
            return;
        }
        i++;
    }
    // Se a variável não existe, adiciona uma nova
    data()->copy_env = ft_realloc(data()->copy_env, (i + 2) * sizeof(char *));
    if (data()->copy_env)
    {
        data()->copy_env[i] = ft_strdup(var);
        data()->copy_env[i + 1] = NULL;
    }
    else
        ft_putstr_fd("export: memory allocation error\n", 2);
}

void    func_export(char **line)
{
    int i = 1;

    if (!line[i])
    func_env();
    else {
        while (line[i])
        {
            if (ft_strchr(line[i], '=') != NULL)
                add_var(line[i]);
            else
            {
                ft_putstr_fd("export: not an identifier: ", 2);
                ft_putstr_fd(line[i], 2);
                ft_putstr_fd("\n", 2);
            }
            i++;
        }
    }
}
