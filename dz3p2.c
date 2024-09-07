//#include <stdio.h>
//#include <stdlib.h>
//// i = 2 j = 1
//
//typedef struct {
//    int id;
//} Cvor;
//
//typedef struct node{
//    Cvor *cvor;
//    struct node *next;
//} listaCvorova;
//
//typedef struct {
//    Cvor *cvor;
//    listaCvorova *susedni;
//    listaCvorova *tail;
//} Graf;
//
//int brojCvorova;
//
//Cvor *FormirajCvor(int id)
//{
//    Cvor *t=malloc(sizeof(*t));
//    t->id = id;
//    return t;
//}
//
//Graf *FormirajGraf()
//{
//    Graf *graf = malloc(sizeof(*graf)*brojCvorova);
//    for (int i = 0; i < brojCvorova; ++i) {
//        Cvor *t = malloc(sizeof(*t));
//        t->id = i;
//        graf[i].cvor = t;
//        graf[i].susedni = NULL;
//        graf[i].tail = NULL;
//    }
//    return graf;
//}
//
//Graf *DodajGranu(Graf *graf,Cvor* x, Cvor* y)
//{
//    int i = 0;
//    for (; i <brojCvorova ; ++i) {
//        if(graf[i].cvor->id == x->id) break;
//    }
//
//    listaCvorova *t = malloc(sizeof(*t));
//    t->cvor = y;
//    t->next = NULL;
//
//    listaCvorova *susedniHead = graf[i].susedni;
//    listaCvorova *susedniTail = graf[i].tail;
//
//    if(susedniHead == NULL)
//    {
//        susedniHead = t;
//    }
//    else
//    {
//        susedniTail -> next = t;
//    }
//
//    susedniTail = t;
//
//    graf[i].susedni = susedniHead;
//    graf[i].tail = susedniTail;
//
//    return graf;
//
//}
//
//Graf *UkloniGranu(Graf *graf, Cvor* x, Cvor* y)
//{
//    int i = 0;
//    for(;i<brojCvorova;i++)
//    {
//        if(graf[i].cvor->id == x->id)
//            break;
//    }
//
//    listaCvorova *head = graf[i].susedni;
//    listaCvorova *prev = head;
//    while(head)
//    {
//        if(head ->cvor ->id == y ->id)
//        {
//            if(prev != head){
//                prev -> next = head -> next;
//                free(head);
//            }
//            else
//            {
//                graf[i].susedni = head->next;
//                free(head);
//
//            }
//            break;
//        }
//        prev = head;
//        head = head->next;
//    }
//
//
//    return graf;
//
//}
//
//Graf *DodajCvor(Graf *graf,Cvor *x)
//{
//    graf = realloc(graf,(brojCvorova+1)*sizeof(*graf));
//
//    graf[brojCvorova].susedni =NULL;
//    graf[brojCvorova].cvor=x;
//    graf[brojCvorova].tail=NULL;
//    brojCvorova++;
//
//    return graf;
//}
//
//void DealocirajSusedne(listaCvorova *susedni)
//{
//    listaCvorova *prev = NULL;
//    while(susedni)
//    {
//        prev = susedni;
//        susedni = susedni->next;
//
//        free(prev);
//    }
//}
//
//Graf *UkloniCvor(Graf *graf,Cvor *x)
//{
//    int i = 0;
//    for (; i < brojCvorova; ++i) {
//        if(graf[i].cvor->id == x->id)
//        {
//            //ukloni iz dinamickog niza
//            DealocirajSusedne(graf[i].susedni);
//            free(graf[i].cvor);
//
//            for(int j = i; j<brojCvorova-1;j++)
//            {
//                Graf t = graf[j];
//                graf[j] = graf[j+1];
//                graf[j+1] = t;
//            }
//
//            graf = realloc(graf,sizeof(*graf)*(brojCvorova-1));
//            brojCvorova--;
//            i--;
//        }
//        else
//        {
//            UkloniGranu(graf,graf[i].cvor,x);
//        }
//
//    }
//
//    return graf;
//
//
//}
//
//void DealocirajGraf(Graf *graf)
//{
//    for (int i = 0; i < brojCvorova; ++i) {
//        DealocirajSusedne(graf[i].susedni);
//        free(graf[i].cvor);
//    }
//}
//
//void IspisiGraf(Graf* graf)
//{
//    putchar('\n');
//    for (int i = 0; i < brojCvorova; ++i) {
//        printf("%d\n",graf[i].cvor->id);
//
//        listaCvorova *head = graf[i].susedni;
//        while(head)
//        {
//            printf("--> %d\n",head->cvor->id);
//            head = head ->next;
//        }
//
//    }
//}
//
//Graf* HendlujDodavanjeCvora(Graf *graf)
//{
//    int u;
//    printf("===============\n");
//    printf("Unesite id cvora: ");
//
//    scanf("%d",&u);
//
//    return DodajCvor(graf, FormirajCvor(u));
//
//}
//
//Graf* HendlujUklanjanjeCvora(Graf *graf)
//{
//    int u;
//    printf("===============\n");
//    printf("Unesite id cvora: ");
//
//    scanf("%d",&u);
//
//    return UkloniCvor(graf, FormirajCvor(u));
//}
//
//Graf* HendlujDodavanjeGrane(Graf *graf)
//{
//    int u,v;
//    printf("===============\n");
//
//    printf("Unesite id cvora od kog pocinje grana: ");
//    scanf("%d",&u);
//
//    printf("Unesite id cvora na kom se grana zavrsava: ");
//    scanf("%d",&v);
//
//    return DodajGranu(graf, FormirajCvor(u), FormirajCvor(v));
//}
//
//Graf* HendlujUklanjanjeGrane(Graf *graf)
//{
//    int u,v;
//    printf("===============\n");
//
//    printf("Unesite id cvora od kog pocinje grana: ");
//    scanf("%d",&u);
//
//    printf("Unesite id cvora na kom se grana zavrsava: ");
//    scanf("%d",&v);
//
//    return UkloniGranu(graf, FormirajCvor(u), FormirajCvor(v));
//}
//
//void PrekiniIzvrsavanjePrograma(Graf* graf)
//{
//    DealocirajGraf(graf);
//    exit(0);
//}
//
//Graf *HendlujFormiranjeGrafa()
//{
//    printf("===============\n");
//    printf("Unesite broj cvorova: ");
//    scanf("%d",&brojCvorova);
//
//    return FormirajGraf();
//
//}
//Graf *Meni(Graf *graf)
//{
//    int opcija = 0;
//    while(1) {
//        printf("###################\n");
//        printf("1. Kreirajte graf\n");
//        printf("2. Dodajte cvor \n");
//        printf("3. Uklonite cvor\n");
//        printf("4. Dodajte granu\n");
//        printf("5. Uklonite granu\n");
//        printf("6. Ispisi graf\n");
//        printf("7. Prekini izvrsavanje programa\n");
//        printf("###################\n");
//
//        printf("Unesite opciju: ");
//        scanf("%d",&opcija);
//
//        if(opcija>7 || opcija < 1)
//        {
//            printf("Pogresan unos!");
//        }
//        else break;
//    }
//
//    switch (opcija) {
//        case 1: graf = HendlujFormiranjeGrafa(); break;
//        case 2: graf = HendlujDodavanjeCvora(graf); break;
//        case 3: graf = HendlujUklanjanjeCvora(graf); break;
//        case 4: graf = HendlujDodavanjeGrane(graf); break;
//        case 5: graf = HendlujUklanjanjeGrane(graf); break;
//        case 6:
//            IspisiGraf(graf);
//            break;
//        default: PrekiniIzvrsavanjePrograma(graf); break;
//    }
//
//    return graf;
//
//
//
//}
//
//int main() {
//
//    Graf *graf = NULL;
//    while(1)
//    {
//        graf = Meni(graf);
//    }
//    return 0;
//}
//=============================================================================



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define  MAXSTRLEN 100
#define MAXBRBACANJA 1000

