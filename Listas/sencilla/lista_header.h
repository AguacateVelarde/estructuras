template <class type>
class List;

template <class type>
class Node{
  private:
    Node* next;
    type data;
  public:
    Node( type );
    friend class List<type>;
};

template <class type>
class List{
private:
  Node<type> * root;
public:
	List( void );
  void insertFirst( type );
  void insertAfterBy( type, type );
  void insertBeforeBy( type, type );
  void insertLast( type );
  void show( void );
  Node<type>* foundLast( void );
  Node<type>* found( type );
  Node<type>* foundOneBefore( type );
  void deleteNode( type );
  void deleteFirst( void );
  void deleteLast( void );


};
