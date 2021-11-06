#ifndef MY_LIST_H
#define MY_LIST_H

#include <memory>

template<class T>
class my_list;
class copy_list_algrthm {
public:

	virtual ~copy_list_algrthm() = default;
	template<class T>
	std::unique_ptr<my_list<T>> copy_list(const std::unique_ptr <my_list<T>> list);

};

template<class T>
class m_Node {
public:
	T data;
	std::shared_ptr<m_Node<T>> next = nullptr;
	std::weak_ptr  <m_Node<T>> p = nullptr;

	m_Node(T data = T()) {}
	m_Node(T data, std::shared_ptr <m_Node<T>> next, std::weak_ptr <m_Node<T>> p) {
		this->data = data;
		this->next = next;
		this->p = p;
	}
	//m_Node()

};

template<class T>
class my_list{
	friend class copy_list_algrthm;
private:
	
	size_t my_lst_size = 0;
	std::shared_ptr< m_Node<T>> head = nullptr;
	std::shared_ptr< m_Node<T>> tale = nullptr;

	std::unique_ptr<copy_list_algrthm> copyList = nullptr;
 
public:
	my_list(){
	
	}
	my_list(T data) {
		head = std::shared_ptr< m_Node<T>>(data);
		tale = head;
		my_lst_size++;
	}

	void set_copy_strategy(std::unique_ptr<copy_list_algrthm> copy_fnctn) {
		copyList.reset();
		copyList = copy_fnctn;
	}

	std::shared_ptr<m_Node<T>> get_head() {

		return head;
	}

	std::shared_ptr<m_Node<T>>get_node() {
		return 

	}


	void clear(){
		if (head == nullptr)
			return nullptr;
		else {
			std::shared_ptr< m_Node<T>> current = head;
			while (current <= tale) {
				head = current->next;
				current.reset();
				current = head;
				my_lst_size--;
			}
		}
	}
	void push_front(T data) {
		std::shared_ptr<m_Node<T>> head_tmp   = head;
		head = std::make_shared<m_Node<T>>(data);
		head->next = head_tmp;
		my_lst_size++;	
	}
	void push_back(T data) {
		std::shared_ptr<m_Node<T>> tale_tmp = tale;
		tale = std::make_shared<m_Node<T>>(data);
		tale_tmp->next = tale;
		my_lst_size++;
	}
	void pop_front() {
		std::shared_ptr<m_Node<T>> head_tmp = head;
		head = head_tmp->next;
		head_tmp.reset();
		my_lst_size--;
	};
	void pop_back() {
		std::shared_ptr<m_Node<T>> tale_tmp = tale;
		std::shared_ptr< m_Node<T>> current = head;
		while (current < tale) {
			current = current->next;
		}
		tale = current->next;
		tale_tmp.reset();
		my_lst_size--;
	};


};


class my_copy_list_fnctn : copy_list_algrthm {
public:
	template<class T>
	std::unique_ptr<my_list<T>> copy_list(std::unique_ptr<my_list<T>> list) {
		if (list->head == nullptr)
			return nullptr;
		std::unique_ptr<my_list> new_list;
		std::shared_ptr<m_Node<T>> current = list->get_head();
		while (current->next != nullptr) {
			new_list push_back(current);
			current = list->
		}

		return new_list;
	};
};


#endif