typedef struct {
    double x,y,r;
} Mina;

typedef struct node{
    Mina *mina;
    struct node *next;
} Node;

typedef struct {
    Mina *mina;
    Node* susedni;
} Graf;

Graf *graf;
int brMina;

//region Red
#define QLEN 100

struct {
    int front,rear;
    Mina *red[QLEN];
} queue;

void InicijalizujRed()
{
    queue.front = queue.rear = 0;

}

bool isQEmpty()
{
    return queue.front == queue.rear;
}

Mina* Delete()
{
    queue.front = (queue.front+1) % QLEN;
    return queue.red[queue.front];
}

void Insert(Mina* x)
{
    queue.rear = (queue.rear+1) % QLEN;
    queue.red[queue.rear] = x;
}


//endregion

void PrekiniIzvrsavanjePrograma();
void DealocirajGraf()
{
    for (int i = 0; i < brMina; ++i) {
        Node *head = graf[i].susedni;

        Node *prev = NULL;
        while(head)
        {
            prev = head;
            head = head -> next;

            free(prev);
        }
    }

    for (int i = 0; i < brMina; ++i) {
        free(graf[i].mina);

    }
    free(graf);
}
int PronadjiIndeksZaMinu(Mina* a)
{
    int i = 0;
    for(; i < brMina; i++)
        if(graf[i].mina == a) break;
    return i;
}

