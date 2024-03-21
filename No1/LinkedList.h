#pragma once
#include <stdexcept>

template<typename Type>
class LinkedList
{
private:
	template<typename Type>
	class ListItem
	{
	public:
		template<typename Type>
		ListItem(int index, Type content) 
		{
			this->index = index;
			this->content = content;
			this->next_item = NULL;
		}

		~ListItem() 
		{
			delete& index;
			delete& next_item;
		}

	private:
		int index;
		Type content;
		ListItem next_item;
	};

	int size;
	ListItem<Type> first_item;

public:
	LinkedList<Type>();
	void Add(Type item);
	Type Remove(int index);
	Type Get(int index);
	int GetSize();
};

