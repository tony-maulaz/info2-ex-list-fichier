
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

Object createObject(char* name, int size, Color c, double weight)
{
    Object o = {0};
    strcpy(o.name, name);
    o.size = size;
    o.color = c;
    o.weight = weight;
    return o;
}

char* color_to_string(Color c)
{
    switch (c)
    {
        case Red:
            return "red";
            break;
        case Blue:
            return "blue";
            break;
        case Black:
            return "black";
            break;
        default:
            break;
    }
    return "";
}

void print_object(Object* o)
{
    printf("Object : %s \n", o->name);
    printf("  - size : %d\n", o->size);
    printf("  - color : %s\n", color_to_string(o->color) );
    printf("  - weight : %.2lf\n", o->weight);
}

// Solution
typedef struct ElemFile{
    Object val;
    struct ElemFile* next;
} ElemFile;

typedef struct{
    ElemFile* tete;
    ElemFile* queue;
} File;

bool inserer_file(File* f, Object* v){
    if(f == NULL){
        return false;
    }

    ElemFile* e = malloc(sizeof(ElemFile));
    if( e == NULL ){
        return false;
    }
    e->val = *v;
    e->next = NULL;

    if(f->queue == NULL){
        f->tete = e;       
    }
    else{
        f->queue->next = e;
    }
    
    f->queue = e;     
    return true;   
}

bool find_obj(File* f, char* name, Object* o){
    
    ElemFile* current = f->tete;
    while( current != NULL ){
        if( strcmp(name, current->val.name) == 0){
            *o = current->val;
            return true;
        }
        current = current->next;
    }    
    return false;
}

int main() {
    FILE* f = fopen("data.bin", "w");
    if( f == NULL ){
        exit(EXIT_FAILURE);
    }

    Object o = createObject("Foo", 10, Red, 3.4);
    fwrite(&o, sizeof(Object), 1, f);
    o = createObject("Bar", 1, Blue, -3.6);
    fwrite(&o, sizeof(Object), 1, f);
    o = createObject("Tutu", 987, Black, -0.02);
    fwrite(&o, sizeof(Object), 1, f);
    fclose(f);

    // Solution
    File file = {0};

    FILE* fp = fopen("data.bin", "r");
    Object obj;
    while( fread(&obj, sizeof(Object), 1, fp) == 1 ){
        inserer_file(&file, &obj);
    }
    fclose(fp);

    ElemFile* current = file.tete;
    while( current != NULL ){
        print_object(&(current->val));
        puts("");
        current = current->next;
    }

    printf("Test find\n");
    Object find = {0};
    if( find_obj(&file, "Bar", &find) ){
        print_object(&find);
    }
    else{
        puts("Object not found\n");
    }

    if( find_obj(&file, "Youplaboom", &find) ){
        print_object(&find);
    }
    else{
        puts("Object not found\n");
    }
    
}