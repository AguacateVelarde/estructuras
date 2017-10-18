

/* Prototipo de la plantilla de la clase ArbolBinBus. En la clase NodoArbol se
   podr� hacer referencia a ella. */
template <class T>
class ArbolBinBus;
/* Declaraci�n de la clase NodoArbol. Cada nodo almacena la informaci�n (lo que da nombre a la
   estructura) y las direcciones de sus hijos izquierdo y derecho. Se incluye una relaci�n de
   amistad con la clase ArbolBinBus para pueda tener acceso a sus miembros privados. */
template <class T>
class NodoArbol
{
private:
  T Info;
  NodoArbol<T> *HijoIzq;
  NodoArbol<T> *HijoDer;
public:
  NodoArbol();
  T RegresaInfo() ;
  void ActualizaInfo(T);
  friend class ArbolBinBus<T>;
};

/* Declaraci�n del m�todo constructor por omisi�n. Inicializa las ligas a los subArboles con el valor
   NULL, indicando que no tiene hijos. */
template <class T>
NodoArbol<T>::NodoArbol()
{
  HijoIzq=NULL;
  HijoDer=NULL;
}

/* M�todo que regresa la informaci�n almacenada en el nodo. */
template <class T>
T NodoArbol<T>::RegresaInfo()
{
  return Info;
}

/* M�todo para actualizar la informaci�n almacenada en el nodo. */
template <class T>
void NodoArbol<T>::ActualizaInfo(T Dato)
{
  Info=Dato;
}

/* Declaraci�n de la clase ArbolBinBus. Su atributo es un apuntador al nodo ra�z. */
template <class T>
class ArbolBinBus
{
private:
  NodoArbol<T> *Raiz;
public:
  ArbolBinBus();
  NodoArbol<T> *RegresaRaiz();
  void Preorden (NodoArbol<T> *);
  void Inorden (NodoArbol<T> *);
  void Postorden (NodoArbol<T> *);
  NodoArbol<T> * Busqueda (NodoArbol<T> *, T);
  void InsertaNodoSinRep (NodoArbol<T> *, T);
  void EliminaNodo (NodoArbol<T> *, T);
};

/* Declaraci�n del m�todo constructor. Inicializa el apuntador a la ra�z con el valor NULL, indicando
   Arbol vac�o (no tiene nodos). */
template <class T>
ArbolBinBus<T>::ArbolBinBus()
{
  Raiz=NULL;
}

/* M�todo que regresa el valor del apuntador a la ra�z del Arbol. */
template <class T>
NodoArbol<T> *ArbolBinBus<T>::RegresaRaiz()
{
  return Raiz;
}

/* M�todo que realiza el recorrido preorden de un Arbol binario de b�squeda. Recibe como par�metro el nodo
   a visitar (la primera vez es la ra�z). */
template <class T>
void ArbolBinBus<T>::Preorden (NodoArbol<T> *Apunt)
{
  if (Apunt)
  {
    cout << Apunt->Info << "  ";
    Preorden(Apunt->HijoIzq);
    Preorden(Apunt->HijoDer);
  }else{
    return;
	  //cout << "esta vacia";
  }
}

/* M�todo que realiza el recorrido inorden de un Arbol binario de b�squeda. Recibe como par�metro el nodo
   a visitar (la primera vez es la ra�z). */
template <class T>
void ArbolBinBus<T>::Inorden (NodoArbol<T> *Apunt)
{
 if (Apunt)
 {
   Inorden(Apunt->HijoIzq);
   cout << Apunt->Info << "  ";
   Inorden(Apunt->HijoDer);
 }
}

/* M�todo que realiza el recorrido postorden de un Arbol binario de b�squeda. Recibe como par�metro el nodo
   a visitar (la primera vez es la ra�z). */
template <class T>
void ArbolBinBus<T>::Postorden (NodoArbol<T> *Apunt)
{
  if (Apunt)
  {
    Postorden(Apunt->HijoIzq);
    Postorden(Apunt->HijoDer);
    cout << Apunt->Info << "  ";
  }
}
/* M�todo que busca un dato en un Arbol binario de b�squeda. Recibe como par�metros la direcci�n del nodo
   a visitar (la primera vez es la ra�z) y el dato a buscar. Regresa como resultado la direcci�n del nodo
   encontrado o el valor NULL, si la b�squeda termina con fracaso. */
