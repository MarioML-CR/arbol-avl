# Árbol binario de búsqueda auto balanceado o AVL

**Notas tomadas del libro:

Yucra, O. G. C., Gúzman, R. J. C., Flores, D. A. C., Argollo, B. F. E., Velazques, B. H. G., Rabaza, G. A. M., & Sempértegui, A. P. R. Introducción en C++ a la Programación Competitiva.

Joyanes Aguilar, L., & Zahonero, I. (2008). Estructuras de datos en Java (No. Sirsi) i9788448156312).

Notas del curso BISOFT-20 Estructuras de datos del 2020, impartido en la Universidad Cenfotec, Costa Rica.

Un árbol de busqueda auto-balanceable o equilibrado es un arbol de búsqueda que intenta mantener su altura, o el número de niveles de nodos bajo la raíz tan pequeños como sea posible en todo momento, automáticamente. Esto es importante, ya que muchas operaciones en un árbol de búsqueda binaria tardan un tiempo proporcional a la altura del árbol, y los árboles binarios de búsqueda ordinarios pueden tomar alturas muy grandes en situaciones normales, como cuando las claves son insertadas en orden. Mantener baja la altura se consigue habitualmente realizando transformaciones en el árbol, como la rotación de árboles, en momentos clave.

##Árbol AVL
En este caso se estudia particularmente el tipo de árbol AVL, que toma su nombre de las iniciales de los apellidos de sus inventores, Georgii Adelson-Velskii y Yevgeniy Landis, fue el primer árbol de búsqueda binario auto-balanceable que se ideó.

Formalmente, en los árboles AVL se debe cumplir el hecho de que para cualquier nodo del árbol, la diferencia entre las alturas de sus subárboles no exceda una unidad.
##Árboles binarios
Un árbol binario es un árbol cuyos nodos no pueden tener más de dos subárboles. En un árbol binario, cada nodo puede tener cero, uno o dos hijos (subárboles). Se conoce el nodo de la izquier- da como hijo izquierdo y el nodo de la derecha como hijo derecho.

##Recorrido
Existen tres tipos:
###Pre-orden (RID):
Se recorre la raíz

En preorden el subárbol izquierdo

En preorden el subárbol derecho
###In-orden(IRD):
Se recorre en In-orden el subárbol izquierdo

Se recorre la raíz

Se recorre en In-orden el subárbol derecho

###Post-orden(IDR):
Se recorre en Post-orden el subárbol izquierdo

Se recorre en Post-orden el subárbol derecho

Se recorre la raíz

###Terminología y conceptos
##Hoja
Un elemento e1 es hoja si los dos subárboles asociados son vacíos.
##No terminal
Todo elemento de un árbol binario que no es hoja es un elemento no terminal o interior.
###Camino
Existe camino entre e1 y e2 si se puede ir desde e1, de elemento en elemento siguiendo la relación padre-hijo, hasta llegar a e2.
###El camino
Entre e1 y e2 es una secuencia única de los elementos del árbol por donde se pasa desde e1 hasta llegar a e2.
###Longitud
Es la entre el fin y el principio del camino, (número de elementos - 1).
###Nivel
Es la longitud del camino que parte desde la raíz hasta él.
###Altura
Es la longitud del camino más largo que parte de la raíz, más 1.
###Peso
Es el número de elementos.

###Equilibrio
La distancia de un nodo a la raíz determina la eficiencia con la que puede ser localizado. Por ejemplo, dado cualquier nodo de un árbol, a sus hijos se puede acceder siguiendo sólo un camino de bifurcación o de ramas, el que conduce al nodo deseado. De modo similar, a los nodos en el nivel 2 de un árbol sólo puede accederse siguiendo dos ramas del árbol.
La característica anterior nos conduce a una característica muy importante de un árbol binario, su **balance** o **equilibrio**. Para determinar si un árbol está equilibrado, se calcula su factor de equilibrio. El **factor de equilibrio** (fe en esta aplicación) de un árbol binario es la diferencia en altura entre los subárboles derecho e izquierdo. Si la altura del subárbol izquierdo es hI y la altura del subárbol derecho hD, entonces el factor de equilibrio del árbol B se determina por la siguiente fórmula: B = hD - hI.

###Completos
Si todos los elementos tienen sus dos subárboles o no tienen ninguno.

###Lleno
se denomina al árbol que además de completo todas sus hojas están al mismo nivel.
##Comparación de árboles
###Iguales
Dos árboles son **iguales** si sus reíces son iguales y sus subárboles también. O si ambos son vacíos.
###Isomorfos
Dos árboles son **isomorfos** si tienen la misma forma, aunque no tengan los mismos elementos.
##Semejantes
Dos árboles son **semejantes** si tiene los mismos elementos aunque no sean isomorfos.

