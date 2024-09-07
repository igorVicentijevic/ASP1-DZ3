#include <stdio.h>
#include <stdlib.h>
// i = 2 j = 1

typedef struct {
    int id;
} Cvor;

typedef struct node{
    Cvor *cvor;
    struct node *next;
} listaCvorova;

typedef struct {
    Cvor *cvor;
    listaCvorova *susedni;
    listaCvorova *tail;
} Graf;

int brojCvorova;

Cvor *FormirajCvor(int id)
{
    Cvor *t=malloc(sizeof(*t));
    t->id = id;
    return t;
}

Graf *FormirajGraf()
{
    Graf *graf = malloc(sizeof(*graf)*brojCvorova);
    for (int i = 0; i < brojCvorova; ++i) {
        Cvor *t = malloc(sizeof(*t));
        t->id = i;
        graf[i].cvor = t;
        graf[i].susedni = NULL;
        graf[i].tail = NULL;
    }
    return graf;
}

Graf *DodajGranu(Graf *graf,Cvor* x, Cvor* y)
{
    int i = 0;
    for (; i <brojCvorova ; ++i) {
        if(graf[i].cvor->id == x->id) break;
    }

    listaCvorova *t = malloc(sizeof(*t));
    t->cvor = y;
    t->next = NULL;

    listaCvorova *susedniHead = graf[i].susedni;
    listaCvorova *susedniTail = graf[i].tail;

    if(susedniHead == NULL)
    {
        susedniHead = t;
    }
    else
    {
        susedniTail -> next = t;
    }

    susedniTail = t;

    graf[i].susedni = susedniHead;
    graf[i].tail = susedniTail;

    return graf;

}

Graf *UkloniGranu(Graf *graf, Cvor* x, Cvor* y)
{
    int i = 0;
    for(;i<brojCvorova;i++)
    {
        if(graf[i].cvor->id == x->id)
            break;
    }

    listaCvorova *head = graf[i].susedni;
    listaCvorova *prev = head;
    while(head)
    {
        if(head ->cvor ->id == y ->id)
        {
            if(prev != head){
                prev -> next = head -> next;
                free(head);
            }
            else
            {
                graf[i].susedni = head->next;
                free(head);

            }
            break;
        }
        prev = head;
        head = head->next;
    }


    return graf;

}

Graf *DodajCvor(Graf *graf,Cvor *x)
{
    graf = realloc(graf,(brojCvorova+1)*sizeof(*graf));

    graf[brojCvorova].susedni =NULL;
    graf[brojCvorova].cvor=x;
    graf[brojCvorova].tail=NULL;
    brojCvorova++;

    return graf;
}

void DealocirajSusedne(listaCvorova *susedni)
{
    listaCvorova *prev = NULL;
    while(susedni)
    {
        prev = susedni;
        susedni = susedni->next;

        free(prev);
    }
}

Graf *UkloniCvor(Graf *graf,Cvor *x)
{
    int i = 0;
    for (; i < brojCvorova; ++i) {
        if(graf[i].cvor->id == x->id)
        {
            //ukloni iz dinamickog niza
            DealocirajSusedne(graf[i].susedni);
            free(graf[i].cvor);

            for(int j = i; j<brojCvorova-1;j++)
            {
                Graf t = graf[j];
                graf[j] = graf[j+1];
                graf[j+1] = t;
            }

            graf = realloc(graf,sizeof(*graf)*(brojCvorova-1));
            brojCvorova--;
            i--;
        }
        else
        {
            UkloniGranu(graf,graf[i].cvor,x);
        }

    }

    return graf;


}

void DealocirajGraf(Graf *graf)
{
    for (int i = 0; i < brojCvorova; ++i) {
        DealocirajSusedne(graf[i].susedni);
        free(graf[i].cvor);
    }
}

void IspisiGraf(Graf* graf)
{
    putchar('\n');
    for (int i = 0; i < brojCvorova; ++i) {
        printf("%d\n",graf[i].cvor->id);

        listaCvorova *head = graf[i].susedni;
        while(head)
        {
            printf("--> %d\n",head->cvor->id);
            head = head ->next;
        }

    }
}

Graf* HendlujDodavanjeCvora(Graf *graf)
{
    int u;
    printf("===============\n");
    printf("Unesite id cvora: ");

    scanf("%d",&u);

    return DodajCvor(graf, FormirajCvor(u));

}

Graf* HendlujUklanjanjeCvora(Graf *graf)
{
    int u;
    printf("===============\n");
    printf("Unesite id cvora: ");

    scanf("%d",&u);

    return UkloniCvor(graf, FormirajCvor(u));
}

Graf* HendlujDodavanjeGrane(Graf *graf)
{
    int u,v;
    printf("===============\n");

    printf("Unesite id cvora od kog pocinje grana: ");
    scanf("%d",&u);

    printf("Unesite id cvora na kom se grana zavrsava: ");
    scanf("%d",&v);

    return DodajGranu(graf, FormirajCvor(u), FormirajCvor(v));
}

Graf* HendlujUklanjanjeGrane(Graf *graf)
{
    int u,v;
    printf("===============\n");

    printf("Unesite id cvora od kog pocinje grana: ");
    scanf("%d",&u);

    printf("Unesite id cvora na kom se grana zavrsava: ");
    scanf("%d",&v);

    return UkloniGranu(graf, FormirajCvor(u), FormirajCvor(v));
}

void PrekiniIzvrsavanjePrograma(Graf* graf)
{
    DealocirajGraf(graf);
    exit(0);
}

Graf *HendlujFormiranjeGrafa()
{
    printf("===============\n");
    printf("Unesite broj cvorova: ");
    scanf("%d",&brojCvorova);

    return FormirajGraf();

}
Graf *Meni(Graf *graf)
{
    int opcija = 0;
    while(1) {
        printf("###################\n");
        printf("1. Kreirajte graf\n");
        printf("2. Dodajte cvor \n");
        printf("3. Uklonite cvor\n");
        printf("4. Dodajte granu\n");
        printf("5. Uklonite granu\n");
        printf("6. Ispisi graf\n");
        printf("7. Prekini izvrsavanje programa\n");
        printf("###################\n");

        printf("Unesite opciju: ");
        scanf("%d",&opcija);

        if(opcija>7 || opcija < 1)
        {
            printf("Pogresan unos!");
        }
        else break;
    }

    switch (opcija) {
        case 1: graf = HendlujFormiranjeGrafa(); break;
        case 2: graf = HendlujDodavanjeCvora(graf); break;
        case 3: graf = HendlujUklanjanjeCvora(graf); break;
        case 4: graf = HendlujDodavanjeGrane(graf); break;
        case 5: graf = HendlujUklanjanjeGrane(graf); break;
        case 6:
            IspisiGraf(graf);
            break;
        default: PrekiniIzvrsavanjePrograma(graf); break;
    }

    return graf;



}

int main() {

    Graf *graf = NULL;
    while(1)
    {
        graf = Meni(graf);
    }
    return 0;
}