void UcitajPodatkeIzDatoteke(char* imeUlazneDatoteke)
{
    FILE *fajl = fopen(imeUlazneDatoteke,"r");

    if(!fajl)
    {
        printf("Neuspesno otvaranje datoteke %s.",imeUlazneDatoteke);
        PrekiniIzvrsavanjePrograma();
    }

    fscanf(fajl,"%d",&brMina);
    graf = malloc(sizeof(*graf)*brMina);


    for (int i = 0; i < brMina; ++i) {
        Mina* t = malloc(sizeof(*t));
        fscanf(fajl,"%lf %lf %lf",&t->x,&t -> y, &t -> r);

        graf[i].mina = t;
        graf[i].susedni = NULL;
    }

    fclose(fajl);
}

double IzracunajRazdaljinuKvadrat(Mina* a, Mina* b)
{
    double x1 = a->x;
    double y1 = a->y;
    double x2 = b->x;
    double y2 = b->y;
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void DodajGranu(Mina *a, Mina *b)
{
    int i = PronadjiIndeksZaMinu(a);

    Node *t = malloc(sizeof(*t));
    t->mina = b;
    t->next = NULL;

    Node* head = graf[i].susedni;
    if(!head)
    {
        graf[i].susedni= t;
    }
    else
    {
        while(head->next)
        {
            head = head->next;
        }
        head -> next = t;
    }
}

void PoveziCvorSaOstalime(int i)
{
    for (int j = 0; j < brMina; ++j) {
        if(i == j) continue;

        if(IzracunajRazdaljinuKvadrat(graf[i].mina,graf[j].mina) <= graf[i].mina->r * graf[i].mina->r)
        {
            DodajGranu(graf[i].mina,graf[j].mina);
        }

    }

}

void PoveziCvorove()
{
    for (int i = 0; i < brMina; ++i) {
        PoveziCvorSaOstalime(i);
    }
}

void IspisiDetoniraneMine(Mina **detoniraneMine,int n) {
    printf("Detonirane mine su:\n");
    for (int i = 0; i < n; ++i) {
        Mina* t = detoniraneMine[i];
        printf("%.2lf %.2lf %.2lf",t -> x, t->y, t->r);
        putchar('\n');
    }
}

#define CHUNK 10
int NadjiEfikasnostMine(Mina* a,Mina*** detoniraneMine,bool uracunajMinu)
{
    InicijalizujRed();
    bool visit[brMina];
    for (int i = 0; i < brMina; ++i) {
        visit[i] = false;
    }

    int i = PronadjiIndeksZaMinu(a);
    int n = 0;
    visit[i] = true;
    Insert(a);


    if(detoniraneMine) *detoniraneMine = realloc(*detoniraneMine,CHUNK*sizeof(**detoniraneMine));
    if(detoniraneMine ) *detoniraneMine[n] = a;
    if(uracunajMinu) n++;
    while(!isQEmpty())
    {
        Mina* curr = Delete();
        Node* head = graf[PronadjiIndeksZaMinu(curr)].susedni;
        while (head)
        {
            int indeks = PronadjiIndeksZaMinu(head->mina);
            if(!visit[indeks]) {
                visit[indeks] = true;

                if(detoniraneMine)
                    if(n%CHUNK == 0) *detoniraneMine = realloc(*detoniraneMine,sizeof(**detoniraneMine)*(n+CHUNK));
                if(detoniraneMine)
                {
                    *(*detoniraneMine+n) = head->mina;
                }
                n++;
                Insert(head->mina);
            }
            head = head -> next;
        }
    }

    if(detoniraneMine) *detoniraneMine = realloc(*detoniraneMine,sizeof(**detoniraneMine)*n);

    return n;

}

int NadjiNajvecuEfikasnostUGrafu(Mina** minaNajveceEfikasnosti)
{
    int max = -1;
    for (int i = 0; i < brMina; ++i) {
        int e = NadjiEfikasnostMine(graf[i].mina,NULL,1);
        if(e > max)
        {
            max = e;
            *minaNajveceEfikasnosti = graf[i].mina;
        }
    }
    return max;
}

void DodajMinuUGraf(Mina* a)
{
    brMina++;
    graf = realloc(graf,brMina*sizeof(*graf));
    graf[brMina-1].mina = a;
    graf[brMina-1].susedni = NULL;

    PoveziCvorSaOstalime(brMina-1);
}

void IzbrisiMinuIzGrafa(Mina* a)
{
    for (int i = 0; i < brMina; ++i) {
        Node *head = graf[i].susedni;
        Node *prev = head;
        while(head)
        {
            if(head->mina == a)
            {
                prev -> next = head -> next;
                if(prev == head) graf[i].susedni = head -> next;
                free(head);
                break;
            }

            prev = head;
            head = head -> next;
        }

    }

    int indeks = PronadjiIndeksZaMinu(a);

    for (int i = indeks; i < brMina -1; ++i) {
        graf[i] = graf[i+1];
    }
    brMina --;
    graf = realloc(graf,brMina*sizeof(*graf));
}

int AktivirajRaketu(double x,double y,double r,Mina ***detoniraneMine)
{
    Mina *t = malloc(sizeof(*t));
    t -> x = x;
    t -> y = y;
    t -> r = r;

    DodajMinuUGraf(t);

    int e = NadjiEfikasnostMine(t,detoniraneMine,false);
    IzbrisiMinuIzGrafa(t);
    return e;
}

char *UcitajImeDatoteke()
{
    char str[MAXSTRLEN];

    char c;
    int n = 0;

    c = getchar();
    while((c=getchar()) != '\n')
    {
        str[n++] = c;
    }
    str[n] = '\0';

    char *rtn = str;
    return rtn;
}

void PrekiniIzvrsavanjePrograma()
{
    printf("Program uspesno prekinut!\n");
    DealocirajGraf();
    exit(0);
}

double Bacanje(double gornjaGranica, double donjaGranica)
{
    double bacanje01 = (double)rand() / (double)RAND_MAX ;

    return donjaGranica + bacanje01 * (gornjaGranica-donjaGranica);
}

double PronadjiUkupnuPovrsinu(int brBacanja)
{
    Mina *minaNajveceEfikasnosti = NULL;
    int n = NadjiNajvecuEfikasnostUGrafu(&minaNajveceEfikasnosti);
    Mina **detoniraneMine = NULL;
    NadjiEfikasnostMine(minaNajveceEfikasnosti,&detoniraneMine,true);

    Mina *curr = detoniraneMine[0];
    double minX = curr->x - curr -> r,
    minY = curr -> y - curr -> r,
    maxX = curr -> x + curr -> r,
    maxY = curr -> y + curr -> r;
    for (int i = 1; i < n; ++i) {
        curr = detoniraneMine[i];
        if(curr -> x - curr-> r < minX) minX = curr->x - curr -> r;
        if(curr -> y - curr -> r < minY) minY = curr -> y - curr -> r;
        if(curr -> x + curr -> r > maxX) maxX =  curr -> x + curr -> r;
        if(curr -> y + curr -> r > maxY) maxY = curr -> y + curr -> r;
    }

    double PPravougaonika = (maxX - minX)*(maxY-minY);
    int brPogodnjenih = 0;

    Mina* t = malloc(sizeof(*t));
    t->r = 0;
    for (int i = 0; i < brBacanja; ++i) {

        double x = Bacanje(maxX,minX);
        double y = Bacanje(maxY,minY);

        t->x = x;
        t->y = y;

        for (int j = 0; j < n; ++j) {
            curr = detoniraneMine[j];
            if(IzracunajRazdaljinuKvadrat(curr,t) <= curr->r * curr->r ) {brPogodnjenih++;break;}
        }

    }
    free(t);
    double odnos = (double)brPogodnjenih / (double)brBacanja;

    return PPravougaonika*odnos;
}

//region Hendlovanje

void HendlujPronalazenjeNajvecePovrsine()
{
    printf("=====================\n");
    printf("Ukupna povrsina mine sa najvecom efikasnosti je %.2lf.\n", PronadjiUkupnuPovrsinu(MAXBRBACANJA));
}
void HendlujKreiranjeGrafa()
{
    printf("=====================\n");
    printf("Unesite ime datoteke: ");
    char *imeUlazneDatoteke = UcitajImeDatoteke();

    if(imeUlazneDatoteke == NULL)
    {
        printf("Greska pri otvaranju datoteke!\n");
        return;
    }



    UcitajPodatkeIzDatoteke(imeUlazneDatoteke);
    PoveziCvorove();
    printf("Graf uspesno kreiran!\n");

}

void HendlujPronalazenjeEfikasnostiMine()
{
    printf("=====================\n");
    printf("Unesite redni broj mine (redni broj isti kao ulaz - pocinje od 0): ");
    int indeks;
    scanf("%d",&indeks);
    if(indeks < 0 || indeks >= brMina)
    {
        printf("Pogresan unos!\n");
        return;
    }

    Mina **detoniraneMine = NULL;
    int n = NadjiEfikasnostMine(graf[indeks].mina,&detoniraneMine,true);

    printf("Efikasnost mine je %d.\n",n);
    IspisiDetoniraneMine(detoniraneMine,n);
}

void HendlujPronalazenjeMineNajveceEfikasnosti()
{
    printf("=====================\n");
    Mina* minaNajveceEfikasnosti = NULL;
    int n = NadjiNajvecuEfikasnostUGrafu(&minaNajveceEfikasnosti);

    printf("Mina najvece efikasnosti ima indeks %d (%.2lf %.2lf %.2lf) i njena efikasnost je %d.\n",
           PronadjiIndeksZaMinu(minaNajveceEfikasnosti),minaNajveceEfikasnosti->x,minaNajveceEfikasnosti->y,minaNajveceEfikasnosti->r
           ,n);
}

void HendlujSimuliranjeRakete() {
    printf("=====================\n");
    printf("Unesite x y r: ");

    double x, y, r;
    if (scanf("%lf %lf %lf", &x, &y, &r) != 3)
    {
        printf("Pogresan unos!\n");
        return;
    }

    Mina **detoniraneMine = NULL;
    int n = AktivirajRaketu(x,y,r,&detoniraneMine);

    IspisiDetoniraneMine(detoniraneMine,n);

}

//endregion

bool Meni()
{
    int opcija;
    while(1) {
        printf("#####################################################################\n");
        printf("1. Kreiraj graf iz ulazne datoteke\n");
        printf("2. Pronadji efikasnost mine i ispisi detonirane mine\n");
        printf("3. Pronadji minu najvece efikasnosti\n");
        printf("4. Simuliraj eksploziju rakete\n");
        printf("5. Pronadji ukupnu povrsinu koja je pokrivena eksplozijom mine najvece efikasnosti\n");
        printf("6. Prekini program\n");
        printf("#####################################################################\n");


        scanf("%d", &opcija);
        if (opcija >= 1 && opcija <= 6) break;

        printf("Pogresan unos!\n");
    }

    switch (opcija) {
        case 1: HendlujKreiranjeGrafa(); break;
        case 2: HendlujPronalazenjeEfikasnostiMine();break;
        case 3: HendlujPronalazenjeMineNajveceEfikasnosti();break;
        case 4: HendlujSimuliranjeRakete();break;
        case 5: HendlujPronalazenjeNajvecePovrsine();break;
        default:
            return false;
    }

    return true;
}
int main() {

    while(Meni());

    PrekiniIzvrsavanjePrograma();
    return 0;
}
