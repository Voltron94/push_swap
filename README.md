*This project has been created as part of the 42 curriculum by Volt*

# Description

**Push swap** est un projet du tronc commun de l'école 42 qui a pour objectif de trier une stack en utilisant uniquement les instructions autorisées.
Pour cela, nous devons trouver l'algorithme le plus approprié et optimisé <br>
La stack A étant la pile finale ordonnée, et la stack B une pile désordonnée temporaire.

## ⚙️ Instruction

**Tout appareil beneficiant de git** 

```bash
#Etape 1
git clone <link> push_swap
```
La commande suivante lancera le makefile principal qui compilera le programme et toutes les librairies dans les autres dossiers : 
```bash
#Etape 2
cd push_swap
make
```

### Executer le programme : 

```bash
./push_swap 45 69 11 42 61
```
ou
```bash
./push_swap "45 69 11 42 61"
```

## Explication

La complexite algorithmique, nous permet en partie de trouver reponse a cette recherche.

| Notation | Complexity |
| --- | --- |
| O(1) | Constant |
| O(log n) | Logarithmic |
| O(n) | Linear time |
| O(n log n) | Log linear |
| O(n^2) | Quadratic |
| O(n^3) | Cubic |
| O(2^n) | Exponential |
| O(n!) | Factorial |

Elle exprime la vitesse a la quel un algorithme va executer sont programme.<br>
[Complexité explication approfondie](https://www.notion.so/Time-Complexity-of-an-Algorithm-2c643dfd70d1801e9b7bffa44958c09f)

**Quel est le principe d'un radix sort binaire ?**

Radix sort n'est pas forcement binaire il en existe plusieur variante, alors pourquoi avoir choisis le trie binaire ?

Il est le meilleur compromis, là où les autres radix aurait besoin de plus de 2 pile.
Un radix décimal rangerait dans chaque catégorie (de 0 à 9) chaque nombre en passant d'abord par les unités et ensuite les centaines, dizaines, etc.
Ce qui demanderait donc plus de stack ou serait plus complexe a faire.

L'algorithme de notre push swap tourne ici avec radix sort en recherche binaire, de **compliexite O(n log n)**<br>
La **recherche binaire** a pour **complexite O(log n)**
```c
		while (tmp-- > 0)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				push(stack_a, stack_b, 'b');
			else
				rotate(stack_a, stack_b, 'a');
		}
```
On deplace n element de la stack B a la stack A se qui fait O(n) pour cette boucle :
```c
		while (*stack_b)
			push(stack_a, stack_b, 'a');
```
Resultat O(n log n)

### Etape 

- Avant d'arriver a radix, push swap va d'abord faire un check des arguments, verifier que les conditions soit bonne pour le trie.<br>
*Des nombres, et pas des carateres parasites, sinon revoie Error suivie d'un \n*

- Un premier tri est fait dans un tableau parallèle, chaque élément recevra l'index de la position qu'il devra obtenir dans la liste finale<br>
  Exemple : La liste [42, 44, 46, 41, 69]  prendra pour index  [1, 2, 3, 0, 4]

- Nous arrivons enfin à Radix, on récupère le nombre de bits du nombre le plus grand pour savoir combien de bits Radix va vérifier au total.<br>
  Exemple : 42 => 101010 , ici 6 bit <br>
  Push swap verifira 
  ```c
  while (i <= max_bit) // jusqu'a n bit
	{
        //Boucle chaque element
          //push l'element dans la stack b si le bit etudie est egal a 0
          // sinon le premiere element deviens le dernier
        //Tout les element envoyer dans la stack B revienne dans la stack A
        i++;
	}
  ```

-----------
<h1>Ressource</h1>


### Ressource complexite algorithmique: 

Video :

- https://www.youtube.com/watch?v=pULw1Fpru0E
- https://www.youtube.com/watch?v=XMUe3zFhM5c&t=154s <br>

Introduction/shema :
- https://www.geeksforgeeks.org/dsa/what-is-logarithmic-time-complexity/#what-is-complexity-analysis<br>
O(n) : 
- https://www.geeksforgeeks.org/dsa/what-does-big-o-on-complexity-mean/<br>
O(log n) : 
- https://www.geeksforgeeks.org/dsa/what-does-big-o-olog-n-complexity-mean/<br>
O(n^2):
- https://www.geeksforgeeks.org/dsa/what-does-big-on2-complexity-mean/<br>
Bonne exemple : 
- https://www.freecodecamp.org/news/big-o-cheat-sheet-time-complexity-chart/<br>

### Ressource Push swap
- https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e
- https://www.geeksforgeeks.org/dsa/radix-sort/
- https://www.programiz.com/dsa/bubble-sort
- https://github.com/o-reo/push_swap_visualizer (verification)
