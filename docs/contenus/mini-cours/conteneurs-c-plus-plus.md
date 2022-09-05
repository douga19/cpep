---
title: Conteneurs de la bibliothèque standard C++
---

## Collections

* Une collection regroupe un nombre arbitraire d'éléments de _**même type**_.
* La _**complexité**_ des opération varie suivant la collection :
    - accès au $n$-ème élément
    - rechercher un élément
    - ajouter un élément à une position arbitraire
    - supprimer un élément
    - parcourir les éléments dans l'ordre
* En particulier les **tableaux associatifs** peuvent être vus comme des collections de paires (clé, valeur).
* Il est primordiale de choisir la collection *adaptée* pour chaque problème.

---

## Collections en C++

* Toutes les collections sont dans l'espace de nom `std`.
* Toujours écrire `using namespace std;`.
* Certaines collections (`stack`, `queue`, `priority_queue`) sont des **adapteurs** qui utilisent plusieurs classes comme implémentation (`list`, `vector`, ...).
