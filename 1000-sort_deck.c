#include "deck.h"


/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_val - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_val(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_deckSort- Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deckSort(deck_node_t **deck)
{
	deck_node_t *current_lead, *current_follow, *temp;

	for (current_lead = (*deck)->next; current_lead != NULL; current_lead = temp)
	{
		temp = current_lead->next;
		current_follow = current_lead->prev;
		while (current_follow != NULL && current_follow->card->kind >
			current_lead->card->kind)
		{
			current_follow->next = current_lead->next;
			if (current_lead->next != NULL)
				current_lead->next->prev = current_follow;
			current_lead->prev = current_follow->prev;
			current_lead->next = current_follow;
			if (current_follow->prev != NULL)
				current_follow->prev->next = current_lead;
			else
				*deck = current_lead;
			current_follow->prev = current_lead;
			current_follow = current_lead->prev;
		}
	}
}

/**
 * insertion_sort_sortValue - Sort a deck of cards sorted from
 * spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_sortValue(deck_node_t **deck)
{
	deck_node_t *current_lead, *current_follow, *temp;

	for (current_lead = (*deck)->next; current_lead != NULL;
	current_lead = temp)
	{
		temp = current_lead->next;
		current_follow = current_lead->prev;
		while (current_follow != NULL &&
		       current_follow->card->kind == current_lead->card->kind &&
		       get_val(current_follow) > get_val(current_lead))
		{
			current_follow->next = current_lead->next;
			if (current_lead->next != NULL)
				current_lead->next->prev = current_follow;
			current_lead->prev = current_follow->prev;
			current_lead->next = current_follow;
			if (current_follow->prev != NULL)
				current_follow->prev->next = current_lead;
			else
				*deck = current_lead;
			current_follow->prev = current_lead;
			current_follow = current_lead->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and function
 * from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deckSort(deck);
	insertion_sort_sortValue(deck);
}
