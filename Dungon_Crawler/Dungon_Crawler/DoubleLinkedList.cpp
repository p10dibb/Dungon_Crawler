//#include "DoublelinkedList.h"
//
//
//template<class T>
//Node<T>* DoubleLinkedList<T>::getHead() {
//	return Head();
//}
//
//template<class T>
//void DoubleLinkedList<T>::setHead(Node<T> node) {
//	Head = node;
//}
//
//template<class T>
//Node<T>* DoubleLinkedList<T>::getTail() {
//	return Tail;
//}
//
//template<class T>
//void DoubleLinkedList<T>::setTail(Node<T> node) {
//	Tail = node;
//}
//
//template<class T>
//DoubleLinkedList<T>::DoubleLinkedList() {
//	this->Head = NULL;
//	this->Tail = NULL;
//	this->size = 0;
//}
//template<class T>
//int DoubleLinkedList<T>::Size() {
//	return this->size;
//}
//
//template<class T>
//void DoubleLinkedList<T>::add(T info) {
//	Node<T>* temp = new Node<T>(info);
//
//	if (this->Head == NULL) {
//		this->Head = temp;
//		this->Tail = Head;
//		this->size++;
//	}
//	else {
//		this->Tail->setNext(temp);
//		temp->setPre(Tail);
//		Tail = temp;
//		size++;
//	}
//}