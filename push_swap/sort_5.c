#include "push_swap.h"

int	size_five(t_node **a, t_node **b, int size)
{
	if (size == 5)
	{
		if ((*b)->content < (*a)->content
			&& (*b)->content > (*a)->prev->content)
		{
			pa(a, b);
			rra(a);
			rra(a);
			return (1);
		}
	}
	return (0);
}

int	push_rules_1(t_node **a, t_node **b, int size)
{
	max_values maxValues = find_max(*a);
	if ((*b)->content > maxValues.max)
	{
		pa(a, b);
		ra(a);
	}
	else if ((*b)->content < (*a)->content)
		pa(a, b);
	else if ((*b)->content > (*a)->content
		&& (*b)->content < (*a)->next->content)
	{
		pa(a, b);
		sa(a);
	}
	else if ((*a)->prev->content > (*b)->content
		&& (*b)->content > (*a)->prev->prev->content)
	{
		rra(a);
		pa(a, b);
		if (size_five(a, b, size))
			return (0);
		ra(a);
		ra(a);
	}
	return (1);
}

void	last_case(t_node **a, t_node **b)
{
	ra(a);
	ra(a);
	pa(a, b);
	rra(a);
	rra(a);
}

void	push_rules_2(t_node **a, t_node **b)
{
	if ((*b)->content < (*a)->content)
		pa(a, b);
	else if ((*b)->content > (*a)->prev->content)
	{
		pa(a, b);
		ra(a);
	}
	else if ((*b)->content > (*a)->content
		&& (*b)->content < (*a)->next->content)
	{
		pa(a, b);
		sa(a);
	}
	else if ((*b)->content < (*a)->prev->content
		&& (*b)->content > (*a)->prev->prev->content)
	{
		rra(a);
		pa(a, b);
		ra(a);
		ra(a);
	}
	else
		last_case(a, b);
}

void	sort_5(t_node **a, t_node **b)
{

	if (is_sorted(a) == true)
		return ;
	if (ft_lstsize((*a)) == 4)
	{
		pb(b, a);
		sort_3(a);
		push_rules_1(a, b, 4);
	}
	else
	{
		if (((*a)->content < (*a)->next->content)
			&& ((*a)->next->content < (*a)->next->next->content)
			&& ((*a)->next->next->content < (*a)->prev->prev->content)
			&& ((*a)->prev->prev->content < (*a)->prev->content))
			return ;
		pb(a, b);
		pb(a, b);
		sort_3(a);
		if (push_rules_1(a, b, 5))
			push_rules_2(a, b);
	}
}