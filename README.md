Un fichier binaire contient une liste de structure `Objet` qui est définie ainsi

```C
typedef enum
{
    Red,
    Blue,
    Black
} Color;

#define TEXT_LENGTH 20

typedef struct
{
    int size;
    Color color;
    double weight;
    char name[TEXT_LENGTH];
} Object;
```

## Lecture des données
Créer une fonction qui permet d'extraire les structures et de les insérer dans
une file chaînée.

## Affichage
Parcourir la liste pour afficher les objets sans les retirer.

## Fonction recherche
Créer une fonction qui permet de trouver un objet dans la liste en fonction 
de son nom.

Si un objet est trouvé, il faut l'afficher avec la fonction fournie.
