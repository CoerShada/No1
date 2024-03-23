#pragma once
#include <iostream>
#include <stdexcept>
#include <string> 


template<typename Type>
class LinkedList
{
friend class ListItem;

private:
	class ListItem
	{
		
	friend class LinkedList;

	public:
		ListItem(Type *content)
		{
			this->m_content = content;
			this->m_next_item = nullptr;
		}

		ListItem* GetNext() 
		{
			return m_next_item;
		}

		friend std::ostream& operator<<(std::ostream& stream, ListItem* listItem) {
			return stream << listItem->m_content;
		}

	private:
		int m_index;
		Type *m_content;
		ListItem* m_next_item;
	};

	int m_size;
	ListItem* m_first_item;

public:
	LinkedList() 
	{
		m_size = 0;
		m_first_item = nullptr;
	}

	~LinkedList() 
	{
		delete m_first_item;
	}

	void Add(Type* item) 
	{
		if (m_first_item != nullptr) 
		{
			auto current_item = m_first_item;
			while (current_item->m_next_item != nullptr)
			{
				current_item = current_item->m_next_item;
			}

			current_item->m_next_item = new ListItem(item);
		}
		else 
		{
			m_first_item = new ListItem(item);
		}

		m_size++;
	}
	Type *Remove(int index) 
	{
		if (index < 0 || index >= m_size)
			throw new std::out_of_range("index " + std::to_string(index) + " was out of range list of size = " + std::to_string(m_size));

		if (m_first_item == nullptr)
			throw new std::logic_error("first_item can't be nullptr");


		int curix = 0;
		auto cur_item = m_first_item;
		ListItem *prev = nullptr;

		while (cur_item && curix < index) {
			prev = cur_item;
			cur_item = cur_item->m_next_item;
			curix++;
		}

		if (!cur_item) {
			return nullptr;
		}

		Type* cont;
		if (!cur_item->m_next_item && !prev) {
			cont = cur_item->m_content;
			delete m_first_item;
			m_first_item = nullptr;

			return cont;

		}

		if (prev) {
			prev->m_next_item = cur_item->m_next_item;
			cur_item->m_next_item = prev;
		} else {
			m_first_item = cur_item->m_next_item;
		}

		cont = cur_item->m_content;

		delete cur_item;
		m_size--;

		return cont;
	}

	Type* Get(int index) 
	{
		if (index < 0 || index >= m_size)
			throw new std::out_of_range("index " + std::to_string(index) + " was out of range list of size = " + std::to_string(m_size));

		if (m_first_item == nullptr)
			throw new std::logic_error("first_item can't be nullptr");

		auto result = m_first_item;
		
		if (index) {
			while (index--) {
				result = result->m_next_item;
			}
		}


		return result->m_content;
	}

	int GetSize() 
	{
		return m_size;
	}

	Type* operator[](int index) {
		return Get(index);
	}


	friend std::ostream& operator<<(std::ostream& stream, LinkedList<Type>& list) {
		if (list.m_first_item != nullptr) 
		{
			auto current_item = list.m_first_item;

			do 
			{
				stream << current_item << std::endl;
			} while ((current_item = current_item->GetNext()) != nullptr);
		}

		return stream;
	}
};


