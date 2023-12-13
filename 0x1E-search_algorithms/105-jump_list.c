{
	size_t jmp, i;
	listint_t *cur, *prev;

	if (!list || size == 0)
		return (NULL);

	jmp = sqrt(size);
	cur = list;

	while (cur->n < value && cur->next)
	{
		prev = cur;
		i = 0;
		while (cur->next && i < jmp)
		{
			cur = cur->next;
			i++;
		}
		printf("Value checked at index [%lu] = [%d]\n", cur->index, cur->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev->index,
	       cur->index);

	cur = prev;
	while (cur->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", cur->index, cur->n);
		if (cur->next)
			cur = cur->next;
		else
			return (NULL);
	}
	if (cur->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n", cur->index, cur->n);
		return (cur);
	}

	return (NULL);
}