template <class T>
   NodoArbol<T> * ArbolBinBus<T>::Busqueda (NodoArbol<T> *Apunt, T Dato)
   {
    if (Apunt)
     if (Dato < Apunt->Info)
       return Busqueda(Apunt->HijoIzq, Dato);
     else
       if (Dato > Apunt->Info)
         return Busqueda(Apunt->HijoDer, Dato);
       else
         return Apunt;
       else
         return NULL;
     }

/* M�todo que inserta un nodo en un Arbol binario de b�squeda. Recibe como par�metros la direcci�n del nodo
   a visitar (la primera vez es la ra�z) y la informaci�n que se quiere almacenar en el nuevo nodo. En esta
   implementaci�n no se permite que haya informaci�n duplicada en el Arbol. */
template <class T>
   void ArbolBinBus<T>::InsertaNodoSinRep(NodoArbol<T> *Apunt, T Dato)
   {
    NodoArbol<T> *ApAux;
    if (Apunt)
    {
      if (Dato < Apunt->Info)
      {
       InsertaNodoSinRep(Apunt->HijoIzq, Dato);
       Apunt->HijoIzq=Raiz;
     }
     else
      if (Dato > Apunt->Info)
      {
        InsertaNodoSinRep(Apunt->HijoDer, Dato);
        Apunt->HijoDer=Raiz;
      }
      Raiz=Apunt;
    }
    else
    {
          /* Se crea un nuevo nodo, se le asigna la informaci�n y se establecen las ligas entre los nodos correspondientes. */
      ApAux=new NodoArbol<T>();
      ApAux->Info=Dato;
      Raiz=ApAux;
    }
  }

/* M�todo que elimina un nodo del Arbol binario de b�squeda. Recibe como par�metro la direcci�n del nodo a visitar
   (la primera vez es la ra�z) y el dato a eliminar. */
template <class T>
  void ArbolBinBus<T>::EliminaNodo(NodoArbol<T> *Apunt, T Dato)
  {
    if (Apunt)
     if (Dato < Apunt->Info)
     {
       EliminaNodo(Apunt->HijoIzq, Dato);
       Apunt->HijoIzq=Raiz;
     }
     else
       if (Dato > Apunt->Info)
       {
         EliminaNodo(Apunt->HijoDer, Dato);
         Apunt->HijoDer=Raiz;
       }
       else
       {
         NodoArbol<T> *ApAux1,*ApAux2,*ApAux3;
         ApAux3=Apunt;
                 // Encuentra el nodo que contiene el dato a eliminar. Verifica si tiene hijos.
         if (!ApAux3->HijoDer)
           if (!ApAux3->HijoIzq)
                         // Si no tiene hijo derecho ni izquierdo, entonces se redefine como vac�o.
             Apunt=NULL;
           else
                         // Si s�lo tiene hijo izquierdo, el nodo eliminado se reemplaza con este.
             Apunt=ApAux3->HijoIzq;
           else
             if (!ApAux3->HijoIzq)
                         // Si s�lo tiene hijo derecho, el nodo eliminado se reemplaza con este
               Apunt=ApAux3->HijoDer;
             else
             {
                         /* Si tiene ambos hijos, entonces se reemplaza (en esta soluc�n) por el nodo que est� m�s
						    a la derecha del subArbol izquierdo */
               ApAux1=ApAux3->HijoIzq;
               ApAux2=ApAux3;
               while (ApAux1->HijoDer)
               {
                 ApAux2=ApAux1;
                 ApAux1=ApAux1->HijoDer;
               }
               ApAux3->Info=ApAux1->Info;
               if (ApAux3 == ApAux2)
                 ApAux3->HijoIzq=NULL;
               else
                 if (!ApAux1->HijoIzq)
                  ApAux2->HijoDer=NULL;
                else
                  ApAux2->HijoDer=ApAux1->HijoIzq;
                ApAux3=ApAux1;
              }
              delete(ApAux3);
            }
            Raiz= Apunt;
          }
