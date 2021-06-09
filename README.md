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
Créer une fonction qui permet d'extraire les structures du fichier et de les insérer dans
une file chaînée.

## Affichage
Parcourir la liste pour afficher les objets sans les retirer.

## Fonction recherche
Créer une fonction qui permet de trouver un objet dans la liste en fonction 
de son nom.

Si un objet est trouvé, il sera copié dans une structure passée en paramètre par adresse et
la fonction retourne `true`

En cas d'erreur ou si la recherche n'est pas fructueuse, la fonction retourne `false`

Afin de tester cette fonction, vous pouvez utiliser le code mis en commentaire dans le fichier `main.c`
