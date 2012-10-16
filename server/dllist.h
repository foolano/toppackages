#ifndef DLLIST_H
#define DLLIST_H

/* The main reason to have or own DLL is to not
 * use iterators as pointers to list nodes.
 */

template<class T>
struct dlnodelist {
    T value;
    dlnodelist<T> *next;
    dlnodelist<T> *prev;
};

template <class T>
class dllist {
  public:
  dllist() : _head(0), _tail(0), _length(0) { }

  void push_front(T value) {
    dlnodelist<T>* node = new dlnodelist<T>();
    node->value = value;
    node->prev = 0;
    if (_head) {
      node->next = _head;
      _head->prev = node;
    } else {
      node->next = 0;
      _tail = node;
    }
    _head = node;
    _length++;
  }

  void to_front(dlnodelist<T>* node) {
    if (!node->prev)
      return;

    if (!node->next) {
      node->prev->next = 0;
      _tail = node->prev;
    } else {
      node->prev->next = node->next;
      node->next->prev = node->prev;
    }
    node->prev = 0;
    node->next = _head;
    if (_head) {
      _head->prev = node;
    }
    _head = node;
  }

  dlnodelist<T>* front() { return _head; }
  dlnodelist<T>* back() { return _tail; }
  size_t length() { return _length; }

  private:
  dlnodelist<T> *_head;
  dlnodelist<T> *_tail;
  size_t _length;

};

#endif