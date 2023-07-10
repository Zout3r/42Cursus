/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:49:48 by jperez-p          #+#    #+#             */
/*   Updated: 2023/06/14 16:55:02 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

long int			ft_atoi(const char *str);
void				ft_putstr(char *str);
char				**ft_split(char const *s, char c);
void				cost(t_stack **stack_a, t_stack **stack_b);
void				cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);
int					position_lowest_index(t_stack **stack);
void				get_target_position(t_stack **stack_a, t_stack **stack_b);
void				do_ra(t_stack **stack_a);
void				do_rb(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);
void				do_rra(t_stack **stack_a);
void				do_rrb(t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack);
void				sort(t_stack **stack_a, t_stack **stack_b);
t_stack				*stack_new(int value);
void				stack_add(t_stack **stack, t_stack *new);
t_stack				*get_bottom(t_stack *stack);
t_stack				*before_bottom(t_stack *stack);
int					get_stack_size(t_stack *stack);
long				input_is_correct(char *str);
int					is_duplicate(t_stack *column);
void				get_index(t_stack *stack_a, int stack_size);
int					abs(int nb);
void				error_exit(t_stack **stack_a, t_stack **stack_b);
void				free_stack(t_stack **stack);
void				do_ss(t_stack **stack_a, t_stack **stack_b);
void				do_sb(t_stack **stack_b);
void				do_sa(t_stack **stack_a);
int					is_sorted(t_stack *stack);
size_t				ft_strlen(const char *s);
void				get_numbers(char *av, t_stack **stack_a);

#endif