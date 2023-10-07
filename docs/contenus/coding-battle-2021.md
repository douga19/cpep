---
tags:
    - shaker
    - shaker 2021
    - training
---

# Coding battle 2021

## Consignes

* Prenez du temps pour traiter sérieusement tous les problèmes.
* Notez le nombre de problèmes que vous avez réussi à résoudre en 2h.
* Notez le temps que vous avez mis à résoudre tous les problèmes.
* Vous avez le droit de discuter entre vous mais chacun devra écrire son propre code.
* Vous devez être en mesure d'expliquer votre solution.
* Vous avez le droit de vous documenter sur internet si vous êtes bloqués, sans pour autant rechercher les solutions des problèmes.

---

## Liste des problèmes

Voici les sujets de l'édition 2021 de la Coding Battle du Shaker : 6 problèmes, 2h.

---

* Une histoire de couleur
* Gros tas de bouquins
* Oh la belle prise
* Dans de beaux draps
* Un cad(re)eau empoisonné
* Estimation de toile

---

## Solutions

### Une histoire de couleur

Nous voilà à la première épreuve : la peinture. Gérard a oublié de commander la peinture. Il a pu trouver des restes dans son cabanon de jardin, mais ce n'est pas suffisant pour les besoins du concours et des artistes. Il aurait pu changer le thème du concours en concours d'art minimaliste, mais non, parce que Gérard est ambitieux.

Ainsi, il vous demandera de développer un mélangeur de couleurs, un calculateur pour prévoir à l'avance les couleurs mélangées par les artistes. Dans le but d'éviter les mélanges inutiles et donc le gaspillage de peinture, votre mission est donc de calculer la couleur moyenne issue d'un mélange de deux couleurs $C1$ et $C2$.

Les couleurs sont des entiers compris entre 0 et 255.

Le résultat sera toujours entier et arrondi à l'entier supérieur si nécessaire.

**Entrée**

* Ligne 1, 2 : Sur les deux premières lignes, deux entiers $C1$ et $C2$ ($0 \leq C1,C2 \leq 255$) représentant les deux couleurs à mélanger.

**Sortie**

Afficher, sur une seule ligne, la valeur de la couleur obtenue, correspondant à la moyenne des couleurs en entrée, arrondie à l'entier supérieur si nécessaire.

!!! tip

    Il s'agit de lire deux entiers sur l'entrée standard et d'afficher leur moyenne (on attend un entier). En faisant attention à bien afficher une moyenne entière.
    Si la somme est paire pas de soucis, sinon on ajoute 1 à la somme pour avoir l'arrondi à l'entier supérieur.

```cpp linenums="1"
#include "bits/stdc++.h"

using namespace std;

int main () {
  int a, b;
  cin >> a >> b;
  int c = (a + b) % 2 == 0 ? a + b : a + b + 1;
  cout << c / 2 << "\n";
  return 0;
}
```

---

### Gros tas de bouquins

Nous voilà à la deuxième épreuve, l'épreuve de littérature. Les participants ont dû écrire un livre sur le thème de leur choix, mais dans un temps imparti. Face à la pile de livres grandissante et pour éviter un burn-out du jury (dont Gerard Traquenard), ces derniers ont décidé de s'imposer un temps de lecture limite.

Le jury de cette épreuve est composé de trois membres.

Chaque membre a une spécialité et ne juge que sa spécialité, et dispose d'un temps limite pour juger les livres. Il vous est donné le temps de lecture et le type pour chaque livre, vous devez indiquer si chaque jury aura le temps de lire tous les livres de sa spécialité.

**Entrée**

* Ligne 1 : 3 entiers $TF$,$TP$ et $TA$ (avec $0 \leq TF,TP,TA \leq 10^6$) les temps donnés en minutes pour chaque jury, respectivement pour la catégorie de romans Fantastique, Policier, et Autre.

* Ligne 2 : Un entier $N$ (avec $N\geq 10^3$) représentant le nombre de romans à lire.

* $N$ lignes suivantes : Séparés d'un espace, une lettre représentant le type de roman (F pour fantastique, P pour policier, A pour autre) et un entier $t$ représentant le temps en minutes nécessaire pour le lire.

**Sortie**

Une seule ligne avec "**oui**" si le jury a le temps de lire tous les livres, "**non**" sinon. Le jury a le temps de lire tous les livres si chaque membre du jury a le temps de lire tous les romans de sa spécialité. 