##Análisis general de la eficiencia de búsqueda en un ABB.
La cantidad máxima de comparaciones al realizar una búsqueda en un ABB está determinada por la altura del árbol.

Si un árbol degenera en una lista, se tiene un árbol cuya altura es igual a la cantidad de nodos en el árbol, y el peor caso corresponderá a realizar tantas comparaciones como nodos tenga el árbol.

Si la altura de un ABB determina la cantidad máxima de comparaciones en una busqueda, lo ideal sería tener la altura mínima que puede tener un ABB para n elementos.

La altura mínima en un ABB con n elementos se dará en la medida en cada nivel del árbol esté integrado a su máxima capacidad.

En general, se tiene que el número máximo de nodos en el nivel k en un ABB es 2 elevado a la k.

Con base en esto, se puede encontrar la cantidad total de elementos que puede guardar un árbol binario de altura k.

Por lo tanto se tiene que el número maximo de nodos en un ABB de altura k es: 2^k - 1.

Ahora bien, si la altura de un ABB determina el número máximo de comparaciones al buscar un elemento, **¿cuántas comparaciones se harán al buscar un elemento en un ABB ideal que tiene n elementos?**

De acuerdo con el análisis que hemos hecho, la respuesta se obtiene al encontrar el valor de k, dado el valor de n para la fórmula:

n = 2^k - 1

Por lo tanto, despejando k, aplicando las leyes de los logaritmos, se obtiene

k = log2(n + 1)

##¿Qué es un árbol balanceado?

Se considera que un árbol binario está balanceado cuando todos sus niveles, excepto el último, están integrados a la máxima capacidad de nodos.

Las investigaciones respecto a esta estructura de datos no han logrado encontrar una técnica eficiente para manejar árboles de búsqueda completamente balanceados; las propuestas han llegado solo a presentar árboles **parcialmente** balanceados, sin repercutir la eficiencia de las operaciones de inserción y eliminación de nodos. La más común y usada de las técnicas es la de los árboles AVL.

###RSD o Rotación Simple a la Derecha
Esta rotación se usará cuando el subárbol izquierdo de un nodo sea 2 unidades más alto que el derecho, es decir, cuando su FE sea de -2. Y además, la raíz del subárbol izquierdo tenga una FE de -1 ó 0, es decir, que esté cargado a la izquierda o equilibrado.

###RSI Rotación Simple a la Izquierda
Se trata del caso simétrico del anterior. Esta rotación se usará cuando el subárbol derecho de un nodo sea 2 unidades más alto que el izquierdo, es decir, cuando su FE sea de 2. Y además, la raíz del subárbol derecho tenga una FE de 1 ó 0, es decir, que esté cargado a la derecha o esté equilibrado.

###RDD Rotación Doble a la Derecha
Esta rotación se usará cuando el subárbol izquierdo de un nodo sea 2 unidades más alto que el derecho, es decir, cuando su FE sea de -2. Y además, la raíz del subárbol izquierdo tenga una FE de 1, es decir, que esté cargado a la derecha.

Este es uno de los posibles árboles que pueden presentar esta estructura, pero hay otras dos posibilidades. El nodo R puede tener una FE de -1, 0 ó 1. En cada uno de esos casos los árboles izquierdo y derecho de R (B y C) pueden tener alturas de n y n-1, n y n, o n-1 y n, respectivamente.

###RDI Rotación Doble a la Izquierda
Esta rotación se usará cuando el subárbol derecho de un nodo sea 2 unidades más alto que el izquierdo, es decir, cuando su FE sea de 2. Y además, la raíz del subárbol derecho tenga una FE de -1, es decir, que esté cargado a la izquierda. Se trata del caso simétrico del anterior.

###Reequilibrio en árboles AVL por inserción de un nodo
Cuando el valor de FE de un nodo tome el valor -2 ó 2, no seguiremos el camino, sino que, con el valor de FE de el nodo actual y el del nodo derecho si FE es 2 o el del nodo izquierdo si es -2, determinaremos qué tipo de rotación debemos hacer.

##Reequilibrio en árboles AVL por borrado de un nodo
Al igual que en el caso del reequilibrio por inserción, al eliminar un nodo se debe verificar si está desbalanceado, y de sere así se debe proceder a su rebalanceo, usuando la rotación que eplique en el caso en particular.

