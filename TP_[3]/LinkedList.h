/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//herramienta encapsulada

//Publicas
/// @brief Constructor en memoria dinamica. Crea una lista en memoria dinamica
/// @return
LinkedList* ll_newLinkedList(void);

/// @brief Lee la cantidad de elementos dentro de la lista
/// @param this
/// @return
int ll_len(LinkedList* this);

/// @brief
/// @param this
/// @param nodeIndex
/// @return
Node* test_getNode(LinkedList* this, int nodeIndex);

/// @brief
/// @param this
/// @param nodeIndex
/// @param pElement
/// @return
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

/// @brief agrega un elemento a la lista
/// @param this
/// @param pElement
/// @return
int ll_add(LinkedList* this, void* pElement);

/// @brief devuelve un elemento de la lista
/// @param this
/// @param index
void* ll_get(LinkedList* this, int index);

/// @brief ingresa un elemento en un lugar especifico (lo pisa)
/// @param this
/// @param index
/// @param pElement
/// @return
int ll_set(LinkedList* this, int index,void* pElement);

/// @brief remueve un elemento de la lista
/// @param this
/// @param index
/// @return
int ll_remove(LinkedList* this,int index);

/// @brief limpia/vacia la lista
/// @param this
/// @return
int ll_clear(LinkedList* this);

/// @brief borra de memoria toda la lista
/// @param this
/// @return
int ll_deleteLinkedList(LinkedList* this);

/// @brief devuelve el indice de un elemento de la lista
/// @param this
/// @param pElement
/// @return
int ll_indexOf(LinkedList* this, void* pElement);

/// @brief dice si la lista tiene elementos o no
/// @param this
/// @return
int ll_isEmpty(LinkedList* this);

/// @brief me permite insertar un pasajero entre dos elementos en particular
/// @param this
/// @param index
/// @param pElement
/// @return
int ll_push(LinkedList* this, int index, void* pElement);

/// @brief saca un elemento de la lista y lo devuelve (para moverlo de una lista a otra)
/// @param this
/// @param index
void* ll_pop(LinkedList* this,int index);

/// @brief dice si un elemento esta contenido dentro de la lista.
/// @param this
/// @param pElement
/// @return
int ll_contains(LinkedList* this, void* pElement);

/// @brief dice si la lista esta contenida en otra.
/// @param this
/// @param this2
/// @return
int ll_containsAll(LinkedList* this,LinkedList* this2);

/// @brief devuelve una sublista del total.
/// @param this
/// @param from
/// @param to
/// @return
LinkedList* ll_subList(LinkedList* this,int from,int to);

/// @brief crea una copia en memoria de la lista
/// @param this
/// @return
LinkedList* ll_clone(LinkedList* this);

/// @brief ordena la lista. Tiene un puntero a una funcion como segundo parametro.
/// @param this
/// @param pFunc
/// @param order
/// @return
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
