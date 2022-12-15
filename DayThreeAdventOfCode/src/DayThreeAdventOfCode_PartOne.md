<!--- Si no entendés el inglés acá tenés una traducción( no es la más académica pero va) -->
Day 3 - AdventOfCode

Uno de los elfos tuvo la tarea de cargar todas las mochilas con provisiones para el viaje a la jungla. Desafortunadamente ese elfo no siguió las instrucciones de empaquetado y entonces algunos items ahora tienen que ser reorganizados.

Cada mochila tiene 2 bolsillos grandes. Todos los items de un cierto tipo deben ir en exactamente uno de los bolsillos.El elfo sabe que le erró al empaquetado siguiendo esta regla por exactamente un tipo de item por mochila 

Los elfos hicieron una lista de todos los items que actualmente estan en cada mochila (puzzle input), pero necesitan tu ayuda para encontrar los errores.Cada tipo de item es identificado por una única letra en mayúscula o minúscula(por ejemplo, "a" y "A" son dos tipos distintos).


La lista de items para cada mochila es dada como caracteres en una sola línea.Cada mochila siempre tiene el mismo número de items en cada una de sus dos bolsillos , de manera que la primer mitad de los caracteres representan los items en el primer bolsillo y la segunda mitad representa los items en el segundo bolsillo.

Por ejemplo supongamos que tenemos la siguiente lista de cosas que hay dentro de seis mochilas (una línea por mochila)

```sh
vJrwpWtwJgWrhcsFMMfFFhFp
jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
PmmdzqPrVvPwwTWBwg
wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
ttgJtRGJQctTZtZT
CrZsJsPPZsGzwwsLwLmpwMDw
```
- La primer mochila contiene los items 

```sh
vJrwpWtwJgWrhcsFMMfFFhFp 
```
En el primer bolsillo están los items 

```sh
vJrwpWtwJgWr
```
mientras que en el segundo están los items 

```sh 
hcsFMMfFFhFp
```
Como vemos el único item en común que tienen ambos bolsillos es "p".

La segunda mochila tiene en sus bolsillos los siguientes items :
 
```sh
jqHRNqRjqzjGDLGL
```
y 

```sh
rsFMfFZSrLrFZsSL
```
El único item en común en este caso es "L".

Para la tercera mochila el único elemento en común que tiene los bolsillos es : "P".

Para la cuarta mochila el único elemento en común que tiene los bolsillos es : "v".

Para la quinta mochila el único elemento en común que tiene los bolsillos es : "t".

Para la sexta mochila el único elemento en común que tiene los bolsillos es : "s".

Con el objetivo de priorizar la reorganización de los items , a cada tipo de item se le puede asignar una prioridad de la siguiente manera.

- Items en minúscula de la "a" a "z" tienen prioridad del 1 al 26.
- Items en mayúsucla de la "A" a la "Z" tienen prioridades desde 27 a 52.

Para el ejemplo de las 6 mochilas que acabamos de ver, las prioridades que tienen cada uno de los elementos en común entre los bosillos de una mochila dada son:  
p &rarr; 16  
L &rarr; 38  
P &rarr; 42  
v &rarr;     22  
t &rarr; 20  
s &rarr; 19  

y su suma es 157.

**Encontrar el item que tienen en común los bosillos de cada mochila.¿Cuál es la suma de las prioridades de esos items?**