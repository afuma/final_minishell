// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   utils.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: edesaint <edesaint@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/22 11:23:27 by edesaint          #+#    #+#             */
// /*   Updated: 2024/01/27 18:01:33 by edesaint         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../include/minishell.h"

// void	ft_token_add_back(t_token **token, t_token *newlist)
// {
// 	t_token	*l;

// 	if (!token || !newlist)
// 		return ;
// 	if (*token)
// 	{
// 		l = ft_token_last(*token);
// 		l->next = newlist;
// 	}
// 	else
// 		*token = newlist;
// }

// t_token	*ft_token_last(t_token *token)
// {
// 	if (!token)
// 		return (NULL);
// 	while (token->next)
// 		token = token->next;
// 	return (token);
// }

// void	ft_token_iter(t_data *data, bool (*f)(t_token *))
// {
// 	t_token *token;

// 	token = data->token;
// 	while (token)
// 	{
// 		f(token);
// 		token = token->next;
// 	}
// }

// void	ft_token_iter_expander(t_data *data, void (*f)(t_env *, char *))
// {
// 	t_token *token;
// 	t_env *tmp_env;
	
// 	token = data->token;
// 	tmp_env = data->env;
// 	while (token)
// 	{
// 		if (is_expandable(token))
// 			f(tmp_env, token->str);
// 		token = token->next;
// 	}
// }

// bool process_tokens(t_data *data, bool (*f)(char *str))
// {
//     t_token *token;
    
//     token = data->token;
//     while (token)
//     {
//         if (!f(token->str))
//             return (false);
//         token = token->next;
//     }
//     return (true);
// }

// bool is_redir_heredoc(t_state *ttoken_1, t_state *ttoken_2)
// {
// 	return (ttoken_1 == T_REDIR_HEREDOC && ttoken_2 == T_FILE);
// }

// bool process_heredoc(t_data *data, t_node *node)
// {
//     t_token *token;
    
//     token = data->token;
//     while (token)
//     {
// 		if (token && token->next && in_node(data, token))
// 		{
// 			if (is_redir_heredoc(token->type_token, token->next->type_token))
// 			{
// 				if (!sub_process_heredoc(node, token->next->str))
// 					return (false);
// 			}
// 		}
//         token = token->next;
//     }
//     return (true);
// }

// bool sub_process_heredoc(t_node *node, char *str, char *delimiter)
// {
// 	get_and_save_heredoc_content(node, str, delimiter);
// 	node->redir_heredoc = get_name_heredoc();

//     return (true);
// }

// void	get_and_save_heredoc_content(t_node *node, char *str, char *delimiter)
// {
// 	char *line;
//     char *heredoc_content;
// 	size_t new_size;
	
// 	line = readline("> ");
//     while (line != NULL)
// 	{
//         if (ft_strcmp(line, delimiter) == 0)
// 		{
//             free(line);
//             break;
//         }
// 		new_size = strlen(heredoc_content) + strlen(line) + 2;
//         heredoc_content = ft_realloc(heredoc_content, new_size);
//         ft_strlcat(heredoc_content, line, new_size);
//         ft_strlcat(heredoc_content, "\n", new_size);
//         free(line);
//     }
// 	save_heredoc(node->redir_heredoc, heredoc_content);
// 	free(heredoc_content);
// }

// bool save_heredoc(char *name, char *content)
// {
// 	int fd;

// 	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
//     close(fd);
// 	return (true);
// }