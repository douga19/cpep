# Programmation dynamique (dynamic programming)

La programmation dynamique (**_dynamic programming_** en anglais) est un principe de résolution de problème algorithmique qui consiste à améliorer une approche naïve (souvent récursive) en évitant de résoudre inutilement plusieurs fois un même sous-problème (évite l'appel récursif sur un même sous-problème).



## Algorithme glouton (greedy algorithm)

Un algorithme glouton (**_greedy algorithm_** en anglais) est un algorithme qui suit le principe de faire, étape par étape, un choix optimum local, dans l'espoir d'obtenir un résultat optimum global.

Par exemple, dans le problème du [rendu de monnaie](https://leetcode.com/problems/coin-change/), l'algorithme consistant à répéter le choix de la pièce de plus grande valeur qui ne dépasse pas la somme restante est un algorithme glouton.

Voici une illustration qui démontre que l'algorithme glouton n'est pas optimal pour ce problème.

```
coins = [1, 3, 4]
amount = 6
```

Suivant le principe de l'algorithme glouton, nous obtenons la solution $6 = 4 + 1 + 1$ qui utilise trois pièces, alors que la solution optimale est $6 = 3 + 3$.

---

## Récursion