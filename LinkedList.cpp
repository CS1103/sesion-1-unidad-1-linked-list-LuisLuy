#include "LinkedList.h"

size_t utec::CLinkedList::size() const
{
	return size_;
}

utec::CNode* utec::CLinkedList::p_item(size_t index) const
{
	auto actual = head_;

	while (index--)
		actual = actual->next_;

	return actual;
}

void utec::CLinkedList::erase(size_t index)
{
	if (head_ == tail_)
	{
		delete head_;
		head_ = tail_ = nullptr;
		size_ = 0;
	}
//
	else
	{
		if (index == 0)
			pop_front();

		else if (index == size_ - 1)
			pop_back();

		else
		{
			auto aux = p_item(index + 1);
			delete p_item(index);
			p_item(index - 1)->next_ = aux;
			--size_;
		}
	}
}
void utec::CLinkedList::pop_front() {
  if (size_ == 0)
    return;
        
  auto aux = head_;
  head_ = head_->next_;
  delete aux;
  --size_;
}
    
void utec::CLinkedList::pop_back() {
  if (size_ <= 0) return;

  if (size_ == 1) 
  {
    tail_ = nullptr;
    delete head_;
    head_ = nullptr;
  
    --size_;
      return;
  }
    
    auto aux = head_;
    while ( aux->next_->next_ != nullptr )
        aux = aux->next_;
    
    delete aux->next_;
    aux->next_ = nullptr;
    --size_;
}

utec::CLinkedList::~CLinkedList() {
    while ( size_ > 0 )
        pop_front();
}

utec::CLinkedList::CLinkedList(CLinkedList & other) {
    for ( auto i = other.head_ ; i != nullptr ; i = i->next_ )
        push_back(i->value_);
}

utec::CLinkedList::CLinkedList(CLinkedList && other) noexcept
        : size_(other.size_), head_(other.head_), tail_(other.tail_) {
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
}

utec::CLinkedList & utec::CLinkedList::operator =(const CLinkedList & other) {
    while ( size_ > 0 )
        pop_front();
    
    auto i = other.head_;
    while ( i != nullptr ) {
        push_back(i->value_);
        i = i->next_;
    }
    
    return *this;
}

utec::CLinkedList & utec::CLinkedList::operator =(CLinkedList && other) noexcept {
    size_ = other.size_;
    other.size_ = 0;
    head_ = other.head_;
    other.head_ = nullptr;
    tail_ = other.tail_;
    other.tail_ = nullptr;
    return *this;
}

void utec::CLinkedList::push_front(int value) {
    auto aux = head_;
    head_ = new CNode(value);
    head_->next_ = aux;
}

void utec::CLinkedList::push_back(int value) {
    auto aux = new CNode(value);
    
    if (size_ == 0) {
        head_ = aux;
        tail_ = aux;
        size_ = 1;
        return;
    }
    
    tail_->next_ = aux;
    tail_ = aux;
    ++size_;
}


void utec::CLinkedList::insert(size_t index, int value) {
    if (index == 0) {
        push_front(value);
        return;
    }
    if (index == size_) {
        push_back(value);
        return;
    }
    
    auto aux = head_;
    for ( auto i = 0 ; i < index - 1 ; ++i )
        aux = aux->next_;
    
    auto aux2 = aux->next_;
    aux->next_ = new CNode(value);
    aux->next_->next_ = aux2;
    ++size_;
}

int utec::CLinkedList::item(size_t index) const {
    return p_item(index)->value_;
}

string utec::CLinkedList::complete_list() {
    string str;
    for ( auto i = head_ ; i != nullptr ; i = i->next_ )
    str += to_string(i->value_) + " -> ";
    
  return str;
}
