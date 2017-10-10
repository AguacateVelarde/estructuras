template <class type>
class ArbolBinario;

template < class Type>
class Nodo{
private:
	Nodo<Type>* izquierda;
	Nodo<Type>* derecho;
	Type  dato;

public:
	Nodo(Type );
	friend class ArbolBinario<Type>;

};

template <class Type>
class ArbolBinario{
private:
	Nodo<Type>* Raiz;
public:
	ArbolBinario();
	// lado = 0 -> se inserta en izquierda lado = 1 -> se inserta en derecho
	void insertar( Nodo<Type>*, Type, bool );
	void insertar( Type, Type, bool );
	bool arbolVacio();
	void borrar( Type );
	Nodo<Type>* buscar( Nodo<Type>*, Type );
	Nodo<Type>* getRaiz();
	Type getDato( Nodo<Type>* );
	Nodo<Type>* getIzquierda( Nodo<Type>* );
	Nodo<Type>* getDerecho( Nodo<Type>* );
	Nodo<Type>* getPadre( Nodo<Type>* );
	void preOrden( Nodo<Type>* );
	void posOrden( Nodo<Type>* );
	void inOrden( Nodo<Type>* );
	void recorrido( int );

};