!!! tip

    Il s'agit juste d'une boucle `while` qui tourne tant que les trois entiers $TF$, $TP$ et $TA$ sont positifs ou nuls, et qui à chaque itération lit un temps de lecture $t$ sur l'entrée standard et décrémete $TF$, $TP$ et $TA$ selon le type du roman lu. Si on sort de la boucle car on a tout lu, la réponse est "**oui**", sinon on est sorti car l'un des trois entiers de départ est négatif.

```cpp linenums="1"

#include "bits/stdc++.h"

using namespace std;

int main () {
    int tf, tp, ta;
    cin >> tf >> tp >> ta;
    int n;
    cin >> n;
    int i = 0;
    while (i < n && tf >= 0 && tp >= 0 && ta >= 0) {
        char type;
        int t;
        cin >> type >> t;
        if (type == 'F') {
        tf -= t;
        } else if (type == 'P') {
        tp -= t;
        } else if (type == 'A') {
        ta -= t;
        }
        ++i;
    }

    if (i == n) cout << "oui" << "\n";
    else cout << "non" << "\n";
    return 0;
}
```

---

### Oh la belle prise

Après avoir fini de ranger tous les livres, l'épreuve de photographie peut enfin commencer ! Cette fois, Gerard Traquenard a demandé au grand Marcel Fauto, pécheur du village de Rouffiac mais surtout photographe en herbe, d'organiser l'épreuve.

Marcel a voulu aller à l'essentiel, les règles sont donc plutôt simples : les différents candidats vont devoir prendre une photo du paysage, et la meilleure photo gagnera l'épreuve. Hélas avec des endroits magnifiques comme les eaux cristallines de l'Espinet ou encore la forêt de Bonnal, les paysages du Cantal sont bien trop beaux, et les photographes n'arrivent pas à trouver le cliché parfait !

Le but pour gagner est, à partir d'un paysage donné, de trouver la (ou les) photos ayant le plus grand nombre de points d'intérêt. Les photos prises sont toutes au format carré de 3 par 3.

**Entrée**

* Ligne 1 : Deux entiers $H$ et $L$ (avec $3 \leq H,L \leq 100$), correspondant
respectivement à la hauteur et à la largeur du paysage.

* Lignes 2 à $H+1$ : Une chaîne de $L$ caractères composée de "`-`" et de "`X`". Un "`X`" représente un point d'intérêt, un "`-`" un point sans intérêt.

**Sortie**

Deux entiers $a$ et $b$ correspondant aux coordonnées du coin haut gauche d'une photo de dimension 3 points par 3, contenant le plus de points d'intérêt possible. Si plusieurs photos ont le nombre maximum de points d'intérêt, vous pouvez renvoyer n'importe quelle photo maximisant le score.

*Remarques* :

* $1 \leq a \leq H-2$ et $1 \leq b \leq L-2$
* Le point haut gauche du paysage est aux coordonnées $(1, 1)$

!!! tip
    - Il s'agit de parcourir une matrice de taille $L \times H$ avec une fenêtre de taille $3 \times 3$ et dans la fenêtre compter le nombre de points d'intérêts.
    - On intialise une variable stockant le max des points d'intérêts. Cette variable sera mise à jour dès que l'on change de fenêtre.
    - Pour mieux comprendre on peut par exemple générer toutes les coordonnées des coins supérieur gauche des fenêtres possibles en commençant par $(1,1)$.

```cpp linenums="1"
#include "bits/stdc++.h"

using namespace std;

int main () {
  int h, l;
  cin >> h >> l;
  vector<string> p(h);

  for (int i = 0; i < h; i++) {
    cin >> p[i];
  }

  int max = 0;
  pair<int, int> ans = {-1, -1};

  for (int i = 0; i < h - 2; ++i) {
    for (int j = 0; j < l - 2; ++j) {
      int pi = 0;
      for (int k = i; k < i + 3; ++k) {
        for (int t = j; t < j + 3; ++t) {
          if (p[k][t] == 'X') pi++;
        }
      }
      if (max < pi) {
        ans = {i, j};
      }
    }
  }
 
  cout << ans.first + 1 << " " << ans.second + 1 << "\n"; 
  return 0;
}
```

---

### Dans de beaux draps

Le sujet est [ici](../assets/files/shaker-2021/d.pdf).

