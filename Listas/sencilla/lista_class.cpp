template <class type>
Node<type>::Node( type data ){
  this -> data = data;
  next = NULL;
}


template <class type>
List<type>::List( ){
  root = NULL;
}

template <class type>
void List<type>::insertFirst( type data ){
  Node<type> * buffer;
  if( root == NULL ){
    root = new Node<type>( data );
  }else{
	  buffer = new Node<type>( data );
    buffer -> next = root;
    root = buffer;
  }

}

template <class type>
void List<type>::show( ){
  Node<type>* buffer = root;
  if( root != NULL ){
    while( buffer != NULL ){
      cout << buffer -> data << " <- ";
      buffer = buffer -> next;
    }
  }else{
    cout << "Esta vacia su Lista"<< endl;
  }
}

template<class type>
Node<type>* List<type>::foundLast( ){
  Node<type>* buffer = root;
  while( buffer -> next != NULL ){
    buffer = buffer -> next;
  }
  return buffer;
}

template<class type>
void List<type>::insertLast( type data ){
  Node<type>* buffer;
  if( root == NULL ){
    root = new Node<type>( data );
  }else{
    buffer = foundLast();
    buffer -> next = new Node<type>( data );
  }

}

template <class type>
void List<type>::deleteNode( type data  ){
  Node<type>* buffer = found( data );
  Node<type>* buffer_ = foundOneBefore( data );
  if( buffer == NULL ){
    cout << "No existe el dato que desea eliminar"<< endl;
  } else if( buffer == root ){
    root = root -> next;
    delete buffer;
  }
  else{
    buffer_ -> next = buffer -> next;
    delete buffer;
  }

}

template <class type>
Node<type>* List<type>::found( type data ){
    Node<type>* buffer = root;
    while(  buffer != NULL ){
      if( buffer -> data == data )
        break;
      buffer = buffer ->next;
    }
    return buffer == NULL ? NULL : buffer;
}

template <class type>
Node<type>* List<type>::foundOneBefore( type data ){
    Node<type>* buffer = root;
    Node<type>* verify = found( data );
    if( verify != root ){
      while( buffer -> next -> data != data && buffer != NULL ){
        buffer = buffer ->next;
      }
      return buffer;
    }else{
      return NULL;
    }
}

template <class type>
void List<type>::deleteFirst(  ){
  Node<type>* buffer = root;
  root = root -> next;
  delete buffer;
}

template <class type>
void List<type>::deleteLast(  ){
  Node<type>* buffer = root;

  while( buffer -> next != NULL )
    buffer = buffer -> next;
    if( buffer == root )
       root = NULL;
    else
      buffer = NULL;
}

template <class type>
void List<type>::insertAfterBy(  type data , type data_ ){
  Node<type>* buffer = found( data );
  Node<type>* buffer_;
  if( buffer != NULL ){

    buffer_ = buffer -> next;
    buffer -> next = new Node<type> ( data_ );
    buffer -> next -> next = buffer_;
  }else{
    cout << "Su dato no se puede eliminar porque no existe :( "<< endl;
  }

}

template <class type>
void insertBeforeBy( type, type );
