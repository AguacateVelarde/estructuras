



template < class Type>
	Nodo<Type>::Nodo(Type dato){
		izquierda= derecho = NULL;

		this -> dato = dato;
	}



template < class Type>
	ArbolBinario<Type>::ArbolBinario(){Raiz = NULL;}
	// lado = 0 -> se inserta en izquierda lado = 1 -> se inserta en derecho
  template < class Type>
	void ArbolBinario<Type>::insertar(Nodo<Type>* root, Type datito, bool lado){

		if(Raiz == NULL){
			Raiz = new Nodo<Type>(datito);
		return; }

		if(lado==1&&root->izquierda == NULL){
				root -> izquierda = new Nodo<Type> (datito);

				return; }

		if(lado==0&&root->derecho == NULL){
			root -> derecho = new Nodo<Type> (datito);

			return; }

		if(lado == 1&&root->izquierda != NULL){
			insertar(root->izquierda, datito, 1);
			return; }

		if(lado==0&&root->derecho != NULL){
			insertar(root->derecho, datito, 0);
			return; }
		if(root == NULL){
			cout << "No mame con su root :|"<< endl;
			return; }
	}


	template < class Type>
	void ArbolBinario<Type>::insertar(Type busca, Type datito, bool lado){
		if(Raiz == NULL){
			insertar(Raiz, datito,lado);
		return;
		}
		insertar(buscar(Raiz, busca), datito, lado);
		return;
	}


	template < class Type>
	bool  ArbolBinario<Type>::arbolVacio(){return (Raiz != NULL);}

  template < class Type>
  void ArbolBinario<Type>::borrar(Type datito){
		Nodo<Type>* del = buscar(Raiz, datito);
		Nodo<Type>* aux = NULL;


		if(del == NULL){
			cout << "Su dato no existe" << endl;
			return;
		}else{
			if(del ->derecho == del ->izquierda != NULL){
				if(del == Raiz)
					Raiz = NULL;
				delete del;

				return;
			}else if(del -> derecho == NULL){
				del -> dato = del -> izquierda -> dato;
				return;

			}else if(del -> izquierda == NULL){
				del -> dato = del -> derecho -> dato;
				return;
			}else{
				aux = del;
				while(aux ->derecho != NULL){
					aux = aux -> derecho;
				}
				del -> dato = aux ->dato;
				delete aux;
			}

		}


	}

	template < class Type>
  Nodo<Type>*  ArbolBinario<Type>::buscar(Nodo<Type>* root, Type busca){
		if(Raiz == NULL){
			cout<< "El arbol está vacío" << endl;
			return NULL;
		}
		if(root ->dato == busca)
			return root;

		if( root ->izquierda!= NULL)
			if(root ->izquierda-> dato == busca)
			return (root ->izquierda);

		if( root ->derecho!= NULL)
			if(root ->derecho-> dato == busca)
			return (root ->derecho);

		if(root -> izquierda != NULL)
			if(root ->izquierda-> dato != busca)
			buscar(root -> izquierda, busca);
		if(root -> derecho != NULL)
			if(root ->derecho-> dato != busca)
			buscar(root ->derecho, busca);

		return 0;

	}



	template < class Type>
  Nodo<Type>*  ArbolBinario<Type>::getRaiz(){return Raiz; }


	template < class Type>
  Type  ArbolBinario<Type>::getDato(Nodo<Type>* root){return root -> dato;}

	template < class Type>
  Nodo<Type>*  ArbolBinario<Type>::getIzquierda(Nodo<Type>* root){return root ->izquierda;}

	template < class Type>
  Nodo<Type>*  ArbolBinario<Type>::getDerecho(Nodo<Type>* root){return root ->derecho;}

	template < class Type>
  Nodo<Type>*  ArbolBinario<Type>::getPadre(Nodo<Type>* root){return root ->padre;}

	template < class Type>
  void ArbolBinario<Type>::preOrden(Nodo<Type>* root){
		cout << root ->dato << " -> ";
		if(root -> izquierda != NULL)
			preOrden(root ->izquierda);
		if(root -> derecho != NULL)
			preOrden(root ->derecho);
		return;

	}
	template < class Type>
  void ArbolBinario<Type>::posOrden(Nodo<Type>* root){

		if(root -> izquierda != NULL)
			posOrden(root ->izquierda);
		if(root -> derecho != NULL)
			posOrden(root ->derecho);
		cout << root ->dato<< " -> ";
		return;
	}
	template < class Type>
  void ArbolBinario<Type>::inOrden(Nodo<Type>* root){
		if(root -> izquierda != NULL)
			inOrden(root ->izquierda);
		cout << root ->dato<< " -> ";
		if(root -> derecho != NULL)
			inOrden(root ->derecho);
		return;

	}

	template < class Type>

	void ArbolBinario<Type>::recorrido(int tipo){
		if(Raiz != NULL){
		//Preorden
		if(tipo == 1)
			preOrden(Raiz);
		//InOrden
		if(tipo == 2)
			inOrden(Raiz);
		//PosOrden
		if(tipo == 3)
			posOrden(Raiz);

	}else{
			cout << "El arbol está vacío"<< endl;
		}

	}