!!! tip
    * Il faut commencer par convertir l'entrée en une liste de points avec des coordonnées $(x, y)$ ou $(y, x)$ comme vous voulez.
    * Ensuite il vous faudra implémenter une version twistée d'un algorithme d'enveloppe convexe en 2D, vous avez le choix entre : [le Graham Scan](https://en.wikipedia.org/wiki/Graham_scan) et [le Jarvis Walk](https://fr.wikipedia.org/wiki/Marche_de_Jarvis) et autres ...
    * Il faut gérer toutefois le cas où les points du bas de la grille ne seront pas pris en compte (car il est plus opti de faire tomber le drap à la verticale).
    * Pour calculer la distance entre les points, il faut utiliser la distance euclidienne 
    
    $$
      |AB| = \sqrt{(x_B - x_A)^2 + (x_B - x_A)^2}.
    $$

---

### Un cad(re)eau empoisonné

Le sujet est [ici](../assets/files/shaker-2021/e.pdf).

!!! tip
    * Il s'agit d'un problème de parcours de graphe (d'arbre en particulier).
    * Il vous faut implémenter la bonne structure d'arbre :
    ```cpp
    struct Node {
      int val;
      vector<struct Node *> neighbors;
    };

    struct Tree {
      Node * root;
    };
    ```

    * Ensuite l'algorithme qui nous intéresse est une adaptation de l'algorithme du [Maximum Independent Set](https://en.wikipedia.org/wiki/Maximal_independent_set) pour les arbres, ou le choix des noeuds se fait de tel sorte qu'il ont au plus un voisin dans l'ensemble choisi.


---

### Estimation de toile

C'est la fin de la compétition ! Les gagnants ont eu leur prix et tout le monde repart satisfait du concours. Afin de faire du profit et profitant de la fatigue générale, Gerard souhaite récupérer et vendre les œuvres réalisées (sans l'accord des artistes, sacré Gérard). Il ne parvient qu'à récupérer les toiles de chacun, leur laissant sculptures et photos.

Ensuite, il cherche à regrouper les œuvres en fonction de leur prix. Débrouillard comme il est, Gerard estime la valeur de ces œuvres avec une formule qu'il a lui-même inventée : $V = A + P$ (avec $V$ = valeur de la toile en euros, $A$ = aire de la toile en cm² et $P$ = périmètre de la toile en cm).

Mais évaluer les prix à la main, c'est trop long pour Gerard, il voudrait bien avoir un prix fixe. Il pense déjà au prochain concours et aux différents formats qui permettraient de vendre toutes les toiles au même prix. Il cherche ainsi à savoir, pour un prix donné par cette formule, combien de formats de toiles est-il possible d'avoir ?

**Entrée**

* Ligne 1 : Un entier $0 \leq V \leq 10^{15}$ correspondant à la valeur de la toile en euros.

**Sortie**

Le nombre de formats de toiles possibles. On notera que la permutation de la longueur et la largeur de la toile ne change pas le format de cette dernière; par exemple, $20 \times 25$ et $25 \times 20$ représentent le même format.

!!! tip
    Ce problème n'est pas aussi dur qu'il ne le paraît : il faut trouver les dimensions $L$ et $l$ d'un rectangle vérifiant :
    
    $$
      V = Ll + 2L + 2l
    $$

    En tenant en compte que $V$ peut être très grand (i.e. stocker la valeur dans un `long long int` par exemple). 

    En réarangeant un peu les choses on peut parvenir à la relation suivante :

    $$
      V + 4 = (L + 2) \times (l + 2)
    $$

    En effet, schéma suivant nous permet de voir que $V + 4$ est l'aire du rectangle de longueur $L + 2$ et de largeur $l + 2$. Il reste alors à trouver deux entiers $L$ et $l$ qui satisfont cette nouvelle relation.

    ```md
            L       2
        +--------+----+
      l |        |    | l
        |   A    | 2l |
        +--------+----+
      2 |   2L   | 4  | 2
        +--------+----+
            L       2
    ```
```cpp linenums="1"
#include "bits/stdc++.h"

using namespace std;

int main () {
    long long int v;
    cin >> v;
    long long int a, b;
    // Une fois le carré atteint, on a les mêmes valeurs 
    // mais dans l'ordre inverse
    for (int i = 3; i < sqrt(v + 4); ++i) { 
        if ((v + 4) % i == 0) {
            a = i - 2;
            b = ((v + 4) / i) - 2;
            cout << a << " " << b << endl;
        }
    }
    return 0;
}
```

---
