#include "LinkedList.h"
#include <iostream>
#include <string> 
#include <stdexcept>


template<typename Type>
inline LinkedList<Type>::LinkedList()
{
	size = 0;
	first_item = NULL;
}

template<typename Type>
inline Type LinkedList<Type>::Get(int index) {
	if (index < 0 || index >= size)
		throw new std::out_of_range("index " + std::to_string(index) + " was out of range list of size = " + std::to_string(size));

	if (first_item == NULL)
		throw new std::logic_error("first_item can't be null");

	ListItem<Type> result = first_item;

	while (result.GetIndex() != index)
	{
		result = result.GetNextItem();

		if (result == NULL)
			throw new std::logic_error("next_item can't be null on index " + std::to_string(index) + " in list size " + std::to_string(size));
	}

	return result.GetContent();
}

template<typename Type>
inline void LinkedList<Type>::Add(Type item)
{
	if (first_item != NULL) {
		ListItem current_item = first_item;
		while (current_item.next_item != NULL)
		{
			current_item = current_item.next_item;
		}
		
		int last_index = current_item.index + 1;
		current_item.next_item = new ListItem<Type>(last_index, item);
		size = last_index + 1;
	}
	else {
		first_item = new ListItem<Type>(0, item);
		size = 1;
	}
}

template<typename Type>
inline Type LinkedList<Type>::Remove(int index) {
	if (index < 0 || index >= size)
		throw new std::out_of_range("index " + std::to_string(index) + " was out of range list of size = " + std::to_string(size));

	if (first_item == NULL)
		throw new std::logic_error("first_item can't be null");

	ListItem<Type> current_item = first_item;
	if (index > 0) 
	{
		bool item_found = false;
		ListItem<Type> previous_item = first_item;

		while (previous_item.next_item != NULL) {
			ListItem<Type> temp_current_item = previous_item.next_item;
			
			if (temp_current_item.index == index && !item_found) {
				current_item = temp_current_item;
				previous_item.next_item = current_item;
				item_found = true;
			}

			if (item_found)
				temp_current_item.index--;

			previous_item = temp_current_item;
		}
	}
	else
	{
		ListItem<Type> temp_current_item = first_item;
		while (temp_current_item.next_item != NULL)
		{
			temp_current_item.index--;
			temp_current_item = temp_current_item.next_item;
		}

		temp_current_item.index--;
		temp_current_item = NULL;

		first_item = first_item.next_item;
	}

	size--;
	return current_item.content;
}

