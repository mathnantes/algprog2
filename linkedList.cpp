#include <iostream>

//  Alguns métodos de listas foram removidos porque não eram necessários para a resolução do exercício.

using namespace std;

class
Node
{
public:
    int data;
    Node *next;
};

class
linkedList
{
public:
    int size;
    Node *head;
    Node *tail;
    Node *temp;
    
    //  Verifica se a lista está vazia
    bool
    isEmpty()
    {
        return head == NULL;
    }

    //  Construtor da lista
    linkedList()
    {
        size = 0;
        head = NULL;
        tail = NULL;
    }

    //  Insere chave na lista
    void
    insert(int x)
    {
        temp = new Node;
        temp->data = x;
        size++;

        if (isEmpty())
        {
            temp->next = NULL;
            tail = temp;
        }
        else
            temp->next = head;
        
        head = temp;
    }
};

// Função que compara os elementos de duas listas
int
same_content(linkedList *L1, linkedList *L2)
{
    int match = 0;

    if (L1->size != L2->size)
        return 0;
    else
    {
        for (L1->temp = L1->head; L1->temp != NULL; L1->temp = L1->temp->next)
        {
            for (L2->temp = L2->head; L2->temp != NULL; L2->temp = L2->temp->next)
            {
                if (L1->temp->data == L2->temp->data)
                {
                    match++;
                    break;
                }
            }
        }

        if (match >= L1->size)
            return 1;
        else
            return 0;
    }
}

//  ###################### MAIN ######################
int
main()
{
    int k;
    
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        linkedList *L1 = new linkedList();
        linkedList *L2 = new linkedList();
        int sizeL1;
        int x;
        int order1, order2;

        cin >> sizeL1; //   Input tamanho de L1

        if (sizeL1 == 0)
            return 0;

        for (int m = 0; m < sizeL1; m++)
        {
            cin >> x;       //  Input dos valores da lista L1 e insere na mesma
            L1->insert(x);
        }

        int sizeL2;
        int y;

        cin >> sizeL2;  //   Input tamanho de L2

        if (sizeL2 == 0)
            return 0;

        for (int n = 0; n < sizeL2; n++)
        {
            cin >> y;       //  Input dos valores da lista L2 e insere na mesma
            L2->insert(y);
        }

        //  Chamada da função do exercício
        order1 = same_content(L1, L2);
        order2 = same_content(L2, L1);

        if (order1 != order2)
            cout << "nao" << endl;
        else if (order1 == 1)
            cout << "sim" << endl;
        else
            cout << "nao" << endl;
    }
}