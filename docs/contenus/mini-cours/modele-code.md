# Modèle de code C++

Voici un modèle de code C++ typique pour la programmation compétitive.

```c++ linenums="1" title="exemple.cpp"
#include <bits/stdc++.h>

using namespace std;

int main() {
    // solution comes here

    return 0;
}
```

À la ligne 1, `#include <bits/stdc++.h>` permet d'inclure toute la bibliothèque standard de C++, ainsi il n'est plus nécessaire d'inclure individuellement les bibliothèques comme `iostream` ou `vector` ...

La directive `using namespace std;` permet d'utiliser directement toutes les collections et les fonctions présentes dans la bibliothèque standard dans le code. Sans cette ligne, il est nécessaire de spécifier à chaque fois l'espace de nom de la collection ou de la fonction. Par exemple avec cette directive au lieu d'écrire `std::cout`, on peut directement écrire `cout`.

Ensuite voici un exemple de ligne de commande pour compiler `exemple.py` en l'exécutable `run`.

```plaintext
g++ -std=c++17 -Wall -O2 -o run exemple.cpp
```

Le compilateur `g++` va suivre le standard C++17 (`-std=c++17`), va optimiser le code (`-O2`) et va afficher toute les erreurs/avertissements possibles (`-Wall`).

---
